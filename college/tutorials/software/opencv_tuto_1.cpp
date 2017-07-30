#Introduction to OpenCV
#core module. The Core Functionality
#imgproc module. Image Processing


#funções

// Inclusão da core e da highgui
	#include <opencv2/core/core.hpp>
	#include <opencv2/highgui/highgui.hpp>
// Inclusão diferente. Primeiro da opencv, depois outras..
	#include <cv.h>
	#include <highgui.h>
// namespace do opencv
	using namespace cv;
// Mat objeto que irá armazenar os dados da imagem carregada
	Mat image;
// Cada objeto Mat tem seu próprio cabeçalho, no entanto, a matriz pode ser compartilhada entre outras instâncias por ter seus ponteiros de matriz apontando
// para o mesmo endereço de dados.O operador de cópia só irá copiar os cabeçalhos e o ponteiro para a outra matriz, não os dados em si.
	Mat A, C;                                 // Cria apenas os headers
	A = imread(argv[1], CV_LOAD_IMAGE_COLOR); // Aloca os dados
	Mat B(A);                                 // Usa o contrutor de cópia. Não copia dados, tem header diferente mas aponta para mesmos dados
	C = A;                                    // Operador sobrecarregado. C aponta para mesmo espaço de dados de A, mas tem header diferente.
// Você pode criar cabeçalhos que se referem a apenas uma subseção dos dados completos. Por exemplo, para criar uma região de interesse (ROI) em uma imagem 
// você só precisa criar um novo cabeçalho com os novos limites:
	Mat D (A, Rect(10, 10, 100, 100) ); // usando um retângulo = Rect(x, y, width, height)
	Mat E = A(Range::all(), Range(1,3)); // usando limites de linhas e retângulos
// clone() e copyTo() para copiar a matriz inteira por si só.
	Mat F = A.clone();
	Mat G;
	A.copyTo(G);
// Mat - Construtor 
	Mat M(2,2, CV_8UC3, Scalar(0,0,255));                                  M= [0, 0, 255, 0, 0, 255;
        cout << "M = " << endl << " " << M << endl << endl;                        0, 0, 255, 0, 0, 255]
        //CV_[The number of bits per item][Signed or Unsigned][Type Prefix]C*[Number of channels]
        CV_<bit_depth>(S|U|F)C<number_of_channels>

	  S = Signed integer
	  U = Unsigned integer
	  F = Float
// Mat - C\C++ matrizes e inicializar via construtor
	int sz[3] = {2,2,2};                                                   L= [0, 0, 0;
        Mat L(3,sz, CV_8UC(1), Scalar::all(0));                                    0, 0, 0]
// Converte IplImage* em Mat
	IplImage* img = cvLoadImage("greatwave.png", 1);
	Mat mtx(img); // convert IplImage* -> Mat
// Mat - create() - default valor 205
	M.create(4,4, CV_8UC(2));                                              M= [205, 205, 205, 205, 205, 205, 205, 205;
        cout << "M = "<< endl << " "  << M << endl << endl;                        205, 205, 205, 205, 205, 205, 205, 205;
                                                                                   205, 205, 205, 205, 205, 205, 205, 205;
                                                                                   205, 205, 205, 205, 205, 205, 205, 205]
// Mat - MATLAB style:  zeros(), ones(), eye().
	Mat E = Mat::eye(4, 4, CV_64F);
        cout << "E = " << endl << " " << E << endl << endl;                    E= [1, 0, 0, 0;
                                                                                   0, 1, 0, 0;  Z= [0, 0, 0;
        Mat O = Mat::ones(2, 2, CV_32F);                                           0, 0, 1, 0;      0, 0, 0;  O= [1, 1;
        cout << "O = " << endl << " " << O << endl << endl;                        0, 0, 0, 1]      0, 0, 0]      1, 1]

        Mat Z = Mat::zeros(3,3, CV_8UC1);
        cout << "Z = " << endl << " " << Z << endl << endl;
	Mat new_image = Mat::zeros( image.size(), image.type() ); //mesmo tamanho e tipo de image
// Mat - Separadores de vírgula
	Mat C = (Mat_<double>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);          C= [0, -1, 0;
        cout << "C = " << endl << " " << C << endl << endl;                        -1, 5, -1;
	                                                                           0, -1, 0]
// Mat - Criar um novo cabeçalho para um objeto existente e Mat clone () ou copyTo () nele.
	Mat RowClone = C.row(1).clone();                                       RowClone = 
        cout << "RowClone = " << endl << " " << RowClone << endl << endl;          [-1, 5, -1]
// Mat - randu() Preencher com números aleatórios. Especificar valor máximo e mínimo
	Mat R = Mat(3, 2, CV_8UC3);
        randu(R, Scalar::all(0), Scalar::all(255));
//Ponto 2D, especificado pelas coordenadas x e y da imagem
	Point pt;		Point pt =  Point(10, 8);
	pt.x = 10;
	pt.y = 8;       ou
// Ponto 2D
	Point2f P(5, 1);
        cout << "Point (2D) = " << P << endl << endl;  //Point (2D) = [5, 1]
// Ponto 3D
	Point3f P3f(2, 6, 7);
        cout << "Point (3D) = " << P3f << endl << endl; //Point (3D) = [2, 6, 7]
// Scalar - Representa um vector de 4 elementos. O tipo Scalar é amplamente utilizado em OpenCV para passar valores de pixel.  Não é necessário definir o último
// argumento se não vai ser usado. No exemplo, definimos uma cor RGB, com red=c green=b blue=a
	Scalar(a, b, c)
// std::vector via cv::Mat
	vector<float> v;
	v.push_back( (float)CV_PI);   v.push_back(2);    v.push_back(3.01f);
	cout << "Vector of floats via Mat = " << Mat(v) << endl << endl; // Vector of floats via Mat = [3.1415927; 2; 3.01]
// std::vector de pontos
	vector<Point2f> vPoints(20);
	for (size_t i = 0; i < vPoints.size(); ++i)
        vPoints[i] = Point2f((float)(i * 5), (float)(i % 7));
	cout << "A vector of 2D Points = " << vPoints << endl << endl;
// imread() Carrega o nome da imagem especificada pelo primeiro argumento (argv [1]). O segundo argumento especifica o formato em que queremos que a imagem
	image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file

                             'CV_LOAD_IMAGE_UNCHANGED (<0)'carrega a imagem como é (incluindo o canal alfa se houver (transparência));
                             'CV_LOAD_IMAGE_GRAYSCALE (0)' carrega a imagem como uma intensidade de um;
                             'CV_LOAD_IMAGE_COLOR (>0)' carrega a imagem no formato BGR.
                             
                             'obs: OpenCV carrega imagem com CV_LOAD_IMAGE_COLOR como padrão. Então mesmo que a imagem já seja em níveis de cinza ele não'
                             'entende e necessita que seja especificado CV_LOAD_IMAGE_GRAYSCALE.                                                         '
// namedWindow() Cria janela opencv para exibir imagem. Você precisa especificar seu nome e como deve lidar com a mudança da imagem que contém a partir de um 
// tamanho de ponto de vista
	namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.

                             'CV_WINDOW_AUTOSIZE' é o único suportado,se você não usar o backend Qt. Neste caso, o tamanho de janela irá ater-se ao tamanho da
                                                  imagem original. Sem redimensionamento permitido!
                             'CV_WINDOW_NORMAL' em Qt você pode usar isso para permitir redimensionamento da janela. A imagem será redimensionada de acordo com 
                                                  o tamanho da janela atual. Ao usar o operador | você também precisa especificar se você gostaria que a imagem
                                                  mantenha sua relação de aspecto (CV_WINDOW_KEEPRATIO) ou não (CV_WINDOW_FREERATIO).
// imshow() Para atualizar o conteúdo da janela do OpenCV com uma nova imagem. Especifique o nome da janela OpenCV para atualizar e imagem para usar durante esta operação
	imshow( "Display window", image );       // Show our image inside it.
// waitKey() Quanto tempo deve esperar por uma entrada do usuário (medido em milissegundos). Zero significa esperar para sempre.
	waitKey(0);
	char c = waitKey(10); //espera por 10 milissegundos ou entrada do usuário e armazena em c.
// cvtColor() Converter a nossa imagem de BGR para o formato em tons de cinza
	cvtColor( image, gray_image, CV_BGR2GRAY );	//cvtColor(img_fonte,img_destino,tipo_de_conversão);
// imwrite() Salva imagem em disco na pasta atual.
	imwrite( "Gray_Image.jpg", gray_image );
// split() Separa uma imagem em suas componentes
	vector<Mat> bgr_planes;
	split( src, bgr_planes );
// Iterador Mat que representa início da imagem e que representa o fim numa imagem grayscale
	I.begin<uchar>() & I.end<uchar>();
// Iterador Mat que representa início da imagem e que representa o fim numa imagem colorida
	I.begin<Vec3b>() & I.end<Vec3b>();
// saturate_cast() garante que a espressão entre parêntesis vai retorna um valor que esteja dentro dos limites do tipo especificado no template.
	saturate_cast<uchar>( ..);
// addWeighted(). Adiciona duas imagens com pesos. dst = alpha*src1 + beta* src2 + gama
	beta = ( 1.0 - alpha );
	addWeighted( src1,		//imagem_1
		    alpha, 		//peso imagem_1
	             src2, 		//imagem_2
	             beta,		//peso imagem_2
	              0.0, 		//adição final - gama
	             dst);		//imagem de saída
// getTickCount() e getTickFrequency(). Como medir tempo passado entre duas etapas?(p/ medir performance). 
// getTickCount() mede quantos ticks a CPU já mandou a partir de um evento do computador(como dar boot no pc).
// getTickFrequecy nos dá a qtd_ticks/segundo que a nossa CPU emite. Então, medimos tempo com a seguinte fórmula.
	double t = (double)getTickCount(); //ticks_passados1
	// do something ...
	t = ((double)getTickCount() - t)/getTickFrequency(); //(ticks_passados2 - ticks_passados1)/(ticks_emitidos/segundo) = segundos passados no evento
	cout << "Times passed in seconds: " << t << endl;
//Scanning - Eficiente(C style - usando ptr<uchar>)
	//aceita só matriz tipo char
	CV_Assert(I.depth() != sizeof(uchar));

	int channels = I.channels();  //recebe quantidade de canais

	int nRows = I.rows;	      //recebe quantidade de linhas
	int nCols = I.cols * channels;//recebe quantidade total de colunas (incluindo subcolunas)

	if (I.isContinuous())         //pergunta se a matriz esta armazenada de forma contínua na memória, como uma grande linha
	{
	    nCols *= nRows;	      //caso sim, faz as alterações  
	    nRows = 1;
	}

	int i,j;
	uchar* p;		      //ponteiro p/ os elementos da matriz, de tipo uchar
	for( i = 0; i < nRows; ++i){  //p/ cada linha
	    p = I.ptr<uchar>(i);               //ponteiro p recebe o endereço do primeiro elemento da linha
	    for ( j = 0; j < nCols; ++j){  //p/ cada coluna 
		p[j] = table[p[j]];        //ponteiro que representa o elemento da matriz recebe o valor da tabela
	    }
	}
	return I;
