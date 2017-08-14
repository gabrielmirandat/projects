#version 130

in  vec4 vPosition;
in  vec4 vColor;

out vec4 cor;

uniform mat4 mvm;

uniform float theta;

void main( void ) {

float angle = radians(theta);
float s = sin(angle);
float c = cos(angle);

mat4 rotz = mat4(c,   -s,   0.0,  0.0,
                 s,    c,   0.0,  0.0, 
               0.0,  0.0,   1.0,  0.0,
               0.0,  0.0,   0.0,  1.0 );

mat4 rx = mat4( 1.0,   0.0,    0.0,  0.0,
                0.0,     c,     -s,  0.0, 
                0.0,     s,      c,  0.0,
                0.0,   0.0,    0.0,  1.0 );



   gl_Position =   rx *  mvm * vPosition;

  cor = vColor;

}