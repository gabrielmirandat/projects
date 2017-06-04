'roscpp' - em C++.

Publisher/Subscriber
#include "ros/ros.h"                                     - inclui todos os header necessários no sistema ROS.
#include "std_msgs/String.h"                             - inclui a mensagem  std_msgs/String. Gerada automaticamente de String.msgdo pacote std_msgs.
ros::init(argc, argv, "talker");                         - inicializa o ROS, já nomeando o processo (nó).
ros::NodeHandle n;                                       - cria um handle ao processo nó. Gerencia alocação e desalocação dos recursos do nó.
ros::Publisher chatter_pub =                             - publica na master tópico chatter de tipo de mensagem std_msgs/String de tamanho de fila 1000.
    n.advertise<std_msgs::String>("chatter", 1000);      - retorna um ros::Publisher,que publica com publish().
ros::Rate loop_rate(10);                                 - especifica frequência do loop. Corrigido com Rate::sleep().
ros::ok()                                                - houve por interrupção SIGINT (Ctrl-C), rede, ros::shutdown() ou destruição de todos os ros::NodeHandles.
chatter_pub.publish(msg);                                - broadcast mensagem para qualquer um conectado.
ROS_INFO("%s", msg.data.c_str());                        - equivalente ao printf/cout.
ros::spinOnce();                                         - necessário para que callbacks sejam ouvidos.
loop_rate.sleep();                                       - espera para atingir a frequência especificada.
ros::Subscriber sub =                                    - inscreve-se no tópico chatter e chama o callback hatterCallback() sempre que receber mensagem.
    n.subscribe("chatter", 1000, chatterCallback);       - retorna um ros::Subscriber.
ros::spin()                                              - entra num loop chamando callbacks de mensagens o mais rápido que puder.

Service/Client
#include "beginner_tutorials/AddTwoInts.h"               - header gerado do arquivo de serviço srv.
bool add(beginner_tutorials::AddTwoInts::Request  &req,  - serviço de adicionar ints. Toma um request e um response e retorna um bool.
         beginner_tutorials::AddTwoInts::Response &res)  
ros::ServiceServer service =                             - cria serviço e indica ao master.
    n.advertiseService("add_two_ints", add);
ros::ServiceClient client =                              - cria um cliente para o serviço add_two_ints. ros::ServiceClient chama o serviço.
    n.serviceClient<beginner_tutorials::AddTwoInts>
    ("add_two_ints");
beginner_tutorials::AddTwoInts srv;                      - obtém serviço.
if (client.call(srv))                                    - chama serviço. Chamadas a serviços são bloqueantes.


'rospy' - em python.

Publisher/Subscriber
#!/usr/bin/env python                                    - coloca a certeza que o script é de python.
import rospy                                             - necessário importar se estamos usando um nó.
from std_msgs.msg import String                          - para reusar o tipo de mensagem std_msgs/String (simples container de string) para publicação.
pub = rospy.Publisher('chatter', String, queue_size=10)  - nó publica no tópico chatter usando mensagem tipo String.
rospy.init_node('talker', anonymous=True)                - inicia um nó chamado talker.
rate = rospy.Rate(10) # 10hz                             - Com a ajuda de sleep(), loop na taxa desejada.
rospy.is_shutdown()                                      - tem o mesmo efeito de ros::ok().
pub.publish(hello_str)                                   - publica uma string no tópico chatter.
rate.sleep()                                             - espera até alcançar a taxa desejada do loop.
rospy.loginfo(str)                                       - mostra na tela, salva no log do nó, escreve no rosout.
rospy.ROSInterruptException                              - lançada por rospy.sleep() e rospy.Rate.sleep().
rospy.Subscriber("chatter", String, callback)            - nó subscriber ouve no tópico chatter e emite um callback quando recebe mensagem.
rospy.spin()                                             - impede que o nó termine até que seja shutdown.

Service/Client
s = rospy.Service                                        - declara novo serviço add_two_ints de tipo de serviço AddTwoInts cujos requests são passados para handle_add_two_ints.
    ('add_two_ints', AddTwoInts, handle_add_two_ints)
rospy.spin()                                             - mantém código rodando enquanto serviço não acabar.
rospy.wait_for_service('add_two_ints')                   - bloqueia até que o serviço add_two_ints esteja disponível.
add_two_ints = rospy.ServiceProxy                        - handle para chamar o serviço.
    ('add_two_ints', AddTwoInts)
resp1 = add_two_ints(x, y)                               - chama o handle como uma função.