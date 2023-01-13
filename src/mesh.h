#include "utils.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

struct vertex {
    glm::vec3 pos;
    glm::vec3 normal;
    glm::vec2 texcoord;
};
struct Material {
    float shininess;
    glm::vec3 diffuseColor;
    glm::vec3 emissionColor;
};
class mesh {
    public:
        // mesh data
        std::vector<vertex> vertices;
        std::vector<int> indices;
        std::vector<texture*> textures;
        Material mat;
        mesh(std::vector<vertex> vertices, std::vector<int> indices, std::vector<texture*> textures, Material mat);
        void render(shader* shad);
    private:
        //  render data
        unsigned int VAO, VBO, EBO;

        void setupMesh();
};

class model : public TransformObject  {
    public:
        glm::vec3 position;
        glm::vec3 scale;
        glm::vec3 rotation;
        model(std::string path,glm::vec3 prepos, glm::vec3 scale, glm::vec3 rotation);
        void render(shader* shad, glm::mat4 projection, glm::mat4 view);
    private:
        // model data
        std::vector<mesh> meshes;
        std::string dir;

        void loadModel(std::string path);
        void handlenode(aiNode*, const aiScene*);
        mesh handlemesh(aiMesh*, const aiScene*);
        std::vector<texture*> loadtexture(aiMaterial*, aiTextureType,
                                             std::string);
};
