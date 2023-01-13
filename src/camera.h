#ifndef CAMERA_H
#define CAMERA_H
#include "utils.h"

class camera {
public:
    camera(glm::vec3 location, glm::vec3 angles) {

    };
    glm::vec3 position;
    glm::vec3 rotation;
    glm::mat4 view() {

    };
};

#endif // CAMERA_H