//Scanning - Iterador(seguro - usando  MatIterator_<uchar>)
	// accept only char type matrices
	CV_Assert(I.depth() != sizeof(uchar));

	const int channels = I.channels();
	switch(channels){
	  case 1:	
	  {
            MatIterator_<uchar> it, end;	//Iterador Mat
            for( it = I.begin<uchar>(), end = I.end<uchar>(); it != end; ++it)
                *it = table[*it];
            break;
	  }
	  case 3:
	  {
            MatIterator_<Vec3b> it, end;					//Em caso de imagens a cores, temos três itens UCHAR por coluna. Isso pode ser 
            for( it = I.begin<Vec3b>(), end = I.end<Vec3b>(); it != end; ++it)  //considerado um curto vector de itens UCHAR, que foi batizado em OpenCV com o 
            {									//nome Vec3b. Para acessar o sub coluna n-th usamos operador [] acesso simples.
                (*it)[0] = table[(*it)[0]];					// É importante lembrar que iterators OpenCV percorrer as colunas e saltam automaticamente 
                (*it)[1] = table[(*it)[1]];					//para a próxima linha. Assim, em caso de imagens coloridas se você usar um iterador uchar 
                (*it)[2] = table[(*it)[2]];					//simples você vai ser capaz de acessar apenas os valores do canal azul.
            }
	  }
	}

	return I;
//Scanning - Cálculo com retorno de referência a endereço On-the-Fly - Não recomendado para scanning (usando at<uchar>)
// Em comparação com a maneira eficiente, a única diferença na utilização desta é que para cada elemento da imagem que você vai ter um novo ponteiro de linha 
// para o que usamos o operador C [] para adquirir o elemento coluna.

	// accept only char type matrices
	CV_Assert(I.depth() != sizeof(uchar));

	const int channels = I.channels();
	switch(channels){
	  case 1:
	  {
	      for( int i = 0; i < I.rows; ++i)
		  for( int j = 0; j < I.cols; ++j )
		      I.at<uchar>(i,j) = table[I.at<uchar>(i,j)];
	      break;
	  }
	  case 3:
	  {
	      Mat_<Vec3b> _I = I;				//Se for necessário várias pesquisas utilizando este método para uma imagem, haverá muito gasto e cansaço. 
								//Para resolver este problema OpenCV tem um tipo de dados Mat_. É o mesmo que Mat com a necessidade extra 
	      for( int i = 0; i < I.rows; ++i)			//que na definição é necessário especificar o tipo de dados através do que olhar para a matriz de dados, 
		  for( int j = 0; j < I.cols; ++j ){		//no entanto, em troca, você pode usar o operador () para acesso rápido de itens. Para tornar as coisas ainda 
		    _I(i,j)[0] = table[_I(i,j)[0]];		//melhor este é facilmente conversível de e para o tipo de dados Mat habitual.
		    _I(i,j)[1] = table[_I(i,j)[1]];
		    _I(i,j)[2] = table[_I(i,j)[2]];
		  }
	      I = _I;
	      break;
	  }
	}

	return I;
//Scanning - MAIS EFICIENTE - função LUT(img_entrada, tabela mat de transformações, img_saída).
// Isso ocorre porque a biblioteca OpenCV é multi-thread habilitado via Intel Threaded Building Blocks.
	Mat lookUpTable(1, 256, CV_8U); //cria matriz com 1 linha e 256 colunas de tipo unsigned char
	uchar* p = lookUpTable.data;	//método data retorna o primeiro elemento da matriz/array
	for( int i = 0; i < 256; ++i)	//Cria tabela do tipo Mat
	  p[i] = table[i];
	
	  LUT(I, lookUpTable, J);
// Shapen => aumento de contraste (eficiente - ptr<uchar>)
	CV_Assert(myImage.depth() == CV_8U);  // accept only uchar images

	Result.create(myImage.size(), myImage.type());    //garante que a imagem de saída tem mesmo tipo e tamanho da de entrada
	const int nChannels = myImage.channels();

	for(int j = 1; j < myImage.rows - 1; ++j)
	{
	    const uchar* previous = myImage.ptr<uchar>(j - 1);
	    const uchar* current  = myImage.ptr<uchar>(j    );   //pega as linhas atual, de baixo e de cima
	    const uchar* next     = myImage.ptr<uchar>(j + 1);
    
	    uchar* output = Result.ptr<uchar>(j);
    
	    for(int i = nChannels; i < nChannels * (myImage.cols - 1); ++i)  //pega as colunas que pertence á mesma cor entre os planos
	    {
		*output++ = saturate_cast<uchar>(5 * current[i]  	     //faz as operações para um mesmo plano
			    -current[i - nChannels] - current[i + nChannels] - previous[i] - next[i]);
	    }
	}
    
	Result.row(0).setTo(Scalar(0));				//seta as bordas de cada plano para zero. Os métodos row() e col() acessam todos os planos ao mesmo tempo
	Result.row(Result.rows - 1).setTo(Scalar(0));
	Result.col(0).setTo(Scalar(0));
	Result.col(Result.cols - 1).setTo(Scalar(0));
// filter2D(). Criando máscara (kernel) e aplicando filtro de correlação.  
	Mat kern = (Mat_<char>(3,3) <<  0, -1,  0,  //cria kernel
				       -1,  5, -1,
                                        0, -1,  0);
	filter2D(I,		//imagem de entrada
		 K, 		//imagem de saída
	 I.depth(),		//profundidade da imagem de entrada
	     kern); 		//máscara usada
// Looping - alterar contraste e brilho (usando image.at<Vec3b>(y,x)[c])
	for( int y = 0; y < image.rows; y++ ){  //linhas
	  for( int x = 0; x < image.cols; x++ ){  //colunas
	    for( int c = 0; c < 3; c++ ){ 	    //canais
	      new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( alpha*( image.at<Vec3b>(y,x)[c] ) + beta ); //mesmo acessando canais em separado usamos Vec3b. 
	    }
	  }
	}
// convertTo() Acessa cada pixel fazendo a seguinte operação: new_image = a*image + beta. 
	image.convertTo(new_image, //imagem de saída
			       -1, //tipo/profundidade da imagem de saída. Negativo significa que queremos o mesmo da entrada
		            alpha, //multiplicador
		            beta); //adicionador
// Desenhar linha - line() 
	int thickness = 2;
	int lineType = 8;
	
	line(		img,	//imagem onde a linha será desenhada
		      start,	//ponto de início
			end,	//ponto de fim
	  Scalar( 0, 0, 0 ),	//Cor da linha em BGR (preto)
		  thickness,	//espessura da linha
		 lineType );	//tipo da linha - 8 conectada
// Desenhar elipse - ellipse()
	int thickness = 2;
	int lineType = 8;

	ellipse(	img,	//imagem onde elipse será desenhada
      Point( w/2.0, w/2.0 ),	//ponto de centro da elipse
      Size( w/4.0, w/16.0 ),	//dimensões da bounding box que engloba a elipse
		      angle,	//rotação da elipse em graus
			  0,	//se estende no arco que vai de 0 graus
			360,	//até 360 graus
	Scalar( 255, 0, 0 ),	//Cor da elipse em BGR (azul)
		  thickness,	//espessura do linha
		 lineType );	//tipo do linha - 8 conectada
// Desenhar círculo preenchido - circle()
	int thickness = -1;
	int lineType = 8;

	circle( 	img,	//imagem onde círculo será desenhado
		     center,	//ponto de centro do círculo
		     w/32.0,	//raio do círculo
	Scalar( 0, 0, 255 ),	//Cor do círculo em BGR (vermelho)
		  thickness,	//espessura da linha (-1 desenha preenchido)
		 lineType );	//tipo do linha - 8 conectada
// Desenhar polígono preenchido - fillPoly()
	int lineType = 8;

	/** Create some points */
	Point rook_points[1][20];
	rook_points[0][0] = Point( w/4.0, 7*w/8.0 );
	rook_points[0][1] = Point( 3*w/4.0, 7*w/8.0 );
	rook_points[0][2] = Point( 3*w/4.0, 13*w/16.0 );
	rook_points[0][3] = Point( 11*w/16.0, 13*w/16.0 );
	rook_points[0][4] = Point( 19*w/32.0, 3*w/8.0 );
	rook_points[0][5] = Point( 3*w/4.0, 3*w/8.0 );
	rook_points[0][6] = Point( 3*w/4.0, w/8.0 );
	rook_points[0][7] = Point( 26*w/40.0, w/8.0 );
	rook_points[0][8] = Point( 26*w/40.0, w/4.0 );
	rook_points[0][9] = Point( 22*w/40.0, w/4.0 );
	rook_points[0][10] = Point( 22*w/40.0, w/8.0 );
	rook_points[0][11] = Point( 18*w/40.0, w/8.0 );
	rook_points[0][12] = Point( 18*w/40.0, w/4.0 );
	rook_points[0][13] = Point( 14*w/40.0, w/4.0 );
	rook_points[0][14] = Point( 14*w/40.0, w/8.0 );
	rook_points[0][15] = Point( w/4.0, w/8.0 );
	rook_points[0][16] = Point( w/4.0, 3*w/8.0 );
	rook_points[0][17] = Point( 13*w/32.0, 3*w/8.0 );
	rook_points[0][18] = Point( 5*w/16.0, 13*w/16.0 );
	rook_points[0][19] = Point( w/4.0, 13*w/16.0) ;
      
	const Point* ppt[1] = { rook_points[0] };
	int npt[] = { 20 };
      
	fillPoly( 	img,	//imagem onde polígono será desenhado
			ppt,	//conjunto de pontos que representam os vértices do polígono
			npt,	//número total de vértices que será desenhado
			  1,	//quantidade de polígonos desenhados
	Scalar(255,255,255),	//Cor do polígono em BGR (branco)
		  lineType );	//tipo do linha - 8 conectada
// Desenhar retângulo - rectangle()
	rectangle(rook_image,	//imagem onde retângulo será desenhado
	 Point( 0, 7*w/8.0 ),	//ponto de vértice 1 oposto ao
		Point( w, w),	//ponto de vértice 2
       Scalar( 0, 255, 255 ),	//Cor do retângulo em BGR (amarelo)
	                  -1,	//espessura da linha (-1 desenha preenchido)
			 8 );	//tipo do linha - 8 conectada
// Números Aleatórios - Criação de um objeto Random Number Generator (RNG):RNG implementa um gerador de números aleatórios.
// Com rng.uniform(a, b), geramos uma distribuição uniforme entre os valores a e b (inclusivo a, exclusivo b).
	RNG rng( 0xFFFFFFFF );
	pt1.x = rng.uniform( x_1, x_2 );
	pt1.y = rng.uniform( y_1, y_2 );
// Cores aleatórias - implementação de função
	randomColor(rng); //chamando função
	
	static Scalar randomColor( RNG& rng ){ //implementação da função
	    int icolor = (unsigned) rng;
	    return Scalar( icolor&255, (icolor>>8)&255, (icolor>>16)&255 );
	}
// Aplicar texto em janela com putText()
	putText( 	image,  	//imagem onde será introduzido o texto
     "Testing text rendering",  	//texto que será introduzido
			  org,  	//canto inferior esquerdo do texto será localizado no ponto org
	      rng.uniform(0,8), 	//tipo da fonte é um valor inteiro aleatório no intervalo: [0,8)
   rng.uniform(0,100)*0.05+0.1, 	//escala da fonte é: [0.1,5.1)
	      randomColor(rng), 	//Cor do texto (aleatória)
	    rng.uniform(1, 10), 	//espessura: [1,10)
		     lineType); 	//tipo de linha
