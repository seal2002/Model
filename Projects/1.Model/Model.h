#pragma once
#include "assimp/Importer.hpp"
#include "assimp/postprocess.h"
#include <assimp/scene.h>
#include "common/Shader.h"
#include "Mesh.h"



class Model
{
public:
	/* Function */
	Model(char* path);
	void Draw(Shader shader);
	~Model();
private:
	/* Model Data */
	vector<Mesh> meshes;
	string directory;
	/* Fucntion */
	void loadModel(string path);
	void processNode(aiNode *node, const aiScene *scene);
	Mesh processMesh(aiMesh *mesh, const aiScene *scene);
	vector<Texture> loadMaterialTextures(aiMaterial *material, aiTextureType type, string typeName);
};

