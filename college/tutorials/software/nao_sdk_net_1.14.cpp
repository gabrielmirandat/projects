#AL é de Aldebaran
#Os includes <al...> devem estar todos no SDK Nao
#Broker = corretor/intermediário
#warehouse = armazém/depósito/almoxarifado

'1.Event creation principle'
- Alguns eventos já são default da aldebaran (um evento é levantado sempre que o nao detecta uma face). Mas você pode querer criar outros.
- Criação de eventos e levantamento deles passam por ALMemory.
- Para criar um evento, use um proxy para ALMemory

AL::ALMemoryProxy memProxy = AL::ALMemoryProxy(getBroker())
memProxy.declareEvent("EventName")

- Sempre que você quiser levantar o evento, use:
memProxy.raiseEvent("EventName", eventValue)

Nota:
A criação de eventos só é possível para um modulo local, já que os módulos estão olhando diretamente para a memória do robô.

functionName("callback", getName(), "");
BIND_METHOD(Events::callback)

'2.Say Hello World'
- Como usar o proxy especializado para ALTextToSpeech.
- Fazer NAO falar Hello World. 

#include <alproxies/altexttospeechproxy.h>

'Creating a simple remote module'
- Como criar módulos e métodos linkáveis acessíveis de fora.

    '3.módulo helloworld'
    /**
    * A simple example module that says "Hello world" using
    * text to speech, or prints to the log if we can't find TTS
    *
    * This class inherits AL::ALModule. This allows it to bind methods
    * and be run as a remote executable or as a plugin within NAOqi
    */
    - Classe HelloWorld herda da classe AL::ALModule
    - Isto permite a HelloWorld vincular métodos e rodá-los como um executável remoto ou como um plugin sem o NAOqi
  
    'virtual' = novas funções não precisam criar um método já existente para fazer o que a nova propõe
    -> Faz Nao dizer helloworld
    -> Faz Nao dizer uma sentença
    -> Faz Nao dizer uma sentença e retorna o tamanho dela

    functionName("sayHello", getName(), "Say hello to the world");
    BIND_METHOD(HelloWorld::sayHello);

    functionName("sayText", getName(), "Say a given sentence.");
    addParam("toSay", "The sentence to be said.");
    BIND_METHOD(HelloWorld::sayText);

    functionName("sayTextAndReturnLength", getName(),"Say a given sentence, and return its length");
    addParam("toSay", "The sentence to be said.");
    setReturn("sentenceLength", "Length of the said sentence.");
    BIND_METHOD(HelloWorld::sayTextAndReturnLength);
    
    testhelloworld.cpp => 'exemplo de como usar o módulo'
    
'4.Creating a custom main'
- Necessidade de mudar a main.cpp. Talvez para mudar a opção de parsing (analisador) ou não usar a caixa preta ALTools::mainFunction.

// A broker needs a name, an IP and a port:
  const std::string brokerName = "mybroker";
  // FIXME: would be a good idea to look for a free port first
  int brokerPort = 54000;
  const std::string brokerIp   = "0.0.0.0";  // listen to anything

  boost::shared_ptr<AL::ALBroker> broker;
  try
  {
    broker = AL::ALBroker::createBroker(
        brokerName,
        brokerIp,
        brokerPort,
        parentBrokerIP,
        parentBrokerPort,
        0    // you can pass various options for the broker creation,
             // but default is fine
      );
  }
  
SOAP (Simple Object Access Protocol) é um protocolo de mensagens que permite que programas que rodam em sistemas operacionais diferentes (como 
windows e linux) se comuniquem usando Hypertext Transfer Protocol (HTTP) e Extensible Markup Language (XML).

'5.Moving NAO’s head'
- Como mover o NAO usando um proxy para ALMotion

/** The name of the joint to be moved. */
  const AL::ALValue jointName = "HeadYaw";
/** Make sure the head is stiff to be able to move it.
* To do so, make the stiffness go to the maximum in one second.
*/
/** Target stiffness. */
AL::ALValue stiffness = 1.0f;
/** Time (in seconds) to reach the target. */
AL::ALValue time = 1.0f;
/** Call the stiffness interpolation method. */
motion.stiffnessInterpolation(jointName, stiffness, time);

