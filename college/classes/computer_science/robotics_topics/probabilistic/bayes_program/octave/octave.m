# M - motor
# T - theta
# L0 - sensor 1
# L1 - sensor 2
# L2 - sensor 3  

# REPRESENTACAO USADA
# NUM LINHAS => NUM DE COMBINACOES POS BARRA
# NUM COLUNAS => NUM DE COMBINACOES PRE BARRA
# DESSA FORMA, O SOMATORIO EM CADA LINHA DEVE SER 1

# Objetivo: achar a conjunta P_MTL0L1L2
# P(M,T,L0,L1,L2) = P(T).P(L0|T).P(L1|T).P(L2|T).P(M|T)
# P_MTL0L1L2 = P_T.P_L0dT.P_L1dT.P_L2dT.P_MdT

# motor ir esquerda, reto, direita
# [P_M] = 3 = [-1,0,1]

# angulos da luz
# [P_T] = 8 = [-135,-90, -45, 0, 45, 90, 135, 180]

# sensor não viu, acha que viu, viu
# [P_L0] = 3 = [0,1,2]; = FRENTE DO ROBO
# [P_L1] = 3 = [0,1,2]; = DIREITA DO ROBO
# [P_L2] = 3 = [0,1,2]; = ESQUERDA DO ROBO

# P(T) = uniforme
P_T = [1./8, 1./8, 1./8, 1./8, 1./8, 1./8, 1./8, 1./8];

# P(L0|T) = linhas -> angulos da luz
#           colunas -> sensor viu, acha que viu, viu
#       nao vi   acho vi   vi
#       ---      ---       ---
# -135  0.7      0.2       0.1 
# -90   0.3      0.45      0.25
# -45   0.2      0.35      0.45
# 0     0.01     0.04      0.95
# 45    0.2      0.35      0.45
# 90    0.3      0.45      0.25       
# 135   0.7      0.2       0.1 
# 180   0.9      0.07      0.03
P_L0dT = [0.7 , 0.2 , 0.1 ;
          0.3 , 0.45, 0.25;
          0.2 , 0.35, 0.45;
          0.02, 0.08, 0.9 ;
          0.2 , 0.35, 0.45;
          0.3 , 0.45, 0.25;
          0.7 , 0.2 , 0.1 ;
          0.9 , 0.07, 0.03];
          
          
# P(L1|T) = linhas -> angulos da luz
#           colunas -> sensor viu, acha que viu, viu
#       nao vi   acho vi   vi
#       ---      ---       ---
# -135  0.8      0.1       0.1 
# -90   0.95     0.04      0.01
# -45   0.6      0.15      0.25
# 0     0.5      0.15      0.35
# 45    0.05     0.35      0.6
# 90    0.05     0.05      0.9       
# 135   0.1      0.2       0.7 
# 180   0.2      0.35      0.45
P_L1dT = [0.8 , 0.1 , 0.1 ;
          0.95, 0.04, 0.01;
          0.6 , 0.15, 0.25;
          0.5 , 0.15, 0.35;
          0.05, 0.35, 0.6 ;
          0.05, 0.05, 0.9 ;
          0.1 , 0.2 , 0.7 ;
          0.2 , 0.35, 0.45];


# P(L2|T) = linhas -> angulos da luz
#           colunas -> sensor viu, acha que viu, viu
#       nao vi   acho vi   vi
#       ---      ---       ---
# -135  0.8      0.1       0.1 
# -90   0.95     0.04      0.01
# -45   0.6      0.15      0.25
# 0     0.5      0.15      0.35
# 45    0.05     0.35      0.6
# 90    0.05     0.05      0.9       
# 135   0.1      0.2       0.7 
# 180   0.2      0.35      0.45
P_L2dT = [0.1 , 0.2 , 0.7 ;
          0.05, 0.05, 0.9 ;
          0.05, 0.35, 0.6 ;
          0.5 , 0.15, 0.35;
          0.6 , 0.15, 0.25;
          0.95, 0.04, 0.01;
          0.8 , 0.1 , 0.1 ;
          0.2 , 0.35, 0.45];          
               
# sum(P_L0dT, 2)
# sum(P_L1dT, 2)
# sum(P_L2dT, 2)

# P(M|T) =  linhas -> angulos da luz
#           colunas -> ir pra esquerda, ir reto, ir pra direita
#       ir esq   ir reto   ir direita
#       ---      ---       ---
# -135  0.9      0.05      0.05 
# -90   0.9      0.05      0.05
# -45   0.9      0.05      0.05
# 0     0.05     0.9       0.05
# 45    0.05     0.05      0.9
# 90    0.05     0.05      0.9       
# 135   0.05     0.05      0.9 
# 180   0.45     0.1       0.45
P_MdT = [0.9 , 0.05, 0.05;
          0.9 , 0.05, 0.05;
          0.9 , 0.05, 0.05;
          0.05, 0.9 , 0.05;
          0.05, 0.05, 0.9 ;
          0.05, 0.05, 0.9 ;
          0.05, 0.05, 0.9 ;
          0.45, 0.1 , 0.45];
          
