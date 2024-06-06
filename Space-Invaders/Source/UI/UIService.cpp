#include "UI/UIService.h"
#include "Main/GameService.h"

namespace UI
{
	using namespace Main;
	using namespace MainMenu;
	using namespace Interface;

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

	void UIService::initializeControllers()
	{
		main_menu_controller->initialize();
	}

	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState())
		{
		case GameState::MAIN_MENU:
			return main_menu_controller;

		default:
			return nullptr;
		}

	}

	void UIService::update()
	{
		IUIController* ui_controller = getCurrentUIController();

		if (ui_controller)
			ui_controller->update();
	}

	void UIService::render()
	{
		IUIController* ui_controller = getCurrentUIController();

		if (ui_controller)
			ui_controller->render();
	}

	void UIService::showScreen()
	{
		IUIController* ui_controller = getCurrentUIController();

		if (ui_controller)
			ui_controller->show();
	}
	
	void UIService::destroy()
	{
		delete(main_menu_controller);
		main_menu_controller = nullptr;
	}
}