/*
 * Object.h, and the future of computing
 * By Knuckles F. Videos
 *
 * Object.h was originally written at exactly 1/1/23 at 12:01AM.
 * What was the purpose of Object.h? Why, to declare everything that would be needed for objects.
 * As the first lines of code written in the new year, Object.h was created as the future of all code going forward.
 * So, what standard did I set myself to acheieve this year with my future code?
 *
 * Tis but a simple answer... As Object.h is utter and disgusting garbage, I find it only fitting that Object.h kicks off the year
 * As you see, I write awful code.
 * Yes, indeed, you read that correctly. Awful code. Straight repugnant even! As a matter of fact, I couldn't see myself writing worse code if I tried!
 *
 * Here's to the new year, lets hope I find what I'm looking for...
 *
 *
 * (...that being good code of course.)
*/
#ifndef OBJECT_H
#define OBJECT_H
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "shader.h"

enum LIGHTTYPE {
    POINT,
    SPOTLIGHT,
    DIRECTIONAL
};

class TransformObject {
    public:
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;
        virtual void render(shader* shad, glm::mat4 projection, glm::mat4 view, int slot){
            shad->setVector("projection", glm::value_ptr(projection));
            shad->setVector("view", glm::value_ptr(view));
        };
        std::vector<TransformObject*> children;
        TransformObject* parent;
};
class Light : public TransformObject {
    public:
        Light(LIGHTTYPE type, glm::vec3 position, glm::vec3 ambient=glm::vec3(0.1f,0.1f,0.1f), glm::vec3 diffuse=glm::vec3(1.0f,1.0f,1.0f), glm::vec3 specular=glm::vec3(0,0,0), float constant=0, float linear=0, float quadratic=0);
        void update(shader*, int);
        void render(shader* shad, glm::mat4 projection, glm::mat4 view, int slot);
        LIGHTTYPE type;
        float constant;
        float linear;
        float quadratic;
        glm::vec3 ambient;
        glm::vec3 diffuse;
        glm::vec3 specular;

};

#endif // OBJECT_H
