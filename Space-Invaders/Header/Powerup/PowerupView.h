#pragma once

#include "UI/UIElement/ImageView.h"

#include <SFML/Graphics.hpp>

namespace Powerup
{
	class PowerupController;;

	enum class PowerupType;

	class PowerupView
	{
	private:
		const float powerup_sprite_height = 30.0f;
		const float powerup_sprite_width = 30.0f;

		UI::UIElement::ImageView* powerup_image;
		PowerupController* powerup_controller;

		void createUIElements();
		void initializeImage();

		sf::String getPowerupTexturePath();

		void destroy();

	public:
		PowerupView();
		~PowerupView();

		void initialize(PowerupController* controller);
		void update();
		void render();
	};
}