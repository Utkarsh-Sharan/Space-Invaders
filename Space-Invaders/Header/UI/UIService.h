#pragma once

#include "UI/MainMenu/MainMenuUIController.h"
#include "UI/GameplayUI/GameplayUIController.h"
#include "UI/SplashScreen/SplashScreenUIController.h"

#include "UI/Interface/IUIController.h"

namespace UI
{
	class UIService
	{
	private:
		MainMenu::MainMenuUIController* main_menu_controller;
		GameplayUI::GameplayUIController* gameplay_ui_controller;
		SplashScreen::SplashScreenUIController* splash_screen_ui_controller;

		void createControllers();
		void initializeControllers();
		void destroy();

		Interface::IUIController* getCurrentUIController();

	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();

		void showScreen();
	};
}