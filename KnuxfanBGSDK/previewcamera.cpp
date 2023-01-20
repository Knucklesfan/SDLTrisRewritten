#include "previewcamera.h"
#include <iostream>
#include <QKeyEvent>
void previewCamera::move(QMap<int, bool> keys, double deltatime)
{
    float velocity = 2.5 * deltatime;
    if (keys[Qt::Key_W])
        position += front * velocity;
    if (keys[Qt::Key_S])
        position -= front * velocity;
    if (keys[Qt::Key_A])
        position -= right * velocity;
    if (keys[Qt::Key_D])
        position += right * velocity;
}
void previewCamera::rotate(float mousex, float mousey) {
    mousex *= sensitivity;
    mousey *= sensitivity;
    rotation.x += mousex;
    rotation.y -= mousey;
    this->updateView();
    if (rotation.y > 89.0f)
        rotation.y = 89.0f;
    if (rotation.y < -89.0f)
        rotation.y = -89.0f;
}
