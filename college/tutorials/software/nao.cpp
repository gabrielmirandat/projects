NAOQI C++ SDK 1.14.5			-kits para desenvolvimento NAO
NAOQI C++ Cross Toolchain 1.14.5	-compilador para embarcado (o nao por si só não suporta um compilador)
Qibuild 1.14.3				-maneja dependencias entre projetos e suporta compilação cruzada (p/ compilar - compatível com ROS)
Choregraphe				-criar animações, comportamentos, diálogos(simulado ou diretamente no robô)
Webots for nao				-simulador para o NAO

'NAOqi' is a program that runs on the robot (it can also run on the computer and communicate with naoqi on the robot, but lets forget about that 
for now). It manages the loading of modules, communication between modules, and acts as the higher-level interface with the hardware.
  
'qiBuild' is a program that runs on the development computer. Its the most important build tool for NAO developers: you use it to configure a 
project, compile it and deploy it on the robot.
Qibuild can configure projects for various robots (Atom or Geode NAO) or to run on a separate computer. For that, it uses CMake, wich is a 
cross-platform and multi-platform meta-build tool. 
You need to give qibuild a 'toolchain name' to let it know which set of tools to use to build your project. You typically will have a toolchain
that contains a compiler and a linker configured for the architecture of your robot (Linux on 32 bit Intel Atom or AMD Geode).
We will also deal a little with common Unix tools like bash, ssh, scp...

ROBOCUP (Competição e simpósio)
- Objetivo: Até a metade deste século, desenvolver uma equipa de robôs humanóides totalmente autônomos capazes de derrotar a equipa campeã 
mundial de futebol humana. 'B-HUMAN'

- Competição: RobocupSoccer, RobocupRescue e RobocupJunior
- Simpósio: após as competições (apresentados e discutidos trabalhos científicos da área)
Todos tem a obrigação de disponibilizar o código.

Competições Existentes:
1) RobocupSoccer
  --Middle size league
  --Small size league
  --Four-legged league
  --Simulation league
  --Humanoid league
  --E-league (simplificada)
2) RobocupRescue
  --Robot league
  --Simulation league
3) RoboCup Junior
4) Robocup@Home

ALDEBARAN
CONTA: unb.lara@gmail.com
SENHA: r0NAOd0

#P/ COMPILAR 1.14	dentro da pasta do programa
qitoolchain create atom ~/nao/devtools/naoqi-sdk-1.14.5-linux64/toolchain.xml	//cria toolchain atom
qibuild configure -c atom	
qibuild make -c atom
qitoolchain create local ~/nao/devtools/naoqi-sdk-1.14.5-linux64/toolchain.xml	//cria toolchain local
qibuild configure -c local
qibuild make -c local
build-local/sdk/bin/nome_do_arquivo_cpp 192.168.0.10 //NAO IP adress

make clean: limpa todos os arquivos gerados pelo makefile

-> Só o NAO de bigode funciona (versão 2)
-> Biblioteca RTI (de tempo real)

navegador: 10.0.44.13 (IP)
senha: nao e nao
terminal: ssh://nao@10.0.44.13
senha:nao
cd naoqi
connect to server: ssh nao@10.0.44.13

-> diretórios invisíveis na $HOME => começam com um . ('PARA VÊ-LOS $ls -a')
-> 'echo' = para printar uma string que vem após echo
-> 'echo' + >> = pega string de echo que escreve ao fim do arquivo que vem depois do >>.

'qitoolchain'
qitoolchain --help
qitoolchain list//lists all toolchains
qitoolchain info atom //more info about the toolchain with nickname atom
qitoolchain remove geode //deletes the toolchain with nickname geode

-> qisrc add . //após adicionar exemplo no workspace pro qitoolchain

#P/ COMPILAR 2.1	dentro da pasta do programa
>> qitoolchain create atom ~/nao/devtools2.1/naoqi-sdk-2.10.5-linux64/toolchain.xml
>> qibuild configure -c atom
>> qibuild make -c atom 
>> cd /teste
>> qibuild open
>> y
- No QT
>> troca pasta para teste/build-atom
- Pronto!


