*cvMahalanobis(Mahalanobis) = Uma medida de distância que verifica a elasticidade do espaço dos dados.

*cvKMeans2(K-médias) = Um algoritmo de agrupamento não supervisionado.

*cvNormalBayesClassifier(Classificador Bayesiano) = Um classificador que assume que as características são Gaussianas e estatisticamente independentes.

*cvDTree(Árvore de Decisão) = Um classificador discriminativo.

*cvBoost(Boosting) = Um classificador de grupo discriminativo. A classificação geral depende da combinação de pesos dada a cada classificador.

*cvRTrees(Árvores Randômicas)= Um conjunto de árvores de decisão combinadas.

*cvHaarDetectObjects(Classificador Haar) = Um classificador baseado em boosting.

*(Maximização esperada) = Um agrupador não supervisionado baseado na técnica generativa.

*(K-vizinhos) = O classificador discriminativo mais simples possível.

*(Redes Neurais) = Baseado nos perceptrons de multiplas camadas.

*(Support Vector Machine) = Um classificador discriminativo capaz de fazer regressões.

obs>>filtros Kalman e filtros de partículas.(Rastreamento-reconhecer padrao)

*(meanshift e camshift) = realizar rastreamento de objetos em frames.

*cvGoodFeaturesToTrack(derivadas de 2ordem e Sobel) = retorna um array de localizações de pixels onde se espera encontrar outra imagem similar.
Além do reconhecimento de objetos em sequência, esta técnica pode ser aplicada para relacionar imagens capturadas sob diferentes
pontos de vista, entre outras aplicações.

*cvFindCornerSubpix(Subpixel Corners) = tem como um dos argumentos de entrada as localizações inteiras dos pixels obtidas com a função 
cvGoodFeaturesToTrack. Além disso, a busca por subpixels é iterativa e o critério de parada é estabelecido pelo usuário 
através de uma das funções do OpenCV.

*cvCalcOpticalFlowLK(Lucas-Kanade) = Optical Flow(identificação de movimento em frames) esparso, ou seja,com conhecimento prévio
sobre os pontos que se deseja rastrear, como por exemplo os corners descritos nas seções anteriores.

*cvCalcOpticalFlowPyrLK(Lucas Kanade Piramidal ) = Optical Flow Esparso.

*cvCalcOpticalFLowHS(Horn-Shunk) = Optical Flow Denso.Os algoritmos densos, por sua vez, associam um vetor de velocidade ou de
deslocamento a cada pixel na imagem, sendo, portanto desnecessário o conhecimento prévio de pontos específicos da imagem. 

*cvCalcOpticalFlowBM(Block Matching) = Optical Flow Denso.

*cvCamShift(Camshift) = Para cada frame, a imagem (raw) é convertida para outra de distribuição de probabilidade de cor
através de um modelo de histograma da cor da pele. O centro e o tamanho da face que se quer rastrear são encontrados através
do CamShift operando na imagem de probabilidade de cores. O tamanho e a localização corrente da face são informados e usados 
para definir o tamanho e a localização da janela de busca da próxima imagem de vídeo.cvCamShift chama o algoritmo CamShift
para buscar o centro, o tamanho e a orientação do objeto sendo rastreado.

*cvCreateKalman e cvReleaseKalman(Estimadores com filtro de Kalman): servem para criar e destruir uma estrutura (struct) com os 
dados a serem processados pelo algoritmo.

*cvKalmanPredict: calcula as estimativas para o próximo passo.

*cvKalmanCorrect: corrige as medidas estimadas.




	