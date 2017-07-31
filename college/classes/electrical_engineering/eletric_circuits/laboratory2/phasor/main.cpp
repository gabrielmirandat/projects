#include "operations.h"

int main()
{
    /*
	Phasor Vf(1.296,0.0); Vf.show("Vf: ");
	Phasor R1(1050.0,0.0); R1.show("R1: ");
	Phasor R2(5050.0,0.0); R2.show("R2: ");
	Phasor L1(2*M_PI*60.0*470*0.000001, 90.0); L1.show("L1: ");
    Phasor L2(2*M_PI*60.0*6, 90.0); L2.show("L2: ");
    //Phasor C(1/(100*0.000000001*2000.0*2*M_PI), -90.0); C.show("capacitor: ");
	//corrente
    Phasor paralelo = divide(multiply(L2,R2), plus(L2,R2)); paralelo.show("paralelo: ");
	Phasor If = divide(Vf, plus(R1, plus(L1,paralelo))); If.show("If: ");
	//potencia dissipada
	Phasor Zlinha = plus(R1, L1); Zlinha.show("Zlinha: ");
	Phasor Vlinha = multiply(Vf, divide(paralelo, plus(Zlinha, paralelo))); Vlinha.show("Vl: ");
	
	Phasor Pcarga = divide(multiply(R2, L2), plus(R2,L2)); Pcarga.show("Pcarga: ");
	*/
	
	Phasor Vf(1.312,0.0); Vf.show("Vf: ");
	Phasor R1(1050.0,0.0); R1.show("R1: ");
	Phasor R2(5050.0,0.0); R2.show("R2: ");
	Phasor L1(2*M_PI*60.0*470*0.000001, 90.0); L1.show("L1: ");
    Phasor L2(2*M_PI*60.0*6, 90.0); L2.show("L2: ");
    Phasor C(1/(2*M_PI*60.0*2446.58*0.000000001), -90.0); C.show("capacitor: ");
	
	//carga
	Phasor paralelo = divide(multiply(L2,R2), plus(L2,R2));
	Phasor paralelo2 = divide(multiply(paralelo,C), plus(paralelo,C)); paralelo2.show("paralelo2: ");
	Phasor Vcarga = multiply(Vf, divide(paralelo2,plus(R1, plus(L1,paralelo2)))); Vcarga.show("Vcarga: ");
	
	//corrente
	Phasor If = divide(Vf, plus(R1, plus(L1,paralelo2))); If.show("If: ");
	
	//potencia dissipada
	Phasor Zlinha = plus(R1, L1); Zlinha.show("Zlinha: ");
	Phasor Vlinha = multiply(Vf, divide(paralelo2, plus(Zlinha, paralelo2)));
	
	//Phasor Pcarga = divide(multiply(R2, L2), plus(R2,L2)); Pcarga.show("Pcarga: ");
	
    return 1;
}