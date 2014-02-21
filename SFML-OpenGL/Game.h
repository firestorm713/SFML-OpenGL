#ifndef _GAME_H
#define _GAME_H

#define SFML_STATIC
#define GLEW_STATIC
#include<SFML\Window.hpp>
#include<GL\glew.h>
#include<iostream>
#include<fstream>

class Game
{
public:
	sf::Window window;
	bool running;
	sf::Event windowEvent;
	GLuint VBO;
	GLuint ShaderProgramID;

private:
	void LoadAndCompileShaders();
public:
	void InitGame();
	void LoadContent();
	int ExecuteGame();
	void Update();
	void Draw();
	void OnEvent();
};

#endif