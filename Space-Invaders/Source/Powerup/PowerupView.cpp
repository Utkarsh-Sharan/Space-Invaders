#include "Powerup/PowerupView.h"
#include "Powerup/PowerupController.h"
#include "Powerup/PowerupConfig.h"

#include "Global/Config.h"
#include "Global/ServiceLocator.h"

namespace Powerup
{
	using namespace Global;
	using namespace UI::UIElement;

	PowerupView::PowerupView()
	{
		createUIElements();
	}

	PowerupView::~PowerupView()
	{
		destroy();
	}

	void PowerupView::createUIElements()
	{
		powerup_image = new ImageView();
	}

	void PowerupView::initialize(PowerupController* controller)
	{
		powerup_controller = controller;

		initializeImage();
	}

	void PowerupView::initializeImage()
	{
		powerup_image->initialize(getPowerupTexturePath(), powerup_sprite_width, powerup_sprite_height, powerup_controller->getCollectiblePosition());
	}

	void PowerupView::update()
	{
		powerup_image->setPosition(powerup_controller->getCollectiblePosition());
	}

	void PowerupView::render()
	{
		powerup_image->render();
	}

	sf::String PowerupView::getPowerupTexturePath()
	{
		switch (powerup_controller->getPowerupType())
		{
		case PowerupType::SHIELD:
			return Config::shield_texture_path;

		case PowerupType::TRIPLE_LASER:
			return Config::triple_laser_texture_path;

		case PowerupType::RAPID_FIRE:
			return Config::rapid_fire_texture_path;

		case PowerupType::OUTSCAL_BOMB:
			return Config::outscal_bomb_texture_path;
		}
	}

	void PowerupView::destroy()
	{
		delete(powerup_image);

		powerup_image = nullptr;
	}

	const sf::Sprite& PowerupView::getPowerupSprite()
	{
		return powerup_image->getSprite();
	}
}