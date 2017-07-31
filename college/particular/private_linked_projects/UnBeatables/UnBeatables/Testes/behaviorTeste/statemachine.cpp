// salva posição odometrica inicial
string stateName;
int awayFromCenter = 0;
std::vector<float> initialPosition = ALMotionProxy::getPosition();
std::vector<float> currentPosition;
float headPosition = 0;
while (1)
{
	switch (stateName)
	{
		case "Initial":
			// vai para posição inicial, corrige alinhamento com linha e com centro, salva posição inicial
			ALMotionProxy::setPositions(initialPosition);
			if(!(angle = lineStraight()))
			{
					ALMotionProxy::setPositions(-angle);
			}
			while (awayFromCenter)
			{
				ALMotionProxy::setAngles("HeadYaw", 1.22f, 0.3f); // gira cabeça para 70 graus a 30% da velocidade máxima
				getGoalFrame(0); // frame do gol à direita
				ALMotionProxy::setAngles("HeadYaw", -1.22f, 0.3f); // gira cabeça para -70 graus a 30% da velocidade máxima
				getGoalFrame(1); // frame do gol à esquerda
				if (awayFromCenter = compareGoalFrames()) // compara a quantidade de branco das 2 imagens, se retornar 0, o robô está no centro, caso contrário o valor irá indicar quanto 
				{
					ALMotionProxy::setPositions(awayFromCenter);
				}
				awayFromCenter = 1;
				initialPosition = ALMotionProxy::getPosition();
			}

			stateName = "SearchBall";

		case "SearchBall":
			// tenta achar a bola, move a cabeça de um lado para o outro se precisar
			ballPosition = searchBall();
			if (ballPosition == NULL) 
			{
				turnHead;
			}
			else 
			{
				stateName = "AlignBall";	
			}

		case "AlignBall":
			// alinha a cabeça para frente, move de lado acompanhando a bola e observando os limites da área
			ALMotionProxy::setAngles("HeadYaw", 0.0f, 0.3f);
			ballPosition = searchBall();
			currentPosition = ALMotionProxy::getPosition();
			if(abs(currentPosition[2] - initialPosition[2]) < maxDistanceFromCenter)
			{
				ALMotionProxy::setPositions(ballPosition);
			}
			if (ballPosition.distance <= defendDistance) 
			{
				stateName = "Defend";
			}
			else if (ballPosition == NULL) 
			{
				stateName = "SearchBall";
			}

		case "Defend":
			// abaixa com os braços de lado tocando o chão, aguarda 2 segundos após o movimento
			// movimento de abaixar, acho que deve ser feito com choregraphe
			ballPosition = searchBall();
			if (ballPosition < ballInfinitesimallyClose) stateName = "Kick";
			else stateName = "Initial";

		case "Kick":
			// alinha com a bola e reto com a linha e executa chute
			stateName = "Initial";
		
		default:
			stateName = "Initial";
	}
}