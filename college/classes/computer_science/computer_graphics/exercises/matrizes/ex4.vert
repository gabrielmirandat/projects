#version 130

in vec4 vPosition;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main( void ) {
   gl_Position =  proj * view * model * vPosition; 
}
