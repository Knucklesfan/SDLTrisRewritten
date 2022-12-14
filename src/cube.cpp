#include "cube.h"

cube::cube(glm::vec3 prepos, glm::vec3 postpos, glm::vec3 scale, glm::vec3 rotation) {

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(2);
    this->rotation = rotation;
    this->position = prepos;
	this->postposition = postpos;
    this->scale = scale;

}

void cube::render(shader* shad, texture* t, glm::mat4 projection, glm::mat4 view) {
		
		t->activate(0);

		shad->activate();
		shad->setInt("texture1",0);
        transform = glm::mat4(1.0f); //the actual transform of the model itself
		transform = glm::translate(transform,position);
        transform = glm::rotate(transform, glm::radians(rotation[0]), glm::vec3(1.0f, 0.0f, 0.0f));  
        transform = glm::rotate(transform, glm::radians(rotation[1]), glm::vec3(0.0f, 1.0f, 0.0f));  
        transform = glm::rotate(transform, glm::radians(rotation[2]), glm::vec3(0.0f, 0.0f, 1.0f));  
        transform = glm::scale(transform, scale);
		transform = glm::translate(transform,postposition);

		shad->setVector("model", glm::value_ptr(transform));
		shad->setVector("projection", glm::value_ptr(projection));
		shad->setVector("view", glm::value_ptr(view));
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);

}