#define GLM_ENABLE_EXPERIMENTAL
#include "gameLayer.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "platformInput.h"
#include "imgui.h"
#include <iostream>
#include <sstream>
#include "imfilebrowser.h"
#include <gl2d/gl2d.h>
#include "../include/gameLayer/game.h"

struct GameData
{
	glm::vec2 rectPos = {100,100};

}gameData;

StateManager mStateManager;
gl2d::Renderer2D renderer;
gl2d::Texture tBoard;
std::vector<glm::vec4> xVects;
std::vector<glm::vec4> oVects;
gl2d::Texture tX;
gl2d::Texture tO;
gl2d::Font f;

bool initGame()
{
	//initializing stuff for the renderer
	gl2d::init();
	renderer.create();

	//loading the saved data. Loading an entire structure like this makes savind game data very easy.
	platform::readEntireFile(RESOURCES_PATH "gameData.data", &gameData, sizeof(GameData));

	tBoard.loadFromFile(RESOURCES_PATH "board.png", true);
	tX.loadFromFile(RESOURCES_PATH "x.png", true);
	tO.loadFromFile(RESOURCES_PATH "o.png", true);
	f.createFromFile(RESOURCES_PATH "roboto_black.ttf");

	return true;
}

bool gameLogic(float deltaTime)
{
#pragma region init stuff
	int w = 0; int h = 0;
	w = platform::getFrameBufferSizeX(); //window w
	h = platform::getFrameBufferSizeY(); //window h
	
	glViewport(0, 0, w, h);
	glClear(GL_COLOR_BUFFER_BIT); //clear screen

	renderer.updateWindowMetrics(w, h);
	if (xVects.empty() || oVects.empty())
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				//renderer.renderRectangle({w / 2 - 260 / 2 + (100 * i), 195 + (100 * j), 50, 50}, tO);
				xVects.push_back(glm::vec4(w / 2 - 260 / 2 + (100 * i), 195 + (100 * j), 50, 50));
				oVects.push_back(glm::vec4(w / 2 - 260 / 2 + (100 * i), 195 + (100 * j), 50, 50));
			}
		}
	}
#pragma endregion

	renderer.renderText({w/2, 100 }, "TicTacToe!", f, Colors_White);

	if (platform::isLMousePressed())
	{
		auto mosPos = platform::getRelMousePosition();
		std::cout << mosPos.x << " " << mosPos.y << std::endl;
	}
	
	//gameData.rectPos = glm::clamp(gameData.rectPos, glm::vec2{0,0}, glm::vec2{w - 100,h - 100});
	renderer.renderRectangle({w / 2 - 250/2, 200, 250, 250}, tBoard);
	
	for (auto& x : xVects)
		renderer.renderRectangle(x, tX);
	//for (auto& o : oVects)
	//	renderer.renderRectangle(o, tO);
	
	//std::cout << mStateManager.isRunning() << std::endl;
	//std::cout << mStateManager.getTurnManager()->getTurnCount() << std::endl;
	renderer.flush();

	//ImGui::ShowDemoWindow();

	return true;
#pragma endregion

}

//This function might not be be called if the program is forced closed
void closeGame()
{

	//saved the data.
	platform::writeEntireFile(RESOURCES_PATH "gameData.data", &gameData, sizeof(GameData));

}
