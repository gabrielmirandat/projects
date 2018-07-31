// 1_insertionSort_mergeSort_analiseAssintotica
- Análise Assintótica (crescimento de T(n) quando n→∞)
- Insertion Sort
- Merge Sort


# 'Análise'
  - ignora constantes dependentes da máquina
  - Θ(g(n)) = { f(n): existes constantes positivas c1 , c2 , n0 tais que c1g(n) ≤ f(n) ≤ c2g(n) para todo n≥n0 }
    - pega maior ordem e ignora constantes (3n³ + 90n² - 5n + 6046 = Θ(n³)) pois sempre é feita uma 'análise assintótica'

# 'Insertion Sort'
  'Única passada no vetor da esquerda para direita'
  'Olha a carta no índice i'
  'Shifta todas as cartas já visitadas (esquerda) para a direita uma a uma para abrir o espaço correto da posição da carta de índice i'

  Tempo depende do tamanho da entrada, modesto para n pequeno, ruim para n grande
  Melhor caso: lista já ordenada
  Pior caso: entrada decrescente
    - T(n) = somatório(j=2->n | Θ(j)) = Θ(n²)
  Caso médio: permutações igualmente prováveis
    - T(n) = somatório(j=2->n | Θ(j/2)) = Θ(n²)

# 'Merge Sort'
  'MERGE duas listas = um iterador para cada lista, escolhe o de menor índice, move elemento pra uma terceira lista, incrementa índice'
  'recursivamente, divide entrada em dois até ter n listas de 1 elemento'
  'recursivamente, MERGE listas em pares, até sobrar uma única lista ordenada'

  Θ(n) para fundir os n elementos
  Árvore de recursão
  Passo1  => T(n)
  Passo2  => cn -> (T(n/2), T(n/2))
  Passolgn=> cn -> (cn/2, cn/2) -> (cn/4, cn/4, cn/4, cn/4) -> 2^(lgn)*(Θ(1)) => 'Θ(nlgn)'

  'Na prática o merge sort supera o insertion sort para n > 30'

// 2_analiseAssintotica_notacaoAssintotica
- Analise assintótica
- Ordem de crescimento
- Notação assintótica (O, o, Ω, ω, Θ)

# Analise assintótica
  - crescimento de T(n) quando n→∞
  - tempo depende de 'n'
  - custo uniforme para cada declaração (menos funções)
  - termo de maior ordem é o que importa (domina quando n→∞)

# Ordem de crescimento
  - 1 << lgn << n << nlgn << n² << n³ << 2^n << n!
  - 1 << alfa(n) << lglgn << lgn/lglgn << lgn << lg²n << sqrt(n) << n << nlgn << n^(1+E) << n² << n³ << c^n << n!
  - 1 << alfa(n) << lg(3)n << lglgn << lgn/lglgn << lgn << lg²n << lg³n << n^E << sqrt(n) << n/lgn << n << nlgn ~ lgn! << n^(1+E) << n² << n³ << 2^n << 3^n << n! << n^n
  - análise exata é difícil, lida-se com limites 'superiores' e 'inferiores'
  - 'QUESTAO7_23' 'QUESTAO8_24'

# Notação assintótica (O, o, Ω, ω, Θ)
  - O (Grande O) 'conjunto de funções com ordem de crescimento menor ou igual a analisada'
    - n ∈ O(n²); 100n² + n ∈ O(n²)
    - O(g(n)) = {f(n): ∃ constantes positivas c e n0 tais que 0 ≤ f(n) ≤ cg(n) ∀ n>n0 }
    - 'QUESTAO1_15' 'QUESTAO4_20'
  - o (Pequeno o) 'conjunto de funções com ordem de crescimento menor que a analisada'
    - 1000n ∈ o(n²)
  - Ω (Grande Ômega) 'conjunto de funções com ordem de crescimento maior ou igual a analisada'
    - n² ∈ Ω(n); 1/1000n ∈ Ω(n)
    - Ω(g(n)) = {f(n): ∃ constantes positivas c e n0 tais que 0 ≤ cg(n) ≤ f(n) ∀ n>n0 }
    - 'QUESTAO2_17' 'QUESTAO5_21'
  - ω (Pequeno ômega) 'conjunto de funções com ordem de crescimento maior que a analisada'
    - 1/1000n² ∈ ω(n)
  - Θ (Theta) 'conjunto de funções com ordem de crescimento igual a analisada'
    - 100n² + lgn ∈ Θ(n²)
    - Θ(g(n)) ={f(n): ∃ constantes positivas c1 , c2 e n0 tais que 0 ≤ c1 g(n) ≤ f(n) ≤ c2 g(n), ∀ n ≥ n0 }
    - 'QUESTAO3_19' 'QUESTAO6_21'

