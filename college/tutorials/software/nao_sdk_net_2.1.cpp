'1.Creating events'
-> criação de eventos só funcionam para módulos locais.
'Event creation principle'
-> Alguns eventos já existem nos módulos Aldebaran. Como o de detectar face. 
-> Porém é desejável criar novos eventos para que se possa usar em métodos callback.
-> 'ALMemory proxy' = criação e levantamento de eventos.
-> Uma vez que um módulo declara um evento, todos os módulos inscritos neste evento serão notificados quando o valor do evento mudar.
#criando evento => proxy para ALMemory
AL::ALMemoryProxy memProxy = AL::ALMemoryProxy(getBroker())
memProxy.declareEvent("EventName")
#para levantar o evento
memProxy.raiseEvent("EventName", eventValue)
-> O valor do evento pode ser qualquer tipo básico.

### exemplo: módulo de eventos ###
-> Gera um evento chamado "ExampleEvent", se inscrevendo nele e mostrando uma mensagem sempre que ele é lançado.

_events.h_
const AL::ALValue &value, const AL::ALValue &msg //armazenam valor do evento
_events.cpp_
functionName("callback", getName(), "");	 //cria a função callback 
BIND_METHOD(Events::callback);			 //inscreve ela no evento
generateEvent(42.0);				 //gera evento ExampleEvent com o valor 42.0
  fMemoryProxy.raiseEvent("ExampleEvent", value);//função que levanta evento com o valor

'2.Say Hello World'
-> 'ALTextSpeech proxy (TTS)' = faz NAO falar.
_sayhelloworld.cpp_
AL::ALTextToSpeechProxy tts(argv[1], 9559);	//cria um proxy ALTextToSpeechProxy
tts.say(phraseToSay);				//chama o método que faz o NAO falar

'3.Creating a simple remote module'
-> Objetivo: criar métodos que possam ser acessados pelo mundo exterior, e como acessar estes módulos do mundo exterior.
# ALModule = permite vincular métodos ao mundo exterior e ser executado remotamente ou como um plugin dentro do NAOqi.
# Funções com incrições no construtor. São imperativos, caso contrário os métodos não seriam visíveis ao mundo exterior.
# Métodos inscritos podem apenas ter argumentos const ref de tipos básicos ou AL:ALValue ou retornar tipos básicos ou um AL::ALValue.

'3.1.Example: HelloWorld module'
_helloworld.h_
class HelloWorld : public AL::ALModule		//herda de ALModule para poder ser usado remotamente
_helloword.cpp_
HelloWorld::HelloWorld(boost::shared_ptr<ALBroker> broker, const std::string& name): ALModule(broker, name)
						//sendo HelloWorld assim definido, os métodos inscritos são visíveis no mundo exterior
functionName("sayHello", getName(), "Say hello to the world");
BIND_METHOD(HelloWorld::sayHello);		//método visível no exterior

### exemplo: módulo de acesso ###
-> Módulo para acessar o módulo HelloWorld do mundo exterior.
# Cria um proxy genérico para o módulo "HelloWorld". Argumentos do construtor são: 

_testhelloworld.cpp_
boost::shared_ptr<AL::ALProxy> testProxy 
	    = boost::shared_ptr<AL::ALProxy>(new AL::ALProxy(broker, "HelloWorld"));		//cria um proxy de teste para acesso
testProxy->callVoid("sayHello");		 //chama o método sayHello usando o proxy criado. Já que retorna void, chame-o usando callVoid    
testProxy->callVoid("sayText", std::string("This is a test."));	
int sentenceLength = testProxy->call<int>("sayTextAndReturnLength",
            std::string("This is another test"));//como aqui o método retorna o tamanho, chamamos o método de chamada com o tipo retornado entre <>


'4.Creating a custom main'
_main.cpp_
AL::ALBrokerManager::setInstance(broker->fBrokerManager.lock());	//cria um fBrokerManager Singleton com .lock()
AL::ALBrokerManager::getInstance()->addBroker(broker);
//Agora carregue seu módulo com
AL::ALModule::createModule<YourModule>(broker, "YourModule");

'5.Moving NAO’s head'
-> 'ALMotion proxy' = mover cabeça do NAO (movimento).
const AL::ALValue jointName = "HeadYaw";			//representa a articulação a ser movida. É um ALValue!
AL::ALMotionProxy motion(argv[1], 9559);			//cria proxy movimentador
motion.stiffnessInterpolation(jointName, stiffness, time);	//seta a rigidez da cabeça (ir para máximo em um segundo)
motion.angleInterpolation(jointName, targetAngles, targetTimes, isAbsolute);	//executa movimentação, após setados os parâmetros necessários

'6.Reacting to an event: bumper'
'6.1 Principle'
-> 'ALMemory proxy' = para reagir com eventos. Após ALMemory, chamar subscribeToEvent.
//Use ou o broker(se dentro de um módulo) ou o endereço de ip para criar este proxy.
//Daí só é preciso indicar qual o nome do evento e a função callback pra ele (o módulo de onde ela vem também - já feito).
AL::ALMemoryProxy memProxy = AL::ALMemoryProxy(getBroker());
memProxy.subscribeToEvent("eventName", "ModuleForCallback", "callbackFunctionName");

-> 'ALMutex' = para construir threads seguras 
AL::ALMutex::createALMutex;
AL::ALCriticalSection section(mutex)
//Adicione <althread/almutex.h> for the mutex, and <althread/alcriticalsection.h>

'6.2 Control the LEDs'
-> 'ALLeds proxy' = para controlar os leds do NAO.
