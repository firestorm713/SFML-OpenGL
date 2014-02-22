#include"Game.h"

void Game::Update()
{
	static float Scale = 0.0f;
	Scale += 0.001f;
	glUniform1f(ScaleUniform, sinf(Scale));
}