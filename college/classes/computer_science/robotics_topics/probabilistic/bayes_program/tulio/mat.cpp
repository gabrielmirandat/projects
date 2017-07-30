// g++ -std=c++11 mat.cpp -o mat
 
#include <iostream>
#include <vector>
 
typedef std::vector<double> m1D_t;
typedef std::vector< std::vector<double> > m2D_t;
typedef std::vector< std::vector< std::vector<double> > > m3D_t;
typedef std::vector< std::vector< std::vector< std::vector<double> > > > m4D_t;
typedef std::vector< std::vector< std::vector< std::vector< std::vector<double> > > > > m5D_t;
 
m5D_t createMatrix(int a, int b, int c, int d, int e, double num) {
    m5D_t matrix (a, m4D_t (b, m3D_t (c, m2D_t (d, m1D_t (e, num)))));
    return matrix;
}
 
int main () {
     
    /*
     *  P(O)
     */
    // cria uma matriz 8x1x1x1x1 para representar P(O)
    m5D_t PO = createMatrix (8, 1, 1, 1, 1, 1.0/8);
     
    /*
     *  P(M|O)
     */
    // cria uma matriz 8x3x1x1x1 para representar P(M|O)
    m5D_t PMgO = createMatrix (8, 3, 1, 1, 1, 0.0);
    // calcula numa matriz temporária fora do padrão
    m2D_t tempPMgO = {  {0.9, 0.05, 0.05},
                        {0.9, 0.05, 0.05},
                        {0.9, 0.05, 0.05},
                        {0.05, 0.9, 0.05},
                        {0.05, 0.05, 0.9},
                        {0.05, 0.05, 0.9},
                        {0.05, 0.05, 0.9},
                        {0.05, 0.05, 0.9}   };
    // ajeita os valores na matrix (tipo o permute do Matlab)
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 3; ++j)
            PMgO[i][j][0][0][0] = tempPMgO[i][j];
     
    /*
     *  P(L0|O)
     */
    // cria uma matriz 8x1x3x1x1 para representar P(L0|O)
    m5D_t PL0gO = createMatrix (8, 1, 3, 1, 1, 0.0);
    // calcula numa matriz temporária fora do padrão
    m2D_t tempPL0gO = { {0.8, 0.15, 0.05},
                        {0.5, 0.3, 0.2},
                        {0.1, 0.3, 0.6},
                        {0.02, 0.08, 0.9},
                        {0.1, 0.3, 0.6},
                        {0.5, 0.3, 0.2},
                        {0.8, 0.15, 0.05},
                        {0.8, 0.15, 0.05}   };
    // ajeita os valores na matrix (tipo o permute do Matlab)
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 3; ++j)
            PL0gO[i][0][j][0][0] = tempPL0gO[i][j];
     
    /*
     *  P(L1|O)
     */
    // cria uma matriz 8x1x1x3x1 para representar P(L1|O)
    m5D_t PL1gO = createMatrix (8, 1, 1, 3, 1, 0.0);
    // calcula numa matriz temporária fora do padrão
    m2D_t tempPL1gO = { {0.02, 0.08, 0.9},
                        {0.1, 0.3, 0.6},
                        {0.5, 0.3, 0.2},
                        {0.8, 0.15, 0.05},
                        {0.8, 0.15, 0.05},
                        {0.5, 0.3, 0.2},
                        {0.1, 0.3, 0.6},
                        {0.8, 0.15, 0.05}   };
    // ajeita os valores na matrix (tipo o permute do Matlab)
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 3; ++j)
            PL1gO[i][0][0][j][0] = tempPL1gO[i][j];
     
    /*
     *  P(L2|O)
     */
    // cria uma matriz 8x1x1x1x3 para representar P(L2|O)
    m5D_t PL2gO = createMatrix (8, 1, 1, 1, 3, 0.0);
    // calcula numa matriz temporária fora do padrão
    m2D_t tempPL2gO = { {0.5, 0.3, 0.2},
                        {0.8, 0.15, 0.05},
                        {0.8, 0.15, 0.05},
                        {0.8, 0.15, 0.05},
                        {0.5, 0.3, 0.2},
                        {0.1, 0.3, 0.6},
                        {0.02, 0.08, 0.9},
                        {0.1, 0.3, 0.6}   };
    // ajeita os valores na matrix (tipo o permute do Matlab)
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 3; ++j)
            PL2gO[i][0][0][0][j] = tempPL2gO[i][j];
     
    /*
     *  P(O,M,L0,L1,L2)
     */
    // cria uma matriz 8x3x3x3x3 para representar P(O,M,L0,L1,L2)
    m5D_t POML0L1L2 = createMatrix (8, 3, 3, 3, 3, 0.0);
    // calcula a probabilidade conjunta
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 3; ++l) {
                    for (int m = 0; m < 3; ++m) {
                        POML0L1L2[i][j][k][l][m] = PO[i][0][0][0][0] * PMgO[i][j][0][0][0] * PL0gO[i][0][k][0][0] * PL1gO[i][0][0][l][0] * PL2gO[i][0][0][0][m];
                    }
                }
            }
        }
    }
     
    /*
     *  P(O|L0,L1,L2)
     */
    // calcula P(O,L0,L1,L2) (matriz 8x1x3x3x3) somando em M
    m5D_t POL0L1L2 = createMatrix (8, 1, 3, 3, 3, 0.0);
    for (int i = 0; i < 8; ++i) {
        for (int k = 0; k < 3; ++k) {
            for (int l = 0; l < 3; ++l) {
                for (int m = 0; m < 3; ++m) {
                    double sum = 0;
                    for (int j = 0; j < 3; ++j) {
                        sum = sum + POML0L1L2[i][j][k][l][m];
                    }
                    POL0L1L2[i][0][k][l][m] = sum;
                }
            }
        }
    }
    // calcula P(L0L1L2) (matriz 1x1x3x3x3) somando em O e em M
    m5D_t PL0L1L2 = createMatrix (1, 1, 3, 3, 3, 0.0);
    for (int k = 0; k < 3; ++k) {
        for (int l = 0; l < 3; ++l) {
            for (int m = 0; m < 3; ++m) {
                double sum = 0;
                for (int i = 0; i < 8; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        sum = sum + POML0L1L2[i][j][k][l][m];
                    }
                }
                PL0L1L2[0][0][k][l][m] = sum;
            }
        }
    }
    // cria uma matriz 8x1x3x3x3 para representar P(O|L0,L1,L2) e calcula P(O|L0,L1,L2) = P(OL0L1L2)/P(L0L1L2)
    m5D_t POgL0L1L2 = createMatrix (8, 1, 3, 3, 3, 0.0);
    for (int i = 0; i < 8; ++i) {
        for (int k = 0; k < 3; ++k) {
            for (int l = 0; l < 3; ++l) {
                for (int m = 0; m < 3; ++m) {
                    POgL0L1L2[i][0][k][l][m] = POL0L1L2[i][0][k][l][m]/PL0L1L2[0][0][k][l][m];
                }
            }
        }
    }
     
    // mostra os valores para l0 = 1, l1 = 2 e l3 = 0
    // por coincidencia os indices sao iguais aos valores
    std::cout << "Dist.: ";
    for (int i = 0; i < 8; ++i) {
        std::cout << POgL0L1L2[i][0][1][2][0] << " ";
    }
    std::cout << "\n";
     
    return 0;
}