#pragma once

#include "UI/UIElement/UIView.h"

namespace UI
{
	namespace UIElement
	{
		class ImageView : public UIView
		{
		protected:
			sf::Texture image_texture;
			sf::Sprite image_sprite;

		public:
			ImageView();
			virtual ~ImageView();

			virtual void initialize(sf::String texture_path, float image_width, float image_height, sf::Vector2f position);
			virtual void update() override;
			virtual void render() override;

			virtual void setTexture(sf::String texture_path);
			virtual void setTextureRect(sf::IntRect texture_rect); //show a specific frame from a sprite-sheet. In-built SFML method

			virtual void setScale(float width, float height);
			virtual void setScale(float width, float height, float tile_width, float tile_height); //set the dimensions for the whole sprite sheet and the dimensions of a specific frame as well.

			virtual void setPosition(sf::Vector2f position);
			virtual void setRoatation(float rotation_angle);

			virtual void setOriginAtCentre();
			virtual void setImageAlpha(float alpha);
			virtual void setCentreAlinged();

			const virtual sf::Sprite& getSprite();
		};
	}
}