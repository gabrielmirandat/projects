// comentado!
// g++ army_problem.cpp -o army_problem
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    // numero de ranks
    int n;
    
    // ranks inicial e final
    int x,y;


    // obtem numero de ranks
    cout<<"Enter the number of ranks in the army ";
    cin>>n;

    // vetor para armazenar os anos acumulados para mudar de rank
    // inicializa os anos para ir de 0 a 1 como zero
    vector<int> sum(n);
    sum[0]=0;
 
    cout<<"Enter the number of years required to rise from previous rank to next rank for every rank"<<endl;
    for(int i=0;i<n-1;i++)
    {
        // constroi o vetor de anos acumulado
        cin>>x;
        sum[i+1]=sum[i]+x;
        cout << "sum["<<i+1<<"] = "<<sum[i+1]<< endl;
    }
 
    cout<<"Enter the initial rank  ";
    cin>>x;
    cout<<"Enter the targer rank ";
    cin>>y;
    cout<<"Number of years required to rise from rank "<<x<<" to rank "<<y<<"are"<<endl;
    cout<<sum[y-1]-sum[x-1]<<endl;
 
    return 0;
}