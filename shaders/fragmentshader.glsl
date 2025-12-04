#version 330 core

out vec4 FragColor; // Output color of the fragment

uniform float greenColor; // Input color from the vertex shader
in vec2 TexCoord; // Input texture coordinate from the vertex shader

uniform sampler2D ourTexture;
uniform sampler2D texture1;

void main()
{
    FragColor = mix(texture(ourTexture, TexCoord), texture(texture1, TexCoord), 0.2);
    
}