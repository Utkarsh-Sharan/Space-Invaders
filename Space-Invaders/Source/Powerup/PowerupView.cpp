#include "Powerup/PowerupView.h"
#include "Powerup/PowerupController.h"
#include "Powerup/PowerupConfig.h"

#include "Global/Config.h"
#include "Global/ServiceLocator.h"

namespace Powerup
{
	using namespace Global;

	void PowerupView::initialize(PowerupController* controller)
	{
		powerup_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		initializeImage(powerup_controller->getPowerupType());
	}

	void PowerupView::initializeImage(PowerupType type)
	{
		switch (type)
		{
		case PowerupType::TRIPLE_LASER:
			if (powerup_texture.loadFromFile(Config::triple_laser_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				scaleImage();
			}
			break;
		case PowerupType::SHIELD:
			if (powerup_texture.loadFromFile(Config::shield_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				scaleImage();
			}
			break;
		case PowerupType::RAPID_FIRE:
			if (powerup_texture.loadFromFile(Config::rapid_fire_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				scaleImage();
			}
			break;
		case PowerupType::OUTSCAL_BOMB:
			if (powerup_texture.loadFromFile(Config::outscal_bomb_texture_path))
			{
				powerup_sprite.setTexture(powerup_texture);
				scaleImage();
			}
			break;
		}
	}

	void PowerupView::scaleImage()
	{
		powerup_sprite.setScale
		(
			static_cast<float> (powerup_sprite_width) / powerup_sprite.getTexture()->getSize().x,
			static_cast<float>(powerup_sprite_height) / powerup_sprite.getTexture()->getSize().y
		);
	}

	void PowerupView::update()
	{
		powerup_sprite.setPosition(powerup_controller->getCollectiblePosition());
	}

	void PowerupView::render()
	{
		game_window->draw(powerup_sprite);
	}
}