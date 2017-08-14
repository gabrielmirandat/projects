import sintese.*;

public class Melodia1{
	public Melodia1(){
	}

	public static Melodia prepara(Dispositivo inst){
		float f1 = 294;
	    float f2 = 440;
	    float f3 = 698;
	    float f4 = 349;
	    float f5 = 523;
	    float f6 = 659;
	    float f7 = 330;
	    float f8 = 494;
	    float f9 = 784;
	    float f10 = 1046;
	    float f11 = 988;
	    float f12 = 587;

	    Nota n1 = new Nota(0.25f, f1, 12);
	    Nota n2 = new Nota(0.25f, f2, 12);
	    Nota n3 = new Nota(0.25f, f3, 12);
	    Nota n4 = new Nota(0.25f, f4, 12);
	    Nota n5 = new Nota(0.25f, f5, 12);
	    Nota n6 = new Nota(0.25f, f6, 12);
	    Nota n7 = new Nota(0.25f, f7, 12);
	    Nota n8 = new Nota(0.25f, f8, 12);
	    Nota n9 = new Nota(0.25f, f9, 12);
	    Nota n10 = new Nota(0.25f, f10, 12);
	    Nota n11 = new Nota(0.25f, f11, 12);
	    Nota n12 = new Nota(0.25f, f12, 12);


	    Melodia mel = new Melodia();
	    mel.addNota(n1);
	    mel.addNota(n2);
	    mel.addNota(n3);
	    mel.addNota(n2);
	    mel.addNota(n1);
	    mel.addNota(n2);
	    mel.addNota(n3);
	    mel.addNota(n2);
	    
	    mel.addNota(n4);
	    mel.addNota(n5);
	    mel.addNota(n6);
	    mel.addNota(n5);
	    mel.addNota(n4);
	    mel.addNota(n5);
	    mel.addNota(n6);
	    mel.addNota(n5);
	    
	    mel.addNota(n7);
	    mel.addNota(n8);
	    mel.addNota(n9);
	    mel.addNota(n8);
	    mel.addNota(n7);
	    mel.addNota(n8);
	    mel.addNota(n9);
	    mel.addNota(n8);
	    
	    mel.addNota(n7);
	    mel.addNota(n8);
	    mel.addNota(n6);
	    mel.addNota(n8);
	    mel.addNota(n7);
	    mel.addNota(n8);
	    mel.addNota(n6);
	    mel.addNota(n8);
	    
	    //mel.append(mel);
	    
	    mel.addNota(n4);
	    mel.addNota(n5);
	    mel.addNota(n3);
	    mel.addNota(n5);
	    mel.addNota(n4);
	    mel.addNota(n5);
	    mel.addNota(n3);
	    mel.addNota(n5); 
	    
	    mel.addNota(n2);
	    mel.addNota(n6);
	    mel.addNota(n10);
	    mel.addNota(n6);
	    mel.addNota(n2);
	    mel.addNota(n6);
	    mel.addNota(n10);
	    mel.addNota(n6); 
	    
	    mel.addNota(n7);
	    mel.addNota(n8);
	    mel.addNota(n11);
	    mel.addNota(n8);
	    mel.addNota(n7);
	    mel.addNota(n8);
	    mel.addNota(n11);
	    mel.addNota(n8); 
	    
	    mel.addNota(n7);
	    mel.addNota(n8);
	    mel.addNota(n6);
	    mel.addNota(n8);
	    mel.addNota(n7);
	    mel.addNota(n8);
	    mel.addNota(n6);
	    mel.addNota(n8); 
	    
	    mel.addNota(n1);
	    mel.addNota(n2);
	    mel.addNota(n12);
	    mel.addNota(n2);
	    mel.addNota(n1);
	    mel.addNota(n2);
	    mel.addNota(n12);
	    mel.addNota(n2); 
	    
	    mel.addNota(n4);
	    mel.addNota(n5);
	    mel.addNota(n3);
	    mel.addNota(n5);
	    mel.addNota(n4);
	    mel.addNota(n5);
	    mel.addNota(n3);
	    mel.addNota(n5);
	    
	    mel.addNota(n7);
	    mel.addNota(n8);
	    mel.addNota(n6);
	    mel.addNota(n8);
	    mel.addNota(n7);
	    mel.addNota(n8);
	    mel.addNota(n6);
	    mel.addNota(n8);
	    
	    mel.addNota(n7);
	    mel.addNota(n8);
	    mel.addNota(n6);
	    mel.addNota(n8);
	    mel.addNota(n7);
	    mel.addNota(n8);
	    mel.addNota(n6);
	    mel.addNota(n8);
	    
	    //mel.append(mel);
	    
	    mel.setNome("Ein Lied");
	    mel.setAutor("Rammstein");
	    
	    return mel;
	}
}
