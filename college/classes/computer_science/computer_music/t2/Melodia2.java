import sintese.*;

public class Melodia2{
	public Melodia2(){
	}

	public static Melodia prepara(Dispositivo inst){
		float f1 = 440;
		float f2 = 659;
		float f3 = 1109;
		float f4 = 988;
		float f5 = 880;
		float f6 = 831;
		float f7 = 415;
		float f8 = 494;
		float f9 = 740;
		float f10 = 370;
		float f11 = 554;
		float f12 = 277;
		float f13 = 523;


	    Nota n1 = new Nota(0.25f, f1, 30);
	    Nota n2 = new Nota(0.25f, f2, 30);
	    Nota n3 = new Nota(0.25f, f3, 30);
	    Nota n4 = new Nota(0.25f, f4, 30);
	    Nota n5 = new Nota(0.25f, f5, 30);
	    Nota n6 = new Nota(0.25f, f6, 30);
	    Nota n7 = new Nota(0.25f, f7, 30);
	    Nota n8 = new Nota(0.25f, f8, 30);
	    Nota n9 = new Nota(0.25f, f9, 30);
	    Nota n10 = new Nota(0.25f, f10, 30);
	    Nota n11 = new Nota(0.25f, f11, 30);
	    Nota n12 = new Nota(0.25f, f12, 30);
	    Nota n13 = new Nota(0.25f, f13, 12);


	    Melodia mel = new Melodia();
	    mel.addNota(n1);
	    mel.addNota(n2);
	    mel.addNota(n3);
	    mel.addNota(n2);
	    mel.addNota(n1);
	    mel.addNota(n2);
	    mel.addNota(n4);
	    mel.addNota(n2);
	    mel.addNota(n1);
	    mel.addNota(n2);
	    mel.addNota(n5);
	    mel.addNota(n2);
	    mel.addNota(n1);
	    mel.addNota(n2);
	    mel.addNota(n6);
	    mel.addNota(n2);
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
	    mel.addNota(n10);
	    mel.addNota(n11);
	    mel.addNota(n5);
	    mel.addNota(n11);
	    mel.addNota(n10);
	    mel.addNota(n11);
	    mel.addNota(n6);
	    mel.addNota(n11);
	    mel.addNota(n10);
	    mel.addNota(n11);
	    mel.addNota(n9);
	    mel.addNota(n11);
	    mel.addNota(n10);
	    mel.addNota(n11);
	    mel.addNota(n2);
	    mel.addNota(n11);
	    mel.addNota(n12);
	    mel.addNota(n7);
	    mel.addNota(n11);
	    mel.addNota(n7);
	    mel.addNota(n12);
	    mel.addNota(n7);
	    mel.addNota(n13);
	    mel.addNota(n7);
	    mel.addNota(n12);
	    mel.addNota(n7);
	    mel.addNota(n11);
	    mel.addNota(n7);
	    mel.addNota(n12);
	    mel.addNota(n7);
	    mel.addNota(n11);
	    mel.addNota(n7);
	    

	    //mel.append(mel);
	    //mel.append(mel);
	    
	    mel.setNome("Seemann");
	    mel.setAutor("Rammstein");
	    
	    return mel;
	}
}
