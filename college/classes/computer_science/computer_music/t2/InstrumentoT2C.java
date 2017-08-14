import sintese.*;

public class InstrumentoT2C extends Dispositivo{
	 	private boolean    canal;
	    private float      lambda;
	    private float      ummenoslambda;
	    private float      fase;
	    private float      ganho = 1;
	    
	    private Envoltoria envAMPLITUDE;
	    private Envoltoria envCONSTANTE;
	    private Envoltoria envRUIDO;
	    private Envoltoria envOSCILADOR;
	    private Ruido      geradorRUIDO;    //--unidade de Ruido
	    private Oscilador  oscSENOIDALi;	//--unidade Senoidal inicial
	    private Oscilador  oscSENOIDALf;    //--unidade Senoidal final
	    private Somador    uniSOMADORA1;    //--unidade somadora1
	    private Somador    uniSOMADORA2;    //--unidade somadora2
	    
	    private float fatorCorte;
	    

	    
	    public InstrumentoT2C(float fc)
	    { this(new Ruido(), new Envoltoria(), new Envoltoria(),new Envoltoria(), 
	    	   new Envoltoria(), fc);
	    }

	    
	    public InstrumentoT2C(Ruido ruido_, Envoltoria env_1, Envoltoria env_2,
	    		              Envoltoria env_3, Envoltoria env_4, float fc_)
	    {
	        super();        
	        fatorCorte = fc_; 
	        
	        this.geradorRUIDO    = ruido_;
	        this.envAMPLITUDE    = env_1;
	        this.envCONSTANTE    = env_2;
	        this.envRUIDO		 = env_3;
	        this.envOSCILADOR	 = env_4;
	        		
	        this.oscSENOIDALi = new Oscilador();
	        
	        this.uniSOMADORA1 = new Somador(envCONSTANTE, geradorRUIDO);
	        this.uniSOMADORA2 = new Somador(uniSOMADORA1, oscSENOIDALi);
	        
	        this.oscSENOIDALf = new Oscilador();
	        this.setRelogio(0);
	    }
	   
	   
	    public void relogio() 
	    { oscSENOIDALf.relogio();
	    }
	   
	   
	    public void setRelogio(long n)
	    { 
	      envAMPLITUDE.setRelogio(n);
	      envCONSTANTE.setRelogio(n);
	      envRUIDO.setRelogio(n);
	      envOSCILADOR.setRelogio(n);
	      oscSENOIDALi.setRelogio(n);
	      oscSENOIDALf.setRelogio(n);
	      geradorRUIDO.setRelogio(n);
	      uniSOMADORA1.setRelogio(n);
	      uniSOMADORA2.setRelogio(n);
	      this.saida = oscSENOIDALf.getSaida()*((canal) ? ummenoslambda : lambda);
	      canal = !canal;
	      reset();
	    }
	        

	    public float getSaida()
	    {         
	      this.saida = oscSENOIDALf.getSaida()*((canal) ? ummenoslambda : lambda);
	      canal      = !canal;
	      return ganho*this.saida;
	    }
	    
	    
	    public void reset() 
	    {        
	        envAMPLITUDE.setDuracao(duracao);
	        envAMPLITUDE.reset();
	        
	        envCONSTANTE.setDuracao(duracao);
	        envCONSTANTE.reset();
	        
	        envOSCILADOR.setDuracao(duracao);
	        envOSCILADOR.reset();
	        
	        oscSENOIDALi.setDispositivoAmplitude(envOSCILADOR);
	        oscSENOIDALi.setFrequencia(frequencia);
	        oscSENOIDALi.setFase(fase);
	        oscSENOIDALi.setDuracao(duracao);
	        oscSENOIDALi.reset();   

	        geradorRUIDO.setDispositivoAmplitude(envRUIDO);
	        geradorRUIDO.setFrequencia((float)frequencia*fatorCorte);
	        geradorRUIDO.setFase(fase);
	        geradorRUIDO.setDuracao(duracao);
	        geradorRUIDO.reset();
	                
	        uniSOMADORA1 = null;
	        uniSOMADORA1 = new Somador(envCONSTANTE, geradorRUIDO);
	        uniSOMADORA1.setDuracao(duracao);
	        uniSOMADORA1.reset();
	        
	        uniSOMADORA2 = null;
	        uniSOMADORA2 = new Somador(uniSOMADORA1, oscSENOIDALi);
	        uniSOMADORA2.setDuracao(duracao);
	        uniSOMADORA2.reset();
	        
	        oscSENOIDALf.setDispositivoAmplitude(envAMPLITUDE);
	        oscSENOIDALf.setDispositivoFrequencia(uniSOMADORA2);
	        oscSENOIDALf.setFase(fase);
	        oscSENOIDALf.setDuracao(duracao);
	        oscSENOIDALf.reset();                
	    }



	    public void setGanho(float g)
	    {this.ganho = g;
	     
	    }

	    public void setDuracao(float d)
	    {   this.duracao = d;
	      	envAMPLITUDE.setDuracao(d);
	      	envCONSTANTE.setDuracao(d);
	      	envRUIDO.setDuracao(d);
	      	envOSCILADOR.setDuracao(d);
	      	oscSENOIDALi.setDuracao(d);
	      	oscSENOIDALf.setDuracao(d);
	      	geradorRUIDO.setDuracao(d);
	      	uniSOMADORA1.setDuracao(d);
	      	uniSOMADORA2.setDuracao(d);
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

	    public void setEnvoltoria(Envoltoria env_1, Envoltoria env_2, 
	    						  Envoltoria env_3, Envoltoria env_4)
	    { this.envAMPLITUDE = env_1;
	      this.envCONSTANTE = env_2;
	      this.envRUIDO		= env_3;
	      this.envOSCILADOR = env_4;
	      reset();
	    }

	    public void setFase(float fase)
	    { this.fase = fase;
	      reset();
	    }
}