/** Set the target angle list, in radians. */
AL::ALValue targetAngles = AL::ALValue::array(-1.5f, 1.5f, 0.0f);
/** Set the corresponding time lists, in seconds. */
AL::ALValue targetTimes = AL::ALValue::array(3.0f, 6.0f, 9.0f);
/** Specify that the desired angles are absolute. */
bool isAbsolute = true;

/** Call the angle interpolation method. The joint will reach the
* desired angles at the desired times.
*/
motion.angleInterpolation(jointName, targetAngles, targetTimes, isAbsolute);

/** Remove the stiffness on the head. */
stiffness = 0.0f;
time = 1.0f;
motion.stiffnessInterpolation(jointName, stiffness, time);


'Reacting to an event: bumper'
- Naoqi framework permite programação baseada em eventos: é possível definir uma função callback em um evento. Esta função callback será chamada 
cada vez que o evento ser acionado.
    'Princípio'
     -> Assinar eventos:
	- Para reagir a um evento particular, você deve assiná-lo (concordar/aceitar ele).Para fazer isto, você deve primeiro criar um proxy para 
	ALMemory, e então chamar o método subscribeToEvent. Se você quer parar de chamar o callback, use o método unsubscribeToEvent.Cada evento 
	tem um nome particular. 
	- Para criar o proxy de memória, você pode usar o módulo do broker diretamente em vez do endereço de IP (só funciona se estiver dentro 
	de um módulo). 
	- Você então indica pra qual evento quer acionar e a função callback que será chamada em algum lugar.
	
	AL::ALMemoryProxy memProxy = AL::ALMemoryProxy(getBroker());
	memProxy.subscribeToEvent("eventName", "ModuleForCallback", "callbackFunctionName");
	
     -> Função callback:
	- Quando se inscrever para um evento, você deve especificar a função callback e o módulo de onde ela vem. Isto significa que a função 
	callback deve estar delimitada em algum lugar. Você não pode atribuir nenhum argumento à função callback.

     -> Consideração de Threads:
	- Callbacks podem levar muito tempo. Para escapar disto, certifique-se que sua função de callback é thread-safe. Para fazer isto, você 
	pode usar a função crítica e a API Mutex fornecida pela Aldebaran, mas pode usar qualquer outro método, como por exemplo,Boost.Thread.
	- Para usar o mutex Aldebaran, você pode usar um metex (AL::ALMutex) e uma critical section. Não se esqueça de inicializar o mutex com 
	AL::ALMutex::createALMutex. Assim vc pode criar sessões críticas no seu código usando o mutex como argumento: 
	AL::ALCriticalSection section(mutex)
	- Os includes correspondentes são  <althread/almutex.h>  para o mutex e <althread/alcriticalsection.h> para a critical section.
  
'6.Control the LEDs '
- O objetivo do exemplo é mostrar como controlar os LEDS do NAO usando um proxy ao módulo ALLeds. Este exemplo fará uma animação colorida em 
todos os LEDs do NAO.
#include <alproxies/alledsproxy.h>

/** Set the duration of the animation. */
float duration = 3.0f;
/** Play a green / yellow / red animation on all of NAO's leds. */
leds.rasta(duration);

'7.Fast getting and setting joint angles'
- É mostrado como ter acesso rápido (a cada 10ms) aos valores dos ângulos das juntas usando o DCM.
- Módulo local, deve ser compilado cruzado (cross-compiled) e mandado para o robô.
- Warning: este exemplo é avançado, e apenas modificado se souber o que está fazendo.

// Sensors names
std::vector<std::string> fSensorKeys;

// Used for fast memory access
boost::shared_ptr<AL::ALMemoryFastAccess> fMemoryFastAccess;

// Store sensor values.
std::vector<float> sensorValues;
boost::shared_ptr<AL::DCMProxy> dcmProxy;

// Used for the test actuator = sensor
std::vector<float>  initialJointSensorValues;

// Used to store command to send
AL::ALValue commands;
};

