# M - motor
# T - theta
# L0 - sensor 1
# L1 - sensor 2
# L2 - sensor 3  

# Objetivo: achar a conjunta P_MTL0L1L2
# P(M,T,L0,L1,L2) = P(T).P(L0|T).P(L1|T).P(L2|T).P(M|T)
# P_MTL0L1L2) = P_T.P_L0dT.P_L1dT.P_L2dT.P_MdT

# motor ir esquerda, reto, direita
# [P_M] = 3 = [-1.,0.,1.]

# angulos da luz
# [P_T] = 8 = [-135.,-90., -45., 0, 45., 90., 135., 180.]

# sensor não viu, acha que viu, viu
# [P_L0] = 3 = [0.,1.,2.]; = FRENTE DO ROBO
# [P_L1] = 3 = [0.,1.,2.]; = DIREITA DO ROBO
# [P_L2] = 3 = [0.,1.,2.]; = ESQUERDA DO ROBO

# P(T) = uniforme
P_T = [1./8, 1./8, 1./8, 1./8, 1./8, 1./8, 1./8, 1./8];

# P(L0|T) = linhas -> angulos da luz
#           colunas -> sensor viu, acha que viu, viu
#       nao vi   acho vi   vi
#       ---      ---       ---
# -135  0.7      0.2       0.1 
# -90   0.3      0.45      0.25
# -45   0.2      0.35      0.45
# 0     0.02     0.08      0.9
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
# -135  0.7      0.2       0.1 
# -90   0.3      0.45      0.25
# -45   0.2      0.35      0.45
# 0     0.02     0.08      0.9
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


# P(L2|T) = linhas -> angulos da luz
#           colunas -> sensor viu, acha que viu, viu
#       nao vi   acho vi   vi
#       ---      ---       ---
# -135  0.7      0.2       0.1 
# -90   0.3      0.45      0.25
# -45   0.2      0.35      0.45
# 0     0.02     0.08      0.9
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
          

          
          
          
          
          
          
          
          
          
          
# sum(P_L0dT, 2)         
 