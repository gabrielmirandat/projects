#version 130

in vec4 vPosition;	//variável de entrada
out vec4 vColor;	//variável de saída, mandada para o shader.frag

uniform vec3 theta;

void main( void ) {
   gl_Position = vPosition; 	//é apenas passada adiante
   
   vColor = vec4(theta, 1.0);	//manda para o fragment shader
}
