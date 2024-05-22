#include "UI/MainMenu/MainMenuUIController.h"
#include "Global/ServiceLocator.h"
#include "Main/GameService.h"
#include "Graphic/GraphicService.h"
#include "Event/EventService.h"

namespace UI
{
	namespace MainMenu
	{
		using namespace Global;
		using namespace Main;
		using namespace Graphic;
		using namespace Event;

		MainMenuUIController::MainMenuUIController()
		{
			game_window = nullptr;
		}

		void MainMenuUIController::initialize()
		{
			game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		}

		void MainMenuUIController::update()
		{

		}

		void MainMenuUIController::render()
		{

		}
	}
}