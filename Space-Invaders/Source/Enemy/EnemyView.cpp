#include "Enemy/EnemyView.h"
#include "Enemy/EnemyController.h"
#include "Enemy/EnemyConfig.h"
#include "Global/ServiceLocator.h"
#include "Graphic/GraphicService.h"

namespace Enemy
{
	using namespace Global;
	using namespace Graphic;

	EnemyView::EnemyView()
	{

	}

	EnemyView::~EnemyView()
	{

	}

	void EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		initializeEnemySprite(enemy_controller->getEnemyType());
	}

	void EnemyView::initializeEnemySprite(EnemyType type)
	{
		switch (type)
		{
		case EnemyType::SUBZERO:
			if (enemy_texture.loadFromFile(subzero_texture_path))
			{
				enemy_sprite.setTexture(enemy_texture);

				scaleEnemySprite();
			}
			break;

		case EnemyType::ZAPPER:
			if (enemy_texture.loadFromFile(zapper_texture_path))
			{
				enemy_sprite.setTexture(enemy_texture);

				scaleEnemySprite();
			}
			break;

		case EnemyType::THUNDER_SNAKE:
			if (enemy_texture.loadFromFile(thunder_snake_texture_path))
			{
				enemy_sprite.setTexture(enemy_texture);

				scaleEnemySprite();
			}
			break;
		}
	}

	void EnemyView::scaleEnemySprite()
	{
		enemy_sprite.setScale
		(
			static_cast<float> (enemy_sprite_width) / enemy_sprite.getTexture()->getSize().x,
			static_cast<float> (enemy_sprite_height) / enemy_sprite.getTexture()->getSize().y
		);
	}

	void EnemyView::update()
	{
		enemy_sprite.setPosition(enemy_controller->getEnemyPosition());
	}

	void EnemyView::render()
	{
		game_window->draw(enemy_sprite);
	}
}