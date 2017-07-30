import sintese.*;

public class Melodia3 extends Melodia {
	public Melodia3(){
	}

	public static Melodia prepara(Dispositivo inst){
		float f1 = 1175;
		float f2 = 1760;
		float f3 = 2349;
		float f4 = 1397;
		float f5 = 2093;
		float f6 = 2794;
		float f7 = 1047;
		float f8 = 1568;
		float f9 = 784;
		float f10 = 1175;
		float f11 = 294;
		float f12 = 440;
		float f13 = 587;
		float f14 = 466;
		float f15 = 698;
		float f16 = 932;
		float f17 = 523;
		float f18 = 784;
		float f19 = 1046;
		float f20 = 392;
		float f21 = 587;
		float f22 = 784;



	    Nota n1 = new Nota(0.375f, f1/4, 30);
	    Nota n2 = new Nota(0.375f, f2/4, 30);
	    Nota n3 = new Nota(0.375f, f3/4, 30);
	    Nota n4 = new Nota(0.375f, f4/4, 30);
	    Nota n5 = new Nota(0.375f, f5/4, 30);
	    Nota n6 = new Nota(0.375f, f6/4, 30);
	    Nota n7 = new Nota(0.375f, f7/4, 30);
	    Nota n8 = new Nota(0.375f, f8/4, 30);
	    Nota n9 = new Nota(0.375f, f9/4, 30);
	    Nota n10 = new Nota(0.375f, f10/4, 30);
	    Nota n11 = new Nota(0.375f, f11/2, 30);
	    Nota n12= new Nota(0.375f, f12/2, 30);
	    Nota n13= new Nota(0.375f, f13/2, 30);
	    Nota n14= new Nota(0.375f, f14/2, 30);
	    Nota n15= new Nota(0.375f, f15/2, 30);
	    Nota n16 = new Nota(0.375f, f16/2, 30);
	    Nota n17 = new Nota(0.375f, f17/2, 30);
	    Nota n18= new Nota(0.375f, f18/2, 30);
	    Nota n19= new Nota(0.375f, f19/2, 30);
	    Nota n20= new Nota(0.375f, f20/2, 30);
	    Nota n21= new Nota(0.375f, f21/2, 30);
	    Nota n22 = new Nota(0.375f, f22/2, 30);



	    Melodia mel = new Melodia();
	    mel.addNota(n1);
	    mel.addNota(n2);
	    mel.addNota(n3);
	    mel.addNota(n2);
	    
	    mel.addNota(n4);
	    mel.addNota(n5);
	    mel.addNota(n6);
	    mel.addNota(n5);
	    
	    mel.addNota(n7);
	    mel.addNota(n8);
	    mel.addNota(n5);
	    mel.addNota(n8);
	    
	    mel.addNota(n9);
	    mel.addNota(n10);
	    mel.addNota(n8);
	    mel.addNota(n10);
	    
	    mel.addNota(n11);
	    mel.addNota(n12);
	    mel.addNota(n13);
	    mel.addNota(n12);
	    
	    mel.addNota(n14);
	    mel.addNota(n15);
	    mel.addNota(n16);
	    mel.addNota(n15);
	    
	    mel.addNota(n17);
	    mel.addNota(n18);
	    mel.addNota(n19);
	    mel.addNota(n18);
	    
	    mel.addNota(n20);
	    mel.addNota(n21);
	    mel.addNota(n22);
	    mel.addNota(n21);
	    
	    mel.append(mel);
	    
	    
	    mel.setNome("Blue");
	    mel.setAutor("The Birthday Massacre");
	    
	    return mel;
	}
}
