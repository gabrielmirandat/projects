#version 130

in vec4 vPosition;

uniform mat4 model;

void main( void ) {
   gl_Position =  model * vPosition; 
}