//transform objects basically

class Camera: public TransformObject  {

public:

    Camera(glm::vec3 position, glm::vec3 rotation, int fov, texture* rendertexture, int w, int h, float near, float far) {
        this->position = position;
        this->rotation = rotation;
        this->fov = fov;
        this->render = rendertexture;
        width = w;
        height = h;
        projection = glm::perspective(glm::radians((float)fov), (float)w / (float)h, near, far);
    };
    glm::mat4 projection;
    glm::mat4 view() { //gets the view for usage
        return glm::lookAt(position, position+front, up);
    };
    int width, height, fov; //all used for projection calculations

    //the following is shamelessly stolen from learnopengl.com, and i will be rewriting this (yknow, if i need to.)

protected:
    //updates the vectors in case of movement.
    void updateView() {
        glm::vec3 tempfront;
        tempfront.x = cos(glm::radians(rotation.x)) * cos(glm::radians(rotation.y));
        tempfront.y = sin(glm::radians(rotation.y));
        tempfront.z = sin(glm::radians(rotation.x)) * cos(glm::radians(rotation.y));
        front = glm::normalize(tempfront);
        // also re-calculate the Right and Up vector
        right = glm::normalize(glm::cross(front, up));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
        up    = glm::normalize(glm::cross(right, front));
        std::cout << rotation.x << " " << rotation.y << "\n";

    };
    texture* render; //if nullptr, then it just doesnt render to a texture lmao

private:

    glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 up    = glm::vec3(0.0f, 1.0f,  0.0f);
    glm::vec3 right    = glm::vec3(0.0f, 1.0f,  0.0f);

};

//this is the camera used for the GUI preview in the editor
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

//pretend this was in previewcamera.cpp, im only making this file an an example
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

