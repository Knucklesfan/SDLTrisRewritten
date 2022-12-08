#include "utils.h"
#include <SDL2/SDL.h>

//std::vector<texture> utils::textures = std::vector<texture>();
//std::vector<shader> utils::shaders = std::vector<shader>();

std::string utils::loadFile(std::string filename) {
        std::ifstream inFile;
        inFile.open(filename); //open the input file

        std::stringstream strStream;
        strStream << inFile.rdbuf(); //read the file
        return strStream.str(); //str holds the content of the file
}
float utils::mean(float arr[], int from, int to) {
    float ret = 0.0;
    for(int i = from; i < to; i++) {
        ret += arr[i];
    }
    return ret/to-from;
}
int utils::unsign(int a) {
    if(a < 0) {
        return 0;
    }
    return a;
}
int utils::keyboardCheck(int keycode) {
    const Uint8 *keys = SDL_GetKeyboardState(NULL);
    return keys[keycode];
}
int utils::getMouseX() {
    int x, y;
    SDL_GetMouseState(&x, &y);
    return x;
}
int utils::getMouseY() {
    int x, y;
    SDL_GetMouseState(&x, &y);
    return y;
}
int utils::mouseCheck(int keycode) {
    Uint32 buttons = SDL_GetMouseState(NULL, NULL);
    return (buttons & keycode) != 0;
}