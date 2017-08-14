#version 130

in vec4 color;		//entrada que veio do shader.vert
out vec4 fColor;	//variável de saída

void main( void ) {
   fColor = color;	//passa adiante.
}
