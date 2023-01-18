#include "previewcamera.h"
#include <iostream>

void previewCamera::move(QMap<int, bool> keys, double deltatime)
{

}
void previewCamera::rotate(float mousex, float mousey) {
    mousex *= sensitivity;
    mousey *= sensitivity;
    std::cout << "START BLOCK\n" << mousex << " " << mousey << "\n";
    rotation.x -= mousex;
    rotation.y += mousey;
    std::cout << rotation.x << " " << rotation.y << "\n";
    std::cout << "END BLOCK\n";
    this->updateView();
    if (rotation.y > 89.0f)
        rotation.y = 89.0f;
    if (rotation.y < -89.0f)
        rotation.y = -89.0f;
}