//getTextSize() Obtém tamanho do texto e armazena na variável do tipo Size
	Size textsize = getTextSize("OpenCV forever!", CV_FONT_HERSHEY_COMPLEX, 3, 5, 0);
// Método p/ retirar todas as cores da imagem em um looping
	for( int i = 0; i < 255; i++){
	  image2 = image - Scalar::all(i); //subtrai todos os valores de cada canal da imagem, operação - já vem com saturate_cast embutido
	}
// Transformada de Fourier
	'1. Expandir a imagem para um tamanho ideal'
	//getOptimalDFTSize() retorna o tamanho ideal da imagem e copyMakeBorder() expande as fronteiras da imagem:
		Mat padded;                            
		int m = getOptimalDFTSize( I.rows );
		int n = getOptimalDFTSize( I.cols );   //expande imagem de entrada para tamanho ótimo
		copyMakeBorder(		I, 	//imagem_de_entrada
				   padded,	//imagem_de_destino
					0, 	//padding para cima
			       m - I.rows,	//padding para baixo
					0, 	//padding para esquerda
			       n - I.cols, 	//padding para direita
			  BORDER_CONSTANT, 	//tipo da borda (BORDER_CONSTANT = mesmo valor para todos os pixels do padding)
			  Scalar::all(0));   	//valor da borda se o tipo for BORDER_CONSTANT. Setado para zero (preto)
	'2. Criar espaço tanto para os valores complexos quanto para os reais'
	//Primeiro criamos uma Mat planes[] que vai conter duas imagens, uma real e uma imaginária. Após a transformada, teremos valores reais e valores
	//complexos num range de float. Então convertemos a imagem padded para float (parte real) e criamos uma de mesmo tamanho tipo float com zeros (parte imaginária)
	//Com merge(), unimos as duas imagens em uma só com 2 canais e chamamos o resultado de complexI.
		Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
		Mat complexI;
		merge(		planes, 	//vetor de imagens que vão ser merged
				     2, 	//números de elementos no vetor de matrizes (deve ser maior de zero) 
			     complexI);		//imagem de saída com qtd de canais definida pela quantidade de imagens do vetor de imagens
	'3. Faz a transformada discreta de Fourier'
	//Colocaremos o resultado na própria imagem de entrada. dft() faz a transformada num vetor (1D) ou matriz (2D) de floats
		dft(complexI, complexI);            // this way the result may fit in the source matrix
	'4. Transformar os valores reais e complexos para magnitude'
	//split() faz o contrário de merge(). Divide uma imagem de canais e guarda num vetor de imagens correspondente.
	//magnitude() faz o cálculo da maginitude entre planes[0] e planes[1] e armazena em planes[0]
		split(complexI, planes);                   // planes[0] = Re(DFT(I)), planes[1] = Im(DFT(I))
		magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
		Mat magI = planes[0];			   //a magnitude é então armazenada na imagem magI
	'5. Mudar para uma escala logarítmica'
	//Aqui somamos 1 á todos os valores da matriz de magnitude para impedir tirar log de zero, lembrando que a matriz de magnitude é toda positiva, pois representam
	//distâncias.
		magI += Scalar::all(1); 
		log(magI, magI);		//tira o log e armazena  o resultado na mesma imagem
		
	'6. Desfazer padding e rearranjar quadrantes'
		magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));	 //Desfaz padding feito inicialmente usando rect
		int cx = magI.cols/2;		//obtém coordenadas do centro da imagem
		int cy = magI.rows/2;

		Mat q0(magI, Rect(0, 0, cx, cy));   // Top-Left - Cria um ROI por quadrante
		Mat q1(magI, Rect(cx, 0, cx, cy));  // Top-Right
		Mat q2(magI, Rect(0, cy, cx, cy));  // Bottom-Left
		Mat q3(magI, Rect(cx, cy, cx, cy)); // Bottom-Right

		Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);

		q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
		q2.copyTo(q1);	
		tmp.copyTo(q2);
	'7. Normalizar'
	//normalize() Normaliza os valores para efeito de visualização. Transforma a matriz de valores float numa matriz visualizável com valores float entre 0 e 1.
		normalize(		magI, 	//imagem de entrada
					magI, 	//imagem de saída
					   0, 	//limite inferior
					   1, 	//limite superior
				  CV_MINMAX);	//tipo de normalização
//Filtros de suavização de imagens - blur(), GaussianBlur(), medianBlur() e bilateralFilter()
	'1. Filtro de caixa normalizado'
	//Faz filtragem com blur()
		  blur( 	src, 	//imagem_de_entrada
				dst, 	//imagem_de_saída
		       Size( i, i ), 	//Size( w,h ): Define o tamanho do kernel usado(w de largura e h de altura)
		     Point(-1,-1) );	//Ponto do kernel a ser avaliado. -1s significam centro
	'2. Filtro Gaussiano'
	//Faz filtragem com GaussianBlur()
		  GaussianBlur( src,	//imagem_de_entrada
				dst, 	//imagem_de_saída
		       Size( i, i ), 	//Size( w,h ): Define o tamanho do kernel usado(w de largura e h de altura)
				  0,	//Desvio padrão em x. Zero implica que é calculado automaticamente de acordo com o tamanho do kernel 
				0 );	//Desvio padrão em y.
	'3. Filtro de Mediana'
	//Faz filtragem com medianBlur()
		  medianBlur ( 	src,	//imagem_de_entrada
				dst, 	//imagem_de_saída
				i );	//Tamanho do kernel(apenas um, porque nós usamos uma janela quadrada).Deve ser ímpar
	'4. Filtro Bilateral'
	//Faz filtragem com bilateralFilter()
		  bilateralFilter( src,	//imagem_de_entrada
				   dst,	//imagem_de_saída 
				     i,	//O diâmetro de cada vizinhança do pixel.
				   i*2,	//Desvio padrão no espaço de cor.
				 i/2 );	//Desvio padrão no espaço de coordenadas (em termos de pixels)

//Cria Trackbar com createTackbar()
	createTrackbar("Operator:\n 0: Opening - 1: Closing \n 2: Gradient - 3: Top Hat \n 4: Black Hat",	//nome da trackbar criada
											     window_name, 	//nome da janela usada como pai da trackbar
											 &morph_operator, 	//Variável ponteiro p/ inteiro q/ vai refletir a pos. do slider
											    max_operator,	//Posição máxima do slider. Ele sempre começa do "0".
										 Morphology_Operations );	/*Ponteiro para a função a ser chamada toda vez que a posição 
														do slider mudar. Esta função deve ser um protótipo como 
														void Foo(int, void *); , Onde o primeiro parâmetro é a posição 
														do trackbar e o segundo parâmetro é o de dados do usuário*/
//Operações morfológicas - erode(), dilate() e morphologyEx()
	'1. Erosão'
	//Criamos o efeito de erosão usando as funções getStructuringElement() e erode()
	    int erosion_type;
	    if( erosion_elem == 0 ){ erosion_type = MORPH_RECT; }
	    else if( erosion_elem == 1 ){ erosion_type = MORPH_CROSS; }
	    else if( erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }
	    
	    Mat element = getStructuringElement( erosion_type,	//forma do elemento estruturante (MORPH_RECT,MORPH_CROSS,MORPH_ELLIPSE)
	          Size( 2*erosion_size + 1,2*erosion_size+1 ),	//Tamanho do elemento estruturante
                        Point( erosion_size, erosion_size ) );	//Ponto de âncora dentro do elemento.(-1,-1) significa no centro.
	    // Aplica operação de erosão
	    erode( 					  src,	//imagem_de_entrada
						  erosion_dst,	//imagem_de_saída
						    element );	//kernel usado para fazer a operação -> definido em getStructuringElement().
	'2. Dilatação'
	//Criamos o efeito de dilatação usando as funções getStructuringElement() e dilate()
	    int dilation_type;
	    if( dilation_elem == 0 ){ dilation_type = MORPH_RECT; }
	    else if( dilation_elem == 1 ){ dilation_type = MORPH_CROSS; }
	    else if( dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }
	  
	    Mat element = getStructuringElement(dilation_type,	//forma do elemento estruturante (MORPH_RECT,MORPH_CROSS,MORPH_ELLIPSE)
                Size(2*dilation_size + 1, 2*dilation_size+1 ),	//Tamanho do elemento estruturante
                      Point( dilation_size, dilation_size ) );	//Ponto de âncora dentro do elemento.(-1,-1) significa no centro.
	   // Aplica operação de dilatação
	   dilate( 					  src,	//imagem_de_entrada
					         dilation_dst, 	//imagem_de_saída
						    element );	//kernel usado para fazer a operação -> definido em getStructuringElement().
	'3. Abertura, 4. Fechamento, 5. Gradiente Morfológico, 6. Top Hat, 7. Black Hat'
	//Criamos estes efeitos morfológicos usando getStructuringElement() e morphologyEx()
	    Mat element = getStructuringElement(  morph_elem,	//forma do elemento estruturante (MORPH_RECT,MORPH_CROSS,MORPH_ELLIPSE)
		    Size( 2*morph_size + 1, 2*morph_size+1 ),	//Tamanho do elemento estruturante
			   Point( morph_size, morph_size ) );	//Ponto de âncora dentro do elemento.(-1,-1) significa no centro.
	    
	    // Apply the specified morphology operation
	    morphologyEx(				 src,	//imagem_de_entrada
							 dst,	//imagem_de_saída
						   operation,	//Tipo de operação morfológica. Temos cinco tipos:
									      'Opening: MORPH_OPEN : 2'
									      'Closing: MORPH_CLOSE: 3'
									      'Gradient: MORPH_GRADIENT: 4'
									      'Top Hat: MORPH_TOPHAT: 5'
									      'Black Hat: MORPH_BLACKHAT: 6'
						   element );	//kernel usado para fazer a operação -> definido em getStructuringElement().
