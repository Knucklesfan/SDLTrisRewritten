 
#include "mesh.h"
#ifdef CLIENT
#include "utils.h"
#else
#include "editorutils.h"
#endif
mesh::mesh(std::vector<vertex> vertices, std::vector<int> indices, std::vector<texture*> textures, Material mat) {
    this->vertices = vertices;
    this->indices = indices;
    this->textures = textures;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
                 &indices[0], GL_STATIC_DRAW);

    // vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)0);
    // vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, normal));
    // vertex texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, texcoord));

    glBindVertexArray(0);
    std::cout <<"SIZE MATTERS: " << vertices.size() <<"\n";

}
void mesh::render(shader* shad) {
//    unsigned int diffuseNr = 1;
//    unsigned int specularNr = 1;
//    for(unsigned int i = 0; i < textures.size(); i++) {
//        textures[i]->activate(i);
//        // retrieve texture number (the N in diffuse_textureN)
//        std::string number;
//        std::string name = textures[i]->type;
//        if(name == "texture_diffuse")
//            number = std::to_string(diffuseNr++);
//        else if(name == "texture_specular")
//            number = std::to_string(specularNr++);

//        shad->setInt(("material." + name + number), i);
//    }
//    glActiveTexture(GL_TEXTURE0);

//    // draw mesh
//    glBindVertexArray(VAO);
//    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
//    glBindVertexArray(0);
    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    unsigned int diffuseNr = 1;
    unsigned int specularNr = 1;
    unsigned int emmisiveNr = 1; //i have no idea if i spelled this right or not, but its 1:45am and im tired
    //(please dont use timestamps to verify this information i promise its late please believe me im not a coward)

    for(unsigned int i = 0; i < textures.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + i); // activate proper texture unit before binding
        // retrieve texture number (the N in diffuse_textureN)
        std::string number;
        std::string name = textures[i]->type;
        if(name == "texture_diffuse")
            number = std::to_string(diffuseNr++);
        else if(name == "texture_specular")
            number = std::to_string(specularNr++);
        else if(name == "texture_emission")
            number = std::to_string(emmisiveNr++);

        shad->setInt(("material." + name).c_str(), i);
        glBindTexture(GL_TEXTURE_2D, textures[i]->id);
    }

    shad->setFloat("material.shininess", 1.0f);

    shad->setVec3("material.diffuseColor", glm::value_ptr(mat.diffuseColor));
    shad->setVec3("material.emissionColor", glm::value_ptr(mat.emissionColor));

    glActiveTexture(GL_TEXTURE0);
    //std::cout << indices.size() << "\n";
    // draw mesh
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    //glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
}

