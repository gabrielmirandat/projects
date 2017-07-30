*cvMahalanobis(Mahalanobis) = Uma medida de dist�ncia que verifica a elasticidade do espa�o dos dados.

*cvKMeans2(K-m�dias) = Um algoritmo de agrupamento n�o supervisionado.

*cvNormalBayesClassifier(Classificador Bayesiano) = Um classificador que assume que as caracter�sticas s�o Gaussianas e estatisticamente independentes.

*cvDTree(�rvore de Decis�o) = Um classificador discriminativo.

*cvBoost(Boosting) = Um classificador de grupo discriminativo. A classifica��o geral depende da combina��o de pesos dada a cada classificador.

*cvRTrees(�rvores Rand�micas)= Um conjunto de �rvores de decis�o combinadas.

*cvHaarDetectObjects(Classificador Haar) = Um classificador baseado em boosting.

*(Maximiza��o esperada) = Um agrupador n�o supervisionado baseado na t�cnica generativa.

*(K-vizinhos) = O classificador discriminativo mais simples poss�vel.

*(Redes Neurais) = Baseado nos perceptrons de multiplas camadas.

*(Support Vector Machine) = Um classificador discriminativo capaz de fazer regress�es.

obs>>filtros Kalman e filtros de part�culas.(Rastreamento-reconhecer padrao)

*(meanshift e camshift) = realizar rastreamento de objetos em frames.

*cvGoodFeaturesToTrack(derivadas de 2ordem e Sobel) = retorna um array de localiza��es de pixels onde se espera encontrar outra imagem similar.
Al�m do reconhecimento de objetos em sequ�ncia, esta t�cnica pode ser aplicada para relacionar imagens capturadas sob diferentes
pontos de vista, entre outras aplica��es.

*cvFindCornerSubpix(Subpixel Corners) = tem como um dos argumentos de entrada as localiza��es inteiras dos pixels obtidas com a fun��o 
cvGoodFeaturesToTrack. Al�m disso, a busca por subpixels � iterativa e o crit�rio de parada � estabelecido pelo usu�rio 
atrav�s de uma das fun��es do OpenCV.

*cvCalcOpticalFlowLK(Lucas-Kanade) = Optical Flow(identifica��o de movimento em frames) esparso, ou seja,com conhecimento pr�vio
sobre os pontos que se deseja rastrear, como por exemplo os corners descritos nas se��es anteriores.

*cvCalcOpticalFlowPyrLK(Lucas Kanade Piramidal ) = Optical Flow Esparso.

*cvCalcOpticalFLowHS(Horn-Shunk) = Optical Flow Denso.Os algoritmos densos, por sua vez, associam um vetor de velocidade ou de
deslocamento a cada pixel na imagem, sendo, portanto desnecess�rio o conhecimento pr�vio de pontos espec�ficos da imagem. 

*cvCalcOpticalFlowBM(Block Matching) = Optical Flow Denso.

*cvCamShift(Camshift) = Para cada frame, a imagem (raw) � convertida para outra de distribui��o de probabilidade de cor
atrav�s de um modelo de histograma da cor da pele. O centro e o tamanho da face que se quer rastrear s�o encontrados atrav�s
do CamShift operando na imagem de probabilidade de cores. O tamanho e a localiza��o corrente da face s�o informados e usados 
para definir o tamanho e a localiza��o da janela de busca da pr�xima imagem de v�deo.cvCamShift chama o algoritmo CamShift
para buscar o centro, o tamanho e a orienta��o do objeto sendo rastreado.

*cvCreateKalman e cvReleaseKalman(Estimadores com filtro de Kalman): servem para criar e destruir uma estrutura (struct) com os 
dados a serem processados pelo algoritmo.

*cvKalmanPredict: calcula as estimativas para o pr�ximo passo.

*cvKalmanCorrect: corrige as medidas estimadas.




	