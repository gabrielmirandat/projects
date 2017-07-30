#imgproc module. Image Processing
#calib3d module. Camera calibration and 3D reconstruction
#feature2d module. 2D Features framework
#objdetect module. Object Detection
#ml module. Machine Learning
#contrib module. The additional contributions made available !
#OpenCV Viz

#funções

// createTrackbar() - Cria um trackbar e atribui-la para a janela especificada.
    createTrackbar(		TrackbarName,	//nome da trackbar criada.
			      "Linear Blend",	//Nome da janela que vai ser utilizado como um pai da trackbar criado.
			       &alpha_slider,	//Ponteiro opcional a uma variável inteira, cujo valor reflete a posição do controle deslizante.
			    alpha_slider_max,	//Posição máxima do slider. A posição mínima é sempre 0.
				on_trackbar);	//Ponteiro para a função a ser chamada toda vez que a posição mudar no slider. Esta função deve ser um protótipo como 
						//void func(int, void *); , Onde o primeiro parâmetro é a posição trackbar e o segundo parâmetro é o de dados do utilizador.
//video - entrada
    // VideoCapture() - Essencialmente, todas as funcionalidades necessárias para a manipulação de vídeo (webcam ou arquivo offline)
	VideoCapture cap(0); // abre camera padrão
			     // Se esse argumento for um número inteiro, então você vai ligar a classe para uma câmera, um dispositivo. O número passado aqui é o ID do 
			     //dispositivo,atribuída pelo sistema operativo.Se o parâmetro passado é uma string, este vai se referir a um arquivo de vídeo, sendo a seqüência 
			     //de caracteres para o local e o nome do arquivo.
	for(;;){
	  Mat frame;
	  cap >> frame; // geta um novo frame da camera
	}
        
	const string sourceReference = argv[1],sourceCompareWith = argv[2]; //parâmetro para a main
	VideoCapture captRefrnc(sourceReference); //cria objeto da classe VideoCapture via contrutor para inicializá-lo
	// or
	VideoCapture captUndTst;		      //cria objeto da classe VideoCapture via função open()
	captUndTst.open(sourceCompareWith);
    
    // isOpened() - checa se o caminho do vídeo é válido e se foi adequadamente associado ao obejto VideoCapture
	if ( !captRefrnc.isOpened())
	  //..mensagem de erro ..

    // read() - Quadros são obtidos pela função read() ou pelo operador sobrecarregado >>
	Mat frameReference, frameUnderTest;
	captRefrnc >> frameReference;
	captUndTst.read(frameUnderTest);
    
    //empty() - testa se o frame foi preenchido com imagem (não deu problema ou vídeo não acabou)
	if( frameReference.empty()  || frameUnderTest.empty())
	  // sai do programa

    //get() - retorna valores double das propriedades do frame, dependendo da flag usada
	Size refS = Size((int) captRefrnc.get(CV_CAP_PROP_FRAME_WIDTH),(int) captRefrnc.get(CV_CAP_PROP_FRAME_HEIGHT));
	cout << "Reference frame resolution: Width=" << refS.width << "  Height=" << refS.height 
	     << " of nr#: " << captRefrnc.get(CV_CAP_PROP_FRAME_COUNT) << endl;
	 
    //set() - muitas vezes você pode querer controlar esses valores, e mover-se no vídeo.
	captRefrnc.set(CV_CAP_PROP_POS_MSEC, 1.2);  // vai para o segundo 1.2 do vídeo
	captRefrnc.set(CV_CAP_PROP_POS_FRAMES, 10); // vai para o 10º frame do vídeo
	// agora uma operação de read() deve ler o frame na posição setada
//algorítmo PSRN
    double getPSNR(const Mat& I1, const Mat& I2){
	Mat s1;
	absdiff(I1, I2, s1);       // |I1 - I2|
	s1.convertTo(s1, CV_32F);  // cannot make a square on 8 bits
	s1 = s1.mul(s1);           // |I1 - I2|^2
	
	Scalar s = sum(s1);         // sum elements per channel
	
	double sse = s.val[0] + s.val[1] + s.val[2]; // sum channels
	
	if( sse <= 1e-10) // for small values return zero
	    return 0;
	else{
	    double  mse =sse /(double)(I1.channels() * I1.total()); //MSE = erro do quadrado médio		(QUANTO MENOR MELHOR)
	    double psnr = 10.0*log10((255*255)/mse);		    //PSNR = algorítmo Pico de sinal-para-ruído (QUANTO MAIOR MELHOR)
	    return psnr;
	}
    }
//algorítmo SSIM
    Scalar getMSSIM( const Mat& i1, const Mat& i2){
	const double C1 = 6.5025, C2 = 58.5225;
	/***************************** INITS **********************************/
	int d     = CV_32F;
    
	Mat I1, I2;
	i1.convertTo(I1, d);           // cannot calculate on one byte large values
	i2.convertTo(I2, d);
	
	Mat I2_2   = I2.mul(I2);        // I2^2
	Mat I1_2   = I1.mul(I1);        // I1^2
	Mat I1_I2  = I1.mul(I2);        // I1 * I2
	
	/***********************PRELIMINARY COMPUTING ******************************/
    
	Mat mu1, mu2;  
	GaussianBlur(I1, mu1, Size(11, 11), 1.5);
	GaussianBlur(I2, mu2, Size(11, 11), 1.5);
  
	Mat mu1_2   =   mu1.mul(mu1);
	Mat mu2_2   =   mu2.mul(mu2);
	Mat mu1_mu2 =   mu1.mul(mu2);
	
	Mat sigma1_2, sigma2_2, sigma12;
    
	GaussianBlur(I1_2, sigma1_2, Size(11, 11), 1.5);
	sigma1_2 -= mu1_2;
    
	GaussianBlur(I2_2, sigma2_2, Size(11, 11), 1.5);
	sigma2_2 -= mu2_2;
      
	GaussianBlur(I1_I2, sigma12, Size(11, 11), 1.5);
	sigma12 -= mu1_mu2;
    
	///////////////////////////////// FORMULA ////////////////////////////////
	Mat t1, t2, t3;
      
	t1 = 2 * mu1_mu2 + C1;
	t2 = 2 * sigma12 + C2;
	t3 = t1.mul(t2);              // t3 = ((2*mu1_mu2 + C1).*(2*sigma12 + C2))
    
	t1 = mu1_2 + mu2_2 + C1;
	t2 = sigma1_2 + sigma2_2 + C2;
	t1 = t1.mul(t2);               // t1 =((mu1_2 + mu2_2 + C1).*(sigma1_2 + sigma2_2 + C2))
  
	Mat ssim_map;
	divide(t3, t1, ssim_map);      // ssim_map =  t3./t1;
    
	Scalar mssim = mean( ssim_map ); // mssim = average of ssim map
	return mssim;
     }
//video-saída
    //Para o nome da saída, contém o tipo decontainer na extensão da entrada. Neste momento, apenas AVI é suportado. Nós construímos isso a partir do arquivo de entrada, 
    //adicione a isso o nome do canal a ser usado, e termine com a extensão do container.
	const string source      = argv[1];            // the source file name
	string::size_type pAt = source.find_last_of('.');   // Find extension point
	const string NAME = source.substr(0, pAt) + argv[2][0] + ".avi";   // Form the new name with container
    
    //O codec a usar para a trilha de vídeo. Agora, todos os codecs de vídeo têm um nome curto única de no máximo quatro caracteres. Assim, os nomes XVID, DIVX ou H264. 
    //Isso é chamado de um código de quatro caracteres. Você também pode pedir isso a partir de uma entrada de vídeo usando a sua função get.
	VideoCapture inputVideo(source);                                   // Open input
	int ex = static_cast<int>(inputVideo.get(CV_CAP_PROP_FOURCC));     // Get Codec Type- Int form
    
    //OpenCV trabalha internamente com este tipo inteiro e espera isso como seu segundo parâmetro. Agora para converter inteiro para string podemos usar dois métodos: 
    //um operador bit a bit ou um método de união.
	union { int v; char c[5];} uEx ;
	uEx.v = ex;                              // From Int to char via union
	uEx.c[4]='\0';
	
    //open() para criar a saída. Se você quer janela pop-up, na variável "ex" sete-a para -1, caso contrário deixa-a pois representa o codec de saída.
	VideoWriter outputVideo;
	Size S = Size((int) inputVideo.get(CV_CAP_PROP_FRAME_WIDTH),(int) inputVideo.get(CV_CAP_PROP_FRAME_HEIGHT)); //Acquire input size
	outputVideo.open(		NAME ,	//nome do vídeo de saída.
					   ex,	//Código de 4 caracteres do codec usado para compactar os quadros. Por exemplo, CV_FOURCC ('P', 'I', 'M', '1') é um MPEG-1.
	      inputVideo.get(CV_CAP_PROP_FPS),	//Framerate do fluxo de vídeo criado.
					    S,	//tamanho dos frames do vídeo.
		                        true);	//Por padrão é verdadeiro e diz que a saída será um colorido. Para escala de cinza passar um parâmetro false aqui.
	
    //write() Depois de abrir o objeto com sucesso você pode enviar os frames do vídeo em uma ordem seqüencial, utilizando a função write() da classe. Alternativamente, você 
    //pode usar o seu operador sobrecarregado <<
	outputVideo.write(res);  //or
	outputVideo << res;
	
    //Aqui nós fazemos um split, setamos os outros planos de cor para zero, e depois merge() de novo.
	split(src, spl);                 // process - extract only the correct channel
	for( int i =0; i < 3; ++i)
	    if (i != channel)
		spl[i] = Mat::zeros(S, spl[0].type());
	merge(spl, res);
