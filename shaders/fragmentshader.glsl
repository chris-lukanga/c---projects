#version 330 core
out vec4 FragColor;

in vec3 vertexColor;
in vec2 texCoords;

uniform sampler2D ourSampler;


void main()
{
    FragColor = texture(ourSampler, texCoords)*vec4(vertexColor, 1.0f);

}