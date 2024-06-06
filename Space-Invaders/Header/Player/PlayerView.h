#pragma once

#include "UI/UIElement/ImageView.h"

#include <SFML/Graphics.hpp>

namespace Player
{
	class PlayerController;

	class PlayerView
	{
	private:
		const float player_sprite_width = 60.f;
		const float player_sprite_height = 60.f;

		UI::UIElement::ImageView* player_image;

		PlayerController* player_controller;

		void createUIElements();
		void initializeImage();

		sf::String getPlayerTexturePath();

		void destroy();

	public:
		PlayerView();
		~PlayerView();

		void initialize(PlayerController* controller);
		void update();
		void render();
	};
}