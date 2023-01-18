#ifndef PREVIEWCAMERA_H
#define PREVIEWCAMERA_H

#include "../src/object.h"

#include <QMap>
class previewCamera: public Camera
{
public:
    previewCamera(glm::vec3 position, glm::vec3 rotation, int fov, texture* rendertexture, int w, int h, float near, float far,float sensitivity): Camera(position,rotation,fov,rendertexture,w,h,near,far) {
        //this is where i'd put my debug camera constructor...


        //IF I HAD ONE!
        this->sensitivity = sensitivity;
        //this joke didnt last long
    };
    float sensitivity;
    void move(QMap<int, bool> keys,double deltatime);
    void rotate(float mousex, float mousey);
};

#endif // PREVIEWCAMERA_H