# sum(P_MdT, 2)

# Calculo da conjunta
# P(M,T,L0,L1,L2) = P(T).P(L0|T).P(L1|T).P(L2|T).P(M|T)
# P_MTL0L1L2 = P_T.P_L0dT.P_L1dT.P_L2dT.P_MdT

P_MTL0L1L2 = zeros(3,8,3,3,3);

for m = 1:3
  for t = 1:8
    for l0 = 1:3
      for l1 = 1:3
        for l2 = 1:3
        
          P_MTL0L1L2(m,t,l0,l1,l2) = P_T(t)*P_L0dT(t,l0)*P_L1dT(t,l1)*P_L2dT(t,l2)*P_MdT(t,m);
        
        endfor
      endfor
    endfor
  endfor
endfor

# Pergunta
# Calculo de P(T|L0L1L2)
# P(T|L0L1L2) =  P(TL0L1L2)/P(L0L1L2)
# Em P(MTL0L1L2) / Emt P(MTL0L1L2)
# ~ Em P(MTL0L1L2)

# motor ir esquerda, reto, direita
# [P_M] = 3 = [-1,0,1]

# angulos da luz
# [P_T] = 8 = [-135,-90, -45, 0, 45, 90, 135, 180]

# sensor não viu, acha que viu, viu
# [P_L0] = 3 = [0,1,2]; = FRENTE DO ROBO
# [P_L1] = 3 = [0,1,2]; = DIREITA DO ROBO
# [P_L2] = 3 = [0,1,2]; = ESQUERDA DO ROBO

# se assumi valores 0 ou 1, base 2
# numero de algarismos, expoente
# se assumi valores 0,1 ou 2, base 3
# numero de algarismos , expoente

# combinacoes possiveis de L0L1L2 -> 3^3 = 27 valores
# 000 100 200
# 001 101 201
# 002 102 202
# 010 110 201
# 011 111 211
# 012 112 212
# 020 120 220
# 021 121 221
# 022 122 222

# P(T=-135|L0=0,L1=0,L2=0) = P(M=-1,T=-135,L0=0,L1=0,L2=0) + P(M=0,T=-135,L0=0,L1=0,L2=0) + P(M=1,T=-135,L0=0,L1=0,L2=0)
# P(T=- 90|L0=0,L1=0,L2=0) = ...
# P(T=- 45|L0=0,L1=0,L2=0) = 
# P(T=   0|L0=0,L1=0,L2=0) = 
# P(T=  45|L0=0,L1=0,L2=0) = 
# P(T=  90|L0=0,L1=0,L2=0) = 
# P(T= 135|L0=0,L1=0,L2=0) = 
# P(T= 180|L0=0,L1=0,L2=0) = 
# ...
# P(T=-135|L0=2,L1=2,L2=2) = P(M=-1,T=-135,L0=2,L1=2,L2=2) + P(M=0,T=-135,L0=2,L1=2,L2=2) + P(M=1,T=-135,L0=2,L1=2,L2=2)
# P(T=- 90|L0=2,L1=2,L2=2) = 
# P(T=- 45|L0=2,L1=2,L2=2) = 
# P(T=   0|L0=2,L1=2,L2=2) = 
# P(T=  45|L0=2,L1=2,L2=2) = 
# P(T=  90|L0=2,L1=2,L2=2) = 
# P(T= 135|L0=2,L1=2,L2=2) = 
# P(T= 180|L0=2,L1=2,L2=2) =

# Representacao usada em P_TdL0L1L2_r1
# num linhas = num de combinacoes pos barra = 27 linhas
# num colunas = num de combinacoes pre barra = 8 colunas

P_TdL0L1L2_r1 = zeros(27,8);
P_TdL0L1L2_aux = zeros(3,3,3,8);
P_TdL0L1L2_r2 = zeros(3,3,3,8);
line = 1;

for l0 = 1:3
  for l1 = 1:3
    for l2 = 1:3
      for t = 1:8
        for m = 1:3
          P_TdL0L1L2_r1(line,t) += P_MTL0L1L2(m,t,l0,l1,l2);
          P_TdL0L1L2_aux(l0,l1,l2,t) += P_MTL0L1L2(m,t,l0,l1,l2);
        endfor
      endfor
      line++;
    endfor
  endfor
endfor

for line = 1:27
  normalization = sum(P_TdL0L1L2_r1(line,:));
  for col = 1:8
    P_TdL0L1L2_r1(line,col) /= normalization;
  endfor
endfor
  
# sum(P_TdL0L1L2, 2)

for l0 = 1:3
  for l1 = 1:3
    for l2 = 1:3
      for t = 1:8
          normalization = sum(P_TdL0L1L2_aux(l0,l1,l2,:));
          P_TdL0L1L2_r2(l0,l1,l2,t) = P_TdL0L1L2_aux(l0,l1,l2,t)/normalization;
      endfor
    endfor
  endfor
endfor
























