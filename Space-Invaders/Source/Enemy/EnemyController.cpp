#include "Enemy/EnemyController.h"
#include "Enemy/EnemyModel.h"
#include "Enemy/EnemyView.h"
#include "Enemy/EnemyConfig.h"

#include "Bullet/BulletConfig.h"
#include "Bullet/BulletController.h"

#include "Global/ServiceLocator.h"
#include "Player/PlayerController.h"
#include "Sound/SoundService.h"
#include "Entity/EntityConfig.h"

namespace Enemy
{
	using namespace Global;
	using namespace Collision;
	using namespace Entity;
	using namespace Player;
	using namespace Sound;
	using namespace Bullet;

	EnemyController::EnemyController(EnemyType type)
	{
		enemy_model = new EnemyModel(type);
		enemy_view = new EnemyView();
	}

	EnemyController::~EnemyController()
	{
		delete(enemy_model);
		delete(enemy_view);

		enemy_model = nullptr;
		enemy_view = nullptr;
	}

	void EnemyController::initialize()
	{
		enemy_model->initialize();
		enemy_model->setEnemyPosition(getRandomInitialPosition());

		enemy_view->initialize(this);
	}

	void EnemyController::update()
	{
		move();

		updateFireTime();
		processBulletFire();

		enemy_view->update();
		handleOutOfBounds();
	}

	void EnemyController::updateFireTime()
	{
		elapsed_fire_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void EnemyController::processBulletFire()
	{
		if (elapsed_fire_duration >= rate_of_fire)
		{
			fireBullet();
			elapsed_fire_duration = 0.f; //set elapsed duration back to 0.
		}
	}

	void EnemyController::render()
	{
		enemy_view->render();
	}

	sf::Vector2f EnemyController::getRandomInitialPosition()
	{
		// Calculate the distance between the leftmost and rightmost positions of the enemy.
		float x_offset_distance = (std::rand() % static_cast<int>(enemy_model->right_most_position.x - enemy_model->left_most_position.x));

		// Calculate the x position by adding the x offset distance to the leftmost position.
		float x_position = enemy_model->left_most_position.x + x_offset_distance;

		//y position remains same
		float y_position = enemy_model->left_most_position.y;

		//return calculated 2D position
		return sf::Vector2f(x_position, y_position);
	}

	void EnemyController::handleOutOfBounds()
	{
		sf::Vector2f enemy_position = getEnemyPosition();
		sf::Vector2u window_size = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		if (enemy_position.x < 0 || enemy_position.x > window_size.x || enemy_position.y < 0 || enemy_position.y > window_size.y)
		{
			ServiceLocator::getInstance()->getEnemyService()->destroyEnemy(this);
		}
	}

	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyPosition();
	}

	EnemyState EnemyController::getEnemyState()
	{
		return enemy_model->getEnemyState();
	}

	EnemyType EnemyController::getEnemyType()
	{
		return enemy_model->getEnemyType();
	}
	const sf::Sprite& EnemyController::getColliderSprite()
	{
		return enemy_view->getEnemySprite();
	}

	void EnemyController::onCollision(ICollider* other_collider)
	{
		BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);
		if (bullet_controller && bullet_controller->getOwnerEntityType() != EntityType::ENEMY)
		{
			destroy();
			return;
		}

		PlayerController* player_controller = dynamic_cast<PlayerController*>(other_collider);
		if (player_controller)
		{
			destroy();
			return;
		}
	}

	void EnemyController::destroy()
	{
		ServiceLocator::getInstance()->getAnimationService()->spawnAnimationSystem(enemy_model->getEnemyPosition(),
			Animation::AnimationType::EXPLOSION);

		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::EXPLOSION);

		ServiceLocator::getInstance()->getPlayerService()->increaseEnemiesKilled(1);
		ServiceLocator::getInstance()->getEnemyService()->destroyEnemy(this);
	}
}