//Pirâmedes de imagens - usando pyrUp() e pyDown().
	'1. Upsampling = aumentar tamanho da imagem - máscara Gaussiana'
	    pyrUp( 				tmp,	//imagem_currente. É inicializada com a imagem original src;
						dst,	//imagem_destino.
		      Size( tmp.cols*2, tmp.rows*2 );	//tamanho da mudança (dobro), aplicada na imagem_destino.
	'2. Downsampling = diminuir tamanho da imagem - máscara Gaussiana'
	    pyrDown( 				tmp,	//imagem_currente. É inicializada com a imagem original src;
						dst,	//imagem_destino.
		     Size( tmp.cols/2, tmp.rows/2 );	//tamanho da mudança (metade), aplicada na imagem_destino.
//Thresholding
	threshold(		 src_gray,	//imagem_entrada
				      dst,	//imagem_destino
			  threshold_value,	//o valor de limiar
			 max_BINARY_value,	//valor máximo usado no thresholding
			 threshold_type );	/*1 dos 5 tipos de Thresholding.*/		0: Binary
												1: Binary Inverted
												2: Threshold Truncated
												3: Threshold to Zero
												4: Threshold to Zero Inverted
//Como fazer o próprio filtro linear - filter2D()
	//cria um kernel, no caso é um filtro linear de 1's normalizado.
	kernel = Mat::ones(		 kernel_size,	//n_linhas
					 kernel_size,	//n_colunas
		      			      CV_32F)	//tipo_elemetos
		  / (float)(kernel_size*kernel_size);	//normaliza matriz
	
	filter2D(		src,	//imagem_entrada
				dst,	//imagem_saída
			    ddepth ,	//profundidade da imagem_saída. -1 significa mesma profundidade de imagem_entrada
			     kernel,	//kernel criado com cv::Mat
			     anchor,	//posição da âncora no kernel. Point(-1, -1) indica centro.
			      delta,	//Valor a ser adicionado a cada pixel durante a convolução. Padrão é 0.
		   BORDER_DEFAULT );	//valor padrão.
//Bordas e padding - copyMakeBorder()
	//Criamos os limites da borda para 5% da imagem original
	top = (int) (0.05*src.rows); bottom = (int) (0.05*src.rows);
	left = (int) (0.05*src.cols); right = (int) (0.05*src.cols);
	//criamos cores aleatórias
	value = Scalar( rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255) );
	
	copyMakeBorder( 		src,	//imagem_entrada
					dst,	//imagem_destino
					top,	//tamanho em pixels da borda do topo
				     bottom,	//tamanho em pixels da borda de baixo
				       left,	//tamanho em pixels da borda da esquerda
				      right,	//tamanho em pixels da borda da direita
				 borderType,	//tipo da borda. BORDER_CONSTANT ou BORDER_REPLICATE
				    value );	//define a cor a ser usada se BORDER_CONSTANT.
// Operador de Sobel - Sobel() ou Scharr(kernel 3x3)
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;

	//...realiza suavização como GaussianBlur()..
	
	/// Gradient X
	//Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
	Sobel(		 src_gray,	//imagem_entrada (um CV_8U - char 8-bits sem sinal)
			   grad_x,	//imagem_saída, o mesmo tamanho e o mesmo número de canais de imagem_entrada.
			   ddepth,	//profundidade da imagem_saída. (uma CV_16S - int 16-bits com sinal) - p/ evitar overflow, não truncar as derivadas.
				1,	//ordem da derivada em x
				0,	//ordem da derivada em y
				3,	//tamanho do kernel de sobel (1,3,7 ou 11) - argumento que não é necessário na Scharr()
			    scale,	//fator de escala opcional para os valores computados nas derivadas; por padrão,escala não é aplicada.
			    delta,	//valor delta opcional que é acrescentado aos resultados antes de armazená-los em imagem_saída.
		 BORDER_DEFAULT );	//tipo de borda.
	/// Gradient Y
	//Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
	Sobel( src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT );
	
	//Convertemos nossos resultados parciais de volta para CV_8U
	convertScaleAbs( grad_x, abs_grad_x );
	convertScaleAbs( grad_y, abs_grad_y );
	
	//Tentamos aproximar o gradiente adicionando dois gradientes direcionais
	addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );
//Operador laplaciano - Laplacian()
	Mat abs_dst;
	
	//...realiza suavização como GaussianBlur()..
	
	Laplacian( 	src_gray,	//imagem_entrada (um CV_8U - char 8-bits sem sinal)
			     dst,	//imagem_saída, o mesmo tamanho e o mesmo número de canais de imagem_entrada.
			  ddepth,	//profundidade da imagem_saída. (uma CV_16S - int 16-bits com sinal) - p/ evitar overflow, não truncar as derivadas.
		     kernel_size,	//tamanho do kernel do operador Sobel a ser aplicada internamente.
			   scale,	//fator de escala opcional para os valores computados nas derivadas; por padrão,escala não é aplicada.
		           delta,	//valor delta opcional que é acrescentado aos resultados antes de armazená-los em imagem_saída.
		BORDER_DEFAULT );	//tipo de borda.
	
	//Converte a saída do operador de Laplace para uma imagem CV_8U
	convertScaleAbs( dst, abs_dst );
// Operador Canny - Canny()
	//primeiro borramos a imagem com um kernel 3x3 e armazenamos em detected_edges 
	blur( src_gray, detected_edges, Size(3,3) );
	
	Canny( 			detected_edges,		//imagem_de_entrada (níveis de cinza).
				detected_edges,		//imagem_de_saída (mesmo tamanho da entrada).
				  lowThreshold,		//limiar inferior da histerese.
			    lowThreshold*ratio,		//limiar superior da histerese (setado como 3 vezes - sugerido por Canny).
				 kernel_size );		//tamanho do kernel para as operações de Sobel usadas.
	
	//Preenchemos imagem de saída com zeros
	dst = Scalar::all(0);
	
	//Usamos copyTo() para mapear apenas as áreas da imagem que são identificadas como bordas (em um fundo preto). Copia src em dst. Entretanto, isto só vai copiar os 
	//pixels nos locais onde os valores são diferentes de zero. Como a saída do operador Canny são contornos das bordas em um fundo preto, o resultado em dst sará preto 
	//em toda a área mas com as bordas detectadas.
	src.copyTo( 		dst,	//matriz_saída
		    detected_edges);	//máscara de operação.Seus elementos diferentes de zero indicam que os elementos da matriz de entrada precisam ser copiados.
// Transformada de linha de Hough - detectar linhas retas
	//Primeiro detectamos bordas com Canny
	Canny(src, dst, 50, 200, 3);
	
	'1. Transformada de linha de Hough padrão - HoughLines()'
	      //vetor float com 2 elementos por vez
	      vector<Vec2f> lines;
	      
	      //Dá como resultado um vetor de casais (theta,r(theta))
	      HoughLines(		dst,	//imagem_entrada_saída binária grayscale.
				      lines,	//Um vetor que vai armazenar os parâmetros (r,theta) das linhas detectadas.
					  1,	//rho: A resolução do parâmetro r em pixels. Usamos 1 pixel.
				  CV_PI/180,	//theta: A resolução do parâmetro theta em radianos. Usamos 1 grau (CV_PI / 180).
				        100,	//threshold: limiar mínimo para ser considerado uma reta.
					  0,	//srn: Para a multi-escala transformada de Hough, é um divisor para a resolução de distância de rho - 0 padrão.
					0 );	//stn: Para a multi-escala transformada de Hough, é um divisor para a resolução de distância de theta- 0 padrão.
	      
	      //Mostra o resultado desenhando as linhas
	      for( size_t i = 0; i < lines.size(); i++ ){
		float rho = lines[i][0], theta = lines[i][1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a*rho, y0 = b*rho;
		pt1.x = cvRound(x0 + 1000*(-b));
		pt1.y = cvRound(y0 + 1000*(a)); //cvRound converte um float para o int mais próximo
		pt2.x = cvRound(x0 - 1000*(-b));
		pt2.y = cvRound(y0 - 1000*(a));
		line( cdst, pt1, pt2, Scalar(0,0,255), 3, CV_AA); //CV_AA significa anti-aliasing
	      }
	'2. Transformada de linha de Hough probabilística - HoughLinesP()'
	      //vetor int com 4 elementos por vez
	      vector<Vec4i> lines;
	      
	      //Mais eficiente que HoughLines(). Dá como saída os extremos das linhas detectados (x0,y0,x1,y1)
	      HoughLinesP(		  dst,		//imagem_entrada_saída binária grayscale.
					lines,		//Um vetor que vai armazenar os parâmetros (x0,y0,x1,y1) das linhas detectadas.
				            1,		//rho: A resolução do parâmetro r em pixels. Usamos 1 pixel.
		                    CV_PI/180,		//theta: A resolução do parâmetro theta em radianos. Usamos 1 grau (CV_PI / 180).
		                           50,		//threshold: limiar mínimo para ser considerado uma reta.
		                           50,		//minLinLength: O número mínimo de pontos que podem formar uma linha. Linhas com menos serão desconsideradas.
		                         10 );		//maxLineGap: gap máximo entre dois pontos para ainda ser considerada a mesma linha.
	      
	      //Mostra o resultado desenhando as linhas
	      for( size_t i = 0; i < lines.size(); i++ ){
		Vec4i l = lines[i];
		line( cdst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, CV_AA);
	      }
// Transformada de Círculo de Hough - detectar círculos - HoughCircles()
	//Aplicamos um Gaussian Blur para reduzir o ruído e evitar a detecção círculo falso
	GaussianBlur( src_gray, src_gray, Size(9, 9), 2, 2 );
	
	//vetor float com 3 elementos por vez
	vector<Vec3f> circles;

	//Faz a transformada
	HoughCircles(			 src_gray,	//imagem_entrada (grayscale).
					  circles,	//Um vector que armazena conjuntos de três valores:(xc,yc,r) para cada círculo detectado.
			        CV_HOUGH_GRADIENT,	//Definir o método de detecção. Atualmente, esse é o único disponível em OpenC.
						1,	//dp: A razão inversa de resolução. (o acumulador tem a mesma resolução que a imagem de entrada). 
				  src_gray.rows/8,	//min_dist: Distância mínima entre centros detectados.
					      200,	//param_1: Limite superior para o detector de bordas de Canny interno.
					      100,	//param_2: Isto é o limiar do acumulador para os centros de círculos na fase de detecção.
						0,	//raio mínimo do círculo. 0 se não se sabe.
					      0 );	//raio máximo do círculo. 0 se não se sabe.
	
	//Desenha os círculos detectados
	for( size_t i = 0; i < circles.size(); i++ ){
	  Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
	  int radius = cvRound(circles[i][2]);
	  // circle center
	  circle( src, center, 3, Scalar(0,255,0), -1, 8, 0 );
	  // circle outline
	  circle( src, center, radius, Scalar(0,0,255), 3, 8, 0 );
	}
//Remapeamento - remap()
	//Entrada, destino e 2 matrizes de mapeamento
	Mat src, dst;
	Mat map_x, map_y;
	
	//As matrizes de mapeamento são 4 bytes com sinal float com 1 canal
	map_x.create( src.size(), CV_32FC1 );
	map_y.create( src.size(), CV_32FC1 );
	
	update_map(); //função que remapeia os locais dos pixeis do eixo x (map_x) e do eixo y (map_y) e armazanam nestas matrizes (função manual)
	remap( 			src,	//imagem_entrada.
				dst,	//imagem_saída (mesmo tipo de imagem_entrada).
			      map_x,	//A função de mapeamento na direção x. É equivalente à primeira coordenada de h(i,j).
			      map_y,	//A função de mapeamento na direção y. Note-se que map_y e map_x são ambos do mesmo tamanho de src
		    CV_INTER_LINEAR,	//interpolation: O tipo de interpolação a usar para pixels não-inteiros. Este é, por padrão.
		    BORDER_CONSTANT,	//borderMode: Método de extrapolação de pixel. É o padrão.
		    Scalar(0,0, 0));	//borderValue: Valor utilizado no caso de BORDER_CONSTANT. Por padrão, ele é 0.
	
	//função update_map() ..altera as configurações das matrizes map_x e map_y
	case 0://mapeamento da imagem original para o centro da tela
          if( i > src.cols*0.25 && i < src.cols*0.75 && j > src.rows*0.25 && j < src.rows*0.75 )
            {
              map_x.at<float>(j,i) = 2*( i - src.cols*0.25 ) + 0.5 ; //pega a interpolação no eixo x e armazena os números da localização do pixel em x
              map_y.at<float>(j,i) = 2*( j - src.rows*0.25 ) + 0.5 ; //pega a interpolação no eixo y e armazena os números da localização do pixel em y
             }
          else
            { map_x.at<float>(j,i) = 0 ; //se não for o centro, recebe o valor correspondente ao primeiro pixel da imagem original.
              map_y.at<float>(j,i) = 0 ;
            }
              break;
        case 1://mapeamento que inverte eixo y
              map_x.at<float>(j,i) = i ;
              map_y.at<float>(j,i) = src.rows - j ;
              break;
        case 2://mapeamento que inverte eixo x
              map_x.at<float>(j,i) = src.cols - i ;
              map_y.at<float>(j,i) = j ;
              break;
        case 3://mapeamento que inverte os dois eixos (combinação dos dois anteriores)
              map_x.at<float>(j,i) = src.cols - i ;
              map_y.at<float>(j,i) = src.rows - j ;
              break;
//Transformações Afins - getAffineTransform() | getRotationMatrix2D() e  warpAffine()
	'1. Usando 3 pontos'
	    Point2f srcTri[3];
	    Point2f dstTri[3]; //pontos que definem a transformação afim
	    
	    Mat warp_mat( 2, 3, CV_32FC1 ); //Matriz de transformação - equivalente à matriz M
	    Mat warp_dst; //imagem onde será armazenada a primeira transformação (proveniente da matriz de transformação warp_mat)
	
	    //Definição dos pontos para a transformação
	    srcTri[0] = Point2f( 0,0 );			//pontos na imagem de entrada
	    srcTri[1] = Point2f( src.cols - 1, 0 );
	    srcTri[2] = Point2f( 0, src.rows - 1 );
	    
	    dstTri[0] = Point2f( src.cols*0.0, src.rows*0.33 );		//pontos na imagem de saída equivalentes com os da imagem de entrada
	    dstTri[1] = Point2f( src.cols*0.85, src.rows*0.25 );
	    dstTri[2] = Point2f( src.cols*0.15, src.rows*0.7 );
	    
	    /// Geta a matriz 2x3 da transformação Afim.
	    warp_mat = getAffineTransform( 		srcTri,		//pontos de entrada da transformação 
						      dstTri );		//pontos de saída
    
	    /// Aplica a transformação Afim na imagem de entrada e usando a matriz 2x3 obtida por getAffineTransform()
	    warpAffine( 		src,	//imagem_entrada
				   warp_dst,	//imagem_saída
				   warp_mat,	//matriz de transformação (2x3)
			   warp_dst.size());	//dimensão desejada da imagem_saída
	'2. Rotação após a transformação anterior'
	    Mat rot_mat( 2, 3, CV_32FC1 ); //Matriz de rotação - equivalente à matriz M
	    
	    Mat warp_rotate_dst; //imagem onde será armazenada a transformação da rotação (proveniente da matriz de transformação rot_mat)
	  
	    /// Computa a matriz de rotação. Precisamos saber:
	    Point center = Point( warp_dst.cols/2, warp_dst.rows/2 );		//O centro em relação ao qual a imagem irá girar.
	    double angle = -50.0;						//O ângulo a ser rodado. Em OpenCV um ângulo positivo é anti-horário.
	    double scale = 0.6;							//Um fator de escala.
	    
	    /// Geta a matriz 2x3 de rotação com as especificações acima
	    rot_mat = getRotationMatrix2D(		center,		//O centro em relação ao qual a imagem irá girar.
							 angle,		//O ângulo a ser rodado.
						       scale );		//Um fator de escala.
	    
	    /// Aplica a transformação Afim de rotação na imagem warp_dst e usando a matriz 2x3 obtida por getRotationMatrix2D()
	    warpAffine( warp_dst, warp_rotate_dst, rot_mat, warp_dst.size() );
//Equalização de histograma - equalizeHist()
	equalizeHist( src, dst );
//Cálculo de histograma - calcHist()
	'1. Estabelece número de bins (5, 10...)'
	    int histSize = 256; //de 0 a 255
	'2. Define o intervalo de valores (como dissemos, entre 0 e 255)'
	    float range[] = { 0, 256 } ; //o limite superior é exclusivo
	    const float* histRange = { range };
	'3. Queremos que nossos bins tenham o mesmo tamanho (uniforme) e para limpar os histogramas no início, então' 
	    bool uniform = true; bool accumulate = false;
	'4. Por fim, nós criamos os objetos Mat para salvar nossas histogramas. Criação de 3 (um para cada plano):'
	    Mat b_hist, g_hist, r_hist;
	'5. Computa o histograma'
	    calcHist( 		&bgr_planes[0],		//imagem de entrada.
					     1,		//numero de imagens de entrada.
					     0,		//dims: lista de parâmetros usados para computar o histograma.Neste caso, é apenas a intensidade, bastando escrever 0.
					 Mat(),		//Máscara opcional. Se a matriz não está vazia,deve ser uma matriz do mesmo tamanho que as imagens [i] de 8 bits.
					b_hist,		//O objecto Mat onde o histograma vai ser armazenado
					     1,		//A dimensionalidade do histograma.
				     &histSize,		//nro de bins a ser usado em cada dimensão.
				    &histRange,		//range de valores a serem medidos para cada dimensão.
				       uniform,		//O tamanho dos bins é o mesmo.
				   accumulate);		//O histograma é limpado no início.
	'6. Cria uma imagem para mostrar os histogramas'
	    int hist_w = 512; int hist_h = 400;
	    int bin_w = cvRound( (double) hist_w/histSize );
	    Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );
	'7. Observe que antes de desenhar, primeiro normalizamos o histograma para que seus valores estejam na faixa indicada pelos parâmetros introduzidos para a imagem'
	    normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
	    normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
	    normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
	'8. Desenha para cada imagem'
	    for( int i = 1; i < histSize; i++ ){
		line(histImage,Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1))),Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))),Scalar(255,0,0),2,8,0);
		line(histImage,Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1))),Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))),Scalar(0,255,0),2,8,0);
		line(histImage,Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1))),Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))),Scalar(0,0,255),2,8,0);
	    }
