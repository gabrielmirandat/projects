#version 130

in vec4 vPosition;

void main( void ) {

   mat4 escala = mat4( 0.5,     0,     0,   0, 
                         0,   0.5,     0,   0,
                         0,     0,   0.5,   0,
                         0,     0,     0,   1 );

   gl_Position = escala * vPosition;
}