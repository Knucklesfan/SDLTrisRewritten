#include <glm/glm.hpp>

enum interpolation {
    NEAREST,
    LINEAR,
    CUBIC,
    BICUBIC,
    CUSTOM
};
class keyframe {
    public:
        glm::vec3 position;
        interpolation type;
        keyframe* next;
};