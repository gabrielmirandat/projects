%
% mychatbot2.pl
% Este eh um segundo exemplo de chatbot em Prolog
% 
% Baseado em chatterbot2.pl, de Gonzales Cenelia
% http://ai-programming.com/prolog_bot_tutorial.htm
%

:- dynamic(knowledge_base/2).

knowledge_base('Como vc se chama?', 
	['Meu nome eh chatbot.',
 	 'Por que vc quer saber meu nome?']).

knowledge_base('Oi', 
	['Ola!',
 	 'Como vai vc?']).

knowledge_base('Tudo bem?', 
	['Tudo otimo!',
 	 'Tudo bem, e vc?']).

knowledge_base('Quem eh vc?', 
	['Sou um robo.',
 	 'Por que vc quer saber?']).

knowledge_base(bye, 
	['Ate mais! Foi otimo conversar com voce']).

knowledge_base(_, []).

search_base(Input, Found) :-
	knowledge_base(Input, Found), !.

quit_session(Input):- 
	Input = bye.

get_response([], Response) :- 
	write('Nao entendo o que vc quer dizer.'), nl,
	write('Por favor, escreva uma pergunta e me ensine a resposta.'), nl,
	write('Pergunta: '),
	read(Q),
	write('Resposta: '),
	read(A),
	asserta(knowledge_base(Q,[A])),  % asserta: insere no inicio da base
	Response = 'Ok, continue falando comigo.', !.
	
get_response(RespList, Response) :-
	length(RespList, NumOfResponse),
	IndexOfResponse is random(NumOfResponse),
	nth0(IndexOfResponse, RespList, Response), !.
		
main:- 
	repeat,
	nl, write('> '),
	read(Input),
	search_base(Input, ListOfResponse),
	get_response(ListOfResponse, Response),
	write(Response), nl,
	quit_session(Input).

