// g++ recursao_13_0111350_Gabriel.cc -o calcula_recorrencia
// ./calcula_recorrencia 1 4 0 1 2 0 2 10000

// RESTRIÇOES
// - altura_arvore < 1000
#include <iostream>
#include <sstream>
#include <cmath>
#include <time.h>

using namespace std;
int a, b, c, d, e, f, g, n;
int altura_arvore = 1;
double tempo_total_gasto;
double trabalho_nivel[1000];
double numero_recursoes_nivel[1000];
double trabalho_fn[1000];
const double TEMPO_TRUNCAMENTO = 360.0; // 6 minutos

clock_t tempo_execucao_inicial, tempo_execucao_atual, tempo_execucao_final;

void relacao_recorrencia(int a,int b,int c,int d,int e,int f,int g,int n);
void func_T (int n, int altura_atual, double tempo_atual);
int func_f (int n);
void calcula_altura_arvore(int altura_no);
void registra_trabalho_nivel(int altura_no, double tempo_no);
void registra_numero_recursoes_nivel(int altura_no);
void registra_trabalho_fn(int altura_no, double trabalho);
void mostra_altura_arvore();
void mostra_trabalho_nivel();
void mostra_numero_recursoes_nivel();
void mostra_tempo_total_execucao();
void mostra_trabalho_fn();
bool metodo_mestre_teorico();

int main(int argc, char* argv[])
{
  if (argc == 9)
  {
    std::stringstream ss(argv[1]);
    ss << argv[1] << ' ' << argv[2] << ' ' << argv[3] << ' ' << argv[4] << ' ' << argv[5] << ' ' << argv[6]
       << ' ' << argv[7] << ' ' << argv[8];

    cout << endl;
    if (ss >> a >> b >> c >> d >> e >> f >> g >> n)
    {
      tempo_execucao_inicial = clock();

      relacao_recorrencia(a, b, c, d, e, f, g, n);
      func_T(n, 1, 0.0);

      mostra_altura_arvore();
      mostra_trabalho_nivel();
      mostra_numero_recursoes_nivel();
      mostra_tempo_total_execucao();
      mostra_trabalho_fn();

      bool mestre_se_aplica = metodo_mestre_teorico();

      tempo_execucao_final = clock();
      double tempo = (double)(tempo_execucao_final - tempo_execucao_inicial) / CLOCKS_PER_SEC;
      string tipo_execucao = tempo > TEMPO_TRUNCAMENTO ? "TRUNCADO" : "NORMAL";
      cerr << "Tempo Execução = "<<tempo<< "s - "<<tipo_execucao<< endl << endl;
      cout << "\nTempo Execução = "<<tempo<< "s - "<<tipo_execucao<< endl;
    }
  }
  else
  {
    cout << "Rode na forma calcula_recorrencia a b c d e f g n" << endl;
  }

  cout << endl;
  return 0;
}

void relacao_recorrencia(int a,int b,int c,int d,int e,int f,int g,int n) // T(n) = aT( (n/b) –c ) + dT( (n/e) –f ) + f(n)
{
  cout << "T(n) = "<<a<<"T( (n/"<<b<<") -"<<c<<" ) + "<<d<<"T( (n/"<<e<<") -"<<f<<" ) + n^"<<g<< endl;
  cout << "Com n = "<<n<< endl;
}

void func_T (int n, int altura_atual, double tempo_atual) // simula a recorrencia
{
  if (n<=1) return;
  tempo_execucao_atual = clock();
  if((double)(tempo_execucao_atual - tempo_execucao_inicial) / CLOCKS_PER_SEC > TEMPO_TRUNCAMENTO) return;

  tempo_atual++;

  for (int cont=1; cont<=a; cont++) // faz a chamadas de tamanho (n/b) - c
    func_T( (n/b) - c, altura_atual + 1, tempo_atual);

  for (int cont=1; cont<=d; cont++) // faz d chamadas de tamanho (n/e) - f
    func_T( (n/e) - f, altura_atual + 1, tempo_atual );

  int trabalho_fn = 0;
  for (int cont=1; cont<= func_f(n); cont++) // simula o tempo de f(n) no nível atual
  {
    tempo_atual++;
    trabalho_fn++;
  }
  tempo_total_gasto += tempo_atual;

  calcula_altura_arvore(altura_atual);
  registra_trabalho_nivel(altura_atual, tempo_atual);
  registra_numero_recursoes_nivel(altura_atual);
  registra_trabalho_fn(altura_atual, trabalho_fn);
}

int func_f (int n) // conta numero iterações de f(n).
{
  int resultado = pow(n,g);
  return resultado; // retorna n^g
}

void calcula_altura_arvore(int altura_no)
{
  altura_arvore = altura_no > altura_arvore ? altura_no : altura_arvore;
}

void registra_trabalho_nivel(int altura_no, double tempo_no)
{
  trabalho_nivel[altura_no-1] += tempo_no;
}

void registra_numero_recursoes_nivel(int altura_no)
{
  numero_recursoes_nivel[altura_no-1] += 1.0;
}

void registra_trabalho_fn(int altura_no, double trabalho)
{
  trabalho_fn[altura_no-1] += trabalho;
}

void mostra_altura_arvore()
{
  cout << "|=> Altura arvore = " << altura_arvore << endl;
}

void mostra_trabalho_nivel()
{
  cout << "|=> Trabalho por nivel" << endl;

  for(int nivel=0; nivel < altura_arvore; nivel++)
    cout << "Nivel " << nivel+1 << " = " << trabalho_nivel[nivel] << endl;
}

void mostra_numero_recursoes_nivel()
{
  cout << "|=> Numero recursoes por nivel" << endl;

  for(int nivel=0; nivel < altura_arvore; nivel++)
    cout << "Nivel " << nivel+1 << " = " << numero_recursoes_nivel[nivel] << endl;
}

void mostra_tempo_total_execucao()
{
  cout << "|=> Tempo total = " << tempo_total_gasto << endl;
}

void mostra_trabalho_fn()
{
  cout << "|=> Trabalho de fn por nivel" << endl;

  for(int nivel=0; nivel < altura_arvore; nivel++)
    cout << "Nivel " << nivel+1 << " = " << trabalho_fn[nivel] << endl;
}

bool metodo_mestre_teorico()
{
  if(a == 0 || c > 0 || d > 0)
    return false;

  cout << "\nMetodo Mestre" << endl;
  cout << "T(n) = "<<a<<"T( (n/"<<b<<") + n^"<<g<< endl;
  cout << "b = "<<b<<", a = "<<a<<", f(n) = n^"<<g<< endl;
  double logbA = log(a)/log(b);
  cout << "log de "<<a<<" na base "<<b<<" = "<< logbA << endl;
  int diff = logbA - g;

  if(diff > 0)
  {
    cout << "Caso 1 Método Mestre" << endl;
    cout << "T(n) = Teta(n^"<<logbA<<")" << endl;
  }
  else if (diff < 0)
  {
    cout << "Caso 3 Método Mestre" << endl;
    cout << "T(n) = Teta(n^"<<g<<")" << endl;
  }
  else
  {
    cout << "Caso 2 Método Mestre" << endl;
    cout << "T(n) = Teta(n^"<<logbA<<"lgn)" << endl;
  }
}
