Numpy é uma biblioteca altamente otimizado para operações numéricas. Ele dá uma sintaxe de estilo MATLAB.
Todas as estruturas de array OpenCV são convertidos para-e-de arrays Numpy.

 NumPy é como núcleo Matlab
 SciPy é como as toolboxes do matlab
 Matplotlib permite você plotar gráficos
 IPython emula o ambiente de desenvolvimento do matlab
 
**Gui Features in OpenCV**
#Getting Started with Images
Aprenda a carregar uma imagem, mostrá-la e salvá-la
    1.'cv2.imread(), cv2.imshow() , cv2.imwrite(), e mostrar imagens com Matplotlib'
    flags: 		'cv2.IMREAD_COLOR' : Carrega imagem colorida. Qualquer transparência na imagem será negligenciada. É a flag padrão.
	.		'cv2.IMREAD_GRAYSCALE' : Carrega imagem em níveis de cinza
	.		'cv2.IMREAD_UNCHANGED' : Carrega imagem também incluindo o canal alfa.
	.		'ou 1, 0 or -1' respectivamente.
    .'cv2.waitKey()' - após que o tempo em milissegundos passar, espera por eventos do teclado.
    .'cv2.namedWindow('image', cv2.WINDOW_NORMAL)'
    flags:		'cv2.WINDOW_NORMAL : permite janela resizeable'
    
    from matplotlib import pyplot as plt
    plt.imshow(img, cmap = 'gray', interpolation = 'bicubic')				#mostra imagem no matplot
    plt.xticks([]), plt.yticks([])  # to hide tick values on X and Y axis		#mostra eixos
    plt.show()										#mostra tudo