//Comparação de Histograma - compareHist()
	'1. Inicializar os argumentos para calcular os histogramas (bins, ranges e channels H (hue) e S (saturation)).'
	    /// Usando 50 bins para hue e 60 para saturation
	    int h_bins = 50; int s_bins = 60;
	    int histSize[] = { h_bins, s_bins };

	    // hue varia de 0 a 179, saturação de 0 a 255
	    float h_ranges[] = { 0, 180 };
	    float s_ranges[] = { 0, 256 };

	    const float* ranges[] = { h_ranges, s_ranges };

	    // Usa o 0-th e 1-st channels
	    int channels[] = { 0, 1 };
	    
	'2. Criar os objetos MatND para armazenar os histogramas'
	    MatND hist_base;
	    MatND hist_half_down;
	    MatND hist_test1;
	    MatND hist_test2;
	'3. Calcula o histograma de cada imagem'
	    calcHist( &hsv_base, 1, channels, Mat(), hist_base, 2, histSize, ranges, true, false );
	    normalize( hist_base, hist_base, 0, 1, NORM_MINMAX, -1, Mat() );
		      ...
	'4. Aplicam-se sequencialmente os quatro métodos de comparação entre o histograma de uma imagem base (hist_base) e os outros histogramas'
	    double base_half = compareHist( hist_base, hist_half_down, compare_method );	// (0) CV_COMP_CORREL Correlation
												// (1) CV_COMP_CHISQR Chi-Square
												// (2) CV_COMP_INTERSECT Intersection
												// (3) CV_COMP_BHATTACHARYYA Bhattacharyya distance
												// (4) CV_COMP_HELLINGER Synonym for CV_COMP_BHATTACHARYYA
//Back Projection - calcBackProject(_
	'1. Para este tutorial, vamos usar apenas o valor Hue para o nosso histograma 1-D'
	    hue.create( hsv.size(), hsv.depth() );
	    int ch[] = { 0, 0 };
	    mixChannels( 	&hsv,	//matriz origem a partir do qual os canais serão copiados.
				   1,	//número de matrizes origem.
				&hue,	//A matriz de destino dos canais copiados.
				   1,	//número de matrizes destino.
				  ch,	//matriz pares de índice que indica como os canais são copiados. Neste caso, o Hue (0) canal do HSV está sendo copiado para o 0 canal 
					//de Hue (1 canal).
				 1 );	//Número de pares de índice.
	'2. Realiza o Back Projection'
	    MatND backproj;
	    calcBackProject( 		&hue,	//imagem_entrada
					   1,	//número de imagens_entrada
					   0,	//Lista dos canais DIMS utilizado para calcular o histograma
					hist,	//máscara opcional.
				    backproj,	//O objecto Mat onde o histograma vai ser armazenado
				     &ranges,	//A dimensionalidade do histograma.
					   1,	//nro de bins a ser usado em cada dimensão.
				      true );	//
	'3. Mostra histograma 1-D'
	    int w = 400; int h = 400;
	    int bin_w = cvRound( (double) w / histSize );
	    Mat histImg = Mat::zeros( w, h, CV_8UC3 );

	    for( int i = 0; i < bins; i ++ )
	      rectangle( histImg, Point( i*bin_w, h ), Point( (i+1)*bin_w, h - cvRound( hist.at<float>(i)*h/255.0 ) ), Scalar( 0, 0, 255 ), -1 );

	    imshow( "Histogram", histImg );
//Matching de templates -  matchTemplate() e minMaxLoc()
	//cria a matriz-resultado (imagem), com o tamanho e tipo adequados.
	int result_cols =  img.cols - templ.cols + 1;
	int result_rows = img.rows - templ.rows + 1;
	result.create( result_cols, result_rows, CV_32FC1 );
	
	//Realiza a operação de casamento da imagem-modelo com a imagem_entrada
	matchTemplate(			img,	//imagem-entrada
				      templ,	//imagem-modelo
				     result,	//imagem-resultado
			      match_method);	/*função de matching usada				'1. CV_TM_SQDIFF'
													'2. CV_TM_SQDIFF_NORMED'
													'3. CV_TM_CCORR'
													'4. CV_TM_CCORR_NORMED'
													'5. CV_TM_CCOEFF'
													'6. CV_TM_CCOEFF_NORMED'					*/
	//Normaliza os resultados
	normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );
	
	//Nós localizamos os valores mínimos e máximos no resultado da matriz R usando minMaxLoc
	double minVal; double maxVal; Point minLoc; Point maxLoc; Point matchLoc;

	minMaxLoc(		    result,	//matriz de entrada
				   &minVal,	//valor mínimo da entrada
				   &maxVal,	//valor máximo da entrada
			           &minLoc,	//ponto onde está o mínimo
				   &maxLoc,	//ponto onde está o máximo
				    Mat());	//máscara opcional
	
	//Armazena o valor correto dependendo da função escolhida (máximo ou mínimo) e desenha um retângulo ao redor da área de maior ajustamento possível
	if( match_method  == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED )
	{ matchLoc = minLoc; }
	else
	{ matchLoc = maxLoc; }
	
	rectangle( img_display, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), Scalar::all(0), 2, 8, 0 );
	rectangle( result, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), Scalar::all(0), 2, 8, 0 );
