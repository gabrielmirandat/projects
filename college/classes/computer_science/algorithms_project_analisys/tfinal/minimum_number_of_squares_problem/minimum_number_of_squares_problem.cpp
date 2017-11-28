// comentado!
// g++ minimum_number_of_squares_problem.cpp -o minimum_number_of_squares_problem
#include <iostream>
using namespace std;
 
int minSquares(int x)
{
    // cria array para armazenar subproblemas
    // minSq[i] eh o numero minimo de quadrados cuja soma eh i 
    int minSq[x+1];
 
    // inicializacao
    minSq[0]=0;
    minSq[1]=1;
 
    // para todos os numeros no array
    // de 2 a x
    for(int i=2;i<=x;i++)
    {
        // o numero maximo de quadrados que somam em i
        // eh i
        minSq[i]=i;
 
        // j representa a base que ao quadrado subtraida do valor de i
        // eh maior que zero
        for(int j=1;i>=j*j;j++)
        {
            // seleciona menor valor para i de acordo com os ja calculados
            // eh o minimo entre o proprio valor e 1 + o valor subtraido de j^2
            minSq[i]=min(minSq[i],1+minSq[i-j*j]);
        }
        cout << "minSq["<<i<<"] = "<< minSq[i] << endl;
    }
 
    return minSq[x];
}
 
int main()
{
    int x;
    
    // obtem o numero de entrada 
    cout<<"Enter the number "<<endl;
    cin>>x;
 
    // mostra menor numero de quadrados na tela
    cout<<"Min. number of squares that sum up to input number are "<<endl;
    cout<<minSquares(x);
    cout<<endl;
 
    return 0;
}