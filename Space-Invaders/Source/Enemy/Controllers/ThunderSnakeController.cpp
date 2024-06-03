#include "Enemy/Controllers/ThunderSnakeController.h"
#include "Enemy/EnemyModel.h"
#include "Enemy/EnemyConfig.h"

#include "Global/ServiceLocator.h"

#include <cmath>

namespace Enemy
{
	using namespace Global;

	namespace Controller
	{
		ThunderSnakeController::ThunderSnakeController(EnemyType type) : EnemyController(type)
		{

		}

		ThunderSnakeController::~ThunderSnakeController()
		{

		}

		void ThunderSnakeController::initialize()
		{
			EnemyController::initialize();
		}

		void ThunderSnakeController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case MovementDirection::LEFT:
				moveLeft();
				break;

			case MovementDirection::RIGHT:
				moveRight();
				break;
			}
		}

		void ThunderSnakeController::moveLeft()
		{
			sf::Vector2f current_position = enemy_model->getEnemyPosition();
			current_position.x += enemy_model->enemy_movement_speed * sin(80) * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			current_position.y -= enemy_model->enemy_movement_speed * cos(80) * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (current_position.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT);
				enemy_model->setReferencePosition(current_position);
			}
			else
			{
				enemy_model->setEnemyPosition(current_position);
			}
		}

		void ThunderSnakeController::moveRight()
		{
			sf::Vector2f current_position = enemy_model->getEnemyPosition();
			current_position.x -= enemy_model->enemy_movement_speed * sin(80) * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			current_position.y -= enemy_model->enemy_movement_speed * cos(80) * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (current_position.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT);
				enemy_model->setReferencePosition(current_position);
			}
			else
			{
				enemy_model->setEnemyPosition(current_position);
			}
		}
	}
}