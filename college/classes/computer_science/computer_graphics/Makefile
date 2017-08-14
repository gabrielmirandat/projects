GLFLAGS = -lGL -lGLEW -lglut -lSOIL -lm
SDLFLAGS = -lSDL -lSDL_mixer

.PHONY: project1 project2 project3 final exercises

project1 :
	g++ common/InitShader.cpp project1/simples/hex_simp.cpp  $(GLFLAGS) -o project1/simples/hex_simp
	g++ common/InitShader.cpp project1/colorido/hex_col.cpp $(GLFLAGS) -o project1/colorido/hex_col
	g++ common/InitShader.cpp project1/aleatorio/hex_alea.cpp $(GLFLAGS) -o project1/aleatorio/hex_alea

project2 :
	g++ common/InitShader.cpp project2/perspectiva/piramide.cpp $(GLFLAGS) -o project2/perspectiva/piramide	
	g++ common/InitShader.cpp project2/responda/piramide.cpp $(GLFLAGS) -o project2/responda/piramide	

project3 :
	g++ common/InitShader.cpp project3/colorida_1.cpp $(GLFLAGS) -o project3/colorida_1
	g++ common/InitShader.cpp project3/colorida_2.cpp $(GLFLAGS) -o project3/colorida_2
	g++ common/InitShader.cpp project3/colorida_3.cpp $(GLFLAGS) -o project3/colorida_3
	g++ common/InitShader.cpp project3/colorida_4.cpp $(GLFLAGS) -o project3/colorida_4

final :
	g++ project_final/redemoinho.cpp common/*.cpp$  $(GLFLAGS) $(SDLFLAGS) -o project_final/redemoinho

exercises :
	g++ common/InitShader.cpp exercises/esfera/colorida.cpp $(GLFLAGS) -o exercises/esfera/colorida
	g++ common/InitShader.cpp exercises/exTransformacoes/triangulo.cpp $(GLFLAGS) -o exercises/exTransformacoes/triangulo
	g++ common/InitShader.cpp exercises/exTransformacoes/triangulo_2.cpp $(GLFLAGS) -o exercises/exTransformacoes/triangulo_2
	g++ common/InitShader.cpp exercises/exercicio1/triangulo.cpp $(GLFLAGS) -o exercises/exercicio1/triangulo
	g++ common/InitShader.cpp exercises/exercicio10/triangulo.cpp $(GLFLAGS) -o exercises/exercicio10/triangulo
	g++ common/InitShader.cpp exercises/exercicio2/tricores.cpp $(GLFLAGS) -o exercises/exercicio2/tricores
	g++ common/InitShader.cpp exercises/exercicio3/quadrado.cpp $(GLFLAGS) -o exercises/exercicio3/quadrado
	g++ common/InitShader.cpp exercises/exercicio3D1/cube.cpp $(GLFLAGS) -o exercises/exercicio3D1/cube
	g++ common/InitShader.cpp exercises/exercicio4rand/rctriangle.cpp $(GLFLAGS) -o exercises/exercicio4rand/rctriangle
	g++ common/InitShader.cpp exercises/exercicio5/triangulo.cpp $(GLFLAGS) -o exercises/exercicio5/triangulo
	g++ common/InitShader.cpp exercises/exercicio6/triangulo.cpp $(GLFLAGS) -o exercises/exercicio6/triangulo
	g++ common/InitShader.cpp exercises/exercicio7/triangulo.cpp $(GLFLAGS) -o exercises/exercicio7/triangulo
	g++ common/InitShader.cpp exercises/exercicio8/triangulo.cpp $(GLFLAGS) -o exercises/exercicio8/triangulo
	g++ common/InitShader.cpp exercises/exercicio9/triangulo.cpp $(GLFLAGS) -o exercises/exercicio9/triangulo
	g++ common/InitShader.cpp exercises/fractal/fract2d.cpp $(GLFLAGS) -o exercises/fractal/fract2d
	g++ common/InitShader.cpp exercises/iluminacao/proj.cpp $(GLFLAGS) -o exercises/iluminacao/proj
	g++ common/InitShader.cpp exercises/matrizes/ex1.cpp $(GLFLAGS) -o exercises/matrizes/ex1
	g++ common/InitShader.cpp exercises/matrizes/ex2.cpp $(GLFLAGS) -o exercises/matrizes/ex2
	g++ common/InitShader.cpp exercises/matrizes/ex3.cpp $(GLFLAGS) -o exercises/matrizes/ex3
	g++ common/InitShader.cpp exercises/matrizes/ex4.cpp $(GLFLAGS) -o exercises/matrizes/ex4
	g++ common/InitShader.cpp exercises/matrizes/ex5.cpp $(GLFLAGS) -o exercises/matrizes/ex5
	g++ common/InitShader.cpp exercises/matrizes/ex6.cpp $(GLFLAGS) -o exercises/matrizes/ex6
	#g++ common/InitShader.cpp exercises/texturaTudo/textura.cpp $(GLFLAGS) -o exercises/texturaTudo/textura
	#g++ common/InitShader.cpp exercises/retangTexturizado/quadrado.cpp $(GLFLAGS) -o exercises/retangTexturizado/quadrado

	