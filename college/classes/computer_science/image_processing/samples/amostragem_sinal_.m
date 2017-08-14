%Frequencia do sinal(em Hertz)
fc= 1;

%Frequencia de amostragem(em Hertz)
fa= 25;

%Periodo de amostragem(em segundos)
Ta=1/fa;

%Intervalo de simula��o em segundos
ti= 0;%Tempo inicial
tf= 1;%Tempo final
t= ti:Ta:tf;

%Simula a fun��o cont�nua
tcont = ti:(1/(100*fa)):tf;
ycont = 3*sin(2*pi*fc.*tcont);

%Amostragem do sinal
y = 3*sin(2*pi*fc.*t);

%Mostra a fun��o cont�nua(simulada) e
%sobrep�e o sinal em tempo discreto
plot(tcont, ycont)
hold on
stem(t,y,'ok')
xlabel('t (s)')
ylabel('V(t)')
legend('Sinal cont�nuo','Sinal em tempo discreto')
grid on