// 3_notacaoAssintotica_logs_pesquisaBinaria_ordemComplexidade_series_somaSerie
- Funções logarítmicas
- Séries aritméticas
- Séries geométricas

# Funções logarítmicas
  - logaritmo é o inverso da função exponencial
  - b^x = y <=> x = logb y
  - quantas vezes podemos dobrar até chegar em 'n'
  - 'pesquisa binária' Quantas vezes podemos dividir 'n' ao meio até encontrar o valor 1? 'teto(lgn)'
  - 'árvores' Quantas vezes devemos dobrar o valor de 1 até atingir um valor de pelo menos n? 'teto(lgn)'
  - 'bits' Quantos bits são necessários para representar os números de 0 até n? 'teto(lg(n+1))'
  - lg*n (alfa(n)) número de vezes que é necessário tirar o logaritmo de um número 'n' até que ele se torna menor ou igual a 1
    - nunca passa de 5 na vida real (considerado uma constante)

# Séries aritméticas
  - diferença entre dois números sucessivos é uma constante
  - 'soma' n(a1 + an)/2

# Séries geométricas
  - razão entre dois números sucessivos na série é uma constante
  - 'soma' p/ r<1 (1-r^(n+1)) / (1-r)
           p/ r>1 (r^(n+1)-1) / (r-1)
           p/ r=1 n+1
  - 'QUESTAO9_24'

// 4_inducao_algoritmoRecursivo_analiseMergeSort_analisePesquisaBinaria
- Relações de recorrência
- Corretude de algoritmos recursivos
- Análise no tempo

# Relações de recorrência
  - T(n) = aT(n-b) + f(n)
  - T(n) = aT(n/b) + f(n)

  - Indução
    - 'declaração' S(n) é verdadeiro para todo n>=k
    - 'base da indução' é verdade quando n=k
    - 'hipótese da indução' é verdade para arbitrário n>k
    - 'passo da indução' então é verdade para n+1
    - 'objetivo' mostrar que se é verdade para n é verdade para n+1 também
                 se é verdade e vale n>=c, vale pra todo n>=c
    - 'QUESTAO10_5'
    - 'QUESTAO11_6'

# Corretude de algoritmos recursivos
  - Para mostrar corretude usa-se indução

  - Indução
    - 'base' mostrar que funciona para exemplos pequenos
    - 'hipótese' assum que solução é correta para todos os subproblemas
    - 'passo' mostrar que hipótese é correta então algoritmo é correto

  - Merge Sort [1.. n]
    - 1. Se n=1, então fim
    - 2. Ordena recursivamente A[1.. teto(n/2)] e A[teto(n/2)+1.. n]
    - 3. "Merge" duas listas ordenadas

    - Indução
      - 'base' se n=1, retorna resposta correta pois A[1.. 1] já está ordenado
      - 'hipótese' assume que algoritmo ordena corretamente A[1.. teto(n/2)] e A[teto(n/2)+1.. n]
      - 'passo' se A[1.. teto(n/2)] e A[teto(n/2)+1.. n] são ordenados corretamente, então todo o vetor
                A[1.. teto(n/2)] e A[teto(n/2)+1.. n] está ordenado depois do “merge”

