#define SFML_STATIC
#define GLEW_STATIC
#include<SFML\Window.hpp>
#include<GL\glew.h>
#include"Game.h"

int main(int argc,char* argv[])
{
	Game game1;
	game1.ExecuteGame();
}

/*	sf::Window window(sf::VideoMode(800,600),"OpenGL",sf::Style::Close);

	glewExperimental = GL_TRUE;
	glewInit();

	//GLuint vertexBuffer;
	//glGenBuffers(1, &vertexBuffer);

	sf::Vector3f vertices[] = {sf::Vector3f(0.0f, 0.0f, 0.0f), sf::Vector3f(0.5f, 0.4f, 0.0f), sf::Vector3f(0.5f, 7.0f, 0.0f), sf::Vector3f(-0.3f, 0.1f, 0.0f), sf::Vector3f(0.8f, 0.7f, 0.0f) };


	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	bool running = true;
	while(running)
	{
		sf::Event windowEvent;
		while (window.pollEvent(windowEvent))
		{
			switch(windowEvent.type)
			{
			case sf::Event::Closed:
				running = false;
				break;
			case sf::Event::KeyPressed:
				if(windowEvent.key.code == sf::Keyboard::Escape)
					running = false;
				break;
			}
		}
		
		glClear(GL_COLOR_BUFFER_BIT);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 0,0);

		glDrawArrays(GL_POINTS, 0,5);

		glDisableVertexAttribArray(0);

		window.display();

	}

	return 0;*/