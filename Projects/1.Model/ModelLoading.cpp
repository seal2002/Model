#include <MainWindow.hpp>
#include <glm\glm.hpp>
#include <glm\common.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "common\Shader.h"
#include "common\Camera.h"
#include "Model.h"

using namespace OpenGLWindow;

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

int main()
{
	Window window{800, 600, "Hello Window!"};

	// build and compile shaders
	// -------------------------
	Shader ourShader("..\\Resource\\1.model_loading.vs", "..\\Resource\\1.model_loading.fs");
	// load models
	// -----------
	Model ourModel("..\\Resource\\Ozelot\\Ozelot.obj");

	while (!window.shouldClose())
	{
		window.processInput();
		window.pollEvents();
		// render
		// ------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// don't forget to enable shader before setting uniforms
		ourShader.Use();

		// view/projection transformations
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
		glm::mat4 view = camera.GetViewMatrix();
		ourShader.setMat4("projection", projection);
		ourShader.setMat4("view", view);

		// render the loaded model
		glm::mat4 model;
		model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // translate it down so it's at the center of the scene
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// it's a bit too big for our scene, so scale it down
		ourShader.setMat4("model", model);
		ourModel.Draw(ourShader);

		window.swapBuffers();
	}

	return 0;
}