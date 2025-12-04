#version 330 core

layout(location = 0) in vec3 aPos; // Vertex position
layout(location = 2) in vec2 aTexCoord; // Texture coordinate

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


out vec3 vertexColor; // Output color to the fragment shader
out vec2 TexCoord; // Output texture coordinate to the fragment shader

void main()
{
    gl_Position = projection* view * model * vec4(aPos, 1.0); // Set the vertex position
    
    TexCoord = aTexCoord; // Pass the texture coordinate to the fragment shader
    
}