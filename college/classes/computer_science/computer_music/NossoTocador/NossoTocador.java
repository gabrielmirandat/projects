import javax.sound.midi.*;
import java.io.*;


public class NossoTocador {
	static private Sequencer sequenciador = null;
	static private Sequence sequencia;
	static private Synthesizer sintetizador = null;
	static private Receiver receptor;
	static private Transmitter transmissor;
	static private MidiChannel canal;
	static private Soundbank banco_instrumentos;
	static private Track trilha;
	static private float andamento_inicial;
	static private float alteracao_andamento;
	
	final int MENSAGEM_ANDAMENTO = 0x51;
	final int FORMULA_DE_COMPASSO = 0x58;
	final int MENSAGEM_TONALIDADE = 0x59; 
	final int MENSAGEM_TEXTO = 0x01;
	
	public NossoTocador() 
	{ 
		this.open();
	}
	
	public void open(){ 
		try{
			//MidiDevice.Info[] info = MidiSystem.getMidiDeviceInfo();
			
			//sequenciador = (Sequencer) MidiSystem.getMidiDevice(info[3]);
			sequenciador = MidiSystem.getSequencer(true);
			sequenciador.open();
			//sintetizador = (Synthesizer) MidiSystem.getMidiDevice(info[2]);
			sintetizador = MidiSystem.getSynthesizer();
			sintetizador.open();
			// --crucial para volume
			receptor = null;
			receptor = sequenciador.getTransmitters().iterator().next().getReceiver();
			sequenciador.getTransmitter().setReceiver(receptor);
			// --
			transmissor = sequenciador.getTransmitter();
			transmissor.setReceiver(receptor);
		}catch (Exception ex) {}
	}
  
    public void carregar_musica(InputStream musica){
		try{
			// Seta a sequencia atual na qual o sequenciador ira atuar
			// A stream deve se referir a um arquivo de dados MIDI
			sequencia = MidiSystem.getSequence(musica); 
			sequenciador.setSequence(sequencia);
			trilha = sequencia.getTracks()[0];
			NossoTocador.alteracao_andamento = 0;
		}catch (Exception ex) {}
	}
    
    public void carregar_soundbank(InputStream banco, String nome){
	// Carregar soundbank de arquivo
    	
    	/*try {
	      banco_instrumentos = MidiSystem.getSoundbank(banco);
	}catch (Exception e) {}
    	
    	sintetizador.unloadAllInstruments(banco_instrumentos);
    	sintetizador.loadAllInstruments(banco_instrumentos);
    	
    	canal = sintetizador.getChannels()[0];
    	canal.programChange( banco_instrumentos.getInstruments()[0].getPatch().getBank()-1, 
    			         banco_instrumentos.getInstruments()[0].getPatch().getProgram()-1);
    	
    	try{ sequenciador.getTransmitter().setReceiver(sintetizador.getReceiver());}
		catch (Exception e) { e.printStackTrace(); }*/
    	sequenciador.stop();
    	Soundbank bancodefault = sintetizador.getDefaultSoundbank();
		
    	if(bancodefault != null)
		{ 
			
			
			sintetizador.unloadAllInstruments(bancodefault);          
		}         
    		File arquivoSF2 = new File(nome);
			if(!arquivoSF2.exists()) { System.out.println("Arquivo inexistente: " + nome + "\n");
                                     System.exit(0);
                                   }
    	try 
		{ 
			banco_instrumentos = MidiSystem.getSoundbank(arquivoSF2); 
		}
		catch (Exception e) { e.printStackTrace(); }

		sintetizador.loadAllInstruments(banco_instrumentos);
		
		try{ sequenciador.getTransmitter().setReceiver(sintetizador.getReceiver());}
		catch (Exception e) { e.printStackTrace(); }
		
	}
	
	public void tocar(int volume){
		try{  
			if(!sequenciador.isRunning()){
			// Comeca playback do arquivo de dados MIDI que acabou de ser carregado pelo sequenciador
				sequenciador.start();
				mudarVolume(volume);
				
			}
		}catch (Exception ex) { }
	}
	
	public boolean pausar(){
		if(sequenciador.isRunning()){
			sequenciador.stop();
			return true;
		}
		return false;
	}
	
	public void parar(){
		if(sequenciador!=null){
			sequenciador.stop();
			sequenciador.setTickPosition(0);
		}
	}
	
	public void sair() 
	{ 
		if (sequenciador != null) { 
			sequenciador.close();
		}
		sequenciador = null;
	}
	
	public void iniciarDe(int valor, int maximo, int volume){
		long total = sequenciador.getTickLength();
		double razao = ((double) valor/(double) maximo);
		double posicao = razao * (double) total;

		sequenciador.setTickPosition((long) posicao);
		mudarVolume(volume);
	}

	public void espera(int miliseg)
	{  
		try { Thread.sleep(miliseg);
		    }
		catch(InterruptedException e) { }
	}
	
