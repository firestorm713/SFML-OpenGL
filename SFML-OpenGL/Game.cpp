#include"Game.h"

void Game::InitGame()
{
	window.create(sf::VideoMode(800, 600), "OpenGL", sf::Style::Close);
	running = true;

	glewExperimental = GL_TRUE;
	glewInit();

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	sf::Vector3f vertices[] = {sf::Vector3f(-1.0f, -1.0f, 0.0f),
							   sf::Vector3f(1.0f, -1.0f, 0.0f),
							   sf::Vector3f(0.0f, 1.0f, 0.0f)};

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

int Game::ExecuteGame()
{
	InitGame();
	LoadContent();
	glUseProgram(ShaderProgramID);	// Use this when switching from one shader to another. 
	while(running)
	{
		OnEvent();
		Update();
		Draw();
	}
	return 0;
}