#pragma once
#include <string>
#include <vector>
#include "glm\glm.hpp"
#include "common\Shader.h"

using namespace glm;
using namespace std;

struct Vertex
{
	vec3 Postition;
	vec3 Normal;
	vec2 Texcoords;
};

struct Texture
{
	unsigned int id;
	string type;
};

class Mesh
{
public:
	/* Mesh data*/
	vector<Vertex> vertices;
	vector<unsigned int> indices;
	vector<Texture> textures;
	/* Functions */
	Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
	void Draw(Shader shader);
	~Mesh();
private:
	/* Render data */
	unsigned int VAO, VBO, EBO;
	/* Functions */
	void setupMesh();
};