#Getting Started with Videos
Aprenda a tocar vídeos, capturar vídeos da câmera e salvar salvar como vídeo
    2.'cv2.VideoCapture(), cv2.VideoWriter()'
    
    Você também pode acessar algumas das características deste vídeo usando o método cap.get(PropID) onde PropID é um número de 0 a 18. Cada 
    número indica uma propriedade do vídeo (se for aplicável a esse vídeo) e os detalhes completos podem ser visto aqui:  Property Identifier. 
    Alguns destes valores podem ser modificados utilizando cap.set(PropID, valor). O valor é o novo valor que você deseja.
    
    
    .'CV_CAP_PROP_POS_MSEC' Posição atual no arquivo de vídeo em milissegundos ou carimbo de tempo da captura de vídeo.
    .'CV_CAP_PROP_POS_FRAMES' 0-index do frame a ser decodificado/capturado em seguida.
    .'CV_CAP_PROP_POS_AVI_RATIO' Posição relativa do arquivo de vídeo: 0-início do filme, 1-fim do filme.
    .'CV_CAP_PROP_FRAME_WIDTH' Width of the frames in the video stream.
    .'CV_CAP_PROP_FRAME_HEIGHT' Height of the frames in the video stream.
    .'CV_CAP_PROP_FPS' Frame rate.
    .'CV_CAP_PROP_FOURCC' 4-character code of codec.
    .'CV_CAP_PROP_FRAME_COUNT' Number of frames in the video file.
    .'CV_CAP_PROP_FORMAT' Format of the Mat objects returned by retrieve() .
    .'CV_CAP_PROP_MODE' Backend-specific value indicating the current capture mode.
    .'CV_CAP_PROP_BRIGHTNESS' Brightness of the image (only for cameras).
    .'CV_CAP_PROP_CONTRAST' Contrast of the image (only for cameras).
    .'CV_CAP_PROP_SATURATION' Saturation of the image (only for cameras).
    .'CV_CAP_PROP_HUE' Hue of the image (only for cameras).
    .'CV_CAP_PROP_GAIN' Gain of the image (only for cameras).
    .'CV_CAP_PROP_EXPOSURE' Exposure (only for cameras).
    .'CV_CAP_PROP_CONVERT_RGB' Boolean flags indicating whether images should be converted to RGB.
    .'CV_CAP_PROP_WHITE_BALANCE_U' The U value of the whitebalance setting (note: only supported by DC1394 v 2.x backend currently)
    .'CV_CAP_PROP_WHITE_BALANCE_V' The V value of the whitebalance setting (note: only supported by DC1394 v 2.x backend currently)
    .'CV_CAP_PROP_RECTIFICATION' Rectification flag for stereo cameras (note: only supported by DC1394 v 2.x backend currently)
    .'CV_CAP_PROP_ISO_SPEED' The ISO speed of the camera (note: only supported by DC1394 v 2.x backend currently)
    .'CV_CAP_PROP_BUFFERSIZE' Amount of frames stored in internal buffer memory (note: only supported by DC1394 v 2.x backend currently)

    Por exemplo, eu posso verificar a largura e altura do quadro por cap.get (3) e cap.get (4). Isso me dá 640x480 por padrão. Mas eu quero 
    modificá-lo para 320x240. Basta usar ret = cap.set (3320) e ret = cap.set (4240)

    P/salvar vídeo
    
    Desta vez, criamos um objeto VideoWriter. Devemos especificar o nome do arquivo de saída (por exemplo: output.avi). Então, devemos 
    especificar o código FourCC (detalhes no próximo parágrafo). Em seguida, o número de quadros por segundo (fps) e tamanho do quadro deve 
    ser passado. E por último, uma bandeira é isColor. Se é verdade, codificador esperar quadro de cor, caso contrário, ele funciona com 
  moldura em tons de cinza.FourCC é um código de quatro bytes utilizado para especificar o codec de vídeo. A lista de códigos disponíveis 
  pode ser encontrado em fourcc.org. É dependente de plataforma. Na sequência de codecs funciona bem para mim.
  
  Código FourCC é passado como cv2.VideoWriter_fourcc ('M', 'J', 'P', 'G') ou cv2.VideoWriter_fourcc (* 'MJPG) para MJPG'.

#Drawing Functions in OpenCV
Draw different geometric shapes with OpenCV
    cv2.line(), cv2.circle() , cv2.rectangle(), cv2.ellipse(), cv2.putText()
    
    img : The image where you want to draw the shapes
    color : Color of the shape. for BGR, pass it as a tuple, eg: (255,0,0) for blue. For grayscale, just pass the scalar value.
    thickness : Thickness of the line or circle etc. If -1 is passed for closed figures like circles, it will fill the shape. default thickness= 1
    lineType : Type of line, whether 8-connected, anti-aliased line etc. By default, it is 8-connected. cv2.LINE_AA gives anti-aliased line which
      looks great for curves.

#Mouse as a Paint-Brush
Handle mouse events in OpenCV
    cv2.setMouseCallback()
    
    lista de eventos disponíveis => (events = [i for i in dir(cv2) if 'EVENT' in i])
    ['EVENT_FLAG_ALTKEY', 'EVENT_FLAG_CTRLKEY', 'EVENT_FLAG_LBUTTON', 'EVENT_FLAG_MBUTTON', 'EVENT_FLAG_RBUTTON', 'EVENT_FLAG_SHIFTKEY', 
     'EVENT_LBUTTONDBLCLK', 'EVENT_LBUTTONDOWN', 'EVENT_LBUTTONUP', 'EVENT_MBUTTONDBLCLK', 'EVENT_MBUTTONDOWN', 'EVENT_MBUTTONUP', 
     'EVENT_MOUSEMOVE', 'EVENT_RBUTTONDBLCLK', 'EVENT_RBUTTONDOWN', 'EVENT_RBUTTONUP']

#Trackbar as the Color Palette
Learn to bind trackbar to OpenCV windows
    cv2.getTrackbarPos(), cv2.createTrackbar() 
    
    Another important application of trackbar is to use it as a button or switch. OpenCV, by default, doesn’t have button functionality. So you
    can use trackbar to get such functionality. In our application, we have created one switch in which application works only if switch is ON, 
    otherwise screen is always black.
    
**Core Operations**
#Basic Operations on Images
Accessing and Modifying pixel values
    Access pixel values and modify them
    Access image properties
    Setting Region of Image (ROI)
    Splitting and Merging images
    
    Almost all the operations in this section is mainly related to Numpy rather than OpenCV. A good knowledge of Numpy is required to write 
    better optimized code with OpenCV.
    
    Numpy is a optimized library for fast array calculations. So simply accessing each and every pixel values and modifying it will be very slow
    and it is discouraged.
    
    Above mentioned method is normally used for selecting a region of array, say first 5 rows and last 3 columns like that. For individual pixel 
    access, Numpy array methods, array.item() and array.itemset() is considered to be better. But it always returns a scalar. So if you want to 
    access all B,G,R values, you need to call array.item() separately for all.
    
    Shape of image is accessed by img.shape. It returns a tuple of number of rows, columns and channels (if image is color):
    If image is grayscale, tuple returned contains only number of rows and columns. So it is a good method to check if loaded image is grayscale
    or color image.
    
    Total number of pixels is accessed by img.size
    
    Image datatype is obtained by img.dtype
    
    img.dtype is very important while debugging because a large number of errors in OpenCV-Python code is caused by invalid datatype.
    
    ROI is again obtained using Numpy indexing. Here I am selecting the ball and copying it to another region in the image

    The B,G,R channels of an image can be split into their individual planes when needed. Then, the individual channels can be merged back 
    together to form a BGR image again. This can be performed by
    
    cv2.split() is a costly operation (in terms of time), so only use it if necessary. Numpy indexing is much more efficient and should be used 
    if possible.
    
    If you want to create a border around the image, something like a photo frame, you can use cv2.copyMakeBorder() function. 
    
        cv2.BORDER_CONSTANT - Adds a constant colored border. The value should be given as next argument.
        cv2.BORDER_REFLECT - Border will be mirror reflection of the border elements, like this : fedcba|abcdefgh|hgfedcb
        cv2.BORDER_REFLECT_101 or cv2.BORDER_DEFAULT - Same as above, but with a slight change, like this : gfedcb|abcdefgh|gfedcba
        cv2.BORDER_REPLICATE - Last element is replicated throughout, like this: aaaaaa|abcdefgh|hhhhhhh
        cv2.BORDER_WRAP - Can’t explain, it will look like this : cdefgh|abcdefgh|abcdefg

#Arithmetic Operations on Images
Addition, subtraction, bitwise operations 
    cv2.add(), cv2.addWeighted()
    
    cv2.add() ou operador sobrecarregado Numpy res = img1 + img2.
    
    Both images should be of same depth and type, or second image can just be a scalar value.
    
    There is a difference between OpenCV addition and Numpy addition. 
    
    -> Adicionar com opencv é uma operação saturada. (se uint8 250 + 10 = 260 => 255)
    -> Adicionar no Numpy usa módulo. (250 + 10 = 260 => 260%256 = 4)
    
    Bitwise Operations
    This includes bitwise AND, OR, NOT and XOR operations. They will be highly useful while extracting any part of the image (as we will see in
    coming chapters), defining and working with non-rectangular ROI etc

#Performance Measurement and Improvement Techniques
To measure the performance of your code.
Some tips to improve the performance of your code.
    cv2.getTickCount, cv2.getTickFrequency
    
    Python também oferece um módulo 'time' útil para medir tempo de execução.
    Além deste, o método 'profile' para obter relatório detalhado sobre o código, como quanto tempo cada função do código tomou, quantas
    vezes uma mesma função tomou.
    
    Porém, se estiver usando IPython, todas estas características estão integradas numa maneira amigável.
    
    Para medir performance:
      .'cv2.getTickCount' - função que retorna o número de ciclos-clocks depois de um evento de referência (como o momento que a máquina foi ligada)
	até o momento que a função é chamada. Então, se chamar a função antes e depois da execução da função, você obtém o número de ciclos-clocks 
	usados para executar a função.
	
      .'cv2.getTickFrequency' - função que retorna a frequência de ciclos-clocks, ou este valor por segundo.
      
      Você pode fazer o mesmo com o módulo 'time'. Em vez de usar cv2.getTickCount, use time.time(). Desta forma, tome a diferença!
      
      Default Optimization in OpenCV.......

      



















*PYTHON*
-Given a string of length one, return an integer representing the Unicode code point of the character when the argument is a unicode object, or 
 the value of the byte when the argument is an 8-bit string. For example, ord('a') returns the integer 97, ord(u'\u2020') returns 8224.
-A abundância de opções de plotagem estão disponíveis em matplotlib.
-Mas matplotlib exibe no modo RGB. Assim imagens de cores não serão exibidos corretamente no matplotlib se a imagem é lida com OpenCV.