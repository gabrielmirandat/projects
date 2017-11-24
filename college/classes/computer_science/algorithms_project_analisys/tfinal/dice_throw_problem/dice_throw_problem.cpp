// comentado!
// g++ dice_throw_problem.cpp -o dice_throw_problem

#include <iostream>
#include <vector>
using namespace std;
 
// funcao principal que retorna a quantidade de formas
// que eh possivel obter "sum" lançando "n" dados cada 
// um com "faces" faces
int diceThrow(int n, int faces, int sum)
{
    // matriz para armazenar resultados intermediarios
    // preenchida inicialmente com zeros
    // dp[i][j] - numero de formas de obter soma j com i dados disponiveis
    // dim(i) - n+1
    // dim(j) - sum+1
    vector<vector<int> > dp(n+1,vector<int>(sum+1,0));
 
    // i - num dados disponiveis
    // j - soma obtida
    // k - numero de faces no dado
    int i,j,k;
 
    // inicializacao
    // com 0 dados obtenho soma 0 de 1 forma(s) - fazendo nada
    dp[0][0]=1;
 
    // com i dados disponiveis
    for(i=1;i<=n;i++)
    {
        // para obter soma j
        for(j=1;j<=sum;j++)
        {
            // se soma j eh menor que o numero de dados
            // soma eh menor que a soma das menores faces de todos os dados
            // nenhuma maneira possivel
            if(j<i)
                dp[i][j]=0;
 
            // se soma j eh maior que o numero de faces vezes o numero de dados
            // soma eh maior que a soma das maiores faces de todos os dados
            // nenhuma maneira possivel
            else if(j>faces*i)
                dp[i][j]=0;
 
            // dependendo do numero de faces k
            // o numero de maneiras de obter uma soma j com 1 dados
            // eh a soma do numero de maneiras de obter as somas j-k
            // com i-1 dados
            else
            {
                for(k=1;k<=faces && k<=j;k++)
                    dp[i][j]+=dp[i-1][j-k];
            }
            cout << "tab["<<i<<"]["<<j<<"] = " << dp[i][j] << endl;
        }
    }
 
    // retorna o valor da tabela correspondente
    return dp[n][sum];
 
}
 
int main()
{
    int n;
    int faces;
    int sum;
 
    // obtem numero de dados
    cout<<"Enter number of dices"<<endl;
    cin>>n;
 
    // obtem numero de faces por dados
    cout<<"Enter number of faces in a dice"<<endl;
    cin>>faces;
 
    // obtem valor da soma desejada
    cout<<"Enter the value of sum"<<endl;
    cin>>sum;
 
    // calcula tabela de valores de forma bottom-up
    // e retorna numero de maneiras desejado
    cout<<"Number of ways in which the dices can give the required sum is "<<endl;
    cout<<diceThrow(n,faces,sum);
 
    // termina o programa
    cout<<endl;
    return 0;
}