# Análise no tempo
  - Para analisar, coloca-se execução em função de n como função do tempo dos subproblemas menores
    - Dividir, conquistar e combinar

  - Merge Sort
      T(n)    -> Merge Sort [1.. n]
      Θ(1)    ->  1. Se n=1, então fim
      2T(n/2) ->  2. Ordena recursivamente A[1.. teto(n/2)] e A[teto(n/2)+1.. n]
      f(n)    ->  3. "Merge" duas listas ordenadas

      - 'Dividir' = trivial
      - 'Conquistar' = ordena recursivamente 2 subarrays
      - 'Combinar' = faz merge de 2 subarrays ordenados

      - T(n) = 2 T(n/2) + f(n) + Θ(1)
        - 2    - num de subproblemas
        - n/2  - tamanhho do subproblema
        - f(n) - dividir e combinar = tempo linear = Θ(n)

      - Recorrência do merge sort
        - T(n) = Θ(1) se n=1
               = 2T(n/2) + Θ(n) se n>1
        - Podemos omitir o caso base para um n pequeno quando não afeta solução

      - Recorrência da pesquisa binária
        - T(n) = Θ(1) se n=1
               = T(n/2) + Θ(1) se n>1

      - Recorrência do fatorial
        - T(n) = Θ(1) se n=1
               = T(n−1) + Θ(1) se n>1

// 5_relacoesRecorrencia
- Formas de recorrência
- Formando relações de recorrência

# Formas de recorrência
  - T(n) = T(n−1) + 1
  - T(n) = T(n−1) + n
  - T(n) = T(n/2) + 1
  - T(n) = 2T(n/2) + 1

  Questão: Como resolver recorrência para obter uma forma fechada do tipo T(n) = Θ(n²) ou T(n) = O(n)

# Formando relações de recorrência

    long fatorial (int n) {
        if (n == 0)
          return 1;
        else
          return n * fatorial (n – 1);
    }

    'Resolvendo'
    - (1) T(0) = c
    - (2) T(n) = b + T(n-1)
               = b + b + T(n-2)
               = b + b + b + T(n-3)
               = kb + T(n-k)
    - usando (1) "queremos k(n)", temos que n-k=0; k=n, logo
          T(n) = bn + T(0)
               = bn + c = O(n)

    int binarySearch (int target, int * array, int low, int high) {
      if (low > high)
        return -1;
      else {
        int middle = (low + high)/2;
        if (array[middle] == target)
          return middle;
        else if(array[middle] < target)
          return binarySearch(target, array, middle + 1, high);
        else
          return binarySearch(target, array, low, middle - 1);
      }
    }

    'Resolvendo' - assumindo que n é potencia de 2
    - (1) T(1) = a
    - (2) T(n) = T(n/2) + b
               = T(n/4) + b + b
               = T(n/8) + b + b + b
               = T(n/2^k) + kb
    - usando o 'caso base' (1) "queremos k(n)", temos que n/2^k=1; n=2^k; k= lgn
          T(n) = T(1) + blgn
               = a + blgn = O(lgn)

    long fibonacci (int n) {
      if( n == 1 || n == 2)
        return 1;
      else
        return fibonacci(n – 1) + fibonacci(n – 2);
    }

    'Resolvendo' - faz por limite inferior
    - (1) T(n) = c                    se n=1 ou n=2
    - (2) T(n) = T(n-1) + T(n-2) + b  se n>2
              >= 2T(n-2) + b
               = 2(2T(n-4)+b)+b
               = 2²T(n-4)+3b
               = 2(2(2T(n-6)+b)+b)+b = 2(4T(n-6)+3b)+b = 8T(n-6) + 7b "desenvolve um pra ver"
               = 2³T(n-6)+7b
               = 2⁴T(n-8)+15b
               = 2^k * T(n-2k)+(2^k-1)b
    - usando o 'caso base' (1) "queremos k(n)", temos n-2k=2; k= (n-2)/2
          T(n) >= 2^(n-2/2) * T(2) + (2^(n-2/2) - 1)b
               =  2^(n-2/2) * c + 2^(n-2/2) * b - b
               = (b+c) * 2^(n-2/2) - b
               = (b+c)/2 * 2^(n/2) - c = O(2^n)

// 6_metodoSubstituicao_metodoArvoreRecursao_metodoIteracao_metodoMestre
- Métodos de resolução
- Método da substituição
- Método da Árvore de recursão
- Método da Iteração

# Métodos de resolução
  - Definir a recorrência
  - Resolver a recorrência

  - Método da substituição 'Genérico, rígido mas pode ser difícil de ser usado'
  - Método da Árvore de recursão 'Bom para tentar obter a resposta'
  - Método Mestre 'Fácil mas de aplicação limitada'