enum SensorType { HEAD_PITCH, HEAD_YAW,
                  L_ANKLE_PITCH,
                  L_ANKLE_ROLL,
                  L_ELBOW_ROLL,
                  L_ELBOW_YAW,
                  L_HAND,
                  L_HIP_PITCH,
                  L_HIP_ROLL,
                  L_HIP_YAW_PITCH,
                  L_KNEE_PITCH,
                  L_SHOULDER_PITCH,
                  L_SHOULDER_ROLL,
                  L_WRIST_YAW,
                  R_ANKLE_PITCH,
                  R_ANKLE_ROLL,
                  R_ELBOW_ROLL,
                  R_ELBOW_YAW,
                  R_HAND,
                  R_HIP_PITCH,
                  R_HIP_ROLL,
                  R_KNEE_PITCH,
                  R_SHOULDER_PITCH,
                  R_SHOULDER_ROLL,
                  R_WRIST_YAW,
                  ACC_X,
                  ACC_Y,
                  ACC_Z,
                  GYR_X,
                  GYR_Y,
                  ANGLE_X,
                  ANGLE_Y,
                  L_COP_X,
                  L_COP_Y,
                  L_TOTAL_WEIGHT,
                  R_COP_X,
                  R_COP_Y,
                  R_TOTAL_WEIGHT};


- Desde 1.12, o DCM (Device Communication Manager) foi reescrito.
- Agora é separado em duas partes:
    -> o HAL (Hardware Abstract Layer).
    -> módulo DCM Naoqi, conecta o HAL e NAOqi.
- A API para o DCM HAL é a mesma que a API para o DCM.

// Use DCM proxy
#include <alproxies/dcmproxy.h>

// Used to read values of ALMemory directly in RAM
#include <almemoryfastaccess/almemoryfastaccess.h>

setStiffness(0.2f); // Set to 1.0 for maximum stiffness, but only after a test
preparePositionActuatorCommand();

// Create alias
dcmProxy->createAlias(jointAliasses);

- Alocação dinâmica e chamada de sistema são estritamente proibidas neste método

'8.Capturing audio and video'
- Módulo AVCaptureRemote mostra como capturar simultâneamente audio e vídeo.
- Este é um módulo remoto.

/**
* Default Constructor for modules.
* @param broker the broker to which the module should register.
* @param name the boadcasted name of the module.
*/
AVCaptureRemote(boost::shared_ptr<AL::ALBroker> broker, const std::string& name);

// Our output buffer, allocated once.
AL_SOUND_FORMAT* fAudioBuffer;

qi::os::msleep(10); //dorme por 10 milissegundos

// You can get some information about the image.
//    int width = (int) image[0];
//    int height = (int) image[1];
//    int nbLayers = (int) image[2];
//    int colorSpace = (int) image[3];
//    long long timeStamp = ((long long)image[4])*1000000LL + (long long)image[5];
//    image[4] is the number of seconds, image[5] the number of microseconds

//    You can get the pointer to the image data and its size
//    const char* dataPointer =  static_cast<const char*>(image[6].GetBinary());
//    int size = image[6].getSize();

'9.Using OpenCV'
- Desde de 1.14, NAOqi SDK suporta OpenCV 2.3.1 para tanto compilação quanto compilação cruzada.

    core: it contains the basic structures and functionalities
    highgui: anything to do with display, opening or saving images
    imgproc: color conversion, filters...
    video: optical flow, background substraction...
    calib3d: homography, fundamental matrices... anything to do with camera calibration and stereovision
    features2d: feature detection, descriptors (FAST, SURF), matching
    ml: machine learning (neural networks, SVM, boosting, KNN etc)
    flann: efficient clustering and search in databases
    objectdetection: object detection with Cascade or Haar classifiers

IplImage x cv::Mat
OpenCV 2.1 	OpenCV 2.3
width 	cols
height 	rows
imageData 	data
nChannels 	channels()

- Especifique os módulos que você quer usar. Por exemplo, se você estiver usando core e highgui:
qi_use_lib(mylib OPENCV2_CORE OPENCV2_HIGHGUI)
- Todos os módulos usam o seguinte formato: OPENCV2_MODULENAME.

- Existem novas implementações de vários descritores para keypoints: Star (também chamado Censure), MSER, Upgraded SURF, BRIEF, Ferns... 

'Toolchain OpenCV versus system OpenCV'
C++ NAOqi SDK provê algumas OpenCV libraries.
- Entretanto, no ubuntu, estas bibliotecas foram compiladas sem o suporte a GTK por razões de portabilidade (GTK tem um monte de dependências,
e será útil no robô já que ele não possui display). Isto significa que você não irá apto a usar nenhum método de interface gráfica do OpenCV
(como o cv::imshow). A solução é trocar a versão Aldebaran robotics’ do OpenCV pela do seu sistema.

-Agora limpe seu projeto e roda novamente:
qibuild configure [-c mytoolchain]
qibuild make [-c mytoolchain]