//Entradas de arquivos XML e YAML
    // Abrir e fechar arquivos XML\YAML. A estrutura de dados XMLYAML em OpenCV é FileStorage. Use ou o construtor ou a função open()
	string filename = "I.xml"; //também determina formato de saída
	FileStorage fs(filename, FileStorage::WRITE);
	//...
	fs.open(filename, FileStorage::READ);
    // O arquivo fecha automaticamente quando os objetos FileStorage são destruídos. No entanto, você pode chamar explicitamente para isso usando a função de liberação
	fs.release();                                       // explicit close
    // Entrada e saída de texto e números. As estruturas de dados usam o mesmo operador << de saída da biblioteca STL. 
	//Para saída de qualquer tipo de estrutura de dados precisamos especificar um nome. Para os tipos básicos você pode seguir esta com a impressão do valor.
	fs << "iterationNr" << 100;
	//Lemos por endereçamento([]) e casting ou pelo >>
	int itNr;
	fs["iterationNr"] >> itNr;
	itNr = (int) fs["iterationNr"];
    // Entrada e saída das estruturas de dados OpenCV. 
	Mat R = Mat_<uchar >::eye  (3, 3),
	T = Mat_<double>::zeros(3, 1);

	fs << "R" << R;                                      // Write cv::Mat
	fs << "T" << T;

	fs["R"] >> R;                                      // Read cv::Mat
	fs["T"] >> T;
    // Entrada e saída de vetores e mapas associativos. Como mencionei anteriormente, podemos printar mapas de saída e sequências (array, vetor) também. Mais uma vez, 
    //primeiro imprimir o nome da variável e, em seguida, temos de especificar se a nossa saída é uma seqüência ou mapa.
	// P/ sequências antes do primeiro elemento printe "[" e depois do último printe "]"
	    fs << "strings" << "[";                              // text - string sequence
	    fs << "image1.jpg" << "Awesomeness" << "baboon.jpg";
	    fs << "]";  
	// P/ mapas é o mesmo, mas com "{" e "}"
	    fs << "Mapping";                              // text - mapping
	    fs << "{" << "One" << 1;
	    fs <<        "Two" << 2 << "}";
	// Para ler a partir desses usamos as estruturas de dados filenode e  FileNodeIterator. O operador [] da classe FileStorage retorna um tipo de dados filenode. Se o 
	//nó é sequencial, podemos usar o FileNodeIterator para percorrer os itens:
	    FileNode n = fs["strings"];                         // Read string sequence - Get node
	    if (n.type() != FileNode::SEQ){
	      cerr << "strings is not a sequence! FAIL" << endl;
	      return 1;
	    }
	    
	    FileNodeIterator it = n.begin(), it_end = n.end(); // Go through the node
	    for (; it != it_end; ++it)
	      cout << (string)*it << endl;
	// P/ mapas usamos [] para acessar item (ou o >>)
	    n = fs["Mapping"];                                // Read mappings from a sequence
	    cout << "Two  " << (int)(n["Two"]) << "; ";
	    cout << "One  " << (int)(n["One"]) << endl << endl;
    // Leitura e escrita de suas próprias estruturas de dados. Suponha que tenha uma estrutura de dados assim. É possível serializar isso através da interface de I/O  XML/YAML 
    //OpenCV (tal como no caso das estruturas de dados OpenCV), adicionando uma função de leitura e uma função de escrita dentro e fora de sua classe.	class MyData{
	  public:
	    MyData() : A(0), X(0), id() {}
	  public:   // Data Members
	    int A;
	    double X;
	    string id;
	};
	// leitura e escrita de dentro
	    void write(FileStorage& fs) const {                       //Write serialization for this class
	      fs << "{" << "A" << A << "X" << X << "id" << id << "}";
	    }

	    void read(const FileNode& node) {                          //Read serialization for this class
	      A = (int)node["A"];
	      X = (double)node["X"];
	      id = (string)node["id"];
	    }
	// leitura e escrita de fora
	    void write(FileStorage& fs, const std::string&, const MyData& x){
	      x.write(fs);
	    }
	    
	    void read(const FileNode& node, MyData& x, const MyData& default_value = MyData()){
	      if(node.empty())
		x = default_value;
	      else
		x.read(node);
	    }
	// Use >> p/ escrever e >> p/ ler após declarar estas funções
	    MyData m(1);
	    fs << "MyData" << m;                                // your own data structures
	    fs["MyData"] >> m;                                 // Read your own structure_
	    
	    fs["NonExisting"] >> m;   // Do not add a fs << "NonExisting" << m command for this to work
	    cout << endl << "NonExisting = " << endl << m << endl;
//Calibração de câmera com tabuleiro de xadrez
	// findChessboardCorners() - Detecta um tabuleiro de xadrez numa imagem
	    bool found = findChessboardCorners(		img,	//tabuleiro de entrada. 8-bit grayscale ou colorida.
						  boardSize,	//nº de cantos internos por linha e coluna do tabuleiro. cvSize(colums, rows).
						      ptvec,	//vetor de saída dos contos detectados.
			       CV_CALIB_CB_ADAPTIVE_THRESH);	//flags
	    
	//.. escreve funçãoque gera um array de vector<Point3f> de coordenadas 3D de um tabuleiro em algum sistema de coordenadas. Para simplificar, vamos escolher um 
	//sistema de tal forma que um dos cantos do tabuleiro de xadrez está na origem e a borda está no plano z = 0.

	// Lê parametros da câmera do arquivo XML/YAML
	    FileStorage fs(filename, FileStorage::READ);
	    Mat intrinsics, distortion;
	    fs["camera_matrix"] >> intrinsics;
	    fs["distortion_coefficients"] >> distortion;
	    
	// solvePnP() - Agora estamos prontos para encontrar a representação do tabuleiro de xadrez, executando solvePnP.
	    vector<Point3f> boardPoints;
	    // fill the array...
	    solvePnP(			Mat(boardPoints),	//array de pontos do objeto em seu espaço de coordenadas, 3xN/N/3 1-canal ou 1xN/Nx1 3-canais, N=nº de pontos.
				  Mat(foundBoardCorners),	//array dos pontos correspondentes na imagem, 2xN/Nx2 1-canal ou 1xN/Nx1 2-canais, N=nº de pontos.
					    cameraMatrix,	//matriz de entrada A = [fx 0 cx
											 0 fy cy
											 0  0  1]
					      distCoeffs,	//vetor de entrada dos coeficientes de distorção (k1,k2,p1,p2[,k3[,k4,k5,k6]]) de 4,5 ou 8 elementos.
						    rvec,	//vetor de saída de rotação. Com tvec, traz pontos do model coordinate system ao camera coordinate system.
						    tvec,	//vetor de saída de translação.
						  false);	//se true, usa os valores de rvec e tvec como aproximações inicias dos vetores de rotação e translação.

	//computeReprojectionErrors() - Calcula erros de reprojeção.