# Método da substituição
  - 1. Imaginar solução
  - 2. Verificar por indução
  - 3. Resolver para constantes c e n "(desejado - residual) > 0"

  'T(n) = 4T(n/2) + n'
    - Imagine solução deve ser O(n³)
    - !Assume T(1) = Θ(1)
    - !Assume T(k) <= ck³ para k<n
    - Provar T(n) <= cn³

    T(n) <= 4c(n³/8) + n
          = 1/2*cn³ + n
          = cn³ - (1/2cn³ - n)
         <= cn³ quando c>1 e n>0

    Resolvendo para c e n temos cn³/2 - n > 0
      Valores de c e n capazes são c>1 e n>0

    P/ o caso base, sendo 1≤ n < n0 , temos “Θ(1)” ≤ cn 3 , se pegamos um c grande o suficiente
      Ajustando o caso base da indução vemos que não é um limite estreito o suficiente!

    - Imagine solução deve ser O(n²)
    - !Assume T(k) <= ck² para k<n
    - Provar T(n) <= cn²

    T(n) <= 4c(n²/4) + n
          = cn² + n
         >= cn² NÃO PROVA A INDUÇÃO

    - Deve fortalecer a hipótese indutiva subtraindo um termo de baixa ordem
    - !Assume T(k) <= c1k² - c2k para k<n
    - Provar T(n) <= c1n² - c2n

    T(n) <= 4(c1n²/4 - c2n/2) + n
          = c1n² - 2c2n + n
          = c1n² - c2n - (c2n - n)
         <= c1n² - c2n quando c2>0

    Resolvendo para c e n temos c2n - n > 0; c2>0 e c1 suficiente para condições iniciais

# Método da Árvore de recursão
  - modelo custo temporal de execução recursiva de algoritmo
  - pode não ser totalmente confiável
  - promove a intuição do processo
  - se torna útil para gerar tentativas de soluções para outros métodos

  'Merge Sort'
    - 'T(n) = 2T(n/2) + dn', com d > 0 constante

      1. T(n)
      2. dn
          \T(n/2) \T(n/2)
      3. dn                                 -- dn
          \dn/2 \dn/2                       -- dn
          \T(n/4) \(n/4) \T(n/4) \T(n/4)    -- dn

      lgn. ... Θ(1)                         -- dn

      Logo, dn * lgn
      = Θ(nlgn)

  'T(n) = T(n/4) + T(n/2)+ n²'

      1. T(n)
      2. n²
          \T(n/4) \T(n/2)
      3. n²                                   -- n²
          \n²/16 \n²/4                        -- 5/16n²
          \T(n/16) \T(n/8) \T(n/8) \T(n/4)    -- 25/256n²

      Logo, n² * (1⁰ + (5/16)¹ + (5/16)² + (5/16)³ + (5/16)^(lglgn-1))
      = Θ(n²)


# Método da Iteração (generico - melhor)

  'T(n) = T(n/2) + 1'
        = T(n/4) + 1 + 1
        = T(n/8) + 1 + 1 + 1
        = T(1) + 1 + 1 + 1 .. + 1 (= lgn*1)
        = Θ(lgn)

  'T(n) = T(n-1) + 1'
        = T(n-2) + 1 + 1
        = T(1) + 1 + 1 .. + 1 (= n*1)
        = Θ(n)

  'T(n) = T(n-1) + n'
        = T(n-2) + n-1 + n
        = T(n-3) + n-2 + n-1 + n
        = T(n-4) + n-3 + n-2 + n-1 + n
        = T(n-n+1) + n-n+2 + n-n+3 + n-n+4 + .. + n-n+n
        = T(1) + 2 + 3 + 4 + .. + n (=n*n)
        = Θ (n²)

// 7_metodoMestre
- Método Mestre

