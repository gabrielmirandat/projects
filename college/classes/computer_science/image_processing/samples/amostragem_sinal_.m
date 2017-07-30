%Frequencia do sinal(em Hertz)
fc= 1;

%Frequencia de amostragem(em Hertz)
fa= 25;

%Periodo de amostragem(em segundos)
Ta=1/fa;

%Intervalo de simulação em segundos
ti= 0;%Tempo inicial
tf= 1;%Tempo final
t= ti:Ta:tf;

%Simula a função contínua
tcont = ti:(1/(100*fa)):tf;
ycont = 3*sin(2*pi*fc.*tcont);

%Amostragem do sinal
y = 3*sin(2*pi*fc.*t);

%Mostra a função contínua(simulada) e
%sobrepõe o sinal em tempo discreto
plot(tcont, ycont)
hold on
stem(t,y,'ok')
xlabel('t (s)')
ylabel('V(t)')
legend('Sinal contínuo','Sinal em tempo discreto')
grid on
