  Em Eletromagnetismo 1 o foco é
    • Eletrostática (Capítulos 4-6)
    • Magnetostática(Capítulo 7)
    • Dispositivos Magnéticos (Capítulo 8)
    • Equações de Maxwell (Capítulo 9)
    • Introdução às Ondas Eletromagnéticas (Capítulo 10 – Partes)
    • Introdução às Linhas de Transmissão (Capítulo 11 – Partes)

  Ramo da física que estuda fenômenos elétricos e magnéticos
  – Ou seja grande parte da engenharia elétrica:
    • Circuitos
    • Telecomunicações (Antenas, Transmissores,Receptores, Fibras Ópticas)
    • Dispositivos Magnéticos (Motores, Transformadores )
    • Bioeletromagnetismo
    • Aquecimento por Rádio Frequência (RF)
    • Radares (Posição e Sensoriamento Remoto)

  – E – intensidade de campo elétrico
  – D – densidade de fluxo elétrico
  – H – intensidade de campo magnético
  – B – densidade de fluxo magnético
  – J –	densidade de fluxo de corrente elétrica
  – ρv – densidade volumétrica de cargas
  – ∇ – operador diferencial
  – G – campo escalares
  – V – campo vetorial

  Grandezas escalares:
    -Potencial elétrico

  Grandezas vetoriais("Ao longo do curso vamos usar as representações com seta em equações e a em negrito em textos"):
    -Intensidade de campo elétrico

  "Campo" - é uma função que especifica uma quantidade particular em todos os pontos da região.
    -escalares : Potencial elétrico em uma região.
    -vetoriais : intensidade de campo elétrico em uma região.

  "obs" O vetor posição rp é um vetor, mas o ponto P não é um vetor.

  "Produto escalar"
    -O produto da projeções de um vetor sobre outro vetor ('resulta um escalar = mesmo eixo')

  "Produto vetorial"
    -O produto das componentes ortogonais de um vetor em outro ('resulta um vetor= eixos distintos')
    -resulta num vetor ortoganal a ambos
    -a magnitude é igual à área de um paralelogramo formado pelos dois vetores sendo multiplicados.

  "Mudança de coordenadas" -Todos ortogonais, ou seja, eixos que são perpendiculares entre si.
    -Retângulares
    -Cilindricas
    -Esféricas

    -A descrição precisa das variações espaciais das quantidades (campos) necessita da definição única de todos os pontos no espaço.

      'Retangular'
	-Este sistema é conhecido por representar o ponto P por uma tripla de valores (x,y,z).
	-Os eixos são equivalentes a uma reta contendo todos os números reais.
      'Retangular'
	-O ponto P é determinado pela tripla de valores (ρ,φ,z).
	    ρ - é o raio do cilindro que passa por P (distância radial ao eixo z). 	[0,∞]
	    Φ - é ângulo de azimute, medido no plano xy a partir do eixo x. 		[0,2π]
	    z - como sistema retangular.						[R]
      'Esférico'
	-O ponto P é determinado pela tripla de valores (r,θ,φ).
	    r - distância da origem ao ponto P.												[0,∞]
	    Φ - é ângulo de azimute, medido no plano xy a partir do eixo x.								[0,2π]
	    θ - é ângulo de co-latitude (relacionado ao ângulo de elevação das coordenadas geográficas), medido a partir do eixo z.	[0,π]

  "Cálculo Vetorial"
    -integração
      -Em um percurso (integral de linha)
      -Em uma área (integral de superfície)
      -Em um volume (integral de volume)

      • Os elementos diferenciais podem ser usado tanto em vetores quanto em escalares.
	– Eles indicam quais as variáveis em integração e quais os elementos adicionais no processo
	– Cada sistema de coordenadas tem seu elemento de integração
	  • E cada um deles tem elementos característicos do sistema
	  • Na realidade todas as integrações são em função dos eixos usados.

      – Por que os diferenciais nas direções âΦ e âθ  são tão diferentes da direção âz,âρ ,âr,âx e ây?
      – O diferencial mede deslocamento linear, e aqueles são angulares. Por isto precisam de um conversão.
	  na direção Φ : ρdΦ = rsenθdΦ
	  na direção θ : rdθâθ

      – 'As integrais de linha também são chamadas de integrais de contorno, curva ou trajetória (este último vem da cinemática).'
      – 'As integrais de área também são chamadas de integrais de superfície ou fluxo.'
      – 'Já a integral de volume é geralmente utilizada quando se quer definir a quantidade total de uma determinada grandeza em uma região'
         'fechada'

      - As integrais de 'linha' e de 'superfície' podem ser abertas ou fechadas.
	-de linha fechada = determina uma área
	-de superfície fechada = determina um volume

      • A 'integral de linha' calcula a contribuição da componente tangencial de um vetor A na curva L.
	'integral de linha fechada calcula a circulação do vetor A no percurso L'

      • Já a integral de superfície é calculada como a integral da componente normal de A na superfície S.
	'O resultado da integral é chamado de fluxo do vetor A através de S'
	'A integral de superfície fechada calcula o fluxo líquido saindo da superfície S'

      • A integral de volume é a integral de um escalar em um volume V

    'Operador Gradiente (del)'
      - Pode operar em um 'campo escalar'
	• Transforma em um campo vetorial ('Gradiente')
	• Transforma em um outro campo escalar ('Laplaciano')
      - Pode operar em um 'campo vetorial'
	• Transforma em um campo escalar ('Divergente')
	• Transforma em outro campo vetorial ('Rotacional')

      • O gradiente de um campo escalar é o vetor que representa a direção e magnitude da máxima taxa de aumento do campo.

    'Divergente de um vetor e teorema da divergência'
      -'Atua sobre um campo vetorial gerando um campo escalar'
      -fluxo líquido que sai da superfície fechada S por unidade de volume.
      -quando o volume V definido pela superfície tende para zero.
      -Para obtermos a expressão do divergente temos que considerar o fluxo líquido em uma superfície que defina uma volume infinitesimal.
      -Linear e multiplicação por escalar.
      -'Teorema da divergência' O fluxo líquido total do campo vetorial A saindo pela superfície fechada S é igual a integral de volume
       do divergente de A.

    'Rotacional de um vetor e o Teorema de Stokes'
      -O rotacional de A é um vetor axial cuja magnitude é a máxima circulação de A por unidade de área, quando esta área tende a zero.
      -Atua sobre um campo vetorial gerando um campo vetorial.
      -Linearidadem, Multiplicação , Identidades.
      -O rotacional fornece a máxima circulação por unidade de área, indicando a direção aonde a mesma ocorre.
      -'Teorema de stokes' A circulação de um campo vetorial ao longo de um percurso fechado L é igual a integral de superfície do rotacional
			   sobre a superfície S definida pelo percurso L

    'Laplaciano de um escalar'
      -O Laplaciano de um campo escalar V é o divergente do gradiente de V.
      -Se o Laplaciano de um campo escalar é zero  em uma dada região, este campo é chamado de harmônico

    'Campos Vetoriais'
      • Um campo vetorial é caracterizado pelo seu divergente e rotacional. O conhecimento de ambos permite descrever completamente o campo.
      – Então podemos classificar os campos baseados se o divergente ou o rotacional são nulos
	• Campos com divergente nulo – campos solenoidais
	  'Campo magnético, fluido incompressíveis'
	• Campos com rotacional nulo – campos potenciais (ou irrotacionais )
	  'Campo Eletrostático, Campo Gravitacional (campos conservativos)'

    'Eletrostática'
    'Campos eletrostáticos'
      'Campos Elétricos estáticos no espaço livre'
	  - Campo não varia no tempo e o meio eletromagnético é o vácuo homogêneo.
	  - São causados por distribuições estáticas de carga.

      'Campos Elétricos devido a Distribuições Contínuas de Cargas'
	  -Distribuições Lineares
	  -Distribuições Superficiais
	  -Distribuições Volumétricas

    – Lei de Coulomb: cálculo do campo elétrico causado por qualquer distribuição de cargas.
	  Trata da força que uma carga pontual exerce em outra carga pontual.
	  – 1 elétron tem carga de -0.16019 attoC (10⁻¹⁸ C)
	  – 6 exa (10¹⁸) eletróns valem -1 C

	– Permissividade do vácuo
	– Intensidade de Campo Elétrico
	– Campos Elétricos devido a distribuições contínuas de carga
    – Lei de Gauss: No caso de distribuições simétricas de carga, a Lei de Gauss é mais simples de ser utilizada.

   'Densidade de Fluxo Elétrico (D)'
   - Como a intensidade de campo elétrico é dependente do meio, o fluxo elétrico deve ser calculado de forma a ser
     independente do meio.
   - Fluxo é algo que atravessa uma superfície.
     • O fluxo elétrico é a integral de superfície da densidade de fluxo.
     • A densidade de fluxo elétrico é também chamada de vetor deslocamento elétrico.
   - Calculamos fluxo com a Lei de Gauss.

   'Lei de Gauss'
   - o fluxo elétrico total através de qualquer superfície fechada é igual a carga total no volume definido pela
     superfície.
   - A Lei de Gauss permite calcular D ou E de modo mais simples que a Lei de Coulomb.
   - Para aplicar a Lei de Gauss em distribuições simétricas.
       • Necessário usar superfícies gaussianas.
       • Escolhida de forma que D seja normal a superfície(na mesma direção do vetor superfície).
       • Além disso, D deve ser constante na superfície.

   'Potencial Elétrico'
   -  O Potencial Elétrico permite encontrar o campo elétrico devido a uma distribuição de cargas de modo mais
      direto e simples, pois ele é um valor escalar.
   -  O potencial é obtido do trabalho necessário para mover uma carga.
        • A é o ponto inicial e B o ponto final
        • Se V de A a B é negativo, houve perda de energia potencial ao mover Q de A para B
        • Se V de A a B é positivo, houve ganho de energia potencial ao mover Q de A para B. Então houve um agente
          externo realizando trabalho.
        • V de A a B é independente do percurso tomado na integração
        • V de A a B é medido em Joules por Coulomb ou Volts

   - Podemos associar potenciais absolutos a cada ponto se:
        • Estivermos definirmos o potencial no infinito como zero (referência).

    'Relação entre E e V '
	• No caso eletrostático (as cargas são estáticas), a diferença de potencial entre dois pontos  independe do percurso tomado.

    'Um Dipolo Elétrico e Linhas de Fluxo'
      • Um dos primeiro exemplos a utilizar o  potencial para calcular o campo elétrico é o  dipolo elétrico
	– Ele é composto de duas cargas iguais, mas com sinais opostos separadas de uma distância d.
	– Ele é muito importante: a partir dele é que vamos calcular o efeito de meios materiais no cálculo do campo elétrico (tudo calculado
	  até este ponto considera o vácuo ou espaço livre).
      • O potencial do dipolo é simplesmente a soma  dos potenciais de cada carga.

      –Este tipo de distribuição é do tipo dipolo (o campo elétrico varia com r3)
	•Temos o de uma carga pontual –monopolo que varia com r2
	•Mas podemos ter quadripolos, octopolos, ou mais genericamente multipolos.

      -Campo pode ser visto por 'linhas de fluxo'.
	-Linhas imaginárias que tem a mesma direção do campo elétrico em todos os pontos.
	  'perpendiculares a elas temos as equipotenciais'

      • Nas equipotenciais,o trabalho para mover uma carga é zero (já que a diferença de potencial entre quais pontos de uma equipotencial
        é zero).
      – Os campos elétricos sempre serão perpendiculares à equipotenciais

    'Campos Elétricos em Meio Material'
    • Até agora vimos campos eletrostáticos no espaço livre (vácuo)
    – Mas o que acontece em meios materiais?
      • Os campos também vão existir nestes– Na realidade será possível descrever estes campos com poucas modificações ao que foi visto até
	agora
      • Veremos materiais condutores e não condutores– Não condutores são normalmente chamados de isolantes ou dielétricos (a coisa é uma
        pouco mais complexa:

    Normalmente os materiais são classificados de acordo com sua condutividade δ.(Siemens/metro)
    – Materiais em que δ >>1 são classificados como condutores (ou metais)
    – Materiais em que δ <<1 são classificados como isolantes (ou dielétricos)
    – Para o curso os efeitos importantes são macroscópicos.

   • Além dos efeitos na intensidade de campo elétrico
   – Vamos considerar o efeito da corrente elétrica  causada pelo movimento de cargas
    • A rigor isto não é eletrostática, mas se o movimento não for acelerado ou brusco, certas adaptações são possíveis
   – Corrente é dada por cargas elétricas que  passam por uma dada área por unidade de tempo.
   – A densidade de corrente em um determinado ponto é a corrente atravessando a unidade normal de área naquele ponto.

   'Correntes de Convecção e Condução'
    • Esta corrente é chamada de corrente de convecção e J é chamado de densidade de corrente de convecção
    • Esta corrente não requer um condutor em si, apenas uma densidade de carga volumétrica ρv que seja “transportada” ao longo do volume ΔlΔS.
    A relação entre a densidade de corrente e o campo elétrico é, na realidade, a lei de Ohm na forma pontual.

    'Condutores'
    • No condutor isolado, quando um campo elétrico é aplicado
        – As cargas livres se alinharão rapidamente de modo a contrabalançar o fluxo elétrico.
        • Estas cargas irão formar uma carga de superfície induzida.
        • A carga de superfície irá cancelar o campo elétrico aplicado no interior do condutor.
            – Um condutor perfeito não tem campo eletrostático em seu interior (alinhamento instantâneo).
        • O condutor perfeito é uma equipotencial (o potencial é o mesmo em todos os pontos do condutor).
    • E no caso do condutor com condutividade finito?
        – No caso eletrostático, a mesma situação ocorre – mas com um tempo finito no alinhamento de cargas.
        – Ou seja: o campo não é zero a partir de t=0, mas leva um tempo para chegar neste ponto.
        • Esta distinção é fundamental para explicar a situação aonde mantém-se uma diferença de potencial.
    • Considere agora um condutor com condutividade finita submetido a uma diferença de potencial:
        – Nesse caso não há equilíbrio estático de cargas
        • Podemos ver uma força eletromotiva V fazendo com que as cargas se movam.
        • Então neste caso tem de existir um campo elétrico E dentro do condutor fazendo com que as cargas se movam.

    'Polarização em Dielétricos'
    • No caso de isolantes não existem cargas livres, ou seja, as cargas não podem se mover livremente
        – Mas podem se deslocar de sua posição de equilíbrio com a aplicação de um campo elétrico externo
        – Isto irá causar um momento de dipolo – que irá se opor ao campo aplicado
        • Essencialmente: com um campo E aplicado as cargas positivas tenderão a seguir a orientação do campo, enquanto as cargas negativas seguirão a
          orientação oposta.
    • Considere um átomo de um dielétrico consistindo de uma nuvem de elétrons com carga –Q e um núcleo com carga Q
        – A distribuição final é igual a original mais um momento de dipolo p.
        • Este caso é quando os átomos/moléculas não tem momento de dipolo próprio
            – Chamados apolares ou não polares
            • O efeito é o alinhamento do momento de dipolo de cada elemento pk com o campo E.
        • Mas há o caso de moléculas com momento próprio
            – Moléculas polares
            • Neste caso o momento de dipolo permanente sofre um torque devido ao campo E.
        • Em todos os casos, o efeito é uma polarização no dielétrico
            – O efeito de torque tem outras consequências, no entanto.
        • Para incluir o efeito do dielétrico vamos considerar que existe no espaço em questão uma carga livre volumétrica QL.
            – Logo a densidade volumétrica de carga total

        +susceptibilidade elétrica de um material
            • Basicamente é o quanto o material polariza quando submetido a um campo elétrico.
        • A susceptibilidade elétrica pode ser incorporada como uma permissividade diferente do espaço livre.

    'Constante e Rigidez Dielétrica'
    • Naturalmente essas relações supõe linearidade (além de isotropia – mas isso vem depois).
    • Só que com campos suficientemente intensos, mesmo os elétrons são arrancados das órbitas e o material se torna condutor.
        – Este é o ponto de ruptura da rigidez dielétrica
        • A rigidez dielétrica e o campo elétrico máximo que um dielétrico pode suportar sem ruptura da mesma.

    'Dielétricos Lineares, Isotrópicos e Homogêneos'
    • Se D varia linearmente com E (D é proporcional a E), o material é dito linear.
        – Caso contrário é não linear.
    • Se D e E estiverem na mesma direção, o meio é dito isotrópico.
        – Caso contrário é não isotrópico (anisotrópico).
    • Se a permissividade do meio não variar com a posição (coordenadas espaciais), o meio é dito homogêneo.
        – Caso contrário é não homogêneo.
    • Todos os cálculos que foram feitos para o caso do espaço livre podem ser aproveitados para dielétricos lineares, isotrópicos e homogêneos.
        – Ou seja basta substituir ε0 por ε0εr

    'Equação da Continuidade e Tempo de Relaxação'
    • A equação da continuidade relaciona a corrente com a taxa de variação da carga
        – Considere uma esfera aonde foi introduzida uma carga Q no seu interior (centro).
        – Esta esfera tem condutividade finita.
    • O tempo de relaxação é, de certa forma, uma medida de quão bom o material é condutor (ou dielétrico)
        – Tempos de relaxação grandes indicam bons dielétricos (capacidade de manter cargas por longos períodos de tempo)
            • Exemplo: Quartzo – 51.2 dias
        – Tempos de relação curtos indicam bons condutores (capacidade de “escoar” carga com rapidez).
            • Exemplo: Cobre – 0.153 attosegundo (10-18 s)

    'Condições de Contorno'
    • Um forma de resolver problemas com vários dielétricos homogêneos é considerar cada um deles separadamente e depois associar ambos.
        – Para tanto temos de conhecer as condições de contorno dos campos na interface entre os meios
        • Lembrando que como estamos tratando de vetores temos de relacionar as componentes normais e tangenciais.
    • Considerando dois meios homogêneos, lineares e isotrópicos, temos de decompor o campo elétrico (E=ET+EN)
        – na sua componente normal EN
        – na sua componente tangencial ET
    • Fazemos isso para o meio 1 e o meio 2
        – E1=ET1+EN1
        – E2=ET2+EN2
        • Para encontrar a relação utilizamos as duas equações anteriores
            – Vamos fazer isto para:
                • Interface entre dielétricos
                • Interface dielétrico e condutor
    • Estas propriedades são importantes:
        • Não há campo elétrico dentro do condutor(isolamento)
        • O condutor é uma equipotencial
        • Só há campo elétrico normal na superfície e externo a mesma.

Densidade de fluxo elétrico é independente do meio.
Já a intensidade de campo elétrico depende.
    Lei de Gauss = calcula. D e E simétrico.
    Superfície gaussiana: D deve ser normal e constante pela superfície.

O potencial elétrico é obtido do trabalho necessário para mover uma carga
Dividindo a energia pela carga temos a diferença de potencial entre A e B.

Dipolo elétrico = utilizar o potencial para calcular o campo elétrico.
                  No dipolo, o campo varia com r^3.
                  O campo elétrico é sempre perpendicular à equipotenciais.

Materiais cuja condutividade seja maior que 1 são condutores, e os que são menor são dielétricos.

Corrente de convecção: não requer um condutor em si, apenas uma densidade de carga volumétrica que seja transportada ao longo do volume.
Corrente de condução: devido aos elétrons livres do condutor, que batem numa rede cristalina.

Se D variar linearmente com E, o material é 'linear'.
Se D e E estão na mesma direção, o meio é 'isotrópico'.
Se premissividade do meio não varia com posição, meio 'homogêneo'.

Resistência pode ser calculada como um problema de valor de contorno. Capacitância também.

Método das imagens: Substituir um problema por outro mais simples.
    -A carga imagem deve estar na região condutora.
    -A carga imagem deve estar localizada de modo que a superfície condutora tenha potencial zero ou constante.

'Forças, Materiais e Dispositivos  Magnéticos'
    • Introdução
    • Forças devido aos Campos Magnéticos
    • Torque e Momento Magnéticos
    • Dipolo Magnético
    • Magnetização em Materiais
    • Classificação dos Materiais Magnéticos
    • Condições de Fronteira Magnéticas
    • Indutores e Indutâncias
    • Energia Magnética
    • Circuitos Magnéticos
    • Força sobre Materiais Magnéticos
    • Conclusões
    
    'Introdução'
      • Após apresentar as Leis básicas do  Magnetismo
      – Vamos estudar a força que os campos magnéticos fazem em partículas carregadas, elementos de corrente e espiras.
      – Em adição, vamos estudar campos magnéticos em meios materiais, e não apenas no vácuo (como no capítulo anterior)
      – E por fim, também serão estudados circuitos magnéticos, indutores e energia magnética.

    'Forças devido aos Campos Magnéticos'
      No caso do campo elétrico:
	– A força atua na mesma direção do campo elétrico
	  •Caso Q seja positiva, o sentido de F E é o mesmo de E
	  •Caso Q seja negativa, o sentido de F E é o contrário de E
	– A carga Q pode estar estacionária ou em movimento.
	
      • Já no caso do campo magnético:
	'u' é velocidade que a carga está se  movendo.
	• A direção da força é perpendicular a densidade de fluxo  magnético  B e a velocidade  u da carga Q. 
	• A força magnética  Fm não causa uma variação na energia cinética da carga Q, pois não realiza trabalho.
	
      Força de Lorentz
      Devido à força elétrica e força magnética.
      No caso da presença do campo elétrico E e da densidade de fluxo magnético B, temos a expressão da força de Lorentz.
	
      Magnetização em Materiais
	• A ideia é associar um momento magnético m ao átomo (modelo simples)
	  – Cada um produzindo um campo magnético Bi 
	  – Devido a corrente Ib
	• Se B varia linearmente com H( B é proporcional a H), o material é dito linear.
	– Caso contrário é não linear
	• Se B e H estiverem na mesma direção, o meio é dito isotrópico
	– Caso contrário é não isotrópico (anisotrópico)
	• Se a permeabilidade do meio não variar com a posição (coordenadas espaciais), o meio é dito homogêneo
	- Caso contrário é não homogêneo.
	
      • A classificação dos materiais magnéticos pode ser sumarizada na figura abaixo
	–Diamagnéticos		
	–Paramagnéticos
	–Ferromagnéticos
	
      • Nos dois primeiros casos (diamagnetismo e paramagnetismo) a permeabilidade relativa é praticamente 1 (ou seja u é aproximadamente u0).
      – No diamagnetismo os campos magnéticos pelo spin e pela órbita se cancelam.
      – No paramagnetismo estes campos magnéticos (spin e órbita) não se cancelam completamente.
      
      • Já os materiais ferromagnéticos possuem momento magnético permanente considerável
      – Capazes de serem magnetizados fortemente por um campo magnético
      – Retém uma parcela da magnetização mesmo quando o campo magnético é retirado
      – Se tornam paramagnéticos a partir de uma dada temperatura
      – São não-lineares
      
      • Os materiais ferromagnéticos não tem uma definição única de permeabilidade 
      – a mesma dependerá do ponto de operação do material
      – Mas em geral são valores elevados. E isto permite o uso destes materiais para blindagem
      
      • Além disto, devido a magnetização residual a curva B-H apresentará histerese
      
      Condições de Fronteira Magnéticas
      • De modo similar ao caso elétrico é necessário caracterizar os campos quando temos mais de uma material magnético.
      – Para tanto novamente temos de conhecer as condições de contorno dos campos na interface  entre os meios
      • Lembrando que como estamos tratando de vetores temos de relacionar as componentes normais e tangenciais.
      
      • Considerando dois meios homogêneos, lineares e isotrópicos, temos de decompor o campo magnético (H=HT+HN)
      –na sua componente normal Hn
      –na sua componente tangencial Ht
      
      • Fazemos isso para o meio 1 e o meio 2
      –H1=HT1+HN1
      –H2=HT2+HN2
      • Para encontrar a relação utilizamos as duas equações anteriores
      – Vamos fazer isto para:
      • Interface entre materiais magnéticos
      
      Indutores e Indutâncias
      •Um circuito carregando uma corrente I produz um campo magnético H e uma densidade de fluxo B
      –Esta densidade de fluxo causa um fluxo Y que flui por cada enrolamento da bobina abaixo.
      
      • Naturalmente se o meio for linear, o fluxo concatenado l é proporcional a corrente I (pois ela é que gera o campo magnético).
      
      • O elemento de circuito que modela esta indutância é chamado indutor
      – A indutância tem unidades de Henry	
      
      • Na formulação acima, a indutância é também chamada de auto-indutância, pois liga o fluxo magnético l produzido pelo indutor quando o
        mesmo esta sob ação de uma corrente I.
      – Da mesma forma que a capacitância, a indutância pode ser vista como a relação de quanta energia magnética armazenada por unidade de 
        corrente
        
      • No caso de várias correntes em vários circuitos teremos um efeito de acoplamento.
      – No caso de duas correntes I1 e I2, teremos  fluxos próprios y11, y22 e entrelaçados y12 e y21.
      
      • O cálculo de indutância própria pode ser realizado pelo fluxo
      – Escolhe-se um sistema de coordenadas apropriado
      – Assume-se uma corrente I no indutor
      – Calcula-se a densidade de fluxo B devido a I
      – Calcula-se Y devido a B
      – Calcula-se o fluxo concatenado l.
      – Calcula-se a indutância dividindo o fluxo concatenado l pela corrente I.
      
      Circuitos Magnéticos 
      • O conceito de circuitos magnéticos é o de utilizar técnicas de circuitos elétricos para resolver alguns problemas de campo magnético
      – A ideia é usar uma analogia entre conceitos dos dois tópicos
      • Essencialmente associação de impedâncias(resistores no caso de circuito) e de relutâncias (no caso magnético)
      
      Força sobre Materiais Magnéticos
      • Um ponto de interesse é como determinar a força que um campo magnético exerce sobre um material magnético
      – Muito importante em sistemas eletromecânicos	
      – No caso de poder
	- se utilizar potencial magnético escalar (não há corrente envolvida diretamente nos cálculos, apenas os campos)
      • O melhor método é o dos trabalhos virtuais
	  
	  Leis de Maxwell
	  • Nas partes anteriores deste curso concentrou-se no estudo de
			– Campos Eletrostáticos – 'E' não variava no tempo
			– Campos Magnetostáticos – 'H' não variava no tempo
	  • A partir daqui concentraremos em
			– Campos dinâmicos ou variantes no tempo (E e H variam no tempo)
			
	  • No caso em que os campos não variam no tempo
			– E e H são independentes entre si
	  • Isto não é mais o caso quando os campos variam no tempo
			– E e H são mutuamente dependentes
	  • Mas o estudo do caso invariante no tempo auxilia bastante no estudo do caso variante no tempo
	  
	  • O estudo de campos dinâmicos parte de cargas aceleradas ou correntes variantes no tempo
			– Qualquer corrente variante no tempo irá produzir campos eletromagnéticos
			
	  • Para estudar esse tópico é necessário	entender dois conceitos chaves:
			– A força eletromotiva observada nos experimentos de Faraday (Lei de Faraday)
			– A corrente de deslocamento que advém dos estudos de Maxwell
	  • Com estes dois conceitos teremos as equações de Maxwell
			– Que se baseiam nas equações da eletrostática e magnetostática modificadas pelos conceitos acima
			
	  • Oersted provou em 1820 que uma corrente gerava um campo magnético
			– Isso levava a pergunta: E um campo magnético produz uma corrente elétrica?
	  • Em 1831 Michael Faraday e Joseph Henry descobriram que um campo magnético variável produzia uma corrente elétrica
	  
	  • Um campo magnético estático não produz corrente
			– Mas um campo magnético variável produz uma tensão induzida (força eletromotiva ou fem) em um circuito fechado e esta produz uma corrente
	  • Esta é a Lei de Faraday
	  
	  • Portanto a variação de fluxo pode resultar das seguintes situações
			– Área S estacionária e B variante no tempo
			– Área S variante no tempo e B estacionário
			– Área S e B variantes no tempo
	  • Vamos ver cada um dos casos separadamente, considerando uma espira definindo a área de integração
	  
	  • A integral só terá integrando diferente de zero no bastão, aonde u é diferente de zero. Logo o percurso de integração será somente sobre o bastão
	  • A orientação do percurso deve estar no sentido a tensão induzida. Assim no exemplo anterior o percurso deve ser tomado na direção – âx
	  
	  Corrente de Deslocamento 
	  • A corrente de deslocamento é chave para entender conceitos relativos a como passa corrente em um capacitor.
	  
	  Corrente de Deslocamento
	  • Isto soluciona a questão de qual a corrente que atravessa o capacitor quando uma tensão alternada é aplicada entre suas placas
	  
	  Potenciais Variáveis no Tempo
	  • Geralmente não é simples resolver as equações de Maxwell diretamente
			– Assim como no caso do potencial elétrico escalar no caso eletrostático e do potencial vetorial magnético no caso magnetostático
	  • É mais interessante utilizar potenciais para resolver as equações de Maxwell em determinadas situações
	  
	  Potenciais Variáveis no Tempo
	  • Esta é condição de Lorentz para os potenciais 
			– Note que ela é consistente com o caso estático (divergente de A igual a zero)
			
	  Potenciais Variáveis no Tempo
	  • Estes são chamados de potenciais retardados
	  • Potencial escalar elétrico retardado
	  • Potencial vetorial magnético retardado
	  
	  Campos Harmônicos no Tempo
	  • Até este ponto a d	ependência no tempo foi considerada qualquer
			– No entanto, para a maioria das aplicações práticas a excitação senoidal de campos é a mais utilizada
			– Isto sugere que se estude em profundidade maior o caso dos campos harmônicos no tempo
	  • Isto quer dizer excitação senoidal dos campos (fontes variam senoidalmente no tempo)
	  • Isto também permite o uso de fasores
	  
	  



.


			
	  

      
      
      
      
