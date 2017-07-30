#version 130

in vec4 vPosition;	//variáveis de entrada
in vec4 vColor;
out vec4 color;

void main( void ) {
   gl_Position = vPosition; 	//é apenas passada adiante
   color = vColor;
}
