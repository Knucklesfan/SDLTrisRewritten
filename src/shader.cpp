#include "shader.h"
#include "utils.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h> // otherwise we want to use OpenGL
#include <stdio.h>
#include <string>

shader::shader(std::string vertPath, std::string fragpath)
{
    int success; //debug stuff
    char infoLog[512];

    //compile shaders
    std::string vertStr = utils::loadFile(vertPath);
    const char* vertex = vertStr.c_str();
    std::cout << vertStr << "\n";
    id = glCreateProgram();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertex, NULL);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    //fragment
    std::string fragStr = utils::loadFile(fragpath);
    const char* fragment = fragStr.c_str();
    std::cout << fragment << "\n";
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragment, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //make shader program
    glAttachShader(id, vertexShader);
    glAttachShader(id, fragmentShader);
    glLinkProgram(id); // you can absolutely set this up to auto-configure from an xml file
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

}

void shader::activate()
{
    glUseProgram(id);
}

void shader::setBool(const std::string& name, bool value) const
{
    int location = glGetUniformLocation(id, name.c_str());
    glUniform1i(location, (int)value);

}

void shader::setInt(const std::string& name, int value) const
{
    int location = glGetUniformLocation(id, name.c_str());
    glUniform1i(location, value);

}

void shader::setFloat(const std::string& name, float value) const
{
    int location = glGetUniformLocation(id, name.c_str());
    glUniform1f(location, value);

}

void shader::setVector(const std::string& name, float* value) const {
    int location = glGetUniformLocation(id, name.c_str());
    glUniformMatrix4fv(location,1, GL_FALSE, value);

}
void shader::setVec2(const std::string& name, float* value) const {
    int location = glGetUniformLocation(id, name.c_str());
    glUniform2fv(location,1, value);

}