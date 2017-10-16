// Os casos devem ser rodados de forma automatizada
// Como se pode compilar e rodar os casos
// Documento (pdf ou odt) com os gráficos e as respostas para as perguntas
// programa_matricula_primeironome.c (Ex: recursao_06_12345_Jose.c, recursao_06_12345_Jose.pdf) e um 06_12345_Jose.txt dizendo como compilar e rodar os programas.

OLHAR TABELA DE VALORES DE TESTES
Valor A - 1 2 4 8 16 2 1 1 1 8
Valor B - 2 2 2 2 4 1 1 1 4 4
Valor C - 0 0 0 0 0 1 1 1 0 0
Valor D - 0 0 0 0 0 0 0 1 1 8
Valor E - 1 1 1 1 1 1 1 1 2 2
Valor F - 0 0 0 0 0 0 0 2 0 0

P/cada f(n) sendo: 1 (constante), n, n 2 , n 3
P/n sendo 50 100 200 400 800 1000 2000 4000 8000 16000 32000 64000 128000
Fazendo a média de 10 rodadas para cada caso

- 'gráfico para estes casos'
  a) Para cada f(n)= 1 (constante), n, n 2 , n 3 e cada possibilidade de a-f da tabela, o eixo x é o valor de n=50-128000 e o eixo y é o tempo para os casos n =50-128000
  b) Repita o item a) só que o eixo y é dado pelo tempo teórico dado pelo método mestre, nos casos onde se aplica
  c) Para f(n)= n 2 e cada possibilidade de a-f da tabela e casos n =50-128000 faça um gráfico onde o eixo x é o número do
      nível (1 sendo a raiz e crescendo para as folhas), e o eixo y é a soma dos tempos naquele nível
  d) Para f(n)= n e cada possibilidade de a-f e casos n =50-128000 faça um gráfico onde o eixo x é o número da linha (1 sendo
      a raiz e crescendo em direção as folhas), e o eixo y é o número de chamadas a funções naquela linha

- 'perguntas' grande parte da nota deste trabalho depende de justificativas adequadas
  1) Nos casos em que o método mestre se aplica:
    a) Como os tempos gastos se relacionam com o método mestre ?
    b) De acordo com o método mestre qual era o tempo esperado? O tempo obtido foi maior ou menor? A diferença pode ser explicada com uma multiplicação por constante?
    c) Como o número de linhas na árvore de recursão e o número de chamadas a funções em cada linha está relacionado ao método mestre?
    d) Como os tempos de execução mudam em cada uma das linhas da árvore para cada um dos casos?

  2) Para os casos executados, calculando o tamanho total da árvore em termos de número de chamadas recursivas e tempo por cada chamada,
      o tempo total está de acordo com o esperado?

  3) Nos casos em que a árvore de recursão e desbalanceada, o que acontece com o tempo por nível? O que acontece com o tempo para
      cada f(n)? O tempo f(n) aumenta ou diminui quando n cresce?

  4) Nas recursões em que os valores de c ou f são diferentes de zero, os resultados obtidos
      estão de acordo com as complexidades esperadas?

  5) Para os casos onde não foi possível executar a recursão até o final, faça uma estimativa,
      baseada na teoria, de quanto tempo demoraria para rodar a recursão


- 'objetivos'
  - simular relação de recorrencia 'T(n) = aT( (n/b) - c ) + dT( (n/e) - f ) + f(n)', todos valores inteiros

  - medir o tempo total gasto para executar a recursão até a condição de saída que é n <= 1
    a) A altura da árvore, ou seja, quantas recursões têm de ser feitas até se chegar na condição de saída.
        A árvore pode ser desbalanceada, o que faz com que um lado seja maior que o outro.
    b) O trabalho por nível. Cada nível pode demorar um tempo diferente.
    c) O número de recursões por nível.
    d) O tempo total para a execução da árvore.
    e) O tempo total para cada f(n), sendo que n varia para em cada chamada. A mesma árvore pode ter várias recursões f(n)

  - programa também deve imprimir na saída padrão o resultado dado pelo método mestre, se o método mestre puder ser aplicado
    Ex: calcula_recorrencia 4 2 0 0 1 0 1 2048

    - O programa deve calcular o tempo dado pelo método mestre (o Theta) de forma semelhante ao mostrado anteriormente.
    Ex: calcular quantas iterações n logb a , n logb a * log n e f(n) (dependendo do a e b no método mestre) mudando a função f(n) em:
    A seguir, o programa deve ser capaz medir os itens de a) até e) indicados anteriormente e o tempo simulado esperado para o método mestre
        for ( cont=1; cont<= f(n); ) // simula o tempo de f(n)
            cont++

    // saída
    // T(n) = 4T(n/2) + n
    // b = 2, a = 4, f(n) = n^1
    // log de 4 na base 2 = 2
    // f(n) = n = O(n ^ (2-e) ), para e = 1 -> Caso 1 Método Mestre
    // T(n) = Teta(n^2)

- 'exemplos'
// a=1 b=4 c=0 d=1 e=2 f=0 g=2
// T(n) = aT( (n/b) –c ) + dT( (n/e) –f ) + f(n)
// T(n) = 1T( (n/4) – 0 ) + 1T( (n/2) –0 ) + n^2
// T(n) = T(n/4) + T(n/2) + n^2

- código
// calcula_recorrencia a b c d e f g n

int f (int n, real g) // conta numero iterações de f(n).
{
  ...
  return resultado ; // retorna n^g
}

func_t (int n, ...) // simula a recorrencia
{
  ...
  if (n<=1) return;
  ...
  for (int cont=1; cont<=a; cont++) // faz a chamadas de tamanho (n/b) - c
    func_t( (n/b) - c );
    ...
  for (int cont=1; cont<=d; cont++) // faz d chamadas de tamanho (n/e) - f
    func_t( (n/e) - f );
    ...

  tempo_inicial = pega_tempo(...);

  for ( cont=1; cont<= f(n); ) // simula o tempo de f(n) no nível atual
    cont++

  tempo_final = pega_tempo(...);

  ...
  Calcula_nivel_atual_arvore(...);
  registra_trabalho_nivel_atual_arvore(...);
  registra_trabalho_por_n(...);
  registra_trabalho_por_f_n(...);
  ...
}
