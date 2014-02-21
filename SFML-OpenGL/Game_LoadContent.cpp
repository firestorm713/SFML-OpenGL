#include"Game.h"



void Game::LoadContent()
{
	// Load all files to be loaded from a text file
	// Load eacn individual file based on what the text file says it is.
	// For now, load the shader text files here, with hardcoded values for each part.
	LoadAndCompileShaders();
}

void Game::LoadAndCompileShaders()
{
	// In the future, this should return an GLuint ID for the shader program.
	// Also, in the future, this should be adding a shader program to a material component.
	// Essentially, the eventual purpose of this function will be to load all the shaders for all the mats.
	std::ifstream inf("vertexShader.vertex");
	std::string vertexShaderCode ( (std::istreambuf_iterator<char>(inf) ), (std::istreambuf_iterator<char>() ) );
	inf.close();
	inf.open("fragmentShader.frag");
	std::string fragmentShaderCode ( (std::istreambuf_iterator<char>(inf)), (std::istreambuf_iterator<char>() ) );
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	GLint Result = GL_FALSE;
	int InfoLogLength;

	std::ofstream log("log.txt");
	std::cout << " Compiling Vertex Shader" << std::endl;
	char const * VertexSourcePointer = vertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
	glCompileShader(VertexShaderID);

	// Check shader compilation
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if(InfoLogLength > 0)
	{
		std::vector<char> VertexShaderErrorMessage(InfoLogLength);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		std::cout << &VertexShaderErrorMessage[0] << std::endl;
		log << &VertexShaderErrorMessage[0] << std::endl;
	}

	std::cout << "Compiling Fragment Shader" << std::endl;
	char const * FragmentSourcePointer = fragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
	glCompileShader(FragmentShaderID);

	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if(InfoLogLength > 0)
	{
		std::vector<char> FragmentShaderErrorMessage(InfoLogLength);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		std::cout << &FragmentShaderErrorMessage[0] << std::endl;
		log << &FragmentShaderErrorMessage[0] << std::endl;
	}

	std::cout << "Linking Program" << std::endl;

	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);
	
	glGetProgramiv(ProgramID, GL_COMPILE_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	std::vector<char> ProgramErrorMessage(std::max(InfoLogLength, int(1)));
	std::cout << &ProgramErrorMessage[0] << std::endl;

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);
	glValidateProgram(ProgramID);

	ShaderProgramID = ProgramID;
}