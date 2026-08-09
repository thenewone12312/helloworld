#version 330 core

out vec4 FragColor;

uniform vec4 uColor;

in vec2 texCoord;

uniform sampler2D tex0;



void main()
{
    FragColor = texture(tex0, texCoord);
}