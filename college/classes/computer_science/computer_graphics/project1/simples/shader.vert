#version 130

in vec4 vPosition;	//variável de entrada

void main( void ) {
   gl_Position = vPosition; 	//é apenas passada adiante
}