//#ifdef CLIENT //start that silly GOOFY Q    U   I   R   K   Y client stuff
//TODO: implement client model import handling of KMF file format importer
//#else
model::model(std::string path,glm::vec3 prepos, glm::vec3 scale, glm::vec3 rotation) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path,aiProcess_Triangulate|aiProcess_OptimizeMeshes);
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << "\n";
        return;
    }
    dir = path.substr(0,path.find_last_of('/'));

    handlenode(scene->mRootNode, scene);
    this->rotation = rotation;
    this->position = prepos;
    this->scale = scale;

}
void model::handlenode(aiNode* node, const aiScene* scene) {
    for(uint i = 0; i < node->mNumMeshes; i++) {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(handlemesh(mesh,scene));
    }
    for(uint i = 0; i < node->mNumChildren; i++) {
        handlenode(node->mChildren[i],scene);
    }
}
void model::render(shader* shad,  glm::mat4 projection, glm::mat4 view) {
    shad->activate();
    shad->setVector("projection", glm::value_ptr(projection));
    shad->setVector("view", glm::value_ptr(view));

    glm::mat4 transform = glm::mat4(1.0f); //the actual transform of the model itself
    transform = glm::translate(transform,position);
    transform = glm::rotate(transform, glm::radians(rotation[0]), glm::vec3(1.0f, 0.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(rotation[1]), glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(rotation[2]), glm::vec3(0.0f, 0.0f, 1.0f));
    transform = glm::scale(transform, scale);

    glm::mat3 normal = glm::mat3(1.0f);
    normal = glm::transpose(glm::inverse(transform)); //calculate normals

    shad->setVector("model", glm::value_ptr(transform));
    shad->setMat3("worldspace", glm::value_ptr(normal));

    for(int i = 0; i < meshes.size(); i++) {
        meshes[i].render(shad);
    }
}

mesh model::handlemesh(aiMesh* aimesh, const aiScene* scene) {
    std::vector<vertex> vertices; //smells like mesh.h
    std::vector<int> indices;
    std::vector<texture*> textures;
    Material mat;
    for(uint i = 0; i < aimesh->mNumVertices; i++) {
        vertex v;
        v.pos.x = aimesh->mVertices[i].x;
        v.pos.y = aimesh->mVertices[i].y;
        v.pos.z = aimesh->mVertices[i].z;
        v.normal.x = aimesh->mNormals[i].x;
        v.normal.y = aimesh->mNormals[i].y;
        v.normal.z = aimesh->mNormals[i].z;
        if(aimesh->mTextureCoords[0]) {
            v.texcoord.x = aimesh->mTextureCoords[0][i].x;
            v.texcoord.y = aimesh->mTextureCoords[0][i].y;
        }
        vertices.push_back(v);
    }
    for(uint i = 0; i < aimesh->mNumFaces; i++) {
        aiFace face = aimesh->mFaces[i];
        for(unsigned int j = 0; j < face.mNumIndices; j++) {
            indices.push_back(face.mIndices[j]);
        }
    }

    if(aimesh->mMaterialIndex >= 0) {
        aiMaterial* material = scene->mMaterials[aimesh->mMaterialIndex];
        std::vector<texture*> diffuseMaps = loadtexture(material,
                                            aiTextureType_DIFFUSE, "texture_diffuse");
        textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

        std::vector<texture*> specularMaps = loadtexture(material,
                                            aiTextureType_SPECULAR, "texture_specular");        
        textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());

        std::vector<texture*> emissionMaps = loadtexture(material,
                                            aiTextureType_SPECULAR, "texture_specular");
        textures.insert(textures.end(), emissionMaps.begin(), emissionMaps.end());

        aiColor3D clr (0.f,0.f,0.f);
        material->Get(AI_MATKEY_COLOR_DIFFUSE,clr);
        mat.diffuseColor = glm::vec3(clr.r,clr.g,clr.b);
        material->Get(AI_MATKEY_COLOR_EMISSIVE,clr);
        mat.emissionColor = glm::vec3(clr.r,clr.g,clr.b);
        material->Get(AI_MATKEY_SHININESS,mat.shininess);


    }

    return mesh(vertices,indices,textures, mat);
}
std::vector<texture*> model::loadtexture(aiMaterial *mat, aiTextureType type, std::string typeName)
{
    std::vector<texture*> textures;
    for(unsigned int i = 0; i < mat->GetTextureCount(type); i++)
    {
        aiString str;
        mat->GetTexture(type, i, &str);
        bool skip = false;
        for(unsigned int j = 0; j < graphics::textures.size(); j++)
        {
            if(std::strcmp(graphics::textures[j]->path.c_str(), std::string(dir+"/"+str.C_Str()).c_str()) == 0)
            {
                std::cout << "pass " << graphics::textures[j]->path.c_str() << "\n";
                textures.push_back(graphics::textures[j]);
                skip = true;
                break;
            }
        }
        if(!skip)
        {   // if texture hasn't been loaded already, load it
            texture* tex = new texture(std::string(dir+"/"+str.C_Str()));
            tex->type = typeName;
            textures.push_back(tex);
            graphics::textures.push_back(tex); // add to loaded textures
        }
    }
    return textures;
}
//#endif
