#pragma once

#include <SFML/Graphics.hpp>

namespace Element
{
	class BunkerController;

	namespace Bunker
	{
		class BunkerView
		{
		private:
			const sf::String bunker_texture_path = "assets/textures/bunker.png";

			const float bunker_sprite_height = 80.0f;
			const float bunker_sprite_width = 80.0f;

			sf::Texture bunker_texture;
			sf::Sprite bunker_sprite;

			sf::RenderWindow* game_window;
			Bunker::BunkerController* bunker_controller;

			void scaleSprite();
			void initializeImage();

		public:
			BunkerView();
			~BunkerView();

			void initialize(BunkerController* controller);
			void update();
			void render();
		};
	}
}