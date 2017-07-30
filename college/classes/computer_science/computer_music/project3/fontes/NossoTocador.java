import javax.sound.midi.*;

import java.io.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
//import java.io.FileNotFoundException;
import java.io.IOException;

public class NossoTocador {
	static private Sequencer sequenciador = null;
	static private Sequence sequencia;
	static private Synthesizer sintetizador = null;
	static private Receiver receptor;
	static private Transmitter transmissor;
	static private Instrument[] instrumentos = null;
	static private Track trilha;
	static private float durtique;
	
	private String nome_arquivo_java    = "MusicaCriada.java";
	private String nome_arquivo_txt = "musica.txt";
	FileWriter fout_txt, fout_java, fout_midi, fout_inst , fout_sintese;
	BufferedWriter bw_txt, bw_java, bw_midi,bw_inst, bw_sintese;
	FileReader fin_txt = null;
	BufferedReader bin_txt = null;

	private double[] TABELA_FREQ = 
{8.1757989156 ,8.6619572180 ,9.1770239974 ,9.7227182413 ,10.3008611535 ,10.9133822323 ,11.5623257097 ,12.2498573744 ,12.9782717994,
 13.7500000000,14.5676175474,15.4338531643,16.3515978313,17.3239144361 ,18.3540479948 ,19.4454364826 ,20.6017223071 ,21.8267644646,					
 23.1246514195,24.4997147489,25.9565435987,27.5000000000,29.1352350949 ,30.8677063285 ,32.7031956626 ,34.6478288721 ,36.7080959897,	
 38.8908729653,41.2034446141,43.6535289291,46.2493028390,48.9994294977 ,51.9130871975 ,55.0000000000 ,58.2704701898 ,61.7354126570,	
 65.4063913251,69.2956577442,73.4161919794,77.7817459305,82.4068892282 ,87.3070578583 ,92.4986056779 ,97.9988589954,103.8261743950,
 110.0000000000 ,116.5409403795 ,123.4708253140 ,130.8127826503 ,138.5913154884 ,146.8323839587 ,155.5634918610 ,164.8137784564 ,
 174.6141157165 ,184.9972113558 ,195.9977179909 ,207.6523487900 ,220.0000000000 ,233.0818807590 ,246.9416506281 ,261.6255653006 ,
 277.1826309769 ,293.6647679174 ,311.1269837221 ,329.6275569129 ,349.2282314330 ,369.9944227116 ,391.9954359817 ,415.3046975799 ,
 440.0000000000 ,466.1637615181 ,493.8833012561 ,523.2511306012 ,554.3652619537 ,587.3295358348 ,622.2539674442 ,659.2551138257 ,
 698.4564628660 ,739.9888454233 ,783.9908719635 ,830.6093951599 ,880.0000000000 ,932.3275230362 ,987.7666025122 ,1046.5022612024,
 1108.7305239075,1174.6590716696,1244.5079348883,1318.5102276515,1396.9129257320,1479.9776908465,1567.9817439270,1661.2187903198,
 1760.0000000000,1864.6550460724,1975.5332050245,2093.0045224048,2217.4610478150,2349.3181433393,2489.0158697766,2637.0204553030,
 2793.8258514640,2959.9553816931,3135.9634878540,3322.4375806396,3520.0000000000,3729.3100921447,3951.0664100490,4186.0090448096,
 4434.9220956300,4698.6362866785,4978.0317395533,5274.0409106059,5587.6517029281,5919.9107633862,6271.9269757080,6644.8751612791,
 7040.0000000000,7458.6201842894,7902.1328200980,8372.0180896192,8869.8441912599,9397.2725733570,9956.0634791066,10548.0818212118,
 11175.3034058561,11839.8215267723,12543.8539514160};

	private String[] TABELA_INST_SINTESE = 
		{"BancoDeInstrumentos.flauta_nao_harmonica_tonal(1.75f)",
		"BancoDeInstrumentos.gongo_aa_1994(6f)",
		"BancoDeInstrumentos.marimba_i51(0.3f)",
		"BancoDeInstrumentos.timbre_quasetonal(50f)",
		"BancoDeInstrumentos.sompuro(0.5f)",
		"BancoDeInstrumentos.timbreortogonal3(16f)",
		"BancoDeInstrumentos.trombone_naoharmonico(4f)",
		"BancoDeInstrumentos.trompete01(60f)",
		"BancoDeInstrumentos.flauta_nao_harmonica_tonal(3.0f)",
		"BancoDeInstrumentos.gongo_aa_1994(6f)",
		"BancoDeInstrumentos.marimba_i51(0.3f)",
		"BancoDeInstrumentos.timbre_quasetonal(50f)",
		"BancoDeInstrumentos.sompuro(0.5f)",
		"BancoDeInstrumentos.timbreortogonal3(16f)",
		"BancoDeInstrumentos.trombone_naoharmonico(4f)",
		"BancoDeInstrumentos.trompete01(60f)"};
	
