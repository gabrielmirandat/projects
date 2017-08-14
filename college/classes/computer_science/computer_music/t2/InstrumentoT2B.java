import sintese.*;

public class InstrumentoT2B extends Dispositivo{
	 	private boolean    canal;
	    private float      lambda;
	    private float      ummenoslambda;
	    private float      fase;
	    private float      ganho = 1;
	    
	    private Envoltoria envAMPLITUDE;
	    private Envoltoria envCONSTANTE;
	    private Envoltoria envRUIDO;
	    private Ruido      geradorRUIDO;   //--unidade de Ruido
	    private Oscilador  oscSENOIDAL;    //--unidade Senoidal
	    private Somador    uniSOMADORA;	   //--unidade somadora
	    
	    private float fatorCorte;
	    

	    
	    public InstrumentoT2B(float fc)
	    { this(new Ruido(), new Envoltoria(), new Envoltoria(),new Envoltoria(), fc);
	    }

	    
	    public InstrumentoT2B(Ruido ruido_, Envoltoria env_1, Envoltoria env_2,
	    		              Envoltoria env_3, float fc_)
	    {
	        super();        
	        fatorCorte = fc_; 
	        
	        this.geradorRUIDO    = ruido_;
	        this.envAMPLITUDE    = env_1;
	        this.envCONSTANTE    = env_2;
	        this.envRUIDO		 = env_3;
	        
	        this.uniSOMADORA = new Somador(envCONSTANTE, geradorRUIDO);
	        this.oscSENOIDAL = new Oscilador();
	        this.setRelogio(0);
	    }
	   
	   
	    public void relogio() 
	    { oscSENOIDAL.relogio();
	    }
	   
	   
	    public void setRelogio(long n)
	    { 
	      envAMPLITUDE.setRelogio(n);
	      envCONSTANTE.setRelogio(n);
	      envRUIDO.setRelogio(n);
	      oscSENOIDAL.setRelogio(n);
	      geradorRUIDO.setRelogio(n);
	      uniSOMADORA.setRelogio(n);
	      this.saida = oscSENOIDAL.getSaida()*((canal) ? ummenoslambda : lambda);
	      canal = !canal;
	      reset();
	    }
	        

	    public float getSaida()
	    {         
	      this.saida = oscSENOIDAL.getSaida()*((canal) ? ummenoslambda : lambda);
	      canal      = !canal;
	      return ganho*this.saida;
	    }
	    
	    
	    public void reset() 
	    {        
	        envAMPLITUDE.setDuracao(duracao);
	        envAMPLITUDE.reset();
	        
	        envCONSTANTE.setDuracao(duracao);
	        envCONSTANTE.reset();

	        geradorRUIDO.setDispositivoAmplitude(envRUIDO);
	        geradorRUIDO.setFrequencia((float)frequencia*fatorCorte);
	        geradorRUIDO.setFase(fase);
	        geradorRUIDO.setDuracao(duracao);
	        geradorRUIDO.reset();
	                
	        uniSOMADORA = null;
	        uniSOMADORA = new Somador(envCONSTANTE, geradorRUIDO);
	        uniSOMADORA.setDuracao(duracao);
	        uniSOMADORA.reset();
	        
	        oscSENOIDAL.setDispositivoAmplitude(envAMPLITUDE);
	        oscSENOIDAL.setDispositivoFrequencia(uniSOMADORA);
	        oscSENOIDAL.setFase(fase);
	        oscSENOIDAL.setDuracao(duracao);
	        oscSENOIDAL.reset();                
	    }



	    public void setGanho(float g)
	    {this.ganho = g;
	     
	    }

	    public void setDuracao(float d)
	    {   this.duracao = d;
	        envAMPLITUDE.setDuracao(d);
	        envCONSTANTE.setDuracao(d);
	        envRUIDO.setDuracao(d);
	        geradorRUIDO.setDuracao(d);
	        uniSOMADORA.setDuracao(d);
	        oscSENOIDAL.setDuracao(d);
	        reset();
	    }


	    public void setFrequencia(float freq)
	    { this.frequencia = freq;
	      reset();
	    }

	    public void setLambda(double lambda_)
	    { this.lambda = (float)lambda_;
	      this.ummenoslambda = 1 - this.lambda;
	      reset();
	    }

	    public void setEnvoltoria(Envoltoria env_1, Envoltoria env_2, Envoltoria env_3)
	    { this.envAMPLITUDE = env_1;
	      this.envCONSTANTE = env_2;
	      this.envRUIDO		= env_3;
	      reset();
	    }

	    public void setFase(float fase)
	    { this.fase = fase;
	      reset();
	    }
}
