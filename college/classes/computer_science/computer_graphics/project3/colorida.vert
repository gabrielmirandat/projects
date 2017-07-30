#version 130

in  vec3 vPosition;
//in  vec4 vColor;
out vec4 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform float theta;
uniform float corUni;

void main( void ) {
   float angle = radians( theta );
   float c = cos( angle );
   float s = sin( angle );

   mat4 ry = mat4( c,   0.0,  s,   0.0,
                   0.0, 1.0,  0.0, 0.0, 
                  -s,   0.0,  c,   0.0,
                   0.0, 0.0,  0.0, 1.0 );

   gl_Position = projection * view * model * ry * vec4(vPosition, 1.0); 

   if(corUni == 10.0){
      color = vec4(clamp(vPosition, 0.0, 1.0), 1.0)* vec4(0.0, 0.3, 0.0, 1.0);
   }else if(corUni == 20.0){
      color = vec4(clamp(vPosition, 0.0, 1.0), 1.0)* vec4(1.0, 0.0, 0.5, 1.0);
   }else if(corUni == 30.0){
      color = vec4(clamp(vPosition, 0.0, 1.0), 1.0)* vec4(0.9, 0.0, 1.0, 1.0);
   }
   
}