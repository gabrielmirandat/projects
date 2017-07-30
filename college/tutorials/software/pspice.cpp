r - resistor
Vdc - fonte de tensão
gnd_earth - terra
bubble - para nomear nós do circuito - pode ser usado para identificar partes separadas do circuito



spice
- linguagem de programação em C
- netlist: descrição do circuito

AC sweep - simular magnitude x frequência
DC sweep
Transient - calcula diversos valores do circuito ao longo do tempo

4 programas principais
Schematics - onde é editado o circuito
Spice - compilação e interpretação
Probe - vizualização gráfica dos resultados
Stimulus editor - edição de estimulos de entrada

Em PSpice Schematics
- clicar Draw -> Get New Part - Ctrl + G ou clicar no ícone binóculo
	* libraries - bibliotecas de componentes
	* Advanced - ver desenho do componente
	* zoom area
	* girar - selecionar + Ctrl + R
	* Clicar V(Enable Bias Voltage Display) ou I(Enable Bias Current Display)
	- clicar Simulate
		* View Simulation Output File
- clicar em Analysis -> Setup - tipos de simulações
	* DC Sweep - simulação mudando valor de dispositivo com o tempo
		- clicar Simulate
			* Add Trace
			* p/ mudar eixo - duplo clique eixo e seleciona
	* Transfer function - nos diz a relação entre tensão de saída e tensão de entrada
		* V(Vs) e Vce
			- clicar Simulate
				* View Simulation Output File 
	* AC Sweep - correntes e tensões do circuito em função da frequência
		* Necessário Vac ou Iac (ou combinação)
			* ACMAG - magnitude do sinal AC - expressa valor RMS ou valor de pico
		* Linear
		* Colocar marcador de tensão pra ir pro Probe direto
			*DB - decibéis
		* Toggle cursor - pra mexer cursor no gráfico