	public void mudarVolume(int valor)
	{
	    ShortMessage mensagemDeVolume = new ShortMessage();
	    for(int i=0; i<16; i++)
	    {
	         try { mensagemDeVolume.setMessage(ShortMessage.CONTROL_CHANGE, i, 7, valor);
	               receptor.send(mensagemDeVolume, -1);
             }
	         catch (InvalidMidiDataException e1) {}
	    }
	} 
	
	public long obterTickAtual(){
		return  sequenciador.getTickPosition();
	}
	
	public long obterTicksTotal(){
		return  sequenciador.getTickLength();
	}
	
	public int obterDuracaoSegundos()
	{
		long tempo_total = sequenciador.getMicrosecondLength();
		int   seg        = Math.round(tempo_total*0.000001f);
		return seg;
	}
	
	public int obterDecorridoSegundos()
	{
		long tempo_decorrido = sequenciador.getMicrosecondPosition();
		int   seg            = Math.round(tempo_decorrido*0.000001f);
		return seg;
	}
	
	public String saidaTempoFormatado(int segundos)
	{
		String saida_formatada = String.format("%d:%02d:%02d", segundos/3600, (segundos%3600)/60, (segundos%60));
		return saida_formatada;
	}
	
	public boolean estaTocando()
	{
		return sequenciador.isRunning();
	}
	
	//Retorna um par ordenado (por meio de um objeto da classe Dimension) que representa a metrica (TimeSignature).
	public String getFormulaDeCompasso()
	{   String saida;
		int p=1;
	    int q=1;
	    
	    for(int i=0; i<trilha.size(); i++)
	    {
	       MidiMessage m = trilha.get(i).getMessage();
	       if(m instanceof MetaMessage) 
	       {
	         if(((MetaMessage)m).getType()==FORMULA_DE_COMPASSO)
	         {
	             MetaMessage mm = (MetaMessage)m;
	             byte[] data = mm.getData();
	             p = data[0];
	             q = data[1];
	             saida = p+"/"+(int)Math.pow(2,q);
	             return saida;
	         }
	       }
	     }
        saida = p+"/"+(int)Math.pow(2,q);
        return saida;
	 }

	//Metodo definido para retornar o valor do andamento em BPM, valor este mantido como real (float).
	public String getAndamento() throws InvalidMidiDataException
    {  String saida;   
       
       for(int i=0; i<trilha.size(); i++)
       {
    	   MidiMessage m = trilha.get(i).getMessage();
    	   if(m instanceof MetaMessage) 
    	   {
    		   if(((MetaMessage)m).getType()== MENSAGEM_ANDAMENTO)
    		   {
    			   MetaMessage mm   = (MetaMessage)m;
    			   byte[]      data = mm.getData();
    		   
    			   byte primeiro = data[0];
    			   byte segundo  = data[1];
    			   byte terceiro = data[2];
    		   
    			   long microseg = (long)(primeiro*Math.pow(2, 16) +
    					   				  segundo *Math.pow(2,  8) +
    					   				  terceiro
                                  		 );
    		   
    			   //int andamento = (int)(60000000.0/microseg);
    			   //return "Andamento: " + andamento + " bpm";     
                    this.andamento_inicial = (float)(60000000.0/microseg);
    			   saida = Float.toString((float)(60000000.0/microseg));
    			   return saida + " bpm";                                    
    		   }
    	   }
       }
       return "indispon\u00EDvel";
    }
	
	public String getNovoAndamento()
	{
		String saida;
		float andamento_final;
		
		andamento_final = NossoTocador.andamento_inicial + NossoTocador.alteracao_andamento;
		saida = Float.toString(andamento_final);
		return saida + "bpm";
		
	}	
	
