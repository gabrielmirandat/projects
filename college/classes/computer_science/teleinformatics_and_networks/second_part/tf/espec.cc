TFinal TR2

- commitar no git
- 'aula anterior': definição dos módulos e o que deve ser feito
- 'para terça': definição de líderes, responsabilidades, tarefas, ..
- Módulos: CAMERA
		   SERVIDOR
		   INTERFACE (DB)
- Arduíno + sensor de presença
  Gravar vídeo quando o sensor de presença ativar

- ATA reunião 1
	- uso do github
	- servidor web em DJango
	- interface em HTML, CSS, Javascript com bootstrap
	- líderes:
		- geral: Yan
		- grupo câmera: Hugo
		- grupo servidor web: 
		- grupo interface web: 

- Trab final - reunião 8/11
	- usar Slack por integração com git
	- Toggl - timer
	- HelloWorld biblioteca iniciar imagem ou vídeo de forma remota
		- Real Message Time Protocol
	- Trello do Slack


Grupo 1, Como fazer captura usando o Android
É possível manter o celular em modo inativo e iniciar a captura após algum evento específico?
https://developer.android.com/reference/android/hardware/camera2/package-summary.html
https://inducesmile.com/android/android-camera2-api-example-tutorial/

Grupo 2, Comunicação Wireless entre sensor e arduíno
Escolher sensor adequado, verificar se resolve adequadamente o contexto pedido
http://www.huinfinito.com.br/sensores/469-modulo-sensor-ultrassonico-hc-sr04.html
http://www.huinfinito.com.br/sensores/22-modulo-sensor-de-movimento.html
http://www.huinfinito.com.br/sensores/464-modulo-sensor-de-som.html

Grupo 3, Como enviar sinais do arduíno até o android
Maioria desses links usa Bluetooth, estudar alcance
http://www.instructables.com/id/How-to-Receive-Arduino-Sensor-Data-on-Your-Android/
http://www.buildcircuit.com/how-to-send-data-from-android-to-arduino/
https://wingoodharry.wordpress.com/2014/04/15/android-sendreceive-data-with-arduino-using-bluetooth-part-2/

Grupo 4, Como enviar imagens/vídeos do celular para o servidor
http://stackoverflow.com/questions/18245849/how-to-transmit-android-real-time-sensor-data-to-computer (usa Wi-fi)

Grupo 5, como enviar comandos do PC para o android
Essa parte é necessária caso o usuário deseje mandar comando "inicia gravação", posteriormente, será feita uma interface em cima disso
http://stackoverflow.com/questions/6267696/sending-commands-from-a-pc-to-an-android-phone-via-physical-connection-usb-s (interface física nesse link)
http://android.wonderhowto.com/how-to/send-adb-commands-over-wi-fi-android-0160216/