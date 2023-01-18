#ifndef EDITORUTILS_H
#define EDITORUTILS_H

#include <vector>
#include "../src/texture.h"
#include "../src/shader.h"

class editorutils
{
public:
    static std::vector<texture*> textures;
    static std::vector<shader*> shaders;

};

#endif // EDITORUTILS_H
