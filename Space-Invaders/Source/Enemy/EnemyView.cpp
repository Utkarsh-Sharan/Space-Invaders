#include "Enemy/EnemyView.h"
#include "Enemy/EnemyController.h"
#include "Enemy/EnemyConfig.h"

#include "Global/ServiceLocator.h"
#include "Global/Config.h"

#include "Graphic/GraphicService.h"

namespace Enemy
{
	using namespace Global;
	using namespace Graphic;
	using namespace UI::UIElement;

	EnemyView::EnemyView()
	{
		createUIElements();
	}

	EnemyView::~EnemyView()
	{
		destroy();
	}

	void EnemyView::createUIElements()
	{
		enemy_image = new ImageView();
	}

	void EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;

		initializeImage();
	}

	void EnemyView::initializeImage()
	{
		enemy_image->initialize(getEnemyTexturePath(), enemy_sprite_width, enemy_sprite_height, enemy_controller->getEnemyPosition());
	}

	sf::String EnemyView::getEnemyTexturePath()
	{
		switch (enemy_controller->getEnemyType())
		{
		case EnemyType::SUBZERO:
			return Config::subzero_texture_path;

		case EnemyType::THUNDER_SNAKE:
			return Config::thunder_snake_texture_path;

		case EnemyType::UFO:
			return Config::ufo_texture_path;

		case EnemyType::ZAPPER:
			return Config::zapper_texture_path;
		}
	}

	void EnemyView::update()
	{
		enemy_image->setPosition(enemy_controller->getEnemyPosition());
	}

	void EnemyView::render()
	{
		enemy_image->render();
	}

	const sf::Sprite& EnemyView::getEnemySprite()
	{
		return enemy_image->getSprite();
	}

	void EnemyView::destroy()
	{
		delete(enemy_image);

		enemy_image = nullptr;
	}
}