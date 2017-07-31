#include <iostream>
#include "../common/unBoard.hpp"
#include "../common/motionData.hpp"

int main(){
	motionData aux;
	unBoard<motionData> teste;

	aux.x_vel = 0;
	aux.y_vel = 0;
	aux.theta = 0;
	aux.turn_time = 0;

	while(true){
		std::cin >> aux.x_vel;
		teste.save(aux);
	}

	//int lol = teste.load();

	//std::cout << lol << std::endl;
  return 0;
}
