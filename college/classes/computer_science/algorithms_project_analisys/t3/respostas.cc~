1- Demonstre por indução que sempre é possível dar um troco de n centavos, para qualquer n > 7, com moedas de 3 e 5 centavos

t = num moedas de 3
c = num moedas de 5

- Base da indução
n = k = 8

8 = 3t + 5c
t = 1
c = 1

- Hipótese de Indução
n = n

n = 3t + 5c
n = 3(5c)

-------------------------

n = 3x + 5y

- base
8 = 3x + 5y, com x=1, y=1

- hipotese de inducao
n = 3x + 5y, com n,x,y inteiros

- passo
(3x + 5y) + 1 = (3x2 + 5y2), com n+1, x2, y2 inteiros

http://marathoncode.blogspot.com.br/2012/03/inducao-forte.html

a[8] = 1;
b[8] = 1;

a[9] = 3;
b[9] = 0;

a[10] = 0;
b[10] = 2;

for(i=11;i<=n;i++){
	a[i] = a[i-3]+1;
	b[i] = b[i-3];
}
printf("%d=3*%d + 5*%d\n",n,a[n],b[n]);

8= 3*1 + 5*1
9= 3*3 + 5*0
10=3*0 + 5*2
11=3*2 + 5*1
12=3*4 + 5*0
13=3*1 + 5*2
14=3*3 + 5*1
15=3*5 + 5*0
16=3*2 + 5*2
17=3*4 + 5*1
18=3*6 + 5*0


3.
T(n)=T(n/6)+T(7n/9)+O(n) tem O(n)

Chute: T(n) = O(n)
- Indução: Provar que "T(n) ≤ cn", para algum c e n ≥ n0
- Hipótese indutiva: T(n/6)+T(7n/9) + n <= cn/6 + c7n/9 + n

- Prova

T(n)=T(n/6)+T(7n/9)+T(n) 
<= cn/6 + c7n/9 + n
= cn(1/6 + 7/9) + n
Não deu, filha da puta













