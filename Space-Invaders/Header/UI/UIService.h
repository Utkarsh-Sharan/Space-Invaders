#pragma once

#include "MainMenu/MainMenuUIController.h"
#include "UI/Interface/IUIController.h"

namespace UI
{
	class UIService
	{
	private:
		MainMenu::MainMenuUIController* main_menu_controller;

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