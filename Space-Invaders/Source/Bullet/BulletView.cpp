#include "Bullet/BulletView.h"
#include "Bullet/BulletController.h"
#include "Bullet/BulletConfig.h"

#include "Global/ServiceLocator.h"
#include "Global/Config.h"

namespace Bullet
{
	using namespace Global;
	using namespace UI::UIElement;

	BulletView::BulletView()
	{
		createUIElements();
	}

	BulletView::~BulletView()
	{
		destroy();
	}

	void BulletView::createUIElements()
	{
		bullet_image = new ImageView();
	}

	void BulletView::initialize(BulletController* controller)
	{
		bullet_controller = controller;

		initializeImage();
	}

	void BulletView::initializeImage()
	{
		bullet_image->initialize(getBulletTexturePath(), bullet_sprite_width, bullet_sprite_height, bullet_controller->getProjectilePosition());
	}

	void BulletView::update()
	{
		bullet_image->setPosition(bullet_controller->getProjectilePosition());
	}

	void BulletView::render()
	{
		bullet_image->render();
	}

	const sf::Sprite& BulletView::getBulletSprite()
	{
		bullet_image->getSprite();
	}

	sf::String BulletView::getBulletTexturePath()
	{
		switch (bullet_controller->getBulletType())
		{
		case BulletType::LASER_BULLET:
			return Config::laser_bullet_texture_path;

		case BulletType::FROST_BULLET:
			return Config::frost_beam_texture_path;

		case BulletType::TORPEDO:
			return Config::torpedoe_texture_path;
		}
	}

	void BulletView::destroy()
	{
		delete(bullet_image);

		bullet_image = nullptr;
	}
}