-Compilação cruzada do código OpenCV
O cross toolchain contém as bibliotecas OpenCV. Para assegurar que seu código vai rodar no NAO, tenha certeza de não estar usando qualquer 
interface gráfica (como janelas, trackbars, etc).

'10.Optimized access to images'
- Como implementar acesso otimizado às imagens do NAO quando o módulo é remoto.
- Chamada remota é menos eficiente, ent~ao fazemos uma chamada direta para recuperar as imagens: o buffer contendo a imagem atual é tomada 
diretamente.
- Para recuperar as imagens, inscreva-se como de costume usando o proxy ALVideoDevice e especifique o framerate, resolução, etc.
- Para prevenir o NAO de apagar o buffer que queremos usar, precisamos trancá-lo. Significa que após processar a imagem, o buffer precisa 
ser liberado. Então é importante checar que o processamento da imagem não toma muito tempo comparado ao framerate para evitar o bloqueio 
do processo de agarramento do frame.
  
#include <alproxies/alvideodeviceproxy.h>
#include <alvision/alimage.h>
  
private:
  AL::ALVideoDeviceProxy fVideoProxy;
  std::string fGVMId;

  AL::ALImage* fImagePointer;
  
#include <alvision/alvisiondefinitions.h>

fVideoProxy(AL::ALVideoDeviceProxy(broker)),
fGVMId("GVM")  

fVideoProxy.unsubscribe(fGVMId);
delete fImagePointer;

void OptimizedImage::optimizedImageProcessing() {
  /** Retrieve a pointer to the image. */
  fImagePointer = (AL::ALImage*) fVideoProxy.getImageLocal(fGVMId);
  /** Do whatever processing you want... */
  /** Do not forget to release the image. */
  fVideoProxy.releaseImage(fGVMId);
}

'11.img2arv example'
- Converte uma série de imagens em um arquivo de vídeo arv (IMAGEN-> VIDEO).

#include <boost/filesystem.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <alvision/alvisiondefinitions.h>
#include <alvision/alvideo.h>

namespace fs = boost::filesystem;

streamHeader tmpStreamHeader;
ALVideo videoFile;

//conteudo do video arv
tmpStreamHeader.width      = pImg.cols;
tmpStreamHeader.height     = pImg.rows;
tmpStreamHeader.colorSpace = kYUV422ColorSpace;
tmpStreamHeader.pixelDepth = 8;

streamHeaderVector.push_back(tmpStreamHeader);

videoFile.write(pImg.rows, pImg.cols, (char*) pImg.data, timestamp, 0,0.0f, 0.0f, 0.0f, 0.0f);
timestamp += 66000;

videoFile.closeVideo();

#CMakeLists.txt
qi_use_lib(img2arv ALVISION OPENCV2_CORE OPENCV2_HIGHGUI BOOST_FILESYSTEM)

'12.arv2avi example'
- Converte um vídeo arv para um vídeo avi.

#As funções inline servem como códigos a serem copiados ao lugar que são chamados.
#Funções normais quando são chamadas, o programa tem que ir até ela e executar seu código, isso leva uma certa fração de tempo para acontecer 
#o que deixa o programa com uma resposta um pouco menor. Já as funções inline quando são chamadas o código já está lá, porque o compilador
#trata de copiar todo o código da função para o local onde ela está sendo chamada a partir do momento em que o código é compilado.

cv::VideoWriter writer = cv::VideoWriter(aviFile, CV_FOURCC(fourcc[0], fourcc[1], fourcc[2], fourcc[3]), fps, cv::Size(width, height), 1);

ret = videoFile.getFrame( arvImg, i, streamNumber, true );

'12.Getting an image'
- Como recuperar imagens das câmeras do NAO (remotamente). As imagens serão mostradas numa janela, usando a biblioteca OpenCV. ESC sai da 
aplicação.

/** Subscribe a client image requiring 320*240 and BGR colorspace.*/
const std::string clientName = camProxy.subscribe("test", kQVGA, kBGRColorSpace, 30);

/** Create an cv::Mat header to wrap into an opencv image.*/
cv::Mat imgHeader = cv::Mat(cv::Size(320, 240), CV_8UC3);

/** Create a OpenCV window to display the images. */
cv::namedWindow("images");

