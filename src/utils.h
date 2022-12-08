#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream> //std::stringstream
#include <vector>
#include "shader.h"
#include "texture.h"
#define INTERNAL_WIDTH 640
#define INTERNAL_HEIGHT 480

namespace utils {
    std::string loadFile(std::string filename);
    static std::vector<shader> shaders;
    static std::vector<texture> textures;
    static unsigned int renderFB;
    static unsigned int renderTexture;

    static double deltaTime;
	double lerp(double a, double b, double t);
    int sign(int);
    int unsign(int);
    float mean(float arr[], int from, int to);        
    int getMouseX();
    int getMouseY();
    int mouseCheck(int);
    int keyboardCheck(int);

}
 //these classes originate from KnuxfanPong, but I found them useful here.
struct letter {
    char character = ' ';
    int width;
    int x;
    int y;
};

struct color { //technically didnt need this, but included it anyways because SDL_color is jank (and useless in opengl)
public:
    color() {};
    color(int red, int green, int blue) { r = red; g = green; b = blue; }
    int r, g, b;

};
#endif