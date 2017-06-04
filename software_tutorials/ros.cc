$ sudo chown -R <your_username> ~/.ros                  # muda permissão de diretório recursivamente.
rostopic pub /cmd_vel geometry_msgs/Twist -r 1 -- '[2.0, 0.0, 0.0]' '[0.0, 0.0, -1.8]'
$ rostopic pub -1 /v_left std_msgs/Float32 -- 0.5
$ rostopic pub -1 /v_right std_msgs/Float32 -- 0.5

14.04 - Indigo
16.04 - Kinetic

workspace_folder/      			-- WORKSPACE
  src/                          -- SOURCE SPACE
    CMakeLists.txt      		-- 'Toplevel' CMake file, provided by catkin
    package_1/
      CMakeLists.txt     		-- CMakeLists.txt file 1for package_1
      package.xml       		-- Package manifest 1for package_1
    ...
    package_n/
      CMakeLists.txt     		-- CMakeLists.txt file 1for package_n
      package.xml       		-- Package manifest 1for package_n

# Estruturas de arquivos
catkin ou rosbuild

# Variáveis de ambiente (lançadas com $ echo)
$ROS_PACKAGE_PATH  						- indica qual o workspace 1do topo.
$ROSDISTRO_NAME     					- indica qual a versão 1do ros instalada.
$ROS_HOSTNAME        					- indica o hospedeiro usado pelo ros.

# Conceitos de Arquitetura
Pacotes                               - unidade. Contém nós, libs, bancos de dados, arquivos de config.
MetaPacotes                        	  - pacotes com o objetivo único de unir outros pacotes.
Manifesto (package.xml)     		  - metadados sobre o pacote (nome, descrição, dependências, ..).
Repositórios                          - coleção de pacotes que constituem uma release.
Tipos mensagens (msg)       		  - define a estruturas das mensagens ( my_package/msg/MyMessageType.msg).
Tipos serviços (srv)              	  - define estruturas de chamadas e respostas de serviços (my_package/srv/MyServiceType.srv).

# Conceitos de recursos
Nó                        - qualquer processo escrito com uma lib cliente ros (roscpp ou rospy).
Master                    - tabela lookup de nomes para haver comunicação de nós, trocas de mensagens e serviços.
Servidor de parâmetros    - parte 1do Master. Provê o armazenamento das chaves de forma centralizada.
Mensagens                 - estruturas de comunicação trocadas entre nós.
Tópicos                   - transporte muitos para muitos de mensagens de fluxo unidirecional contínuo de dados dos nós. Via publish/subscribe (dados de sensores, estado, ..).
Serviços                  - transporte remoto para par de mensagens de nós servidor e cliente de duração curta. Via request/reply (requerer dado específico).
Bags                      - formato para salvar e recuperar mensagens de nós.
Rosout                    - saída padrão 1do ros (stdout/stderr).
Roscore                   - Master + Rosout + Servidor de parâmetros.
Lib Cliente               - permite que nós escritos em diferentes linguagens possam se comunicar.

'Inicialização do sistema'
$ source /opt/ros/indigo/setup.bash 		# rode este comando em cada novo terminal (a menos que adicione a linha ao .bashrc).
$ printenv | grep ROS 						# checa se variáveis do ambiente estão setadas.
$ . ~/catkin_ws/devel/setup.bash			# coloca workspace atual no topo do ambiente. Use sempre após catkin_make.


'Recursos de terminal para o workspace do topo' - rosbash
$ rospack find roscpp                                           # retorna o caminho de um pacote.
$ roscd roscpp                                                  # move para a pasta 1do pacote ou pilha.
$ roscd log                                                     # move para a pasta de logs 1do ros.
$ rosls roscpp_tutorials                                        # mostra todos os arquivos de dentro da pasta 1do pacote.
$ rosed roscpp Logger.msg                                       # permite editar um arquivo de um pacote.
$ roscp rospy_tutorials AddTwoInts.srv srv/AddTwoInts.srv       # copia arquivos de um pacote para outro.

'Workspace'
$ catkin_init_workspace             			# cria workspace (em catkin_ws/src/).
$ catkin_make  &  source devel/setup.sh    		# compila pacotes 1do workspace (em catkin_ws/).
$ catkin_make --source my_src   				# compila um pacote fora 1do workspace.

'Pacote'
$ catkin_create_pkg beginner_tutorials std_msgs rospy roscpp       # cria pacote com dependências (em /catkin_ws/src/)
$ rospack depends1 beginner_tutorials                              # mostra dependências primárias de pacote.
$ rospack depends beginner_tutorials                               # mostra toda a grade de dependências.

'Sistema'
$ roscore                                                # inicializa o sistema ros (Master + Rosout + Servidor de parâmetros).

'Nós'
$ rosnode list                                           # lista todos os nós atualmente ativos.
$ rosnode info /rosout                                   # retorna informações de um nó específico ativo.
$ rosrun turtlesim turtlesim_node                        # executa nó de um pacote.
$ rosrun beginner_tutorials talker                       # executa um nó em c++
$ rosrun beginner_tutorials talker.py                    # executa um nó em python.
$ rosrun turtlesim turtlesim_node __name:=my_turtle      # executa nó de um pacote atribuindo-lhe um nome customizado.
$ rosnode cleanup                                        # limpa a lista de nós ativos.
$ rosnode ping my_turtle                                 # testa se um nó está respondendo na rede.
$ roslaunch beginner_tutorials turtlemimic.launch        # lança vários nós de acordo com um arquivo launch.

