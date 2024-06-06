#pragma once

#include "UI/UIElement/ImageView.h"

#include <SFML/Graphics.hpp>

namespace Element
{
	namespace Bunker
	{
		class BunkerController;

		class BunkerView
		{
		private:
			const float bunker_sprite_height = 80.0f;
			const float bunker_sprite_width = 80.0f;

			UI::UIElement::ImageView* bunker_image;
			BunkerController* bunker_controller;

			void createUIElements();
			void initializeImage();

			void destroy();

		public:
			BunkerView();
			~BunkerView();

			void initialize(BunkerController* controller);
			void update();
			void render();
		};
	}
}