// Calibração de câmera com OpenCV
	'1. Lê as definições'
	  Settings s;
	  const string inputSettingsFile = argc > 1 ? argv[1] : "default.xml";
	  FileStorage fs(inputSettingsFile, FileStorage::READ); // Read the settings
	  if (!fs.isOpened()){
	    cout << "Could not open the configuration file: \"" << inputSettingsFile << "\"" << endl;
	    return -1;
	  }
	  fs["Settings"] >> s;
	  fs.release();                                         // close Settings file
	  
	  if (!s.goodInput){
	     cout << "Invalid input detected. Application stopping. " << endl;
	     return -1;
	  }
	  
	'2. Obter próxima entrada, se falhar ou termos o suficiente - calibrar'
	//Após isso, temos uma grande loop onde fazemos as seguintes operações: obter a próxima imagem da lista de imagem, câmera ou arquivo de vídeo. Se isso não funcionar 
	//ou termos imagens suficientes, então corremos o processo de calibração. No caso de imagem nós saímos do loop, caso contrário os frames remanescentes serão distorci-
	//dos (se opção setada) mudando do modo DETECTION para o CALIBRATED.
	  for(int i = 0;;++i){
	    Mat view;
	    bool blinkOutput = false;

	    view = s.nextImage();

	    //-----  If no more image, or got enough, then stop calibration and show result -------------
	    if( mode == CAPTURING && imagePoints.size() >= (unsigned)s.nrFrames ){
	      if( runCalibrationAndSave(s, imageSize,  cameraMatrix, distCoeffs, imagePoints))
		mode = CALIBRATED;
	      else
		mode = DETECTION;
	    }
	    if(view.empty()){         // If no more images then run calibration, save and stop loop.
	      if( imagePoints.size() > 0 )
                  runCalibrationAndSave(s, imageSize,  cameraMatrix, distCoeffs, imagePoints);
	      break;
	    imageSize = view.size();  // Format input image.
	    if( s.flipVertical )    flip( view, view, 0 );	// For some cameras we may need to flip the input image. Here we do this too.
	    }

	 '3. Acha padrão na entrada corrente'
	 //A formação das equações mencionadas acima destina-se a encontrar padrões principais na entrada: No caso do tabuleiro são cantos dos quadrados, e nos círculos, eles
	 //mesmos. A posição deles vai formar o resultado que será escrito no vetor pointBuf. Dependendo do objeto de calibração, usaremos findChessboard() ou findCirclesgrid().
	 //Para ambos você passa a imagem corrente e o tamanho do tablado e você receberá as posições e os padrões. Retorna um boolean se o padrão foi encontrado, só pegamos os
	 //true
	    vector<Point2f> pointBuf;

	    bool found;
	    switch( s.calibrationPattern ){ // Find feature points on the input format
	      case Settings::CHESSBOARD:
		found = findChessboardCorners( view, s.boardSize, pointBuf,
			CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FAST_CHECK | CV_CALIB_CB_NORMALIZE_IMAGE);
		break;
	      case Settings::CIRCLES_GRID:
		found = findCirclesGrid( view, s.boardSize, pointBuf ); //sendo view a grade dos círculos de entrada.
		break;
	      case Settings::ASYMMETRIC_CIRCLES_GRID:
		found = findCirclesGrid( view, s.boardSize, pointBuf, CALIB_CB_ASYMMETRIC_GRID );
		break;
	    }
	 //No caso de cameras, escolhemos apenas as imagens que tiveram delay. Isto é feito para permitir que o usuário movimente o tabuleiro para obter diferentes imagens.
	 //Imagens similares resultam em equações similares, que fará com que a calibração falhe. Para imagens quadradas as posições dos cantos são apenas aproximadas. Conser-
	 //tamos isto através de cornerSubPix(), que produz uma melhor calibração. Após, carregamos entradas válidas no vetor imagePontis para coletar todas as equações num
	 //container único. Por fim, desenhamos os pontos na imagem de entrada com a função drawChessboardCorners().
	    if ( found){                // If done with success,
	      // improve the found corners' coordinate accuracy for chessboard
	      if( s.calibrationPattern == Settings::CHESSBOARD){
		Mat viewGray;
		cvtColor(view, viewGray, CV_BGR2GRAY);
		cornerSubPix( viewGray, pointBuf, Size(11,11),
		    Size(-1,-1), TermCriteria( CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));
	      }
	      if( mode == CAPTURING &&  // For camera only take new samples after delay time
		  (!s.inputCapture.isOpened() || clock() - prevTimestamp > s.delay*1e-3*CLOCKS_PER_SEC) ){
		imagePoints.push_back(pointBuf);
		prevTimestamp = clock();
		blinkOutput = s.inputCapture.isOpened();
	      }
	      // Draw the corners.
	      drawChessboardCorners( view, s.boardSize, Mat(pointBuf), found );
	    }
	  
	 '4. Mostra estado e resultado ao usuário, mais comando de linha da aplicação'
	 //Esta parte mostra a saída de texto na imagem
	    //----------------------------- Output Text ------------------------------------------------
	    string msg = (mode == CAPTURING) ? "100/100" :
	    mode == CALIBRATED ? "Calibrated" : "Press 'g' to start";
	    int baseLine = 0;
	    Size textSize = getTextSize(msg, 1, 1, 1, &baseLine);
	    Point textOrigin(view.cols - 2*textSize.width - 10, view.rows - 2*baseLine - 10);

	    if( mode == CAPTURING ){
	      if(s.showUndistorsed)
		msg = format( "%d/%d Undist", (int)imagePoints.size(), s.nrFrames );
	      else
		msg = format( "%d/%d", (int)imagePoints.size(), s.nrFrames );
	    }
	    
	    putText( view, msg, textOrigin, 1, 1, mode == CALIBRATED ?  GREEN : RED);
	    if( blinkOutput )
	      bitwise_not(view, view);
	 //Se corrermos a calibração e obtermos matriz da câmera com coeficientes de distorção, queremos corrigir a imagem usando undistort()
	    //------------------------- Video capture  output  undistorted ------------------------------
	    if( mode == CALIBRATED && s.showUndistorsed ){
	      Mat temp = view.clone();
	      undistort(temp, view, cameraMatrix, distCoeffs);
	    }
	    //------------------------------ Show image and check for input commands -------------------
	    imshow("Image View", view);
	 //Então esperamos por entrada do usuário, "u" p/ alternarmos a remoção da distorção, "g" p/ recomeçar processo de detecção, "ESC" p/ sair.
	    char key =  waitKey(s.inputCapture.isOpened() ? 50 : s.delay);
	    if( key  == ESC_KEY )
	      break;

	    if( key == 'u' && mode == CALIBRATED )
	      s.showUndistorsed = !s.showUndistorsed;

	    if( s.inputCapture.isOpened() && key == 'g' ){
	      mode = CAPTURING;
	      imagePoints.clear();
	    }
	    
	 '5. Mostra a remoção da distorção da imagem'
	 //Quando você trabalha com uma lista de imagem não é possível remover a distorção dentro do loop. Portanto, você deve fazer isto depois do loop. Expandindo a função
	 //undistort, que é de fato a primeira chamada da função initUndistortRectifyMap para achar as matrizes de transformação e, em seguida, realiza a transformação usando
	 //a função remap. Porque depois de alcançado, o cálculo da calibração do mapa só precisa ser feita uma vez, usando esta forma expandida você pode tornar o processo 
	 //mais rápido.
	    if( s.inputType == Settings::IMAGE_LIST && s.showUndistorsed ){
	      Mat view, rview, map1, map2;
	      initUndistortRectifyMap(cameraMatrix, distCoeffs, Mat(),
		    getOptimalNewCameraMatrix(cameraMatrix, distCoeffs, imageSize, 1, imageSize, 0),
		    imageSize, CV_16SC2, map1, map2);

	      for(int i = 0; i < (int)s.imageList.size(); i++ ){
		view = imread(s.imageList[i], 1);
		if(view.empty())
		  continue;
		remap(view, rview, map1, map2, INTER_LINEAR);
		imshow("Image View", rview);
		char c = waitKey();
		if( c  == ESC_KEY || c == 'q' || c == 'Q' )
		  break;
	       }
	     }
	     
	 'Calibração e salvar'
	 //Como a calibração só precisa ser feita uma vez por câmera, faz sentido salvar o resultado se tudo der certo. Assim é só carregar estes valores ao seu programa.
	 //Então primeiro calibramos, e se der certo, salvamos o resultado num arquivo XML ou YAML dependendo do tipo da entrada.
	    bool runCalibrationAndSave(Settings& s, Size imageSize, Mat&  cameraMatrix, Mat& distCoeffs,vector<vector<Point2f> > imagePoints ){
	      vector<Mat> rvecs, tvecs;
	      vector<float> reprojErrs;
	      double totalAvgErr = 0;
    
	      bool ok = runCalibration(s,imageSize, cameraMatrix, distCoeffs, imagePoints, rvecs, tvecs,
									  reprojErrs, totalAvgErr);
	      cout << (ok ? "Calibration succeeded" : "Calibration failed")<< ". avg re projection error = "  << totalAvgErr ;

	      if( ok )   // save only if the calibration was done with success
		saveCameraParams( s, imageSize, cameraMatrix, distCoeffs, rvecs ,tvecs, reprojErrs,
			      imagePoints, totalAvgErr);
	      return ok;
	    }
	//Fazemos a calibração com a função calibrateCamera. Tem os seguintes parâmetros:
	    'pontos do objeto'. /*Vetor Point3f que p/ cada imagem de entrada descreve como o padrão deve parecer. Se temos um padrão planar (como tabuleiro) podemos apenas
	    setar todas as coordenadas em Z para zero. Porque, nós usamos um padrão único para todas as imagens de entrada, podemos calcular isso apenas uma vez e 
	    multiplicá-lo por todos os outros pontos de vista de entrada.*/
	    //Calculamos os pontos dos cantos com calcBoardCornerPositions
	      void calcBoardCornerPositions(Size boardSize, float squareSize, vector<Point3f>& corners,Settings::Pattern patternType /*= Settings::CHESSBOARD*/){
		corners.clear();

		switch(patternType){
		  case Settings::CHESSBOARD:
		  case Settings::CIRCLES_GRID:
		    for( int i = 0; i < boardSize.height; ++i )
		      for( int j = 0; j < boardSize.width; ++j )
			corners.push_back(Point3f(float( j*squareSize ), float( i*squareSize ), 0));
		    break;
		  case Settings::ASYMMETRIC_CIRCLES_GRID:
		    for( int i = 0; i < boardSize.height; i++ )
		      for( int j = 0; j < boardSize.width; j++ )
			corners.push_back(Point3f(float((2*j + i % 2)*squareSize), float(i*squareSize), 0));
		    break;	
		 }
	      }
	    //E multiplicamos isto por:
	      vector<vector<Point3f> > objectPoints(1);
	      calcBoardCornerPositions(s.boardSize, s.squareSize, objectPoints[0], s.calibrationPattern);
	      objectPoints.resize(imagePoints.size(),objectPoints[0]);
	    
	      'pontos da imagem'. /*vetor de Point2f que para cada input de imagem contém coordenadas de pontos importantes. Cantos de tabuleiro e centros dos círculos para o
				    padrão do círculo). Nós já coletamos isto em findChessboardCorners ou findCirclesGrid.*/
				    
	      'Tamanho da imagem obtida da câmera, vídeo ou imagens'
	      
	      'A matriz câmera' //Se setamos a razão de aspecto para ser fixa precisamos setar fx para zero
		cameraMatrix = Mat::eye(3, 3, CV_64F);
		if( s.flag & CV_CALIB_FIX_ASPECT_RATIO )
		  cameraMatrix.at<double>(0,0) = 1.0;
	  
	      'Coeficiente de distorção da matriz. inicialize com zero'
		distCoeffs = Mat::zeros(8, 1, CV_64F);
		
	      'Para todos os pontos de vista a função irá calcular os vetores de translação e rotação que transformam os pontos de objeto (dado pelo espaço de coordenadas do
		'modelo) para pontos da imagem (dado pelo espaço de coordenadas do mundo). O sétimo e oitavo parâmetros o vetor de saída das matrizes contendo a i-ésima posi-
		'ção dos vetores de rotação e translação para o i-ésimo ponto do objeto do i-ésimo ponto da imagem.
		
	      'O argumento final é a flag' /* Você precisa especificar aqui opções como fixar a razão de aspecto para o tamanho focal, assumindo distorção tangencial zero ou
	      para fixar o ponto principal */
		double rms = calibrateCamera(objectPoints, imagePoints, imageSize, cameraMatrix,
                            distCoeffs, rvecs, tvecs, s.flag|CV_CALIB_FIX_K4|CV_CALIB_FIX_K5);
	
	      // A função retorna a média do erro de reprojeção. Este número da uma boa estimação da precisão dos parâmetros encontrados. Devem ser os mais próximos de zero
	      // possível.  Dado o intrínseco, distorção, rotação e matrizes de translação, podemos calcular o erro de um ponto de vista, utilizando o projectPoints para 
	      //primeiro transformar o ponto do objeto para o ponto de imagem.Em seguida, calcula-se a norma absoluta entre o que temos com a nossa transformação e o 
	      //algoritmo de descoberta de canto / círculo. Para encontrar o erro médio calcula-se a média aritmética dos erros calculados para todas as imagens de calibração.
		double computeReprojectionErrors( const vector<vector<Point3f> >& objectPoints,
                          const vector<vector<Point2f> >& imagePoints,
                          const vector<Mat>& rvecs, const vector<Mat>& tvecs,
                          const Mat& cameraMatrix , const Mat& distCoeffs,
                          vector<float>& perViewErrors){
		  vector<Point2f> imagePoints2;
		  int i, totalPoints = 0;
		  double totalErr = 0, err;
		  perViewErrors.resize(objectPoints.size());

		  for( i = 0; i < (int)objectPoints.size(); ++i ){
		    projectPoints( Mat(objectPoints[i]), rvecs[i], tvecs[i], cameraMatrix,  // project
					distCoeffs, imagePoints2);
		    err = norm(Mat(imagePoints[i]), Mat(imagePoints2), CV_L2);              // difference

		    int n = (int)objectPoints[i].size();
		    perViewErrors[i] = (float) std::sqrt(err*err/n);                        // save for this view
		    totalErr        += err*err;                                             // sum it up
		    totalPoints     += n;
		  }

		  return std::sqrt(totalErr/totalPoints);              // calculate the arithmetical mean
		}
// cornerHarris() - detectar cantos com método de Harris
    cornerHarris(	src_gray,	//entrada 8-bit grayscale ou  float
			     dst,	//Imagem para armazenar as respostas do detector de Harris. Tem o tipo CV_32FC1 e o mesmo tamanho que src.
		       blockSize,	//tamanho da vizinhança.
		    apertureSize,	//Parâmetro de abertura para o operador de Sobel().
			       k,	//Parâmetro livre do detector de Harry. Vide fórmula.
		 BORDER_DEFAULT);	//Método de extrapolação do pixel.
    //.. normaliza ..
    //.. cria círculos em volta dos pontos.
// goodFeaturesToTrack() - detectar cantos com método de Shi-Tomasi
    goodFeaturesToTrack(	src_gray,	//entrada 8-bit ou float 32-bit, 1-canal.
				 corners,	//vetor de saída dos cantos detectados. vector<Point2f>
			      maxCorners,	//nº máximo de cantos a ser retornado. Se houver mais do que os cantos são encontrados, o mais forte deles é devolvido.
			    qualityLevel,	//parâmetro caracterizando a qualidade mínima aceira dos cantos da imagem. Multiplicado pelo canto de maior qualidade medida.
			     minDistance,	//distância euclidiana mínima entre os cantos retornados.
				   Mat(),	//região opcional de interesse.
			       blockSize,	//tamanho do bloco médio para calcular a co-variação da derivada da matriz em cada vizinha da vizinhaça.
		       useHarrisDetector,	//parâmetro se usa ou não detector de Harris.
				      k);	//parâmetro livre de Harris.
    //.. cria círculos em volta dos pontos.
// Criando nosso próprio detector de bordas.
    //Usando cornerEigenValsAndVecs() para achar os autovalores e os autovetores para determinar se um pixel é um canto.
    //Usando cornerMinEigenVal() para encontrar os menores autovalores para a detecção dos cantos.
    //Para implementar a nossa própria versão do detector de Harris, bem como o detector de Shi-Tomasi, usando as duas funções acima.
    
    /// My Harris matrix -- Using cornerEigenValsAndVecs
    cornerEigenValsAndVecs(	src_gray,	//entrada 8-bit ou float 32-bit, 1-canal.
			    myHarris_dst,	//Imagem para armazenar as respostas do detector de Harris. Tem o tipo CV_32FC1 e o mesmo tamanho que src.
			       blockSize,	//tamanho da vizinhança.
			    apertureSize,	//Parâmetro de abertura para o operador de Sobel().
			 BORDER_DEFAULT);	//Método de extrapolação do pixel.

    /* calculate Mc */
    for( int j = 0; j < src_gray.rows; j++ ){ 
      for( int i = 0; i < src_gray.cols; i++ ){
            float lambda_1 = myHarris_dst.at<Vec6f>(j, i)[0];
            float lambda_2 = myHarris_dst.at<Vec6f>(j, i)[1];
            Mc.at<float>(j,i) = lambda_1*lambda_2 - 0.04f*pow( ( lambda_1 + lambda_2 ), 2 );
      }
    }
    minMaxLoc( Mc, &myHarris_minVal, &myHarris_maxVal, 0, 0, Mat() );
    
    /// My Shi-Tomasi -- Using cornerMinEigenVal
    cornerMinEigenVal( src_gray, myShiTomasi_dst, blockSize, apertureSize, BORDER_DEFAULT );

    minMaxLoc( myShiTomasi_dst, &myShiTomasi_minVal, &myShiTomasi_maxVal, 0, 0, Mat() );

    //.. círcula resultados..
// cornerSubPix() - usado para encontrar as posições mais exatas (mais exata do que pixels inteiros)
    //.. aplica detecção de cantos com goodFeaturesToTrack() e mostra os círculos na tela.
    
    //A classe que define critérios de terminação para os algoritmos iterativos. Você pode inicializar pelo construtor padrão e, em seguida, substituir quaisquer parâmetros, 
    //ou a estrutura pode ser totalmente inicializado usando a variante avançada do construtor.
      TermCriteria criteria = TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER,	//O tipo de critérios de terminação:TermCriteria::COUNT, TermCriteria::EPS ou um + outro.
								      40,	//maxCount: O número máximo de iterações ou elementos para calcular.
								   0.001);	//epsilon: A precisão desejada ou alterações nos parâmetros em que o algoritmo iterativo pára.

    
    //Calcula os locais de canto refinados e escreve no terminal
      cornerSubPix(		src_gray,	//imagem_entrada
				 corners,	//Coordenadas iniciais dos cantos de entrada e coordenadas refinados previstas na saída.
				 winSize,	//winSize: Metade do tamanho do lado da janela de pesquisa. Se winSize=Size(5,5), então 5.2+1 x 5.2+1 = 11x11 janela usada.
				zeroZone,	//Metade do tamanho da zona morta no meio da zona de pesquisa sobre a qual a soma na fórmula abaixo não é feito.(-1,-1) sem zona.
			       criteria);	//Critérios para a finalização do processo iterativo de canto refinamento.
