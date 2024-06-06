#pragma once

#include "UI/UIElement/ImageView.h"

#include <SFML/Graphics.hpp>

namespace Bullet
{
	class BulletController;
	enum class BulletType;

	class BulletView
	{
	private:
		const float bullet_sprite_height = 18.0f;
		const float bullet_sprite_width = 18.0f;

		UI::UIElement::ImageView* bullet_image;

		BulletController* bullet_controller;

		void createUIElements();
		void initializeImage();

		sf::String getBulletTexturePath();

		void destroy();

	public:
		BulletView();
		~BulletView();

		void initialize(BulletController* controller);
		void update();
		void render();
	};
}