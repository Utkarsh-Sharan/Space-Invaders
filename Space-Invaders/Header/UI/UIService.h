#pragma once

#include "MainMenu/MainMenuUIController.h"
#include "UI/Interface/IUIController.h"

namespace UI
{
	class UIService : public Interface::IUIController
	{
	private:
		MainMenu::MainMenuUIController* main_menu_controller;

		void createControllers();
		void initializeControllers();
		void destroy();

		IUIController* getCurrentUIController();

	public:
		UIService();
		~UIService();

		void initialize() override;
		void update() override;
		void render() override;

		void showScreen();
	};
}