* turtlesim turtlesim_node
* turtlesim turtle_teleop_key
* rqt_graph rqt_graph
* rqt_plot rqt_plot
* rqt_console rqt_console
* rqt_logger_level rqt_logger_level

'Tópicos' - publish/ subscribe
$ rostopic info /hokuyo_scan                             # mostra informações básicas do tópico, tipo de mensagem, quem publica e escuta.
$ rostopic echo /turtle1/cmd_vel                         # mostra dados das mensagens publicadas em determinado tópico em tempo real.
$ rostopic list -v                                       # lista todos os tópicos (e tipos de mensagens ) que atualmente possuem nós publicadores e subscritos .
$ rostopic type /turtle1/cmd_vel                         # mostra o tipo de mensagem de um tópico sendo publicado.
$ rostopic type /turtle1/cmd_vel | rosmsg show           # mostra detalhes 1do tipo da mensagem de um tópico sendo publicado.
$ rostopic pub -1 /turtle1/cmd_vel geometry_msgs/Twist   # publica uma mensagem em um tópico.
	-- '[2.0, 0.0, 0.0]' '[0.0, 0.0, 1.8]'
$ rostopic pub /turtle1/cmd_vel geometry_msgs/Twist      # publica mensagens recursivamente a 1Hz em um tópico.
    -r 1 -- '[2.0, 0.0, 0.0]' '[0.0, 0.0, -1.8]'
$ rostopic pub /turtle1/cmd_vel geometry_msgs/Twist      # publica mensagens ditando campos de forma explícita.
    -r 1 -- '{linear: {x: 2.0, y: 0.0, z: 0.0},
    		 angular: {x: 0.0,y: 0.0,z: 0.0}}'
$ rostopic hz /turtle1/pose                              # mostra a taxa de publicação de dados num tópico.


'Mensagens' - arquivo com um campo type e um campo name em cada linha. Gera mensagens para diferentes linguagens.
$ rosmsg show geometry_msgs/Twist                        # mostra detalhes de um determinado tipo de mensagem.
$ echo "int64 num" > msg/Num.msg                         # cria uma mensagem dentro de msg/ de um pacote.

* geometry_msgs/Twist
* beginner_tutorials/Num

'Serviços' - arquivo que especifica um request e um response separados por ---.  Gera serviços para diferentes linguagens.
$ rosservice list                                        # lista todos os serviços prestados pelos nós atualmente ativos.
$ rosservice type /clear                                 # indica o tipo 1do serviço.
$ rosservice type /spawn | rossrv show                   # indica os argumentos de solicitação e de resposta de determinado tipo de serviço.
$ rosservice call /clear null                            # chama um serviço com seus argumentos.
$ rossrv show beginner_tutorials/AddTwoInts              # mostra os campos de um serviço.

'Parâmetros' - armazenar e manipular dados no Servidor (matar um nó mantém seus parâmetros) de Parâmetros
$ rosparam list                                          # lista os parâmetros atuais no servidor de parâmetros.
$ rosparam set /background_r 150                         # altera (necessita chamar rosservice call /clear após) um parâmetro no servidor de parâmetros.
$ rosparam get /background_g                             # obtém o valor de um parâmetro no servidor de parâmetros.
$ rosparam get /                                         # obtém os valores de todos os parâmetros no servidor de parâmetros.
$ rosparam get /copy/background_b                        # obtém o valor de um parâmetro em determinado 1namespace  1do servidor de parâmetros.
$ rosparam dump params.yaml                              # armazena todos os parâmetros 1do servidor de parâmetros num arquivo.
$ rosparam load params.yaml copy                         # carrega valores de parâmetros em arquivo em determinado 1namespace 1do servidor de Parâmetros.

'Bag' - armazenar dados de tópicos em execução.
$ rosbag record -a                                       # armazena todas as mensagens publicadas em tópicos num arquivo de Bag.
$ rosbag info <your bagfile>                             # checa o conteúdo de um arquivo bag sem executá-lo.
$ rosbag play <your bagfile>                             # executa um arquivo bag.
$ rosbag play -r 2 <your bagfile>                        # executa arquivo bag com ratio de publicação alterado.
$ rosbag record -O subset /turtle1/cmd_vel /turtle1/pose # salva bag de nome subset armazenando dados de tópicos específicos.

'Utensílios'
'rqt'
$ rqt                                                    # lança o ros Qt.

'rqt_graph'
$ rosrun rqt_graph rqt_graph                             # gráfico 1do que está acontecendo com os recursos 1do sistema.

'rqt_plot'
$ rosrun rqt_plot rqt_plot                               # inicia o rqt_plot.

'rqr_console'
$ rosrun rqt_console rqt_console                         # anexado a estrutura de registros 1do ros para exibir a saída dos nós.

'rqt_logger_level'
$ rosrun rqt_logger_level rqt_logger_level               # permite alterar o nível de verbosidade dos nós (DEBUG, WARN, INFO e ERROR) enquanto eles rodam.

'roswtf'
$ roswtf                                                 # examina ros procurando por warnings e erros.

'Gazebo' - simulador para vários tipos de robôs.
$ rosrun gazebo_ros gazebo 								               # roda tanto o servidor quanto o cliente gazebo.
$ rosrun gazebo_ros gzserver 							               # roda o servidor gazebo.
$ rosrun gazebo_ros gzclient 							               # roda o cliente gazebo.
$ roslaunch gazebo_ros empty_world.launch 				       		   # roda gazebo através de launch.

rostopic pub -1 /motor_pwm hector_uav_msgs/MotorPWM -- '[2.0, 0.0, 0.0]' '[0.0, 0.0, 1.8]'