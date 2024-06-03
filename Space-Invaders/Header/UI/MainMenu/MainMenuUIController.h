#pragma once

#include <SFML/Graphics.hpp>

namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController
		{
		private:
			const float button_width = 400.f;
			const float button_height = 140.f;

			sf::RenderWindow* game_window;

			sf::Texture background_texture;
			sf::Sprite background_sprite;

			sf::Texture play_button_texture;
			sf::Sprite play_button_sprite;

			sf::Texture instructions_button_texture;
			sf::Sprite instructions_button_sprite;

			sf::Texture quit_button_texture;
			sf::Sprite quit_button_sprite;

			void initializeBackgroundImage();
			void scaleBackgroundImage();

			void initializeButtons();
			bool loadButtonTexturesFromFile();	//we have 3 buttons so it's better to create a seperate function to check if they are loaded
			void setButtonSprites();

			void scaleAllButttons();
			void scaleButton(sf::Sprite* button_to_scale);
			void positionButtons();

		public:
			MainMenuUIController();

			void initialize();
			void update();
			void render();

			void processButtonInteractions();					//take action based on the specific button that was clicked
			bool clickedButton(sf::Sprite*, sf::Vector2f);		//checking which button was clicked
		};
	}
}