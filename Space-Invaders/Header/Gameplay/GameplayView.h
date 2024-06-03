#pragma once

#include <SFML/Graphics.hpp>

namespace Gameplay
{
	class GameplayView
	{
	private:
		sf::RenderWindow* game_window;

		sf::Texture background_texture;
		sf::Sprite background_sprite;

		void initializeBackgroundSprite();
		void scaleBackgroundSprite();

	public:
		GameplayView();
		~GameplayView();

		void initialize();
		void update();
		void render();
	};
}