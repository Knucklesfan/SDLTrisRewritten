#version 330 core
out vec4 FragColor;
in vec4 vertPos;

void main()
{
    FragColor = vec4(vertPos.x, vertPos.y, 1.0f, 1.0f);
} 