	public NossoTocador() 
	{ 
		this.open();
	}
	
	public void open(){ 
		try{
			sequenciador = MidiSystem.getSequencer(true);
			sequenciador.open();
			sintetizador = MidiSystem.getSynthesizer();
			sintetizador.open();
			receptor = null;
			receptor = sequenciador.getTransmitters().iterator().next().getReceiver();
			sequenciador.getTransmitter().setReceiver(receptor);
			transmissor = sequenciador.getTransmitter();
			transmissor.setReceiver(receptor);
			
			instrumentos = sintetizador.getAvailableInstruments();
		}catch (Exception ex) {}
	}
  
    public void carregar_musica(InputStream musica){
		try{
			// Seta a sequencia atual na qual o sequenciador ira atuar
			// A stream deve se referir a um arquivo de dados MIDI
			sequencia = MidiSystem.getSequence(musica); 
			sequenciador.setSequence(sequencia);
			trilha = sequencia.getTracks()[0];
			
			long duracao     = sequencia.getMicrosecondLength()/1000000;
			long totaltiques = sequencia.getTickLength();
			durtique       = (float)duracao/totaltiques;
			
		}catch (Exception ex) {}
	}
    
    public void get_valores(){
      Track[] trilhas = sequencia.getTracks(); 
      int inst, flag;
      inst = flag = 0;
      int comando = -1;
      long dur1,dur2,dur_tiq;
      dur1 = dur2 = dur_tiq = 0;
      double dur_seg = 0.0;
      double freq,intens,aux;
      freq = intens = aux = 0;

      fout_txt = fout_midi = fout_inst = null;
      bw_txt = bw_midi = bw_inst = null;
      
      try {	
    	fout_txt = new FileWriter(nome_arquivo_txt);
        fout_midi = new FileWriter("dados_midi.txt");
  	    fout_inst = new FileWriter("dados_inst.txt");
  		
        bw_txt = new BufferedWriter(fout_txt);  
        bw_midi = new BufferedWriter(fout_midi);
        bw_inst = new BufferedWriter(fout_inst);
  	  
  	    //note(canal, nota, intensidade)
  	    bw_midi.write("note(canal, nota, intensidade), tick");  bw_midi.newLine();
  	    bw_midi.newLine();
  	    
  	    //Instrumentos MIDI/sintese
  	    bw_inst.write("instrumentos midi x sintese");  bw_inst.newLine();
  	    bw_inst.newLine();

  	    for(int i=0;i < trilhas.length; i++){
    		//Estou dentro da trilha. Analisando eventos da trilha.
    		trilha = trilhas[i];
    		for(int j=0;j < trilha.size();j++){
    			//Estou dentro dos eventos. Analisando ticks e mensagens MIDI.
    			MidiEvent me = trilha.get(j);
                MidiMessage mm = me.getMessage();
                if(mm instanceof ShortMessage){
                	ShortMessage sm = (ShortMessage) mm;
                	comando = sm.getCommand();
                	if(comando == ShortMessage.PROGRAM_CHANGE){
                		//status : 1100kkkk (kkkk = canal Midi = 0...15)
                		//byte 2 : 0ppppppp (número do instrumento = 0...127)
                		bw_inst.write(instrumentos[sm.getData1()].toString()+ " ");
                		bw_inst.write(TABELA_INST_SINTESE[inst] + " ");
                		bw_inst.newLine(); bw_inst.newLine();
                		inst = inst + 1;
                		inst = (inst)%16;
                	}
                	if (comando == ShortMessage.NOTE_ON) {
                		aux = sm.getData2();
                		bw_midi.write("note_on("+sm.getChannel()+", "+sm.getData1()+", "+aux+"), "+me.getTick()); bw_midi.newLine();
                		if(aux != 0.0f){	
                			intens = 0.2 * (double)sm.getData2();
	                		dur1 = me.getTick();
	                		freq = TABELA_FREQ[sm.getData1()];
                		}else{
	                		comando = ShortMessage.NOTE_OFF;
	                		flag = 1;
	                	}
                	}
                	if (comando == ShortMessage.NOTE_OFF) {
                		if(flag!=1){
                			bw_midi.write("note_off("+sm.getChannel()+", "+sm.getData1()+", "+sm.getData2()+"), "+me.getTick()); bw_midi.newLine();
                			flag=0;
                		}
                		dur2 = me.getTick();
                		dur_tiq = dur2 - dur1;
                		dur_seg = ((dur_tiq * durtique)/*1000000.0*/);
                		bw_txt.write(inst + "\t");
                		bw_txt.write(dur_seg + "\t");
                		bw_txt.write(freq + "\t");
                		bw_txt.write(intens + "\t");
       	        	 	bw_txt.newLine();
                	}
                }
    		}
    	}
    
      } catch (IOException e) {
  		// TODO Auto-generated catch block
  		e.printStackTrace();
  	  } finally {
  		  try {
  			bw_inst.close();
  			bw_java.close();
  		    bw_midi.close();
  		    fout_inst.close();
  		    fout_java.close();
  			fout_midi.close();
  		  } catch (IOException e) {
  			// TODO Auto-generated catch block
  			e.printStackTrace();
  		  }
  	  }
    }
    