	//A tonalidade e dada por dois bytes (*): o primeiro indica o numero de sustenidos (se positivo) ou de bemois (se negativo) na armadura de 
		//compasso. O segundo byte pode valer 0 (zero) ou 1 (um). No primeiro caso, a tonalidade sera Maior. E sera Menor no segundo caso. 
	public String getTonalidade() throws InvalidMidiDataException
	{   String stonalidade = "indispon\u00EDvel";
	     
		for(int i=0; i<trilha.size(); i++)
		{
			MidiMessage m = trilha.get(i).getMessage();
			if(m instanceof MetaMessage) 
			{
				if(((MetaMessage)m).getType()== MENSAGEM_TONALIDADE)      
				{
					MetaMessage mm        = (MetaMessage)m;
					byte[]     data       = mm.getData();
					byte       tonalidade = data[0];
					byte       maior      = data[1];

					String       smaior = "Maior";
					if(maior==1) smaior = "Menor";

					if(smaior.equalsIgnoreCase("Maior"))
					{
						switch (tonalidade)
						{
							case -7: stonalidade = "D\u00F3b Maior"; break;
							case -6: stonalidade = "Solb Maior"; break;
							case -5: stonalidade = "R\u00E9b Maior"; break;
							case -4: stonalidade = "L\u00E1b Maior"; break;
							case -3: stonalidade = "Mib Maior"; break;
							case -2: stonalidade = "Sib Maior"; break;
							case -1: stonalidade = "F\u00E1 Maior"; break;
							case  0: stonalidade = "D\u00F3 Maior"; break;
							case  1: stonalidade = "Sol Maior"; break;
							case  2: stonalidade = "R\u00E9 Maior"; break;
							case  3: stonalidade = "L\u00E1 Maior"; break;
							case  4: stonalidade = "Mi Maior"; break;
							case  5: stonalidade = "Si Maior"; break;
							case  6: stonalidade = "F\u00E1# Maior"; break;
							case  7: stonalidade = "D\u00F3# Maior"; break;
						}
					}
					
					else if(smaior.equalsIgnoreCase("Menor"))
					{
						switch (tonalidade)
						{
							case -7: stonalidade = "L\u00E1b Menor"; break;
							case -6: stonalidade = "Mib Menor"; break;
							case -5: stonalidade = "Sib Menor"; break;
							case -4: stonalidade = "F\u00E1 Menor"; break;
							case -3: stonalidade = "D\u00F3 Menor"; break;
							case -2: stonalidade = "Sol Menor"; break;
							case -1: stonalidade = "R\u00E9 Menor"; break;
							case  0: stonalidade = "L\u00E1 Menor"; break;
							case  1: stonalidade = "Mi Menor"; break;
							case  2: stonalidade = "Si Menor"; break;
							case  3: stonalidade = "F\u00E1# Menor"; break;
							case  4: stonalidade = "D\u00F3# Menor"; break;
							case  5: stonalidade = "Sol# Menor"; break;
							case  6: stonalidade = "R\u00E9# Menor"; break;
							case  7: stonalidade = "L\u00E1# Menor"; break;
						}
					}
					return stonalidade;
				}
			}
		}
		return stonalidade;
	}
	
	//Obtem metro
	public String getMetro() 
	{	String saida = "indispon\u00EDvel";
		
		long duracao     = sequencia.getMicrosecondLength()/1000000;
		int  resolucao   = sequencia.getResolution();
		long totaltiques = sequencia.getTickLength();
		
		
		float durtique       = (float)duracao/totaltiques;
		float durseminima    = durtique*resolucao;
		
		saida = Float.toString((float)(durseminima));
		return saida + " s";   

	}
		
	//Andamento e o numero de seminimas por minuto. Mede-se em BPM. O metodo abaixo altera a taxa de seminimas no sintetizador; (em resultado de 
	//alterar a duracao do pulso (tique)).
	void setAndamento(int valor) throws InvalidMidiDataException
    {
      Track[] trilhas = sequencia.getTracks();
		this.alteracao_andamento = valor;
      String aux = getAndamento();
      int tam = aux.length();
      
      aux = aux.substring(0, tam - 4);
      
      float bpm = Float.parseFloat(aux);
      
      bpm = bpm + (float) valor;
      
      MetaMessage mensagemDeAndamento = new MetaMessage();
      int microssegundos = (int)(60000000.0 / bpm);

      byte dados[] = new byte[3];
      dados[0] = (byte)(microssegundos >>> 16);
      dados[1] = (byte)(microssegundos >>> 8);
      dados[2] = (byte)(microssegundos);
      
      mensagemDeAndamento.setMessage(MENSAGEM_ANDAMENTO, dados, 3);
      for(int i=0; i<trilhas.length; i++)
      { trilhas[i].add(new MidiEvent(mensagemDeAndamento, 0));
      }
      
    }
	
	/*//Diz respeito a metrica do compasso. Contem dois dados: numerador e denominador. Este ultimo deve ser usado como expoente para uma potencia de
	//2 a fim de se obter o valor real do denominador da fracao p /q, sendo q a duracao (relativa) de uma das p divisoes em que se divide o compasso.
	//O metodo getFormulaDeCompasso abaixo retorna um par ordenado (por meio de um objeto da classe Dimension) que representa a metrica. 
	void setFormulaDeCompasso(int p, int q, Sequence sequencia) 
            throws InvalidMidiDataException
	{
		Track[] trilhas = sequencia.getTracks();
		MetaMessage mensagemDeFormulaDeCompasso = new MetaMessage();
		int qExp = (int) (Math.log((double)q) / Math.log(2.0));

		//--sequenciador.stop();   //---pode ser preciso
		//--atualizar a GUI;

		byte dados[] = new byte[4];
		dados[0] = (byte)p;
		dados[1] = (byte)qExp;
		dados[2] = (byte)24;
		dados[3] = (byte)8;
		mensagemDeFormulaDeCompasso.setMessage(0x58, dados, 4);

		for(int i=0; i<trilhas.length; i++)
		{ trilhas[i].add(new MidiEvent(mensagemDeFormulaDeCompasso, 0));
		}
	}
	
	*/
}

