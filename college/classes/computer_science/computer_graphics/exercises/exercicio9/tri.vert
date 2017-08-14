#version 130

in  vec4 vPosition;
out vec4 vColor;

uniform float theta;

void main( void ) {

   // Computa o seno e cosseno de theta
 
   float angle = radians( theta );
   float c = cos( angle );
   float s = sin( angle );


   //--------------------------------------------------------------
   // Matriz de rotação



   mat4 rx = mat4( 1.0,   0.0,   0.0,   0.0,
                   0.0,     c,     -s,  0.0, 
                   0.0,     s,      c,  0.0,
                   0.0,   0.0,    0.0,  1.0 );

   gl_Position =  rx * vPosition;


   vColor = vec4( 1 - abs(c), 1 + s, 1 - abs(c*s), 1.0);
}