# Método Mestre
  - Somente se na forma 'T(n) = aT(n/b) + f(n)'
    1. Dividir o problema em a subproblemas de tamanho n/b
    2. Conquistar os subproblemas recursivamente.
    3. Combinar soluções de subproblemas
    Dividir e combinar demora f(n)

  - É uma árvore de recursão
  - 'forma' f(n) -> a*f(n/b) -> ... -> T(1)
  - 'somas' f(n) -> af(n/b) -> a²f(n/b²)
  - 'altura' h=logBn
  - 'folhas' n^(logBa) * T(1)

  - 'CHAVE' comparar f(n) com n^(logBa)
  - 'CASO1' peso cresce da raiz para folhas         f(n)= O(n^(logBa - ε)) -> T(n)= Θ(n^(logBa)) 'complexidade é o tempo das folhas'
    - f(n) cresce mais lento que n^(logBa)
  - 'CASO2' peso quase o mesmo para cada nível      f(n)= Θ(n^(logBa)) -> T(n)= Θ(n^(logBa)*lgn) 'complexidade é o tempo das folhas vezes lgn'
    - f(n) tem mesma ordem assintótica n^(logBa)
    'estendido'                                     f(n)= Θ(n^(logBa)*lg(^k)n) -> T(n)= Θ(n^(logBa)lg(^k+1)n) 'complexidade é o tempo das folhas vezes lgn elevado a k+1'
  - 'CASO3' peso diminui da raiz para folhas        f(n)= Ω(n^(logBa + ε)) -> T(n)= Θ(f(n)) 'complexidade é o tempo da raiz'


  'CASO1'
    'T(n) = 4T(n/2) + n'
          = a=4 b=2 f(n)=n
          Comparando n^log2;4= n² com f(n)=n= O(n^(2-ε)) p/ε=1 => caso1
          Θ(n²)

  'CASO2'
    'T(n) = T(n/2) + 1'
          = a=1 b=2 f(n)=n⁰
          Comparando n^log2,1= n⁰ com f(n)=n⁰ => caso2
          Θ(n⁰lgn) = Θ(lgn)

   'CASO2 estendido'
    - k >= 0
    'T(n) = 4T(n/2) + n²lgn'
          = a=4 b=2 f(n)=n²lgn
          Comparando n^log2,4= n² com f(n)= n²lgn => caso2 estendido
          Θ(n²lg²n)

    'CASO3'
    'T(n) = T(n/2) + n'
          = a=1 b=2 f(n)=n
          Comparando n^log2,1 = n⁰ com f(n)= n¹ => caso3
          Θ(n¹)

    'QUESTAO12_15'

// 8_mudarVariaveis
- Técnicas
- Método da substituição

# Técnicas
- mudar variáveis
- obter limites superior e inferior
    - tentativa baseada em limites
    - provas usando método da substituição

    - mudar variáveis
      'T(n)= T(sqrt(n)) + 1'
      n=2^m
      sqrt(n) = sqrt(2^m) = 2^(m/2)
      T(2^m)= T(2^(m/2))+1
      seja T(n) = T(2^m) = S(m)
      S(m)= S(m/2) + 1
      S(m)= Θ(lgm) = Θ(lglgn)
      T(n)= Θ(lglgn)

      'T(n) = 2T(n-1) + 1'
      n=lgm; m=2^n;
      n-1 = lgm-1 = lgm-lg2 = lg(m/2)
      T(lgm)= 2T(lg(m/2)) + 1
      Seja T(n) = T(lgm) = S(m)
      S(m)= 2S(m/2) + 1
      S(m)= Θ(mlgm) = Θ(2^n²)

   - obter limites superior e inferior

    'Fibonacci'
    - T(n) = T(n-1) + T(n-2) + 1
    - [1] T(n)>= 2T(n-2)+1
    - [2] T(n)<= 2T(n-1)+1
    - Resolvendo [1], temos T(n) >= 1.4^n
    - Resolvendo [2], temos T(n) <= 2^n
    - Logo, T(n) ~ 1.62^n

    'T(n) = T(n/2) + log n'
    - T(n) ∈ Ω(log n) - tempo na raiz
    - T(n) ∈ O(T(n/2) + n^ε )
    - com caso3, obtemos T(n) = n^ε

# Método da substituição
  - 1. Tentar a forma da solução (ex. árvore de recursão/ método da iteração)
  - 2. Verificar por indução
  - 3. Resolver para O constantes n0 e c (caso base da indução)
