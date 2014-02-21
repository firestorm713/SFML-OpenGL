#include "Game.h"

void Game::Draw()
{
	glUseProgram(ShaderProgramID);
	//std::cout << glGetAttribLocation(ShaderProgramID, "Position") << std::endl;
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	
	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 0,0);

	glDrawArrays(GL_TRIANGLES, 0,3);

	glDisableVertexAttribArray(0);

	window.display();
}