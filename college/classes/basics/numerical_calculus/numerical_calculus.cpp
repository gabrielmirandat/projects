	1. Zeros da função
		-Nem sempre é possível calculas analiticamente as raízes de uma função. Para isto usamos os métodos numéricos.

		Etapas
		1) Isolamento das raízes - determinar um intervalo no eixo x, que contenha pelo menos uma raiz de f(x) - manualmente.
		2) Cálculo da raiz através de métodos iterativos.

		1)Isolamento das raízes

			'Teorema de Bolzano'
			Seja uma função f(x) contínua em um intervalo [a,b] tal que f(a)*f(b)<0. Então a função f(x) possui pelo menos uma
			raiz no intervalo [a,b].

		2)Cálculo por métodos iterativos

			'Método da Bisseção'
			Reduzir a amplitude do intervalo que contenha a raiz até atingir a precisão requerida: |b-a|< ε, usando para isto a
			sucessiva divisão de [a,b] ao meio.

			'Método MPF - Ponto Fixo'
			 xk+1 = f(xk)
			-Seja f(x) uma função contínua em [a,b] que contém as raízes de F(x).
			-Transformar F(x) em uma função equivalente x = f(x) e a partir de uma aproximação x0 gerar sequência {xn} de aproxi-
			 mações para ε.
			-Graficamente, uma raiz da equação x=f(x) é a  abcissa do ponto de intersecção da reta y=x e da curva y=f(x).

				'Teorema da convergência'
				-Se
				  1) f(x) e f'(x) são contínuas em I.
				  2) |f'(x)| <= M < 1 p/ todo x pertecente a I.
				  3) x0 pertencente a I.
				sendo ε1 raiz de F(x) isolada num intervalo I centrado em ε1,então a sequência {xk} gerada pelo processo
				xk+1 = f(xk) converge para ε1.

				'Critério de parada'
				- |xk+1 - xk| < ε ou |F(xk+1)| < ε

			'Método de Newton - Raphson'
			xk+1 = xk - f(xk)/f'(xk)
			-Sejam f(x), f'(x) e f"(x) contínuos num intervalo I que contém a raiz (ε1) de f(x) = 0.
			 Supor f'(ε1)!=0. Então existe um intervalo I' C I contendo a raiz ε1 tal que se x0 E I' a sequencia {xk}
			 gerada no processo xk+1 = xk - xk+1 = xk - f(xk)/f'(xk) convergirá para a raiz.

			'Método da Secante'
			xk+1 = ((xk-1).f(xk) - xk.f(xk-1))/(f(xk) - f(xk-1))
			-O objetivo do método é simplificar o método de Newton removendo as derivadas.
			-A partir de 2 aproximações xk-1 e xk o ponto xk+1 é obtido como sendo a abcissa do ponto de interseção do Ox
			 e da reta secante que passa por (xk-1,f(xk-1)) e (xk, f(xk)).

			'Método da posição falsa'
			O mesmo princípio do método da bisseção, vamos restringindo o intervalo.
			Porém, a restrição se dá pela fórmula: xk+1 = (a.f(b) - b.f(a))/(f(b) - f(a))
			É uma média ponderada.

    (PROVA 2)
    2. Sistemas lineares
            'Método Gauss-Jacobi'
            Transforma o sistema linear Ax + b em x = Cx + g.
            x(k+1) = Cx(k) + g

            e fazemos para todas as diagonais:
            Então o método de Gauss-Jacobi consiste em dado X(0), aproximação inicial,
            obter X(1), X(2), ..., x(k) através da relação recursiva:

             X1(k+1) = 1/a11(b1 - a12X2(k) - a13X3(k) -...-a1nXn(k))
             X2(k+1) = 1/a22(b2 - a21X1(k) - a23x3(k) -...-a2nXn(k))

             Critério de parada
                Distância entre duas iterações:
                    d(k) = max|Xi(k) - Xi(k-1)|
                    dr(k) = d(k)/max|Xi(k)| < E

             Critério de convergência
                A = max{Ak}

                                ...
             Xn(k+1) = 1/amn(bm - am1X1(k) - am2X2(k) -...-amn-1Xn-1(k))

             'Método Gauss-Seidel'
             ...

    3. Interpolação Numérica
             'Método de Lagrange'
             Encontrar funções a partir de pontos.
             -estimar valores intermediários entre dados precisos.
             -Consiste em achar uma função g(x), que consideraremos que pertence à classe das funções polinomiais.
             -É verdadeiro o teorema da "Existência e Unicidade", existe e é único.

             'Método de Newton'
             
    4. Integração Numérica
	     'Método do Trapézio'
	     'Método do Trapezio Dividido'
	     'Método Quadratura Gaussiana'