//Contornos em imagens
	//...converte imagem para nível de cinza e borra ela..
	
	//cria variáveis importantes
	Mat canny_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	
	//Detecta bordas usando canny
	Canny( src_gray, canny_output, thresh, thresh*2, 3 );
	
	///Encontra contornos
	findContours(	canny_output,	//imagem-entrada, binária, 8-bit, cinzenta. The function modifies the image while extracting the contours.
			    contours,	//Contornos detectados. Cada contorno é armazenado como um vector de pontos.
		           hierarchy,	//Vetor-saída opcional,contendo informações sobre a topologia da imagem. Ele tem o maior número de elementos como o número de contornos.
	       		CV_RETR_TREE,	//modo de recuperação do contorno. 
	      CV_CHAIN_APPROX_SIMPLE,	//método de aproximação do contorno.
			Point(0, 0));	//deslocamento opcional a cada ponto do contorno.
	
	///Desenha os contornos
	Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
	for( int i = 0; i< contours.size(); i++ ){
	    drawContours(		drawing,	//imagem-destino
				       contours,	//Todos os contornos de entrada. Cada contorno é armazenado como um vector de ponto.
					      i,	//Parâmetro que indica um contorno para desenhar. Se for negativo, todos os contornos são desenhados.
					  color,	//Cor dos contornos.
					      2,	//Espessura das linhas dos contornos.
					      8,	//conectividade da linha.
				      hierarchy,	//Informações opcionais sobre hierarquia.
					      0,	//Nível máximo para contornos desenhados (0,1 ou 2). Apenas se houver hierarquia.
				       Point());	//deslocamento opcional deslocamento do contorno.
	}
