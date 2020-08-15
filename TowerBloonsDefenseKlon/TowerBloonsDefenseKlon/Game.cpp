#include "Game.h"
#include "stb_image.h"
#include "Shader.h"

Game::Game() {
	float boardVertices[] = {
		// positions           	// textures 
		-1.0f, -1.0f,  0.0f,    1.0f, 1.0f,		// bottom left 
		-1.0f,  1.0f,  0.0f,	1.0f, 0.0f,		// top left
		 1.0f,  1.0f,  0.0f,	0.0f, 0.0f,		// top right
		 1.0f, -1.0f,  0.0f,	0.0f, 1.0f		// bottom right
	};

	unsigned int indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};

	const char *vertexShader = "./GameVertexShader.vs", *fragmentShader = "./GameFragmentShader.fs";
	shader = new Shader(vertexShader, fragmentShader);

	// generate the VAO, VBO and EBO
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(boardVertices), boardVertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position attribute
	// location, size, type, normalized, stride = byte offset between consecutive vertex attributes, offset
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// texture attribute
	// location, size(x,y,z), type, normalized, stride = byte offset between consecutive vertex attributes, offset = starting pos
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glGenTextures(1, &texture);

	// bind the texture
	glBindTexture(GL_TEXTURE_2D, texture);

	// set the texture warpping/filtering options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	// load the image properties into these variables
	int width, height, nrChannels;
	unsigned char* data = stbi_load("../res/grass.jpg", &width, &height, &nrChannels, 0);

	if (data) {
		// generate the texture
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		// free the image data
		stbi_image_free(data);
	}
	else {
		std::cout << "Failed to load the texture: awesomeface.png" << std::endl;
	}
}

void Game::draw() {
	
	glBindTexture(GL_TEXTURE_2D, texture);
	shader->use();

	glBindVertexArray(VAO);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}