    public void cria_arquivo(){
    	fout_java = fout_sintese = null;
    	bw_java = bw_sintese = null;
    	fin_txt = null;
    	bin_txt = null;
    	try {
    		fout_java = new FileWriter(nome_arquivo_java);
    		fout_sintese = new FileWriter("dados_sintese.txt");
    		
    		bw_java = new BufferedWriter(fout_java);
    		bw_sintese = new BufferedWriter(fout_sintese);
    		
    		fin_txt = new FileReader(nome_arquivo_txt);
			bin_txt = new BufferedReader(fin_txt);
			
	        //addNota(duracao, frequencia, amplitude)
	  	    bw_sintese.write("Nota(duracao, frequencia, amplitude)");  bw_sintese.newLine();
	  	    bw_sintese.newLine();
			
bw_java.write("import sintese.*;");	 bw_java.newLine();
bw_java.write("public class MusicaCriada{");  bw_java.newLine();
bw_java.write("Polifonia polifonia;");  bw_java.newLine();
							String line;
bw_java.write("public MusicaCriada(){");      bw_java.newLine();
bw_java.write("polifonia = new Polifonia();");	bw_java.newLine();
							line = null;
			
bw_java.write("Dispositivo[] TABELA_INST = ");	bw_java.newLine();
bw_java.write("{BancoDeInstrumentos.flauta_nao_harmonica_tonal(1.75f),	//0");	bw_java.newLine();
bw_java.write("BancoDeInstrumentos.gongo_aa_1994(6f),//1");bw_java.newLine();
bw_java.write("BancoDeInstrumentos.marimba_i51(0.3f),//2");bw_java.newLine();
bw_java.write("BancoDeInstrumentos.timbre_quasetonal(50f),//3");bw_java.newLine();
bw_java.write("BancoDeInstrumentos.sompuro(0.5f),//4");bw_java.newLine();
bw_java.write("BancoDeInstrumentos.timbreortogonal3(16f),//5");bw_java.newLine();
bw_java.write("BancoDeInstrumentos.trombone_naoharmonico(4f),//6");bw_java.newLine();
bw_java.write("BancoDeInstrumentos.trompete01(60f),//7");bw_java.newLine();
bw_java.write("};");bw_java.newLine();
			
bw_java.write("Melodia[] TABELA_MEL ="); bw_java.newLine();
bw_java.write("{new Melodia(),	//0");bw_java.newLine();
bw_java.write("new Melodia(),	//1");bw_java.newLine();
bw_java.write("new Melodia(),	//2");bw_java.newLine();
bw_java.write("new Melodia(),	//3");bw_java.newLine();
bw_java.write("new Melodia(),	//4");bw_java.newLine();
bw_java.write("new Melodia(),	//5");bw_java.newLine();
bw_java.write("new Melodia(),	//6");bw_java.newLine();
bw_java.write("new Melodia(),	//7");bw_java.newLine();
bw_java.write("new Melodia(),	//8");bw_java.newLine();
bw_java.write("new Melodia(),	//9");bw_java.newLine();
bw_java.write("new Melodia(),	//10");bw_java.newLine();
bw_java.write("new Melodia(),	//11");bw_java.newLine();
bw_java.write("new Melodia(),	//12");bw_java.newLine();
bw_java.write("new Melodia(),	//13");bw_java.newLine();
bw_java.write("new Melodia(),	//14");bw_java.newLine();
bw_java.write("new Melodia()	//15");bw_java.newLine();
bw_java.write("};");bw_java.newLine();
			
bw_java.write("Voz[] TABELA_VOZ = ");bw_java.newLine();
bw_java.write("{new Voz(TABELA_INST[0]),//0");bw_java.newLine();
bw_java.write("new Voz(TABELA_INST[1]),	//1");bw_java.newLine();
bw_java.write("new Voz(TABELA_INST[2]),	//2");bw_java.newLine();
bw_java.write("new Voz(TABELA_INST[3]),	//3");bw_java.newLine();
bw_java.write("new Voz(TABELA_INST[4]),	//4");bw_java.newLine();
bw_java.write("new Voz(TABELA_INST[5]),	//5");bw_java.newLine();
bw_java.write("new Voz(TABELA_INST[6]),	//6");bw_java.newLine();
bw_java.write("new Voz(TABELA_INST[7]),	//7");bw_java.newLine();
bw_java.write("new Voz(TABELA_INST[0]),	//8");bw_java.newLine();
bw_java.write("new Voz(TABELA_INST[1]),	//9");bw_java.newLine();
bw_java.write("new Voz(TABELA_INST[2]),	//10");bw_java.newLine();
bw_java.write("new Voz(TABELA_INST[3]),	//11");bw_java.newLine();
bw_java.write("new Voz(TABELA_INST[4]),	//12");bw_java.newLine();
bw_java.write("new Voz(TABELA_INST[5]),	//13");bw_java.newLine();
bw_java.write("new Voz(TABELA_INST[6]),	//14");bw_java.newLine();
bw_java.write("new Voz(TABELA_INST[7])	//15");bw_java.newLine();
bw_java.write("};");bw_java.newLine();

			int[] TABELA_IND = 
				{-1,	//0
				 -1,	//1
				 -1,	//2
				 -1,	//3
				 -1,	//4
				 -1,	//5
				 -1,	//6
				 -1,	//7
				 -1,	//8
				 -1,	//9
				 -1,	//10
				 -1,	//11
				 -1,	//12
				 -1,	//13
				 -1,	//14
				 -1	    //15
				};
			
			while((line=bin_txt.readLine())!=null){
				String[] words = line.split("\t");
				//words[1] = (words[1] == null? "0f" : words[1]); 
				//words[2] = (words[2] == null? "0f" : words[2]); 
				//words[3] = (words[3] == null? "0f" : words[3]); 
				if(words.length==4){
bw_sintese.write("Nota("+Float.parseFloat(words[1])+","+ Float.parseFloat(words[2])+","+ Float.parseFloat(words[3])+")"); bw_sintese.newLine();
bw_java.write("TABELA_MEL["+Integer.parseInt(words[0])+"].addNota(new Nota("+Float.parseFloat(words[1])+","+ Float.parseFloat(words[2])+","+ Float.parseFloat(words[3])+"));");
bw_java.newLine();				
				TABELA_IND[Integer.parseInt(words[0])] = 1;
				}
			}
			
		    for(int i=0;i<16;i++){
		    	if(TABELA_IND[i]==1){
bw_java.write("TABELA_VOZ["+i+"].addMelodia(TABELA_MEL["+i+"]);"); bw_java.newLine();
bw_java.write("polifonia.addVoz(TABELA_VOZ["+i+"]);"); bw_java.newLine();
		    	}
		    }
bw_java.write("polifonia.ganho(0.01f);");bw_java.newLine();
bw_java.write("Som som = polifonia.getSom();"); bw_java.newLine();
bw_java.write("som.visualiza();");bw_java.newLine();
bw_java.write("som.salvawave();");bw_java.newLine();

bw_java.write("try{ System.in.read();");bw_java.newLine();
bw_java.write("System.exit(0); ");bw_java.newLine();
bw_java.write("} ");bw_java.newLine();
bw_java.write("catch(Exception e){};");bw_java.newLine(); 
bw_java.write("}");bw_java.newLine(); 
bw_java.write("public static void main(String args[])");bw_java.newLine(); 
bw_java.write("{ new MusicaCriada();");bw_java.newLine(); 
bw_java.write("}");bw_java.newLine();    
bw_java.write("}");bw_java.newLine();

    	} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
    	} finally {
			try {
				bw_java.close();
				bw_sintese.close();
				fout_java.close();
				fout_sintese.close();
				fin_txt.close();
				bin_txt.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
    }

	public void sair() 
	{ 
		if (sequenciador != null) { 
			sequenciador.close();
		}
		sequenciador = null;
		if (sintetizador != null) { 
			sintetizador.close();
		}
		sequenciador = null;
		sintetizador = null;
	}

	public void espera(int miliseg)
	{  
		try { Thread.sleep(miliseg);
		    }
		catch(InterruptedException e) { }
	}

}