//ConvexHull
	//...converte imagem para nível de cinza e borra ela..
	
	//cria variáveis importantes
	Mat src_copy = src.clone();
	Mat threshold_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	
	//...Detecta bordas usando threshold ..
	threshold( src_gray, threshold_output, thresh, 255, THRESH_BINARY );
	
	//... encontra contornos..
	findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
	
	/// Acha o convexHull para cada contorno
	vector<vector<Point> >hull( contours.size() );
	for( int i = 0; i < contours.size(); i++ ){ 
	    convexHull(		Mat(contours[i]),	//conjunto de pontos 2D de entrada, armazenada em std :: vector ou Mat.
					 hull[i],	//Fecho convexo de saída. Ou é um vector de número inteiro ou de índices de vectores de pontos.
					 false ); 	//Flag Orientação. Se é verdade, a saída do fecho convexo é orientada no sentido horário.
	}
	
	// Desenha contornos/resultados hull
	Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
	for( int i = 0; i< contours.size(); i++ ){
	    drawContours( drawing, contours, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
	    drawContours( drawing, hull, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
	}
//BoundingBox e círculos -  boundingRect() e minEnclosingCircle()
	//...converte imagem para nível de cinza e borra ela..
	
	//cria variáveis importantes
	Mat threshold_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	
	//...Detecta bordas usando threshold ..
	threshold( src_gray, threshold_output, thresh, 255, THRESH_BINARY );
	
	//... encontra contornos..
	findContours( threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
	
	//...mais variáveis ..
	vector<vector<Point> > contours_poly( contours.size() );
	vector<Rect> boundRect( contours.size() );
	vector<Point2f>center( contours.size() );
	vector<float>radius( contours.size() );
	
	/// Contornos aproximados para polígonos e obter caixa e círculo delimitadores
	for( int i = 0; i < contours.size(); i++ ){ 
	  approxPolyDP(		Mat(contours[i]),	//vetor-entrada de ponto 2D em: std::vector ou Mat(C ++ interface).
				contours_poly[i],	//Resultado da aproximação. O tipo deve corresponder ao tipo da curva de entrada.
					       3,	//Parâmetro especificando a precisão da aproximação. Distância máxima entre a curva original e sua aproximação.
					   true);	//Se for verdade, a curva aproximada está fechado (seus primeiros e últimos vértices estão conectados).
	  
	  boundRect[i] = boundingRect( Mat(contours_poly[i]) );	//vetor-entrada de ponto 2D em: std::vector ou Mat(C ++ interface).
	  
	  minEnclosingCircle( (Mat)contours_poly[i],	//vetor-entrada de ponto 2D em: std::vector ou Mat(C ++ interface).
				          center[i],	//centro do círculo de saída.
					 radius[i]);	//raio do círculo de saída.
	}
	
	/// Desenhe poligonos de contorno/bounding rects/círculos
	Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
	for( int i = 0; i< contours.size(); i++ ){
	  drawContours( drawing, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
	  rectangle( drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );
	  circle(drawing, center[i], (int)radius[i], color, 2, 8, 0);
	}
//Bounding boxes rotacionadas e Ellipses - minAreaRect() e  fitEllipse()
	//...converte imagem para nível de cinza e borra ela..
	//...Detecta bordas usando threshold ..
	//... encontra contornos..
	/// Encontra retângulos rotacionados e ellipses para cada contorno
	vector<RotatedRect> minRect( contours.size() );
	vector<RotatedRect> minEllipse( contours.size() );

	for( int i = 0; i < contours.size(); i++ ){ 
	  minRect[i] = minAreaRect( Mat(contours[i]) );	//vetor-entrada de ponto 2D em: std::vector ou Mat(C ++ interface).
	  if( contours[i].size() > 5 ) 
	    minEllipse[i] = fitEllipse( Mat(contours[i]) );	//vetor-entrada de ponto 2D em: std::vector ou Mat(C ++ interface).
	}
	
	//Desenhar contornos/rects rotacionados/elipses
	for( int i = 0; i< contours.size(); i++ ){
	  drawContours( drawing, contours, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
	  ellipse( drawing, minEllipse[i], color, 2, 8 );
	  Point2f rect_points[4]; minRect[i].points( rect_points );
	  for( int j = 0; j < 4; j++ )
	      line( drawing, rect_points[j], rect_points[(j+1)%4], color, 1, 8 );
	}
//Momentos da imagem
	//...converte imagem para nível de cinza e borra ela..
	//Detecta bordas usando canny
	//... encontra contornos..
	
	/// Geta os momentos
	vector<Moments> mu(contours.size() );
	for( int i = 0; i < contours.size(); i++ )
	  mu[i] = moments(	contours[i],	// imagem 8-bit ou vetor 2D de pontos
				     false);	// Se é verdade, todos os não-zero pixels da imagem são tratados como 1. O parâmetro é usado apenas para imagens.
	  
	/// Geta o centro de massa
	vector<Point2f> mc( contours.size() );
	for( int i = 0; i < contours.size(); i++ )
	    mc[i] = Point2f( mu[i].m10/mu[i].m00 , mu[i].m01/mu[i].m00 );
	
	/// Desenha contornos
	Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
	for( int i = 0; i< contours.size(); i++ ){
	  drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
	  circle( drawing, mc[i], 4, color, -1, 8, 0 );
	}
	
	/// Calculate the area with the moments 00 and compare with the result of the OpenCV function
	for( nt i = 0; i< contours.size(); i++ ){
	  printf(" * Contour[%d] - Area (M_00) = %.2f - Area OpenCV: %.2f - Length: %.2f \n", i, mu[i].m00,
									contourArea(contours[i]),	//vetor-entrada de ponto 2D em: std::vector ou Mat(C ++ interface).
								 arcLength( contours[i], true ));	//vetor-entrada de ponto 2D em: std::vector ou Mat(C ++ interface).
													//Sinalizador indicando se a curva é fechada ou não.
	  drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
	  circle( drawing, mc[i], 4, color, -1, 8, 0 );
	}
//Teste Polígono Ponto - Onde aprendemos a calcular distâncias a partir da imagem de contornos
	//..cria uma imagem seguida por uma sequência de pontos para fazer o contorno..
	//..desenha na imagem criada, geta os contornos..
	
	//Calcula as distâncias ao contorno..
	for( int j = 0; j < src.rows; j++ ){ 
	  for( int i = 0; i < src.cols; i++ ){ 
	    raw_dist.at<float>(j,i) = pointPolygonTest(		contours[0],	//contorno de entrada
							       Point2f(i,j),	//ponto testado contra o contorno
								     true ); 	//se true, estima-se a distância com sinal do ponto ao contorno mais próximo. Senão só chega se
	  }									//o ponto está dentro de um contorno.
        }
	
	//Representando a distância graficamente
	Mat drawing = Mat::zeros( src.size(), CV_8UC3 );

	for( int j = 0; j < src.rows; j++ )
	  for( int i = 0; i < src.cols; i++ )
            if( raw_dist.at<float>(j,i) < 0 ){
	      drawing.at<Vec3b>(j,i)[0] = 255 - (int) abs(raw_dist.at<float>(j,i))*255/minVal;
            else if( raw_dist.at<float>(j,i) > 0 )
              drawing.at<Vec3b>(j,i)[2] = 255 - (int) raw_dist.at<float>(j,i)*255/maxVal;
            else
              drawing.at<Vec3b>(j,i)[0] = 255; drawing.at<Vec3b>(j,i)[1] = 255; drawing.at<Vec3b>(j,i)[2] = 255; }
          

          
          
#caderno

Em OpenCV2 temos vários módulos. Cada um cuida de uma área diferente ou abordagem para processamento de imagem.
    -seção 'core', aqui são definidos os blocos básicos da biblioteca.
    -módulo 'highgui', já que esta contém as funções para as operações de entrada e de saída
    
    'Container Mat'
    Mat é basicamente uma classe com duas partes de dados: o cabeçalho de matriz (com informações, tais como o tamanho da matriz, o método utilizado para o armazenamento, 
em que endereço a matriz armazenada, e assim por diante) e um ponteiro para a matriz contendo o os valores de pixel (tendo qualquer dimensionalidade dependendo do 
método escolhido para a armazenagem). O tamanho do cabeçalho matriz é constante, no entanto, o tamanho da matriz pode variar de imagem em imagem e, normalmente, 
é maior por ordens de grandeza.  

    # Alocação de imagens de saída para funções OpenCV é automática (salvo indicação em contrário).
    # Você não precisa pensar sobre o gerenciamento de memória com OpenCVS C ++ interface.
    # O operador de atribuição eo construtor de cópia apenas copia o cabeçalho.
    # A matriz subjacente de uma imagem pode ser copiado usando o clone () e copyTo (funções).
    
    'Espaço de Cores'
    
    # RGB é o mais comum, como os nossos olhos usam algo semelhante, os nossos sistemas de visualização também compõe cores usando estes.
    # O HSV e HLS decompõe as cores em matiz, saturação e componentes de valor / luminância, que é uma forma mais natural para nós descrevermos cores. 
      # Você pode, por exemplo, negar o último componente, fazendo seu algoritmo menos sensível às condições de luz da imagem de entrada.
    # YCrCb é utilizado pelo formato de imagem JPEG popular.
    # CIE L*a*b* é um espaço de cor uniforme perceptivelmente, o que se torna útil se você precisa para medir a distância de uma determinada cor para outra.
    
    'Tipo de armazenamento'
    
    # char =(1 byte/8 bits) => unsigned(0 a 255) e signed(-127 to +127) e 3 componentes(16 milhões)
    # float =(4 byte/32 bits)
    # double  =(8 byte/64 bit)
    
    'Color reduction-Lookup Table'
    *obs* Quando se divide um char por um int, o resultado ainda é um char;
          Inew = (Iold/10)*10
          Lookup Table = tabela, em array, que armazena os novos valores para os 256 níveis de cinza, que representa a quantidade de entradas.
          'IMPORTANTE = Uma imagem grayscale possui uma matriz plana de linhas e colunas dispostas normalmente'
          '             Uma imagem com mais channels contém tantas subcolunas quando a quantidade de channels.' 
          '             Uma matriz composta de 3 planos um atrás do outro, na verdade, no opencv todos os planos são chapados no mesmo plano,
	  ' a matriz é um só plano mas cada coluna vem acompanhada de 2 subcolunas. Então uma matriz 2x2 colorida, na verdade tem 2 linhas x 6 colunas-BGRBGR' 
          '             As matrizes em geral são armazenas como uma grande linha - linha concatenada na próxima sucessivamente (teste com isContinuos())     '
          
     'Método melhora de constraste'
     
     I(i,j)*M, onde M= /0  -1  0\
                       |-1  5 -1|
                       \0  -1  0/
                       
     'Adicionando 2 imagens'
     Um operador interessante dyadic (de duas entradas) é o operador de mistura linear:
	  'g(x) = (1 - a)fo(x) + af1(x)' com 'a = 0->1'
	  
      'Ajuste de brilho e constraste' = transformação em pixel - sem vizinhança -
		    g(x)= a*f(x) + b  -> a= gain(ganho'constraste') b= bias(viés'brilho')
		ou  g(i,j) = a*f(i,j) + b
		
      'Transformada de Fourier Discreta'
      A Transformada de Fourier decompõe uma imagem em seus componentes de senos e cossenos. O resultado da transformação são números complexos. Mostrar o resultado é
      possível através de uma imagem real e uma complexa ou uma imagem de magnitude e outra de fase. No entanto, ao longo dos algoritmos de processamento de imagem apenas 
      a imagem de magnitude é interessante ,pois contém todas as informações de que precisamos sobre a estrutura geométrica da imagem.
      
	  '1. Expandir a imagem para um tamanho ideal' O desempenho de um DFT é dependente do tamanho da imagem. Ele tende a ser mais rápido para tamanhos de imagem que são 
      múltiplos dos números dois, três e cinco. Portanto, para obter o desempenho máximo é geralmente uma boa idéia fazer um padding nas bordas para obter estes valores.
	  '2. Criar espaço tanto para os valores complexos quanto para os reais' O resultado de uma Transformada de Fourier é complexo. Isto implica que, para cada valor de 
      imagem o resultado são dois valores de imagem (um por cada componente). Além disso, a gama de domínios de frequência é muito maior do que a sua contraparte espacial. 
      Portanto, estes geralmente armazenam, pelo menos, variáveis float. Portanto, vamos converter a nossa imagem de entrada para este tipo e expandi-lo com outro canal 
      para manter os valores complexos.
	  '3. Faz a transformada discreta de Fourier'
	  '4. Transformar os valores reais e complexos para magnitude' Fazemos isso tirando a raiz quadrada da soma dos quadrados da parte real com a parte imaginária do resultado
      da dft.
	  '5. Mudar para uma escala logarítmica' Acontece que a gama dinâmica dos coeficientes de Fourier é muito grande para ser visualizado no ecrã. Nós temos algumas pequenas
      e alguns valores de alta mudança que não podemos observar como este. Portanto, todos os valores elevados irá revelar-se como pontos brancos, enquanto os pequenos como 
      preto. Fazemos isso para trazer o range de valores para níveis de cinza e podermos ver o resultado da transformada na tela.
	  '6. Desfazer padding e rearranjar quadrantes'
      Lembre-se, que, na primeira etapa, ampliamos a imagem? Bem, é hora de jogar fora os valores recentemente introduzidas. Para efeitos de visualização que também pode 
      rearranjar os quadrantes do resultado, de modo que a origem (zero, zero) corresponde com o centro da imagem.
	  '7. Normalizar'Isto é feito de novo para efeitos de visualização. Temos agora as magnitudes, porém este ainda estão fora do nosso alcance de visualização de imagem
      de zero a um. 
      
      'Compatibilidade OpenCV1 p/ OpenCV2'
      //Entre variáveis de imagens
	  Mat I;
	  IplImage pI = I;
	  CvMat    mI = I;
      //Isto é para chamar operadores IplImage e CvMat e receber seus ponteiros. Para getar um ponteiro usamos o símbolo &
	  Mat I;
	  IplImage* pI     =  &I.operator IplImage();
	  CvMat* mI        =  &I.operator CvMat();
      //Para contornar o problema de vazamento de memória no OpenCV lá é introduzida uma espécie de ponteiro inteligente. Isso vai liberar automaticamente o objeto 
      //quando ele já não estiver em uso. Para usar isto declare os ponteiros como uma especialização da Ptr:
	  Ptr<IplImage> piI = &I.operator IplImage();
      //Converter a partir de estruturas de dados C para o tapete é feito passando estes dentro de seu construtor. Por exemplo:
	  Mat K(piL), L;
	  L = Mat(pI);

     'Filtros de suavização de imagens'
	  '1. Filtro de caixa normalizado' Cada saída é a média linear dos vizinhos, matriz de 1s dividida pela qtd de elementos. 
	  '2. Filtro Gaussiano' Feito convoluindo-se cada ponto da imagem com uma máscara gaussiana e depois somando tudo para produzir a saída.
	  O meio da máscara tem o maior peso e ele decresce à medida que nos distanciamos radialmente.('mi' = pico e 'rho' = variância)
	  '3. Filtro de Mediana' Substitui o pixel do meio com a mediana dos vizinhos.
	  '4. Filtro Bilateral' Em geral, os filtros não só retiram o ruído como também borram as bordas. Para amenizar o efeito, podemos usar o filtro
	  bilateral.É um filtro com pesos(como o Gaussiano), mas tem duas componentes. A primeira delas é a mesma ponderação do Gaussiano. A segunda 
	  tem em conta a diferença na intensidade entre os pixels vizinhos e o atual sendo avaliado.
	  
      'Operações morfológicas'
      Operações baseadas em formas. Operações morfológicas aplicam um elemento estruturante numa imagem de entrada e geram uma imagem de saída.
	  //dilatação e erosão
	  Usados para remover ruídos, isolar elementos individuais e unir elementos separados, encontrar mudanças drásticas de intensidade e buracos em imagens.
	    'Dilatação' -Convoluir imagem A com kernel B,que pode ter qualquer forma ou tamanho, geralmente quadrado ou círculo.
			-Kernel B tem ponto de âncora, geralmente o centro.
			-Escaneamos a imagem com o kernel B, e substituímos o maior valor sobreposto em B no posição do ponto âncora.
			-Operação causa aumento de brilho e das regiões.
	    'Erosão'	-Computa mínimo local na área do kernel.
			-Imagem aparenta ficar mais fina, enquanto zonas escuras parecem aumentar.
	  //outras
	    'Abertura'  -Erosão seguida de dilatação.
			-Útil para a remoção de pequenos objetos (supõe-se que os objectos são brilhante em um primeiro plano escuro).
			-Pode-se observar que os pequenos espaços nos cantos da letra tendem a desaparecer.
	    'Fechamento'-Dilatação seguida de erosão
			-Útil para remover pequenos buracos (regiões escuras).
	    'Gradiente Morfológico'-É a diferença entre a dilatação e a erosão de uma imagem.
				   -É útil para encontrar o contorno de um objeto.
	    'Top Hat'	-É a diferença entre a imagem de entrada e sua abertura.
	    'Black Hat'	-É a diferença entre o fechamento e a imagem de entrada.
	  
      'Pirâmedes de Imagens '
      Algumas vezes queremos alterar o tamanho de uma imagem - 'zoom out = downsample = diminuir o tamanho' ou 'zoom in = upsample = aumentar o tamanho'
      Apesar de opencv possuir a função resize, iremos aprender pirâmedes de imagens, que tem uma ampla aplicação em visão.
      Uma 'pirâmede de imagens' é uma 'coleção de imagens originária de uma imagem simples', que é sucessivamente 'downsampled' até alcançar um ponto de parada desejado.
      Existem dois tipos de pirâmides de imagens:
	    'Pirâmede Gaussiana' 
		-Para 'downsample = diminuir tamanho', fazemos o seguinte processo. Resultante sempre 1/4 de Gi, construindo a pirâmede. 'pyrUp'
		    *Convolua a imagem Gi com o filtro Gaussiano:	1/16*[1  4  6  4 1
									      4 16 24 16 4
									      6 24 36 24 6
									      4 16 24 16 4
									      1  4  6  4 1]
		    *Remova todas as linhas e colunas de número par.
		-Para 'upsample = aumentar o tamanho'. 'pyrDown'
		    *Converta a imagem original Gi para o dobro em cada dimensão, e preencha os novos pixels com 0.
		    *Convolua a imagem resultante com o filtro gaussiano acima (multiplicado por 4) para aproximar o valor dos pixels esquecidos.
	    'Pirâmede Laplaciana' Usada para reconstruir uma imagem upsampled de uma imagem menor da pirâmede (com baixa resolução).
	  
      'Thresholding'
      Método mais simples de segmentação
      Separar objeto de estudo do fundo
      OpenCV suporta 5 tipos de thresholding:
	  '1. Threshold Binário' se a intensidade do pixel de src (x, y) é maior do que o limiar, então a nova intensidade de pixel é definido como um MaxVal. Caso contrário,
	   os pixels são definidos como 0.
	  '2. Threshold Binário Invertido' se a intensidade do pixel de src (x, y) é maior do que o limiar, então a nova intensidade de pixel é definido como 0.Caso contrário,
	   os pixels são definidos como um MaxVal.
	  '3. Truncado' O valor máximo de intensidade para os pixels é o próprio limiar, se src (x, y) é maior, então o seu valor é truncado. Caso contrário, permanece normal.
	  '4. Threshold para zero' Se src (x, y) é menor do que o limiar, o novo valor de pixel será definido para 0.Caso contrário, permanece normal. 
	  '5. Threshold para zero invertido'  Se src (x, y) é maior do que o limiar, o novo valor de pixel será definido para 0.Caso contrário, permanece normal. 
	  
      'Como fazer o próprio filtro linear'
      Um kernel é essencialmente uma matriz de tamanho fixo com coeficientes numéricos, juntamente com um ponto de âncora, tipicamente localizado no centro. P/ calcular a
      convolução no ponto, colocamos o ponto de âncora do kernel no ponto de interesse, multiplicamos todos os pixels vizinhos pela máscara e substituímos no ponto avaliado.
      

      'Bordas e padding'
      O que fazer com as bordas no momento da convolução? 2 tipos de padding.
	  'BORDER_CONSTANT' padding com um valor constante (i.e. preto ou 0)
	  'BORDER_REPLICATE' A linha ou coluna no limite do original é replicado para o contorno extra.
	  
      'Operador de Sobel - Derivada 1ª ordem e borda'
      Bordas numa imagem sofrem mudanças bruscas de intensidade. A alta mudança no gradiente indica uma grande mudança na imagem. Tirando-se a primeira derivada é fácil
      ver mudanças na intensidade. Pode-se deduzir que um método de detecção de contornos de uma imagem pode ser realizado através da localização de locais de pixel onde o 
      gradiente é mais elevado do que os de seus vizinhos (ou generalizar, maior do que um limiar).
      1) O Operador Sobel é um operador de diferenciação discreta. Ele calcula uma aproximação do gradiente de uma função de intensidade de imagem.
      2) O Operador Sobel combina suavização Gaussiana com diferenciação.
	'1. Mudanças horizontais' Supondo imagem I,obtida convoluindo I com o kernel ímpar Gx.
				  Gx = [-1 0 1
				        -2 0 2 * I
				        -1 0 1]
	'2. Mudanças verticais' obtida convoluindo I com o kernel ímpar Gy.
				  Gx = [-1 -2 -1
				         0  0  0 * I
				         1  2  1]
	'3. Aproximação do gradiente'
				  G = sqrt(Gx² + Gy²) ou G = |Gx| + |Gy|
      3) P/ filtros 3x3,é preferível usar o Operador Scharr, que é mais rápido e eficiente.
				  Gx = [-3  0  3		Gx = [-3 -10 -3	
				        -10 0 10 * I e 		       0   0  0 * I
				        -3  0  3]		       3  10  3]
				        
	'Operador Laplaciano - Derivada 2ª ordem e borda'
	Em bordas, pode-se observar que a segunda derivada é zero! Então, a gente também pode usar este critério para tentar detectar bordas em uma imagem. No entanto, 
	note que zeros não só vão aparecer nas bordas (eles realmente podem aparecer em outros locais sem sentido); isto pode ser resolvido mediante a aplicação de filtragem,
	quando necessário.
	O operador Laplaciano é dado por: 'Laplace(f) = d²f/dx² + d²f/dy²'. Como calcula o gradiente da imagem, a função do operador chama o Operador de Sobel.
	
	'Operador Canny - borda (o melhor)'
	-> Baixa taxa de erros: boa detecção de apenas bordas existentes.
	-> Boa localização: A distância entre pixels da borda detectados e os pixels reais da borda tem de ser minimizada.
	-> Resposta mínima: Apenas uma resposta do detector por borda.
	-> Usamos a saída da função Canny como uma máscara por cima da imagem original.
	    '1. Filtrar qualquer ruído. Como exemplo um filtro gaussiano de tamanho 5'
									K = (1/158)*[2  4  5  4  2
										     4  9 12  9  4
										     5 12 15 12  5
										     4  9 12  9  4
										     2  4  5  4  2]
	    '2. Achar o gradiente de intensidade da imagem. Para isto, fazemos um procedimento análogo ao de Sobel'
		  'a' Aplicamos o par de máscaras de convolução (nas direções x e y) -olhar em operador Sobel.
		  'b' Achamos o módulo do gradiente e sua direção. A direção é arredondada para um dos quatro ângulos possíveis (ou seja, 0, 45, 90 ou 135)
				 G = sqrt(Gx² + Gy²) e (theta) = arctan(Gy/Gx)
	    '3. Aplica-se supressão de não-máximos. Isto remove os pixels que não são considerados parte da borda. Daqui, apenas linhas finas (candidatas a borda) serão mantidas'
	    '4. Histerese: último passo. Canny usa dois limiares (superior e inferior)'
		  'a' Se o gradiente de um pixel é maior que o limiar superior, o pixel é aceito como borda.
		  'b' Se o gradiente de um pixel é menor que o limiar inferior, então é rejeitado.
		  'c' Se o gradiente de um pixel está entre os dois limiares, então ele só será aceito se estiver conectado com um pixel que está acima do limiar superior.
				 Canny recomenda a relação entre superior/inferior como 2:1 ou 3:1.
				 
	'Transformada de linha de Hough - detectar linhas numa imagem'
	->A Transformada de linha de Hough é usada para detectar linhas retas.
	->Para aplicar a Transformada, antes é necessário um pré-processamento com detecção de bordas.
	 1) Para transformadas Hough, expressamos retas em coordenadas polares.
				 y = (-cos(theta)/sen(theta))*x + (r/sen(theta))  ou   r = x*cos(theta) + y*sen(theta)
	 2) Para um ponto (x0,y0), podemos definir uma família de linhas que passa por ele (eq. abaixo).Significando que cada par (r(theta),theta) representa qual linha 
	    passa por (x0,y0).
				 r(theta) = x0*cos(theta) + y0*sen(theta)
	 3) Para um dado (x0,y0), plotamos a família de linhas que passam por ele no plano (theta - r) e obtemos uma senóide. //r>0 - 0<theta<2pi 
	 4) Podemos fazer esta operação p/ todos os pontos. Se duas curvas de pontos diferentes tem intersecção, significa que ambos os pontos pertencem à mesma reta.
	 5) Em geral, podemos definir um limiar para o mínimo de pontos que se intersectam para haver detecção de reta.
	      'Transformada Hough mantém o controle da interseção entre as curvas de cada ponto da imagem. Se o número de cruzamentos é acima de algum limiar, então '
	      'declara-lo como uma linha com os parâmetros (theta, r(theta)) do ponto de intersecção.'
	      
	'Transformada de Círculo de Hough - detectar círculos numa imagem'
	->Similar à Transformada de linha de Hough. Única diferença é que precisamos de 3 parâmetros para representar um círculo, que são (xc,yc,r).
	->OpenCV usa para os cálculos o método gradiente de Hough.
	
	'Remapeamento'
      ->É o processo de tomada de pixels de um lugar na imagem, colocando-os em uma outra posição em uma nova imagem.
      ->Para realizar o processo de mapeamento, pode ser necessário fazer alguma interpolação para locais de pixel não-inteiros, uma vez que não haverá sempre uma 
      correspondência de um-para-um-pixel entre imagens de origem e de destino.
      ->A fórmula é da forma: 		g(x,y) = f(h(x,y))	//g = imagem remapeada
								//f = imagem original
								//h = função mapeadora que opera em (x,y)
	'Transformações Afins'
      ->É qualquer transformação que pode ser expressa na forma de uma multiplicação de matrizes (transformação linear), seguida por uma adição de vetores (translação).
      ->Através de Transformações Afins podemos expressar:
       1) Rotações (transformação linear)
       2) Translações (adição de vetores)
       3) Operações de escala (transformação linear)
      
      ->A maneira usual de representar uma transformação afim é usando uma matriz 2x3. Sendo representada pela união das matrizes de transformação linear com a adição de vetor.
			A = [a00  a01		B = [b00		M = [A B] = [a00  a01  b00
			     a10  a11]²*²            b10]²*¹			     a10  a11  b10]²*³
      ->Dado um vetor 2D X= [x , podemos fazer uma transformação nas formas:
			     y]
		1)T = A.[x + B				2)T = M. [x,y,1]ŧ(transposta)
		         y]
		         
		         T = [a00x + a01y + b00
			      a10x + a11y + b10]
			      
      ->Sabemos que uma transformação afim é basicamente uma relação entre duas imagens.
		'a' Nosso trabalho é achar a matriz M.
		'b' Sabemos que T = M.X. M pode ser uma matriz 2X3 ou pode vir como uma relação geométrica entre os pontos.
		
	'Equalização de histograma'
	 Histograma: representação gráfica da distribuição de intensidade de uma imagem. Ele quantifica o número de pixels para cada valor de intensidade considerados.
	 Equalização de histograma: método que melhora o contraste de uma imagem, de modo a esticar a faixa de intensidade.
	    ->Equalização: implica um mapeamento de distribuição (o histograma dado) para uma outra distribuição (uma distribuição mais alargada e mais uniforme de 
	      valores de intensidade), de modo que os valores de intensidade ficam espalhados por toda a gama de valores.
	    ->Usamos a função de distribuição acumulada p/ realizar a equalização de histograma.
	 
	'Cálculo de histograma'
	 ->Histogramas são contagens coletadas de dados organizados em um conjunto de valores em subpartes (pré-definidos).
		a) dims: O número de parâmetros que você deseja coletar dados de. No nosso exemplo, dims = 1 porque estamos a contar apenas os valores de intensidade de 
		cada pixel (na escala de cinzentos de uma imagem).
		b) bins: É o número de subdivisões em cada dim. No nosso exemplo, bins = 16
		c) intervalo: Os limites para os valores a serem medidos. Neste caso: range = [0,255]
		
	'Comparação de Histograma'
	-> Para comparar dois histogramas, (H1 e H2), primeiro escolhemos uma métrica (d(H1,H2)) para expressar o quanto os dois histogramas combinam. 4 tipos:
	    '1. Correlação ( CV_COMP_CORREL )'
	    '2. Qui-Quadrado ( CV_COMP_CHISQR )'
	    '3. intersecção ( method=CV_COMP_INTERSECT )'
	    '4. Distância de Bhattacharyya ( CV_COMP_BHATTACHARYYA )'
	    
	'Back Projection'
	->Back Projection é um modo de gravar o quão bem os pixels de uma dada imagem se encaixam na distribuição de pixels do modelo de histograma.
	->De modo simplificado: Para Back Projection, você calcula o modelo de histograma da característica e usa ela para encontrar a característica numa imagem.
	->Examplo de aplicação: Se você tem um histograma de cor de carne (Hue-Saturation histogram), então você pode usar isto para encontrar áreas de cor de carne numa 
	->O que queremos fazer é usar o nosso modelo-histograma (que sabemos que representa uma tonalidade de pele) para detectar áreas de pele em nossa imagem-teste.
	Aqui estão os passos:
	    '1. Em cada pixel da nossa imagem-teste (p(i,j)), colete os dados e ache a localização do bin correspondente para cada pixel (Hi,j;Si,j)'
	    '2. Procure no modelo-histograma o bin correspondente - (Hi,j;Si,j) - e leia o valor do bin.'
	    '3. Guarde este valor de bin numa nova imagem (BackProjection). Então, primeiro normalize o modelo-histograma antes, então a saída p/ a imagem-teste será visível.'
	    '4. Em termos de estatística, os valores guardados em BackProjection representam a probabilidade de um pixel em imagem-teste pertencer à área da pele, baseado no'
	        'modelo-histograma que usamos. Por exemplo, em nossa imagem-teste, áreas mais claras tem mais probabilidade de ter área de pele (onde realmente são) enquanto'
	        'áreas mais escuras tem baixa probabilidade (note que estas áreas pertencem à superfícies que tem alguma sombra, que afetam a detecção).'
		
	'Matching de templates'
	->Matching de templates é uma técnica para encontrar áreas de uma imagem que casam (são semelhantes) á uma imagem-modelo (patch).
	->Precisamos de duas componentes primárias:
	    a) imagem-entrada (I): A imagem cuja esperamos encontrar um match com a imagem-modelo.
	    b) imagem-modelo (T): A imagem patch que será comparada à imagem-modelo.
	->Objetivo: encontrar a área de maior matching.
	    '1. Comparar a imagem-modelo com a imagem-entrada percorrendo-a como se fizéssemos uma filtragem'
	    '2. Em cada posição, uma métrica é calculada e representa o quão "bom" ou "ruim" o match naquela localização é'
	    '3. Em cada localização de T em I, guardamos a métrica na matriz-resultado (R). Cada (x,y) de R contém a métrica do casamento'
	    '4. Então, dependendo do método de matching, encontramos um ponto chave (máximo ou mínimo)onde ocorre o maior casamento. Neste local, ocorre o matching.'
	->6 métodos de matching.
	    '1. CV_TM_SQDIFF'
	    '2. CV_TM_SQDIFF_NORMED'
	    '3. CV_TM_CCORR'
	    '4. CV_TM_CCORR_NORMED'
	    '5. CV_TM_CCOEFF'
	    '6. CV_TM_CCOEFF_NORMED'