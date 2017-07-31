//corrige fp
//g++ corrige_fp.cpp operations.cpp -o corrige_fp
#include "operations.h"

int main()
{
	//angulo 65.8719
	//Caso 1 - 0.000123558 e 1.296		743,065n
	//Caso 2 - 0.000123558 e 1.00146	1244,43n
	//Caso 3 - 0.000190804 e 1.296		1147,48n
	//Caso 4 - 0.000190804 e 1.00146	1921,7n
	//angulo 42.58
	//Caso 5 - 0.000123558 e 1.296		230,379n	
	//Caso 6 - 0.000123558 e 1.00146	385,82n
	//Caso 7 - 0.000190804 e 1.296		355,761n
	//Caso 8 - 0.000190804 e 1.00146	595,802n
	//Caso 9 - 0.000242919
	
	Phasor Vf(1.21,0.0); Vf.show("Vf: ");	//1.312
	Phasor R1(1050.0,0.0); R1.show("R1: ");
	Phasor R2(5050.0,0.0); R2.show("R2: ");
	Phasor L1(2*M_PI*60.0*470*0.000001, 90.0); L1.show("L1: ");
    Phasor L2(2*M_PI*60.0*6, 90.0); L2.show("L2: ");
    
	double P_old = 0.000099280;	//0.000103919
	double Theta_old = 65.8719;	//43.2
	double Theta_new = 18.19;
	
	double Q_old = P_old * tan(Theta_old * M_PI/180.0); std::cout<< "Q_old:" << Q_old <<std::endl;
	double Q_new = P_old * tan(Theta_new * M_PI/180.0); std::cout<< "Q_new:" << Q_new <<std::endl;
	double Vrms = (1.00146/sqrt(2.0));	std::cout<< "Vrms:" << Vrms <<std::endl;
	
	double numerator = Q_old - Q_new;
	double denominator = 120*M_PI*(Vrms)*(Vrms);
	double Cap = (numerator/denominator); std::cout << "Capacitor= " << Cap << std::endl;
	Phasor C(1/(2*M_PI*60.0*Cap), -90.0); C.show("capacitor: ");
	
	//verifica se o fator de potencia foi corrigido
	Phasor paralelo = divide(multiply(L2,R2), plus(L2,R2));
	Phasor paralelo2 = divide(multiply(paralelo,C), plus(paralelo,C)); paralelo2.show("paralelo2: ");
	Phasor Vcarga = multiply(Vf, divide(paralelo2,plus(R1, plus(L1,paralelo2)))); Vcarga.show("Vcarga: ");
	Phasor If = divide(Vf, plus(R1, plus(L1,paralelo2))); If.show("If: ");
		
	double Theta_final = Vcarga.getAngle() - If.getAngle(); std::cout << "Theta_final= " << Theta_final << std::endl;
	double fp_corrigido = cos(Theta_final * M_PI/180.0); std::cout << "fp_corrigido= " << fp_corrigido << std::endl;
	
	return 1;

}