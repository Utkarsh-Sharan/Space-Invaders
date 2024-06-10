#include "UI/UIService.h"
#include "UI/UIElement/TextView.h"
#include "Main/GameService.h"

namespace UI
{
	using namespace Main;
	using namespace MainMenu;
	using namespace GameplayUI;
	using namespace Interface;
	using namespace UIElement;
	using namespace SplashScreen;

	UIService::UIService()
	{
		main_menu_controller = nullptr;
		gameplay_ui_controller = nullptr;
		splash_screen_ui_controller = nullptr;

		createControllers();
	}

	UIService::~UIService()
	{
		destroy();
	}

	void UIService::createControllers()
	{
		main_menu_controller = new MainMenuUIController();
		gameplay_ui_controller = new GameplayUIController();
		splash_screen_ui_controller = new SplashScreenUIController();
	}

	void UIService::initialize()
	{
		TextView::initializeTextView();
		initializeControllers();
	}

	void UIService::initializeControllers()
	{
		main_menu_controller->initialize();
		gameplay_ui_controller->initialize();
		splash_screen_ui_controller->initialize();
	}

	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState())
		{
		case GameState::BOOT:
			return splash_screen_ui_controller;

		case GameState::MAIN_MENU:
			return main_menu_controller;

		case GameState::GAMEPLAY:
			return gameplay_ui_controller;

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
		delete(gameplay_ui_controller);
		delete(splash_screen_ui_controller);

		main_menu_controller = nullptr;
		gameplay_ui_controller = nullptr;
		splash_screen_ui_controller = nullptr;
	}
}