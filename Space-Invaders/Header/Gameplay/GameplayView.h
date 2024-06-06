#pragma once

#include "UI/UIElement/ImageView.h"

#include <SFML/Graphics.hpp>

namespace Gameplay
{
	class GameplayView
	{
	private:
		UI::UIElement::ImageView* background_image;

		void createUIElements();
		void initializeImage();
		void destroy();

	public:
		GameplayView();
		~GameplayView();

		void initialize();
		void update();
		void render();
	};
}