//------------------------------------------------CHATBOT-----------------------------------------------------------//
1) Caracterize o chatbot escolhido (2,0) descrevendo domínio de aplicação, disponibilidade, facilidade de uso, linguagem em que foi construído, 
etc.

2) Apresente um diálogo com o chatbot (1,0) e analise as respostas dadas por ele (1,0) procurando mostrar que o chatbot não possui memória e que 
não entendeu as informações passadas a ele (2,0).

3) Apresente o algoritmo utilizado pelo chatbot para responder ao diálogo mantido por você com ele (2,0) e mostre qual foi o "raciocínio" dele 
para apresentar as respostas ao seu diálogo (2,0).

A sua análise deve ser apresentada na forma de um relatório (arquivo pdf).

//------------------------------------------------------------------------------------------------------------------//

//------------------------------------------------ADVINHO-----------------------------------------------------------//

1) Programas Prolog do tipo "adivinho", isto é, você dialogo com o programa respondendo a perguntas formuladas por ele e, ao final, o programa 
"adivinha" o que você estava pensando (2,0)!

2) Descreva o código Prolog do programa escolhido (5,0). Estenda esse código para permitir o aprendizado quando o programa for incapaz de 
adivinhar a resposta correta (4,0).

3) Envie o original do código do programa Prolog e o código estendido por você, juntamente com a pergunta e as características que permitirão à 
nova versão adivinhar corretamente o que você pensou!

//------------------------------------------------------------------------------------------------------------------//

CHATBOT

1) O chatbot escolhido foi o ELIZA, o primeiro software para simulação de diálogos. Usa técnicas de Inteligência Artifical para simular um diálogo 
entre paciente e psicólogo utilizando as frases do paciente para formular novas perguntas. É uma simulação de um Psicoterapeuta Rogeriano, que é 
uma técnica de resolução de conflitos baseado em encontrar um terreno comum em vez de debate argumentativo (Aristótelis). Tenta-se na discussão 
encontrar áreas de experiência compartilhada e, portanto, permite palestrante e público a abrir seus mundos para o outro numa compreensão mútua.
O código está disponível em http://cs.nyu.edu/courses/fall11/CSCI-GA.2110-003/documents/eliza.pl
(versão Prolog), e já foi recriado em diversas linguagens, sendo originalmente escrito em SLIP. O programa é muito simples de ser usado, bastando 
executá-lo com ['eliza.pl'] e escrevendo o que desejar no prompt, sendo que não é necessário escrever nada com o ponto final (.).

2) 
Hello. I am ELIZA. How can I help you?
> I just want to talk.

You say you just want to talk
> Yes.

You seem quite positive.
> The name of my cat is Katiolino.

I am not interested in names.
> Why not?

I am not sure I understand you fully.

ELIZA não entendeu que perguntei porque ela não se interessa por nomes.

3) 
O formato das regras utilizadas é a seguinte:
% rules([[keyword, importance of keyword],[[pattern #, [the pattern], last response used,[response 1],[response 2],...,[response n]]]]).

O loop principal de ELIZA é o que segue:

eliza :-
%	reconsult('eliza.rls'),							#recarrega arquivo - comentado
	retractall(mem(_)),nl,nl,						#tratamento especial se memoria
        write('Hello. I am ELIZA. How can I help you?'),nl,write('> '),		#escreve na tela
	repeat,									#repete enquanto o resto não é TRUE
	   read_atomics(Input),nl,						#lê input, tira pontuações, converte em lista de átomos
           process_input(Input,[],Input2),					#retorna parte do input depois de virgula ou antes de período
           simplify(Input2,Input3),						#simplificações não sobrepostas, Listas em resultado
           findkeywords(Input3,KeyWords),					#retorna lista com keywords. Se não encontrar, memory ou none
           sortkeywords(KeyWords,KeyWords2),					#ordenação das keywords por importancia
           makecomment(KeyWords2,Input3,Comment),				#retorna resposta baseada nas keywords. Toma cuidado com your e memory
           flatten(Comment,Comment2),						#transforma lista em sublistas
           writecomment(Comment2),nl,write('> '),				#Printa na tela a lista anterior em strings na tela
           quittime(Input3),							#checa pelo átomo quit. Se tiver, sai do programa imediatamente
           !.
:- eliza,nl,nl.

> I just want to talk.

resposta:
rules([[you,0],[
		...
		[12,[X],0,
		[you,say,X],
		[can,you,elaborate,on,that,?],
		[do,you,say,X,for,some,special,reason,?],
		[that,is,quite,interesting,.]]]]).
Converte o I (eu) em You (você) e repete minha frase.

> Yes.

resposta:
rules([[yes,0],[
	[1,[_],0,
		[you,seem,quite,positive,.],
		[you,are,sure,?],
		[i,see,.],
		[i,understand,.]]]]).
Ela entendeu o átomo yes e mandou uma resposta qualquer para quando encontra este átomo, mas sem entender realemente que só queria 
conversar e sem dar continuidade à conversa.


> The name of my cat is Katiolino.

resposta:
rules([[name,15],[
	[1,[_],0,
		['I',am,not,interested,in,names,.],
		['I',have,told,you,before,',','I',do,not,care,about,names,.],
	just	[please,continue,.]]]]).
Aqui ela encontrou que a palavra mais relevante[ de minha frase era name e me respondeu com "I am not interested in names.".

> Why not?

resposta:
rules([[none,0],[
	[1,[_],0,
		['I',am,not,sure,'I',understand,you,fully,.],
		[please,go,on,.],
		[what,does,that,suggest,to,you,?],
		[do,you,feel,strongly,about,discussing,such,things,?]]]]).
Aqui ela não encontrou nenhuma regra que se casasse ou com Why ou com not, logo mandou a resposta default de quando não entende.


