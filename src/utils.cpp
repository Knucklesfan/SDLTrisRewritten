#include "utils.h"
#include "pixfont.h"
#include <SDL2/SDL.h>
#ifdef __SWITCH__
#define filepath "/"
#include <switch.h>

#else
#define filepath "./"
#endif
std::vector<texture *> graphics::textures = std::vector<texture *>();
std::vector<shader *> graphics::shaders = std::vector<shader *>();
std::vector<bg *> graphics::backgrounds = std::vector<bg *>();
std::vector<Font *> graphics::fonts = std::vector<Font *>();

std::map<std::string, actiontype> bgconverters::actionmap =
    {
        {"move", actiontype::MOVE},
        {"scale", actiontype::SCALE},
        {"rotate", actiontype::ROTATE}};
std::map<std::string, layertype> bgconverters::layermap = {
    {"background", layertype::BACKGROUND}, //
    {"legacy", layertype::LEGACY},
    {"bg3d", layertype::BG3D},
    {"bg2d", layertype::BG2D}};
;
std::map<std::string, headerdata> bgconverters::headermap =
    {
        {"title", headerdata::TITLE},
        {"version", headerdata::VERSION},
        {"music", headerdata::MUSIC},
        {"filename", headerdata::FILENAME},
        {"creator", headerdata::CREATOR}

};

std::string utils::loadFile(std::string filename)
{
    std::ifstream inFile;
    inFile.open(filename); // open the input file

    std::stringstream strStream;
    strStream << inFile.rdbuf(); // read the file
    return strStream.str();      // str holds the content of the file
}
float utils::mean(float arr[], int from, int to)
{
    float ret = 0.0;
    for (int i = from; i < to; i++)
    {
        ret += arr[i];
    }
    return ret / to - from;
}
int utils::unsign(int a)
{
    if (a < 0)
    {
        return 0;
    }
    return a;
}
int utils::keyboardCheck(int keycode)
{
    const Uint8 *keys = SDL_GetKeyboardState(NULL);
    return keys[keycode];
}
int utils::getMouseX()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    return x;
}
int utils::getMouseY()
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    return y;
}
int utils::mouseCheck(int keycode)
{
    Uint32 buttons = SDL_GetMouseState(NULL, NULL);
    return (buttons & keycode) != 0;
}

bool checkNode(rapidxml::xml_node<char> *node)
{
    if (node == nullptr)
    {
        std::cout << "Failed to parse node\n";
    }
    return node != nullptr;
}

int graphics::generatebgs()
{
    rapidxml::file<> bgFile((filepath "backgrounds/backgrounds.xml"));
    rapidxml::xml_document<> bgDoc;
    bgDoc.parse<0>(bgFile.data());
    rapidxml::xml_node<char> *parent = bgDoc.first_node("backgrounds");
    for (rapidxml::xml_node<char> *child = parent->first_node(); child != NULL; child = child->next_sibling())
    {

        std::cout << "loading background " << child->value() << "\n";
        // std::cout << "HELP ME:" << p.path().filename() << "\n";
        if (child->value() != "")
        {
            bg *backg = new bg(child->value(), false);
            backgrounds.push_back(backg);
        }
    }
    return 0;
}
int graphics::generatefonts()
{
    rapidxml::file<> bgFile((filepath "fonts/fonts.xml"));
    rapidxml::xml_document<> bgDoc;
    bgDoc.parse<0>(bgFile.data());
    rapidxml::xml_node<char> *parent = bgDoc.first_node("fonts");
    for (rapidxml::xml_node<char> *child = parent->first_node(); child != NULL; child = child->next_sibling())
    {

        std::cout << "loading font " << child->value() << "\n";
        // std::cout << "HELP ME:" << p.path().filename() << "\n";
        pixfont* f = new pixfont(child->first_node("path")->value());
        fonts.push_back(f);
    }
    return 0;
}