/** Retrieve an image from the camera.
    * The image is returned in the form of a container object, with the
    * following fields:
    * 0 = width
    * 1 = height
    * 2 = number of layers
    * 3 = colors space index (see alvisiondefinitions.h)
    * 4 = time stamp (seconds)
    * 5 = time stamp (micro seconds)
    * 6 = image buffer (size of width * height * number of layers)
*/

ALValue img = camProxy.getImageRemote(clientName);

# Here we say that our executable depends on
# - ALCOMMON (main naoqi lib)
# - ALVISION (for vision definitions)
# - OPENCV (display)
#
# It automatically links with the corresponding libraries and make their headers
# available.
qi_use_lib(getimages ALCOMMON ALVISION OPENCV2_CORE OPENCV2_HIGHGUI)

'13.Generic video module'
-Como usar várias funções de ALVideoDevice
- É um módulo local, logo deve ser compilado cruzado e mandado para o robô.

cv::imwrite(kImageNameFull, fIplImageHeader);

'14.Reacting to a vision event: face detected'
- Como implementar um módulo que reage a um evento complexo e como recuperar a informação armazenada neste evento.
- Segue o mesmo princípio de de 'Reacting to an event:bumper', mas é baseado em um evento gerado por ALVideoDevice:FaceDetected.
- Agora, os dados colocados na memória correspondendo à chave "FaceDetected" é mais complexa que um booleano: é um ALValue contendo 
informações sobre as faces detectadas.
- Para recuperar esta informação, use um proxy à ALMemory, e recupere os dados armazenados na chave correspondente.
- Faz o NAO dizer a quantidade de faces detectadas.

private:
    /** Memory proxy for event subscription and data access. */
    AL::ALMemoryProxy fMemoryProxy;
    /** TTS proxy to make NAO talk. */
    AL::ALTextToSpeechProxy fTtsProxy;

    /** ALValue containing the information on detected faces. */
    AL::ALValue fFaces;
    /** Current count of detected faces. */
    unsigned int fFacesCount;
    /** Mutex to make the callback function thread-safe. */
    boost::shared_ptr<AL::ALMutex> fCallbackMutex;
    
'15.Using ALVisualCompass'
- Como usar ALVisualCompass

'Princípio'
- Este exemplo permite você escolher sua imagem de referência, de onde será calculado o erro (diferença), e depois mostrar o erro (diferença) do 
ângulo entre a imagem atual e a de referência.
- Rode o programa com o endereço do IP do robô como argumento.
- O executável vai mostrar duas janelas, uma pra imagem referência e uma para a atual tirada pelo ALVIsualCompass. O erro atual será mostrado 
na janela da imagem atual, em graus. Wz é a rotação do eixo vertical Z, e Wy é a rotação através do eixo horizontal Y.
- Para usar o exemplo:
      -> 'r' para começar o compasso. A imagem referência será será a imagem atual no início.
      -> 'p' para pausar/despausar o compasso. 
      -> 's' para parar o compasso (por exemplo para setar outra referência).
      -> 'Esc' para sair do programa. Use isto em vez de interromper o programa para se desinscrever do compasso adequadamente.
      
boost::shared_ptr<ALVisualCompassProxy> compassProxy;
boost::shared_ptr<ALMemoryProxy> memoryProxy;
try {
  // Creating proxy to ALVisualCompass.
  compassProxy = boost::shared_ptr<ALVisualCompassProxy>(new ALVisualCompassProxy(argv[1]));
  memoryProxy = boost::shared_ptr<ALMemoryProxy>(new ALMemoryProxy(argv[1], 9559))
}

'16.Sound playback'
- ALSoundPlayback manda som para os alto-falantes do NAO.
- Este é um módulo local, deve ser compilado cruzado e mandado para o robô.

struct wavheader
{
  char chunkID[4];
  long chunkSize;
  char format[4];
  char subchunk1ID[4];
  long subchunk1Size;
  unsigned short audioFormat;
  unsigned short nbOfChannels;
  unsigned long sampleRate;
  unsigned long byteRate;
  unsigned short blockAlign;
  unsigned short bitsPerSample;
  char subchunk2ID[4];
  long subchunk2Size;
};

boost::shared_ptr <AL::ALProxy> audioDeviceProxy;

wavheader * wavHeader = new wavheader;
fread(wavHeader,1,44,fInputWavFile);

'17.Speech based reaction'
- ALSpeechBasedReaction mostra como reagir a um comando de voz específico usando reconhecimento de voz (speech recognition).
- Este módulo pode ser remoto ou local.

