#include "object.h"
#include "shader.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//for directional lights, position is used as the direction in this case.
Light::Light(LIGHTTYPE type, glm::vec3 position, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float constant, float linear, float quadratic)  {
    this->type=type;
    this->position=position;
    this->ambient=ambient;
    this->diffuse=diffuse;
    this->specular=specular;
    this->constant = constant;
    this->linear=linear;
    this->quadratic=quadratic;
}
//Note about lighting in engine:
//You can only have one directional light (duh)
//Any more than just one directional light will result in the replacement of the first, following the element tree.
//So, if you don't know who your directional light is, your best course is to tread lightly.

void Light::render(shader* shad, glm::mat4 projection, glm::mat4 view, int slot) {
    shad->activate();
    switch(type) {
        case LIGHTTYPE::DIRECTIONAL: {
            shad->setVec3("dirLight.direction",glm::value_ptr(position));
            shad->setVec3("dirLight.ambient",glm::value_ptr(ambient));
            shad->setVec3("dirLight.diffuse",glm::value_ptr(diffuse));
            shad->setVec3("dirLight.specular",glm::value_ptr(specular));
            break;
        }
        case LIGHTTYPE::POINT: {
            shad->setVec3("pointLights["+std::to_string(slot)+"].position",glm::value_ptr(position));
            shad->setVec3("pointLights["+std::to_string(slot)+"].ambient",glm::value_ptr(ambient));
            shad->setVec3("pointLights["+std::to_string(slot)+"].diffuse",glm::value_ptr(diffuse));
            shad->setVec3("pointLights["+std::to_string(slot)+"].specular",glm::value_ptr(specular));

            shad->setFloat("pointLights["+std::to_string(slot)+"].constant",(constant));
            shad->setFloat("pointLights["+std::to_string(slot)+"].linear",(linear));
            shad->setFloat("pointLights["+std::to_string(slot)+"].quadratic",(quadratic));

            break;
        }
    }
}
