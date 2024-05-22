#include "UI/UIService.h"
#include "Main/GameService.h"

namespace UI
{
	using namespace Main;
	using namespace MainMenu;

	UIService::UIService()
	{
		main_menu_controller = nullptr;
		createControllers();
	}

	UIService::~UIService()
	{
		destroy();
	}

	void UIService::createControllers()
	{
		main_menu_controller = new MainMenuUIController();
	}

	void UIService::initialize()
	{
		initializeControllers();
	}

	void UIService::update()
	{
		switch (GameService::getGameState())
		{
		case GameState::MAIN_MENU:
			return main_menu_controller->update();
			break;
		}
	}

	void UIService::render()
	{
		switch (GameService::getGameState())
		{
		case GameState::MAIN_MENU:
			return main_menu_controller->render();
			break;
		}
	}

	void UIService::initializeControllers()
	{
		main_menu_controller->initialize();
	}

	void UIService::destroy()
	{
		delete(main_menu_controller);
		main_menu_controller = nullptr;
	}
}