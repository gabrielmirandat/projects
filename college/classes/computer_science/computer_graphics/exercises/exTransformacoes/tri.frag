#version 130

out vec4 fColor;
in vec4 SColor;

void main( void ) {
   fColor = SColor;
}