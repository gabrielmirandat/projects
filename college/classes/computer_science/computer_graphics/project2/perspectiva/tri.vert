#version 130

in  vec4 vPosition;
in  vec4 vColor;

out vec4 cor;

uniform mat4 mvm;
uniform mat4 proj;

void main( void ) {

   gl_Position = proj * mvm * vPosition;

  cor = vColor;

}