// interface FeatureDetector para encontrar pontos de interesse:
  // -classe SurfFeatureDetector() e função detect() para fazer o processo de detecção
  // -drawKeypoints() - desenhar pontos detectados
     
      // - Passo 1: Detectar os pontos chave usando SURF Detector
        int minHessian = 400;

	SurfFeatureDetector detector( minHessian );

	std::vector<KeyPoint> keypoints_1, keypoints_2;

	detector.detect( img_1, keypoints_1 );
	detector.detect( img_2, keypoints_2 );
      
      //-- Desenha Keypoints
	drawKeypoints(			img_1,	//imagem_entrada
				  keypoints_1,	//Keypoints da imagem_entrada
			      img_keypoints_1,	//imagem_saída.
			      Scalar::all(-1),	//cor dos Keypoints
		   DrawMatchesFlags::DEFAULT);	//flags setando características do desenho.
	
	drawKeypoints( img_2, keypoints_2, img_keypoints_2, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
// interface DescriptorExtractor para encontrar o vetor de características correspondente aos keypoints:
  // -classe SurfDescriptorExtractor() e função compute() para fazer os cálculos necessários
  // -classe BFMatcher() e função matcher() - casar o vetor de características 
  // -drawMatches() - desenhar casamentos detectados
    
	// - Passo 1: Detectar os pontos chave usando SURF Detector
	
	// - Passo 2: Calcular descritores (vetores de características)
	  SurfDescriptorExtractor extractor;

	  Mat descriptors_1, descriptors_2;

	  extractor.compute( img_1, keypoints_1, descriptors_1 );
	  extractor.compute( img_2, keypoints_2, descriptors_2 );
    
	// - Passo 3: Correspondência das descrições dos vetores com um matcher de força bruta
	  BFMatcher matcher(NORM_L2);
	  std::vector< DMatch > matches;
	  matcher.match( descriptors_1, descriptors_2, matches );

	//-- Desenha os casamentos
	  Mat img_matches;
	  drawMatches(		img_1,	//imagem_entrada_1
			  keypoints_1,	//keypoints da imagem_entrada_1
				img_2,	//imagem_entrada_2
			  keypoints_2,	//keypoints da imagem_entrada_2
			      matches,	//casamentos da primeira imagem com a segunda. Significa que keypoints1[i] tem correspondência com keypoints2[matches[i]]
			 img_matches);	//Imagem de saída. O seu conteúdo depende do valor das flags definindo o que é desenhado na imagem de saída.
// Casamento de características com FLANN ( Fast Approximate Nearest Neighbor Search Library)
    //interface FlannBasedMatcher para fazer um rápido e eficiente matching com FLANN 
    
	  // - Passo 1: Detectar os pontos chave usando SURF Detector
	  
	  // - Passo 2: Calcular descritores (vetores de características)
	  
	  // - Passo 3: Casando os vetores de caracterpisticas usando o matcher FLANN
	    FlannBasedMatcher matcher;
	    std::vector< DMatch > matches;
	    matcher.match( descriptors_1, descriptors_2, matches );
  
	  //-- Rápido calculo de distâncias max e min entre os keypoints
	    for( int i = 0; i < descriptors_1.rows; i++ ){ 
	      double dist = matches[i].distance;
	      if( dist < min_dist ) min_dist = dist;
	      if( dist > max_dist ) max_dist = dist;
	    }

	  //-- Desenha apenas "bons" matches (i.e. cuja distancia é menor que 2*min_dist,
	  //-- ou um valor arbitrário menor ( 0.02 ) no evento em que min_dist é bem pequeno
	  //-- PS.- radiusMatch pode também ser usado aqui.
	    std::vector< DMatch > good_matches;

	    for( int i = 0; i < descriptors_1.rows; i++ )
	      if( matches[i].distance <= max(2*min_dist, 0.02) )
		good_matches.push_back( matches[i]); 

	  //-- Desenha apenas "bons" matches
	    Mat img_matches;
	    drawMatches( img_1, keypoints_1, img_2, keypoints_2,
               good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
               vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );
// findHomography() - para encontrar as transformações entre os keypoints que casam.
// perspectiveTransform() -  para mapear os pontos.
      
	 // - Passo 1: Detectar os pontos chave usando SURF Detector
	 // - Passo 2: Calcular descritores (vetores de características)
	 // - Passo 3: Casando os vetores de caracterpisticas usando o matcher FLANN   
	 //-- Rápido calculo de distâncias max e min entre os keypoints 
	 //-- Desenha apenas "bons" matches
	    
	 //-- Localiza o objecto
	 std::vector<Point2f> obj;
	 std::vector<Point2f> scene;

	 for( int i = 0; i < good_matches.size(); i++ ){
	   //-- Geta os keypoints dos "bons" matches
	   obj.push_back( keypoints_object[ good_matches[i].queryIdx ].pt );
	    scene.push_back( keypoints_scene[ good_matches[i].trainIdx ].pt );
	 }

	 Mat H = findHomography(	obj,	//Coordinadas dos pontos no plano original, uma matriz de tipo CV_32FC2 ou vector<Point2f>.
				      scene,	//Coordinadas dos pontos no plano alvo, uma matriz de tipo CV_32FC2 ou vector<Point2f>.
				 CV_RANSAC);	//method - Método usado para computar a matriz de homografia. Os métodos seguintes são possíveis:
														  /*0 - método regular usando todos os pontos
														    CV_RANSAC - método robusto baseado em RANSAC
														    CV_LMEDS - método robusto baseado em Least-Median*/

	 //-- Geta os cantos da image_1 ( o objeto a ser "detectado" )
	 std::vector<Point2f> obj_corners(4);
	 obj_corners[0] = cvPoint(0,0); obj_corners[1] = cvPoint( img_object.cols, 0 );
	 obj_corners[2] = cvPoint( img_object.cols, img_object.rows ); obj_corners[3] = cvPoint( 0, img_object.rows );
	 std::vector<Point2f> scene_corners(4);

	 perspectiveTransform(		obj_corners,	//input de 2-canais ou 3-canais de matriz de float;cada elemento é um vetor de 2D/3D a ser transformado.
				      scene_corners,	//output de mesmo tamanho e tipo da entrada.
						 H);	//matriz de transformação 3x3 or 4x4 de float.

	 //-- Desenha as linhas entre os cantos (o objeto mapeado na cena - image_2 )
	 line( img_matches, scene_corners[0] + Point2f( img_object.cols, 0), scene_corners[1] + Point2f( img_object.cols, 0), Scalar(0, 255, 0), 4 );
	 line( img_matches, scene_corners[1] + Point2f( img_object.cols, 0), scene_corners[2] + Point2f( img_object.cols, 0), Scalar( 0, 255, 0), 4 );
	 line( img_matches, scene_corners[2] + Point2f( img_object.cols, 0), scene_corners[3] + Point2f( img_object.cols, 0), Scalar( 0, 255, 0), 4 );
	 line( img_matches, scene_corners[3] + Point2f( img_object.cols, 0), scene_corners[0] + Point2f( img_object.cols, 0), Scalar( 0, 255, 0), 4 );
// classe FastFeatureDetector() com detect() para detectar keypoints nas duas imagens 
    FastFeatureDetector detector(15);
    vector<KeyPoint> keypoints1;
    detector.detect(img1, keypoints1);
    //... fazer o mesmo p/ a segunda imagem.
    
// classe BruteForceMatcher() com match() para encontrar as correspondências mais próximas entre descritores da primeira imagem com a segunda 
    BruteForceMatcher<L2<float> > matcher;
    vector<DMatch> matches;
    matcher.match(descriptors1, descriptors2, matches);
//Classificador Cascata 
// classe CascadeClassifier() para detectar objetos num fluxo de vídeo. 
    //função load() p/ carregar arquivo classificador .xml. Pode ser um classificador Haar ou um LBP.
    //função detectMultiScale() p/ fazer a detecção.
    
	//var. globais
	CascadeClassifier face_cascade;
	CascadeClassifier eyes_cascade;
	
	CvCapture* capture;
	
	//-- 1. Carrega cascades
	if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };
	if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };
	
	//-- 2. Lê o fluxo de vídeo
	capture = cvCaptureFromCAM( -1 );
	while( true ){
	  frame = cvQueryFrame( capture );
	  //-- 3. Aplica o classificador ao frame e detecta faces
	  face_cascade.detectMultiScale(	frame_gray,	//Matrix do tipo CV_8U contendo uma imagem em que forem detectados objectos.
						     faces,	//std::vector<Rect> onde cada retângulo contém o objeto detectado.
						       1.1,	//Parâmetro especificando o quanto o tamanho da imagem é reduzida em cada escala da imagem.
							 2,	//Parâmetro especificando quantos vizinhos cada retângulo candidato deve ter para retê-lo.
				     0|CV_HAAR_SCALE_IMAGE,	//Parâmetro com o mesmo significado para uma função antiga cvHaarDetectObjectso. Não é usado para uma nova.
					      Size(30,30));	//Tamanho do objeto mínimo possível. Objectos menor do que são ignorados.
	  
	  //Desenha faces detectadas na tela. Acha o centro do rect, e cria uma elipse neste centro
	  for( size_t i = 0; i < faces.size(); i++ ){
	    Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
	    ellipse( frame, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

	    //P/ cada face encontrada, detecta os olhos
	    Mat faceROI = frame_gray( faces[i] );
	    eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30) );

	    //P/ cada olho encontrado, acha o centro e desenha um círculo
	    for( size_t j = 0; j < eyes.size(); j++ ){
	      Point center( faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5 );
	      int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
	      circle( frame, center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
	    }
// CvSVM::train p/ projetar um classificador baseado em SVMs
// CvSVM::predict p/ testar a performance do classificador criado

    //1 --Configura os dados de aprendizagem. São formados por um set de pontos 2-D etiquetados  que pertencem a uma de duas classes. Uma das classes consiste de um ponto
    //e a outra de três pontos. Estes serão armazenados como objetos Mat de floats.
    float labels[4] = {1.0, -1.0, -1.0, -1.0};
    float trainingData[4][2] = {{501, 10}, {255, 10}, {501, 255}, {10, 501}};
    Mat trainingDataMat(3, 2, CV_32FC1, trainingData);
    Mat labelsMat      (3, 1, CV_32FC1, labels);
    
    //2 --Seta os parâmetros do SVM antes de treiná-lo. São armazenados num objeto CvSVMParams
    CvSVMParams params;
    params.svm_type    = CvSVM::C_SVC;	//tipo que pode ser usado para a classificação de classe n (n>=2)
    params.kernel_type = CvSVM::LINEAR;	//função_máscara = Mapeamento feito para os dados de treinamento para melhorar a sua semelhança com um conjunto linearmente separável 
					//​​de dados. Esse mapeamento consiste em aumentar a dimensionalidade dos dados e é feito de forma eficiente usando uma função de kernel.
					//Nós escolhemos aqui o LINEAR tipo CvSVM :: o que significa que nenhum mapeamento é feito.
    params.term_crit   = cvTermCriteria(CV_TERMCRIT_ITER, 100, 1e-6);	//O procedimento de treinamento SVM é implementa a solução atraves de um problema de otimização 
									//de mínimos quadrados de forma iterativa. Aqui nós especificamos um número máximo de iterações e um 
									//erro de tolerância para permitir que o algoritmo termine em um número menor de passos, mesmo que o 
									//hiperplano ideal ainda não tenha sido calculado. Esse parâmetro é definido em uma cvTermCriteria.

    //3 --Treina o SVM. Chamamos CvSVM::train para projetar o modelo SVM
    CvSVM SVM;
    SVM.train(		trainingDataMat,	//formato CV_32FC1 (1-canal 32-bit de float)
			      labelsMat,	//vetor 1-D  de CV_32SC1 (apenas no problema de classificação) ou CV_32FC1, um valor por entrada de vetor (como Redes Neurais).
				  Mat(),	//--
				  Mat(),	//--
				params);	//--
    //4 --Regiões classificadas pelo SVM. CvSVM::predict é usado para classificar exemplos de entrada usando o SVM treinado.Aqui usamos o método p/ colorir o espaço dependendo
    //da predição feita pelo SVM. 
    Vec3b green(0,255,0), blue (255,0,0);

    for (int i = 0; i < image.rows; ++i)
      for (int j = 0; j < image.cols; ++j){
	Mat sampleMat = (Mat_<float>(1,2) << i,j);
	float response = SVM.predict(sampleMat);

	if (response == 1)
	  image.at<Vec3b>(j, i)  = green;
	else if (response == -1)
	  image.at<Vec3b>(j, i)  = blue;
    }
    
    //5 --Vetores de suporte. Usamos alguns métodos para obtermos informações sobre os vetores de suporte. 
    //CvSVM::get_support_vector_count tem por saída o número total de vetores de suporte usados no problema
    //CvSVM::get_support_vector obtém cada vetor de suporte usando seu índice
    int c     = SVM.get_support_vector_count();

    for (int i = 0; i < c; ++i){
      const float* v = SVM.get_support_vector(i); // get and then highlight with grayscale
      circle(   image,  Point( (int) v[0], (int) v[1]),   6,  Scalar(128, 128, 128), thickness, lineType);
    }
//CvSVMParams para dados não-lineares
    
    //.. gera pontos lineares
    //.. gera pontos n-lineares
    //Seta parâmetros do SVM
    CvSVMParams params;			//CvSVM :: C_SVC. Escolhemos aqui um pequeno valor deste parâmetro, a fim de não punir demais erros da classificação incorreta na 
    params.svm_type    = SVM::C_SVC;	//otimização. A idéia de fazer isso decorre da vontade de obter uma solução próxima da intuitivamente esperado. No entanto, 
    params.C           = 0.1;		//recomendamos a obter uma melhor compreensão do problema, fazendo ajustes para este parâmetro.
    params.kernel_type = SVM::LINEAR;
    params.term_crit   = TermCriteria(CV_TERMCRIT_ITER, (int)1e7, 1e-6);	//Critérios de terminação do algoritmo. O número máximo de iterações tem que ser aumentada 
									        //consideravelmente, a fim de resolver correctamente um problema com os dados de formação 
										//não-linearmente separáveis. Em particular, têm aumentado em cinco ordens de magnitude deste
										//valor.
    //..treina SVM
    //.. mostra regiões de decisão
    //.. mostra os dados de aprendizagem
    //.. 
//Mat objetos são armazenados apenas na memória do sistema (ou o cache da CPU). Para obter uma matriz OpenCV para a GPU você vai precisar usar o seu homólogo GpuMat GPU. Ele 
//funciona de forma semelhante ao Mat com uma única limitação 2D e nenhuma referência retornando para suas funções (não pode misturar referências GPU com os da CPU). Para 
//carregar um objeto Mat para a GPU que você precisa chamar a função de upload após a criação de uma instância da classe. Para fazer o download você pode usar atribuição 
//simples para um objeto Mat ou utilizar a função de download.
    Mat I1;         // item na memória principal - lê imagens com imread()
    gpu::GpuMat gI; // GPU matrix - vazia
    gI1.upload(I1); // Upload dados da memória do sistema para a mamória da GPU

    I1 = gI1;       // Download, gI1.download(I1) vai funcionar também
//A alocação de memória sobre a GPU é considerável. Portanto, se for possível alocar nova memória poucas vezes quanto possível, melhor. Se você criar uma função que você 
//pretende chamar várias vezes, é uma boa idéia para alocar todos os parâmetros locais para a função apenas uma vez, durante a primeira chamada. Para fazer isso você cria 
//uma estrutura de dados contendo todas as variáveis ​​locais que você irá usar. Por exemplo, no caso de o PSNR estes são os seguintes:    
					// Optimized GPU versions
    struct BufferPSNR{   // Alocar dados é muito caro na GPU. Use um buffer como solução: aloca uma vez e reusa depois.
      gpu::GpuMat gI1, gI2, gs, t1,t2;
      gpu::GpuMat buf;
    };
    BufferPSNR bufferPSNR;
// Nunca alocar novos dados pra GPU. Algumas funções:
    gpu::multiply(b.mu1_mu2, 2, b.t1); //b.t1 = 2 * b.mu1_mu2 + C1;
    gpu::add(b.t1, C1, b.t1);
//Use chamadas assíncronas (GPU :: Stream). Por padrão, sempre que você chamar uma função gpu, vai aguardar a chamada para terminar e voltar com o resultado depois. No entanto,
// é possível fazer chamadas assíncronas, o que significa que vai ligar para a execução da operação, verificar as alocações de dados onerosas para o algoritmo e voltar 
//imediatamente. Agora você pode chamar uma outra função, se desejar fazê-lo. Para o MSSIM este é um pequeno ponto de otimização. Em nossa implementação padrão nós separamos a
// imagem em canais e, em seguida, chamamos para cada canal as funções de GPU. Um pequeno grau de paralelismo é possível com o fluxo. Usando um fluxo nós podemos fazer a 
// alocação de dados, fazer upload de operações enquanto a GPU já está executando um determinado método. Por exemplo temos que carregar duas imagens. Nós colocamos em fila 
// estes um após o outro e chamamos a função que já processa. As funções irão aguardar o envio ao fim, no entanto, enquanto isso acontece faz com que as alocações de buffer 
// de saída para a função a ser executada em seguida.
    gpu::Stream stream;

    stream.enqueueConvert(b.gI1, b.t1, CV_32F);    // Upload

    gpu::split(b.t1, b.vI1, stream);              // Métodos (passe o stream como último argumento).
    gpu::multiply(b.vI1[i], b.vI1[i], b.I1_2, stream);        // I1^2
//Módulo da retina
    // ponteiro para objeto retina
    cv::Ptr<cv::Retina> myRetina;
    
    // se ultimo parâmetro é 'log', então ativa log sampling (favour foveal vision and subsamples peripheral vision)
    if (useLogSampling){
      myRetina = new cv::Retina(inputFrame.size(), true, cv::RETINA_COLOR_BAYER, true, 2.0, 10.0);
    }else// -> senão aloca retina "classica":
      myRetina = new cv::Retina(inputFrame.size());
      
    //Uma vez feito isso, o código proposto grava um arquivo xml padrão que contém os parâmetros padrão da retina. Isso é útil para fazer a sua própria configuração usando 
    //este modelo. Aqui é gerado o arquivo xml modelo é chamado RetinaDefaultParameters.xml. Você pode talvez modificá-lo e usá-lo no método "setup"
    myRetina->write("RetinaDefaultParameters.xml");

    //Na linha seguinte, a retina tenta carregar outro arquivo xml chamado RetinaSpecificParameters.xml. Se você criou e apresentou a sua própria configuração, ele será 
    //carregado, no outro caso, os parâmetros de retina padrão serão usadas.
    myRetina->setup("RetinaSpecificParameters.xml");
    
    //Não é necessário aqui, mas apenas para mostrar que é possível, você pode redefinir os buffers de retina a zero para forçá-lo a esquecer os acontecimentos passados.
    //Imagine que você feche os olhos por um longo tempo
    myRetina->clearBuffers();
    
    //Agora, é hora de executar a retina! Primeiro, crie alguns buffers de saída pronto para receber os dois canais de saídas de retina
    cv::Mat retinaOutput_parvo;
    cv::Mat retinaOutput_magno;
    
    //Então, retina executado em um loop, carregar novos quadros a partir de seqüência de vídeo, se necessário e obter retina saídas de volta para buffers dedicados.
    // processing loop with no stop condition
    while(true){
      // se usa fluxo de vídeo, então, agarra novo frame, senão, input permanece o mesmo
      if (videoCapture.isOpened())
	  videoCapture>>inputFrame;

      // roda filtro de retina no frame de input
      myRetina->run(inputFrame);
      // Recupera e mostra saída da retina
      myRetina->getParvo(retinaOutput_parvo);
      myRetina->getMagno(retinaOutput_magno);
      cv::imshow("retina input", inputFrame);
      cv::imshow("Retina Parvo", retinaOutput_parvo);
      cv::imshow("Retina Magno", retinaOutput_magno);
      cv::waitKey(10);
    }

    //Está feito! Mas se você quiser proteger o sistema, cuide e gerencie exceções. A retina pode jogar um pouco quando vê dados irrelevantes (sem quadro de entrada, 
    //instalação errada, etc.). Então, eu recomendo para cercar todo o código retina por um try/catch:
    try{
      // pointer to a retina object
      cv::Ptr<cv::Retina> myRetina;
      [---]
      // processing loop with no stop condition
      while(true)
      {
          [---]
      }
    }catch(cv::Exception e){
      std::cerr<<"Error using Retina : "<<e.what()<<std::endl;
    }


    'Parâmetros da retina (arquivo .XML)'
      'Básicos'
    colorMode : 1=colorida, 0=cinza
    normaliseOutput : 1=reescala[0 255]
      'Photo Receptores'
    photoreceptorsLocalAdaptationSensitivity : perto de 1=alta compressão de log na luminância, perto de 0= sensibilidade linear
    photoreceptorsTemporalConstant : grande=forte suavização de efeito temporal
    photoreceptorsSpatialConstant : corta frequências acima di valor
      'Células horizontais' >>'Redes Neurais'
    horizontalCellsGain : 0= tira luminância média e foco em detalhes.Sobe a 1=manter dados dos ambiente de luminância 
    hcellsTemporalConstant : alto=forte efeito pós-operação na retina, baixo=retina mais reativa
    hcellsSpatialConstant : especifica frequência espacial mais baixa permitida
      'canal Parvo'
    ganglionCellsSensitivity : força da adaptação final local. 0= resposta linear, a 1=reforça áreas de baixo contraste
      'canal Magno'
    parasolCells_beta : em geral 0=ganho de amplificação
    parasolCells_tau : suavização temporal no efeito
    parasolCells_k : alto valor=favorecer sinais de frequência espaciais baixas que são mais baixos sujeitos a ruído residual.
    amacrinCellsTemporalCutFrequency : alto valor=eventos transitórios lentos são selecionado
    V0CompressionParameter : especifica a força da compressão de log
    localAdaptintegration_tau : setado a 0
    localAdaptintegration_k : baixo=levar a adaptação de curto alcance local (maior sensibilidade ao ruído), alto=compressão log seguro.
'Viz Module'
// Cria janela
    viz::Viz3d myWindow("Viz Demo");
// Comece ciclo de eventos. Este ciclo de eventos será executado até que o usuário termina-lo pressionando e, E, q, Q.
    myWindow.spin();
// Acessa mesma janela através de seu nome. Como janelas são implicitamente compartilhadas,sameWindow é exatamente a mesma que MyWindow.Se o nome não existir, uma nova janela
//é criada.
    viz::Viz3d sameWindow = viz::get("Viz Demo");
// Começa um loop de eventos controlado. Uma vez que começou, wasStopped é setado falso. Dentro do loop while, em cada iteração, spinOnce é chamado para prevenir loop de even-
//tos de parar completamente. Dentro do while, usuários podem executar outras instruções incluindo as que interagem com a janela.
    /// evento de loop acaba quando é apertado q, Q, e, E
    /// começa evento de loop uma vez por 1 milisegundo
    sameWindow.spinOnce(1, true);
    while(!sameWindow.wasStopped()){
      /// Interage com janela
      /// evento de loop por 1 milissegundo
      sameWindow.spinOnce(1, true);
    }





    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    






    
#caderno
    
    'Entrada de vídeo com OpenCV e medida de similaridade'
    -> Hoje em dia, é comum ter um sistema de gravação de áudio digital a sua disposição. Portanto, você acabará por vir para a situação em que você já não processa um lote de
    imagens, mas fluxos de vídeo .Estes podem ser de dois tipos: de alimentação de imagem em tempo real (no caso de uma webcam) ou arquivos pré-gravados e armazenados em disco
    rígido.
    -> Por sorte, OpenCV trata estes dois da mesma maneira, com a mesma classe em C++.Você irá aprender neste tutorial:
	'Como abrir e ler fluxos de vídeo'
	'Dois modos para checar similaridade de imagens: PSNR e SSIM' - pode ser usado para testar o quão bem funciona um novo algorítmo de compressão.
	
	'PSNR'
	Precisamos de um sistema para verificar quadro a quadro a semelhança ou diferenças. O algoritmo mais comum utilizado para isto é o PSNR (também conhecido como 
	proporção de pico de sinal-para-ruído). A definição mais simples deste começa a partir do erro do quadrado médio 'MSE' seguido do 'PSNR'.
	    ->Para duas imagens iguais, MSE é igual a 'ZERO'.
	    ->'Valores tipicamente entre 30 e 50'
	    ->'Quanto maior melhor'
	    ->'Grande diferença entre as imagens: valores iguais a 15 ou menores'
	    ->No entanto, na prática, pode vir um pouco inconsistente com a percepção do olho humano. O algoritmo de similaridade estrutural 'SSIM' visa corrigir este problema.
	'SSIM'
	    ->Retorna índice de similaridade para cada canal da imagem
	    ->'Valores entre 0 e 1'
	    ->'Valor 1 = similaridade perfeita'
    
    'Salvando vídeo'
    -> Como criar arquivo de vídeo com OpenCV
    -> Quais tipos de arquivos de vídeo você pode criar
    -> Como extrair um dado canal de cor de um vídeo
    -> Cada arquivo de vídeo é por si só um container. O tipo do container é expresso na extensão do arquivo. Isto contém vários elementos, como: alimentações de vídeo e áudio,
       ou outras faixas (como por exemplo legendas). Como estas alimentações são armazenadas é determinado pelo codec usado por cada um deles. Para áudio (mp3,aac, wma), para
       vídeos (XVID, DIVX, H264 or LAGS (Lagarith Lossless Codec). 
    -> Além disso, você só pode criar e expandir uma única faixa de vídeo no interior do container. Não há áudio ou outro suporte para edição de faixa aqui.

    'Arquivos XML e YAML'
       
		    <?xml version="1.0"?>
		    <CAT>
		      <NAME>Izzy</NAME>
		      <BREED>Siamese</BREED>
		      <AGE>6</AGE>
		      <ALTERED>yes</ALTERED>
		      <DECLAWED>no</DECLAWED>
		      <LICENSE>Izz138bod</LICENSE>
		      <OWNER>Colin Wilcox</OWNER>
		    </CAT>
		    
    -> XML utiliza "marcação". "Marcação" é o processo de utilização de códigos denominados tags (ou por vezes tokens) para definir a estrutura, o aspecto visual e, no caso 
    do XML, o significado de todos os dados.
    -> É fácil reconhecer as tags em documentos HTML e XML, uma vez que estão rodeadas por parênteses em ângulo. No código-fonte deste artigo, as tags HTML efectuam diversas 
    funções, tais como definir o início e fim de cada parágrafo (<p> ... </p>) e marcar a localização de cada imagem. Em XML, as tags definem a estrutura e significado dos 
    dados: o que os dados são.
    -> É possível utilizar um sistema para gerar os dados e marcá-los com tags XML e, em seguida, processar esses dados em quaisquer outros sistemas, independentemente da 
    plataforma de hardware ou sistema operativo.
    -> Não é possível utilizar HTML em vez de XML. Contudo, é possível moldar os dados XML em tags HTML e visualizá-los numa página Web.
    -> apenas é possível partilhar dados XML entre programas e sistemas se esses dados forem correctamente concebidos. Se não for possível abrir um ficheiro XML, o mais 
    provável é que esse ficheiro não esteja correctamente concebido.
    -> Para além de dados com tags correctamente concebidas, os sistemas XML utilizam geralmente dois componentes adicionais: esquemas e transformações.
    'Esquemas' Um esquema é apenas um ficheiro XML que contém as regras relativamente ao que pode e não pode residir num ficheiro de dados XML. Os ficheiros de esquema 
	         utilizam geralmente a extensão de nome de ficheiro .xsd, enquanto os ficheiros de dados XML utilizam a extensão .xml.
	       Os esquemas permitem aos programas validar os dados. Desde que os dados num ficheiro XML obedeçam às regras de um determinado esquema, qualquer programa que 
	         suporte XML consegue utilizar esse esquema para ler, interpretar e processar os dados.
	         
		    <xsd:element name="CAT">  
		      <xsd:complexType>  
			 <xsd:sequence>
			    <xsd:element name="NAME" type="xsd:string"/>
			    <xsd:element name="BREED" type="xsd:string"/>
			    <xsd:element name="AGE" type="xsd:positiveInteger"/>
			    <xsd:element name="ALTERED" type="xsd:boolean"/>
			    <xsd:element name="DECLAWED" type="xsd:boolean"/>
			    <xsd:element name="LICENSE" type="xsd:string"/>
			    <xsd:element name="OWNER" type="xsd:string"/>        
			 </xsd:sequence>
		      </xsd:complexType>
		    </xsd:element>
    'Transformações' O mecanismo para a reutilização dos dados é denominado XSLT (Extensible Stylesheet Language Transformation) ou simplesmente transformação. Exemplo passando
		       para tabela no browser.
		       
		    <?xml version="1.0"?>
		    <xsl:stylesheet version="1.0"> 
		    <TABLE>
		      <TR>
			<TH>Name</TH>
			<TH>Breed</TH>
			<TH>Age</TH>
			<TH>Altered</TH>
			<TH>Declawed</TH>    
			<TH>License</TH>
			<TH>Owner</TH>
		      </TR>
		      <xsl:for-each select="CAT">
		      <TR ALIGN="LEFT" VALIGN="TOP">
			<TD>
			  <xsl:value-of select="NAME"/>
			</TD>
			<TD>
			  <xsl:value-of select="BREED"/>
			</TD>
			<TD>
			  <xsl:value-of select="AGE"/>
			</TD>
			<TD>
			  <xsl:value-of select="ALTERED"/>
			</TD>
			<TD>
			  <xsl:value-of select="DECLAWED"/>
			</TD>
			<TD>
			  <xsl:value-of select="LICENSE"/>
			</TD>
			<TD>
			  <xsl:value-of select="OWNER"/>
			</TD>
		      </TR>
		    </xsl:for-each>
		    </TABLE>
    
    
    'Entrada e saída de arquivos usando XML e YAML'
    -> Como imprimir e ler as entradas de texto para um arquivo e OpenCV usando arquivos YAML ou XML?
    -> Como fazer o mesmo para estruturas de dados OpenCV?
    -> Como fazer isso para as suas estruturas de dados?
    -> O uso de estruturas de dados, tais como OpenCV FileStorage, filenode ou FileNodeIterator.
    
    
    
    
    'Calibração de câmera e reconstrução 3D'
    -> Embora temos a maioria de nossas imagens em um formato 2D eles vêm de um mundo 3D. Aqui você vai aprender como descobrir a partir das imagens 2D informações sobre o 
       mundo 3D.
       
	'Calibração de câmera com tabuleiro de xadrez' 
	 -> O objetivo deste tutorial é aprender como calibrar uma câmera dado um conjunto de imagens de tabuleiro de xadrez.
        
	'Calibração de câmera com OpenCV'
	->Infelizmente, câmeras vem com distorção. Porém, existem constante e com calibração e algum remapeamento podemos consertar isto. Além do mais, com calibração você pode
	  determinar a relação entre as unidades naturais da câmera (pixels) e as unidades reais do mundo (por exemplo, milímetros).
	->Pela distorção OpenCV leva em conta fatores "radiais" e "tangenciais". 
	  'Para o factor "radial" se utiliza a seguinte fórmula:'
						    x(corrigido) = x(1 + k1.r^2 + k2.r^4 + k3.r^6)
						    y(corrigido) = y(1 + k1.r^2 + k2.r^4 + k3.r^6)
	  -> Logo, para um pixel antigo (x,y) na imagem de entrada, sua nova posição na imagem de saída será (x(corrigido), y(corrigido)). A presença da distorção radial 
	     manifesta-se nos efeitos de "barril" ou "olho de peixe".
	  'Distorções tangenciais ocorrem porque as lentes não estão perfeitamente paralelas ao plano da imagem. Pode ser corrigido pelas fórmulas'
						    x(corrigido) = x + [2.p1.x.y + p2.(r^2 + 2.x^2)]
						    y(corrigido) = y + [2.p2.x.y + p1.(r^2 + 2.y^2)]
	  -> Então temos 5 parâmetros de distorção, representados pelo OpenCV como uma linha com 5 colunas:
						    'coef_distorção = (k1 k2 p1 p2 k3)'
	  
	  -> Agora, para a conversão de unidade, usamos a seguinte fórmula:
						    [x]    [fx  0 cx]  [X]
						    |y| =  | 0 fy cy| .|Y|
						    [w]    [ 0  0  1]  [Z]
	       -> A presença de w é explicada pelo uso  do sistema de coordenadas de homografia (e w = Z). Os não-sabidos parâmetros são fx e fy (tamanhos focais da câmera)
		  e (cx, cy) que são os centros óticos  expressados em coordenadas de pixels. Se para ambos os eixos um comprimento focal comum é usado com uma dada relação
		  de aspecto (em geral 1), então  'fy = fx * a' e na fórmula superior teremos uma única distância focal f.'A matriz que contém estes 4 parâmetros é chamada de' 
		  'matriz da câmera.' Enquanto os coeficientes de distorção são os mesmos independentemente das deliberações da câmara utilizados, estes devem ser escalados
		  juntamente com a resolução corrente da resolução calibrada.
	        'O processo de determinar estas duas matrizes é chamado de calibração.' O cálculo destes parâmetros é feito através de equações básicas de geometria. As equações
		  usadas dependem dos objetos de calibração escolhidos. Atualmente OpenCV suporta 3 tipos de 'objetos de calibração':
		      'Classico tabuleiro de xadrez preto e branco'
		      'Simétrico padrão circular'
		      'Assimétrica padrão circular'
		Basicamente, você precisa tirar fotos destes padrões com sua câmera e deixar o OpenCV encontrá-los. Cada padrão encontrado é uma nova equação. Para resolver
		  a equação você precisa pelo menos de um número pré-determinado de fotos do padrão para formar um bom sistema de equações. Este número é maior para o padrão
		  do tabuleiro e menor para os dos círculos. Por exemplo, em teoria o padrão do tabuleiro requer pelo menos 2 fotos. Contudo,na prática temos uma grande quanti-
		  dade de ruído em nossas imagens de entrada, então para bons resultados você precisa de pelo menos 10 boas fotos do padrão de entrada em posições diferentes.
		  
		-> 'Objetivos'
		   1)Determinar a matriz de distorção.
		   2)Determinar a matriz câmera.
		   3)Tomar entrada de lista de arquivos de camera, vídeo e imagem.
		   4)Ler configurações de um arquivo XML/YAML.
		   5)Salvar os resultados num arquivo XML/YAML.
		   6)Calcular erro da re-projeção.
		   
    'Detector de cantos de Harris'
    -> Uma feature, em visão computacional, são características que podem ser reconhecidas facilmente. Deve ser unicamente identificável.
    -> Numa imagem são: 'Bordas', 'cantos (pontos de interesse)', 'blobs (regiões de interesse)'.
    -> 'Canto é a intersecção de duas bordas, um ponto onde a direção das bordas muda. Assim, o gradiente da imagem (em ambos os sentidos) têm uma variação elevada, que pode 
	 'ser utilizado na detecção daquele.' Olharemos para a variação do gradiente.
	 
	 1) Vamos varrer uma janela w(x, y) (com deslocamentos u na direção x e v na direção y) e calcular a variação de intensidade.
					    E(u,v) = som(x,y){ w(x,y).[I(x+u,y+v) - I(x,y)]}² 		'w(x,y) é a janela na pos. (x,y)'
													'I(x,y) é a intensidade em (x,y)'
													'I(x+u,y+v) é intensidade na janela movida (x+u,y+v)'
	 2) Como olhamos para janelas com cantos, queremos janelas com grandes variações de intensidade. Portanto temos de maximizar a equação.
					    E(u,v) ~ [u v]. (som(x,y){ w(x,y). [Ix²   IxIy] )  [u  
							    (                   IxIy    Iy²])   v]
							    
					    E(u,v) ~ [u v]. M [u
							       v]
							       
					    R = det(M) - k(traço(M))²			'det(M) = λ1λ2'
											'traço(M) = λ1 + λ2'
	      'Uma janela com uma pontuação R maior do que um determinado valor é considerado um 'canto'

    'Introdução para Máquinas de suporte a vetores (SVM)'
    Na geometria, um hiperplano pode ser um espaço Vetorial, transformação afim ou o sub-espaço de dimensão n-1. Em particular, num espaço tridimensional um hiperplano é um 
      plano habitual. Num espaço bi-dimensional, um hiperplano é uma reta. Num espaço monodimensional, um hiperplano é um ponto.
    
    Uma máquina de suporte a vetores (SVM) é um classificador discriminativo formalmente definido por um hiperplano de separação. Em outras palavras, dado um treino de
      dados etiquetados (aprendizado supervisionado), o algorítmo tem por saída um hiperplano otimizado que categoriza novos exemplos.
      
    Em que sentido é o hiperplano obtido ideal? Consideremos o seguinte exemplo:
      P/ um conjunto de pontos 2-D linearmente separáveis que pertencem a uma entre duas classes, encontra uma linha reta ótima que os separe.
      Esta linha será o hiperplano ideal.
      
      'Nota - Neste exemplo, lidamos com linhas e pontos no plano cartesiano, em vez de hiperplanos e vetores em um espaço dimensional elevada. Esta é uma simplificação do 
        'problema.É importante entender que isso é feito apenas porque a nossa intuição é melhor construída a partir de exemplos que são fáceis de imaginar. No entanto, os 
        'mesmos conceitos devem ser aplicáveis ​​para tarefas em que os exemplos de classificar assentam num espaço cuja dimensão é maior do que dois.'
      
      Muitas linhas oferecem uma solução. O objetivo é encontrar aquela que passe o mais longe possível de todos os pontos. A operação do algorítmo SVM é baseada em encontrar
	o hiperplano que nos dá a maior distância mínima de formação entre todos os exemplos. Esta distância é chamada 'margem' dentro da teoria SVM. Portanto, o hiperplano 
	ótimo é aquele que maximiza a margem dos dados de treino.
     
      Como é calculado o hiperplano ótimo?
	      'f(x) = ßø + ß^T.x	, onde ß é o peso do vetor e ßø seu bias.'
	      'p/ o hiperplano ótimo (representação hiperplano canônico)	, |ßø + ß^T.x| = 1 onde x é o exemplo de treino mais próximo do hiperplano (vetores de suporte)'
	      'Então, calculamos a distância entre o ponto x e o hiperplano(ß,ßø), a margem será duas vezes esta distância'
	      Este é um problema de otimização Lagrangiana que pode ser resolvido usando multiplicadores de Lagrange para obter o peso do vetor e seu bias do hiperplano ótimo.
	      
    'Máquinas de suporte a vetores (SVM) para dados separáveis não-lineares'
    A maior parte das aplicações em que SVMs são usados ​​em visão computacional necessitam de uma ferramenta mais poderosa do que um classificador linear simples. Isso decorre 
      do fato de que nessas tarefas os dados de treinamento podem ser raramente separados através de um hiperplano. Por exemplo reconhecimento de face, separar rostos de 
      não-rostos.
    
    Estes dados de treinamento são muito complexos, de modo a encontrar uma representação de cada amostra (vector de características) que poderia fazer todo o conjunto de 
      rostos linearmente separáveis ​​de todo o conjunto de não-rostos.
      
    Como agora o plano é não-linear, temos de admitir que o hiperplano encontrados irá classificar erroneamente algumas das amostras. Por isto, além do cálculo habitual do 
      hiperplano, querermos encontrar um novo a generalizar os dados de treinamento corretamente, não permitindo muitos erros de classificação. Os cálculos agora devem levar 
      em conta os erros de classificação. Uma boa solução terá em conta a distância das amostras incorrectamente classificadas para as suas regiões de decisões correctas, 
      este parametro será chamado ξ.
      
    'Checando similaridade(PNSR e SSIM) na GPU'
    Uma placa de vídeo é composta por diversos circuitos e elementos eletrônicos, porém seu papel mais importante é o de comportar um processador dedicado especialmente para a
      renderização de gráficos em tempo real. Este tipo de processador é chamado de Graphics Processing Unit, também conhecido como GPU.GPU (Graphics Processing Unit, ou 
      Unidade de Processamento Gráfico), conhecido também como VPU ou unidade de processamento visual, é o nome dado a um tipo de microprocessador especializado em processar 
      gráficos em computadores pessoais, estações de trabalho ou videogames.
      
    Vimos que o processo para checar similaridade é um pouco demorado, ainda mais no SSIM. Se você não está satisfeito com a performance do seu algorítmo na cpu e tem uma uni-
      NVidia CUDA GPU, então você pode importar seu código para ser processado pela GPU(placa de vídeo). Aqui mostraremos como rodar seu código numa ótima performance.
      
    No entanto, sua força reside nos seus números. Nos últimos anos, tem havido uma tendência crescente para colher esses poderes paralelos maciços da GPU em cena não-gráfico 
      de renderização também. Isso deu origem à computação de propósito geral em unidades de processamento gráfico (GPGPU).
      
    'funções da GPU possuem mesmo formato das funções normais, porém seus inputs são sempre objetos GpuMat e possuem namespace gpu::'
    'CUDA', sigla para Compute Unified Device Architecture, é uma extensão para a linguagem de programação C, a qual possibilita o uso de computação paralela. A ideia por trás 
	disso tudo é que programadores possam usar os poderes da unidade de processamento gráfico (GPU) para realizar algumas operações mais rapidamente.
	
    'Descobrindo a retina humana e seu uso no processamento de imagens'
    Você vai aprender como processar imagens e fluxos de vídeo com um modelo de filtro de retina para obter detalhes resultados, remoção de ruído espaço-temporal, correção de 
      iluminação e detecção de eventos espaço-temporal.
    Do modelo que existe, foi alcançado:
    1)Limpamento do espectro, que tem 3 efeitos: cancelamento de sinais de alto frequência espaço-temporal (ruído). Detalhes de frequências médias reforçadas, redução da
      energia de frequências de baixa luminância.Todas estas propriedades em uma permite limpar sinais visuais de distorções indesejadas introduzidas por sensores de imagens
      e gama de entradas de luminancia.
    2)A compressão local do logarítmo da luminância permite que detalhes sejam reforçados mesmo em condições de pouca luz.
    3)Decorrelação das informação de detalhes(canal de saída Parvocellular) e informação transiente(eventos, movimentos disponibilizados no canal de saída Magnocellular).
    
    Infelizmente, a conversão de imagens de OpenEXR (high dynamic-range image file format) para range [0 255] 8-bits envolve perda de características. Com os métodos aqui
      presentes vamos resgatar estas características usando os mesmo métodos de nossa retina.
      
    -> 'Canais de saída do modelo da retina:' O modelo da retina apresenta 2 saídas que se beneficiam dos métodos citados:
    1) O primeiro se chama canal 'Parvocelular'. Esta principalmente ativo na área foveal da retina (visão central de alta resolução sensível à cores por foto-receptores), seu
      objetivo é providenciar visão de cores acurada para detalhes visuais restantes na estática da retina. Porém, objetos se movendo na projeção da retina são borrados.
    2) O segundo canal se chama canal 'Magnocelular'. Está principalmente presente na visão periférica da retina e envia sinais relacionados com a mudança eventos (movimentos, 
      eventos transientes, etc). Estes sinais que saem também ajudam o sistema visual a focar/centralizar  a retina em áreas transientes/que se movimentam para uma análise 
      mais detalhada melhorando assim o contexto da cena visual e classificação de objetos.
      
      'Este canal pode ser usado como um detector de movimento de áreas transientes: ele poderá fornecer informações relevantes para uma ferramenta de segmentação de baixo '
      'custo que pode destacar áreas que tem movimento.'
      
      NOTA: em relação ao modelo proposto, ao contrário da verdadeira retina, nós aplicamos estes dois canais nas imagens de entrada inteiras usando a mesma resolução. Isto 
      permite detalhes visuais reforçados  e informações de movimento a serem extraídos em todas as imagens consideradas ... mas lembre-se, que estes dois canais são 
      complementares. Por exemplo, se o canal magnocellular dá energia forte em uma área, em seguida, o canal parvocelular é certamente borrado lá desde que há um evento 
      transiente.
      
      'objetivos'
      -> Realizar análise de textura com reforço da relação sinal/ruído e reforço de detalhes robustos contra imagens de entrada da ranges de luminância (Parvocelular).
      -> Realizar análise de movimento tomando benefícios das propriedades citadas anteriormente.