/// This line will display a description of this module on the web page of the robot
setModuleDescription("This module launch a text to speech command when a "
                     "specific voice command is heard. To start "
                     "this module, call its startRecognition() method in Choregraphe.");

std::cout << "word recognized: " << val[i*2].toString()
          << " with confidence: " << (float)val[i*2+1] << std::endl;

/// If our "command" has been recognized, start a speech synthesis reaction
if((std::string)val[i*2] == fCommand && (float)val[i*2+1] > 0.15)
{
  fTextToSpeech->callVoid("say",std::string("Ok, Hello There!"));
}

'18.Sound based reaction'
- ALSoundBasedReaction faz o NAO dizer "Hello there" cada vez que um ruído súbito e alto for detectado (sudden and loud).
- Para fazer isto, ele usa o callback do método processSound.
- Este módulo pode ser remoto ou local.

#include <alproxies/altexttospeechproxy.h>
#include "alaudio/alsoundextractor.h"

ALTextToSpeechProxy fProxyToTextToSpeech;

void ALSoundBasedReaction::init()
{
  /// Setting up the appropriate language
  fProxyToTextToSpeech.setLanguage("English");

  audioDevice->callVoid("setClientPreferences",
                        getName(),                //Name of this module
                        16000,                    //16000 Hz requested
                        (int)FRONTCHANNEL,        //Front Channels requested
                        0                         //Deinterleaving is not needed here
                        );

  startDetection();
}

/// This function will be automatically called by the module ALAudioDevice
/// every 170ms with the appropriate audio buffer (front channel at 16000Hz)
void ALSoundBasedReaction::process(const int & nbOfChannels,
                                   const int & nbrOfSamplesByChannel,
                                   const AL_SOUND_FORMAT * buffer,
                                   const ALValue & timeStamp)
{
  
'19.Reacting to an audio event: loud noise'

'Princípio'
- Se você quer ter uma reação baseada em som, você precisa recuperar o som recebido pelos microfones do NAO. Para fazer isto, você deve 
implementar um tipo particular de módulo: este deve herdar de ALSoundExtractor.
- ALSoundExtractor implementa alguns métodos chave para ajudar a processar som:
       'process': Este método deve ser redefinido pelo usuário. É automaticamente chamado cada vez que um buffer de som é mandado, e seus 
       argumentos correspondem à informação do buffer. Você não deve se preocupar com qualquer otimização, já que isto será automaticamente 
       chamado no modo local se possível.
       'startDetection': Uma vez que este método foi chamado, buffers de som serão mandados regularmente com as preferências desejadas ao 
       método de processo.
       'stopDetection': Este método para as mensagens do buffer de som.
       
- As preferências do tipo do buffer a serem enviados são setados via um proxy para ALAudioDevice.
- Certifique-se de que a sua função de processamento de som tem um prazo de execução seja muito menor do que o tempo entre dois buffers de som,
ou seja thread-safe.

- Faz o NAO dizer "Hello there" cada vez que um ruido alto for identificado.

#include <alproxies/altexttospeechproxy.h>
#include "alaudio/alsoundextractor.h"

'20.Sound processing'
- ALSoundProcessing mostra como processar dados de som e interagir com ALMemory. Escreve o poder RMS de todos os 4 canais em ALMemory.
- Este é um módulo remoto ou local.

#include <alproxies/almemoryproxy.h>
#include <alaudio/alsoundextractor.h>

fALMemoryKeys.push_back("ALSoundProcessing/leftMicEnergy");
fALMemoryKeys.push_back("ALSoundProcessing/rightMicEnergy");
fALMemoryKeys.push_back("ALSoundProcessing/frontMicEnergy");
fALMemoryKeys.push_back("ALSoundProcessing/rearMicEnergy");

fProxyToALMemory.insertData(fALMemoryKeys[0],0.0f);
fProxyToALMemory.insertData(fALMemoryKeys[1],0.0f);
fProxyToALMemory.insertData(fALMemoryKeys[2],0.0f);
fProxyToALMemory.insertData(fALMemoryKeys[3],0.0f);

audioDevice->callVoid("setClientPreferences",
		      getName(),                //Name of this module
                      48000,                    //48000 Hz requested
                      (int)ALLCHANNELS,         //4 Channels requested
                      1                         //Deinterleaving requested
                      );
startDetection();

'21.C++ Tips and tricks'