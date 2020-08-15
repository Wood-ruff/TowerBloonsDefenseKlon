#include "Object.h";
#include "MathUtils.h";
#include "Globals.h";

Object::Object(double x, double y, double width, double height,float* vertex, unsigned int* indices, const char* vertexShader, const char* fragmentShader, const char* texturePath){
	this->shader = new Shader(vertexShader, fragmentShader);
	this->vertex = vertex;
    this->indices = indices;

    this->x = x;
    this->y = y;
    this->refitVertex();

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, 32 * sizeof(vertex), vertex, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);



	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);


    int width1, height1, nrChannels;
    unsigned char* data = stbi_load(texturePath, &width1, &height1, &nrChannels, 0);
    if (data) {
        // generate the texture
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        // free the image data
        stbi_image_free(data);
    }
    else {
        std::cout << "Failed to load the texture!"<< std::endl;
    }

    this->shader->use();
    glUniform1i(glGetUniformLocation(this->shader->ID, "texture1"), 0);
}

void Object::draw() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBindVertexArray(VAO);
    shader->use();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Object::update() {
    this->refitVertex();
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, 32 * sizeof(vertex), vertex, GL_DYNAMIC_DRAW);
}

void Object::refitVertex() {
    this->vertex[0] = MathUtils::getNormalizedCoord(this->x + this->width,SCR_WIDTH);
    this->vertex[1] = MathUtils::getNormalizedCoord(this->y + this->height, SCR_HEIGHT); 

    //std::cout << this->vertex[0];

    this->vertex[8] = MathUtils::getNormalizedCoord(this->x +this->width , SCR_WIDTH);
    this->vertex[9] = MathUtils::getNormalizedCoord(this->y, SCR_HEIGHT);

    this->vertex[16] = MathUtils::getNormalizedCoord(this->x, SCR_WIDTH);
    this->vertex[17] = MathUtils::getNormalizedCoord(this->y, SCR_HEIGHT);

    this->vertex[24] = MathUtils::getNormalizedCoord(this->x, SCR_WIDTH);
    this->vertex[25] = MathUtils::getNormalizedCoord(this->y + this->height, SCR_HEIGHT);
}

