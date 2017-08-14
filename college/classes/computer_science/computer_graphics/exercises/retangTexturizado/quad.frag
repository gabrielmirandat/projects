#version 130

in  vec4 color;
in  vec2 texCoord;

out vec4 fColor;

uniform sampler2D texture;

void main() { 
    fColor = /*color */ texture2D( texture, texCoord );

    //fColor =  texture2D( texture, texCoord ) * vec4(1,1,1,1);

} 

