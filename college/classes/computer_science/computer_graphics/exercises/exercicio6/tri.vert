#version 130

in  vec4 vPosition;
out vec4 vColor;

uniform float theta;

void main( void ) {

   mat4 transl = mat4(   1,   0,     0,   0, 
                         0,   1,     0,   0, 
                         0,   0,     1,   0, 
                      0.25, 0.5,  0.75,   1 );

   gl_Position = transl * vPosition;

   vColor = vec4( 0.0, 1.0 , 0.0, 1.0);
}