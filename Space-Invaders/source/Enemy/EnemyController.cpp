#include "../../header/Enemy/EnemyController.h"
#include "../../header/Enemy/EnemyView.h"
#include "../../header/Enemy/EnemyModel.h"
#include "../../header/Enemy/EnemyConfig.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Bullet/BulletConfig.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Bullet;

	EnemyController::EnemyController(EnemyType type)
	{
		enemy_view = new EnemyView();
		enemy_model = new EnemyModel(type);
	}

	EnemyController::~EnemyController()
	{
		delete (enemy_view);
		delete (enemy_model);
	}

	void EnemyController::initialize()
	{
		enemy_model->initialize();
		enemy_model->setEnemyPosition(getRandomInitialPosition());
		enemy_view->initialize(this);
	}

	void EnemyController::update()
	{
		updateEnemyPosition();
		updateFireTimer();
		processBulletFire();
		enemy_view->update();
	}

	void EnemyController::render()
	{
		enemy_view->render();
	}

	void EnemyController::updateFireTimer()
	{
		elapsed_fire_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void EnemyController::processBulletFire()
	{
		if (elapsed_fire_duration >= cooldown_fire_duration)
		{
			fireBullet();
			elapsed_fire_duration = 0.f;
		}
	}

	void EnemyController::updateEnemyPosition()
	{
		switch (enemy_model->getMovementDirection())
		{
		case::Enemy::MovementDirection::LEFT:
			moveLeft();
			break;

		case::Enemy::MovementDirection::RIGHT:
			moveRight();
			break;

		case::Enemy::MovementDirection::DOWN:
			moveDown();
			break;

		case::Enemy::MovementDirection::LEFT_DOWN:
			moveDiagonalLeft();
			break;

		case::Enemy::MovementDirection::RIGHT_DOWN:
			moveDiagonalRight();
			break;
		}
	}

	sf::Vector2f EnemyController::getRandomInitialPosition()
	{
		float x_position = left_most_position.x + (std::rand() % static_cast<int>(right_most_position.x - left_most_position.x));
		float y_position = left_most_position.y;

		return sf::Vector2f(x_position, y_position);
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
}