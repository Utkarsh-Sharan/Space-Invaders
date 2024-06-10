#include "Enemy/Controllers/ZapperController.h"
#include "Enemy/EnemyModel.h"
#include "Enemy/EnemyConfig.h"

#include "Bullet/BulletConfig.h"

#include "Global/ServiceLocator.h"

namespace Enemy
{
	namespace Controller
	{
		using namespace Global;
		using namespace Bullet;

		ZapperController::ZapperController(EnemyType type): EnemyController(type)
		{
			
		}

		ZapperController::~ZapperController()
		{

		}

		void ZapperController::initialize()
		{
			EnemyController::initialize();

			rate_of_fire = zapper_rate_of_fire;
		}

		void ZapperController::fireBullet()
		{
			ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::LASER_BULLET, enemy_model->getEntityType(),
				enemy_model->getEnemyPosition() + enemy_model->barrel_position_offset, Bullet::MovementDirection::DOWN);

		}

		void ZapperController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case MovementDirection::LEFT:
				moveLeft();
				break;

			case MovementDirection::RIGHT:
				moveRight();
				break;

			case MovementDirection::DOWN:
				moveDown();
				break;
			}
		}

		void ZapperController::moveLeft()
		{
			sf::Vector2f current_position = enemy_model->getEnemyPosition();

			current_position.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (current_position.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setReferencePosition(current_position);
			}
			else
			{
				enemy_model->setEnemyPosition(current_position);
			}
		}

		void ZapperController::moveRight()
		{
			sf::Vector2f current_position = enemy_model->getEnemyPosition();

			current_position.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (current_position.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setReferencePosition(current_position);
			}
			else
			{
				enemy_model->setEnemyPosition(current_position);
			}
		}

		void ZapperController::moveDown()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();

			currentPosition.y += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			// Check if the enemy reached the reference position plus vertical travel distance
			if (currentPosition.y >= enemy_model->getReferencePosition().y + vertical_travel_distance)
			{
				if (enemy_model->getReferencePosition().x <= enemy_model->left_most_position.x)
				{
					enemy_model->setMovementDirection(MovementDirection::RIGHT);
				}
				else
				{
					enemy_model->setMovementDirection(MovementDirection::LEFT);
				}
			}
			else
			{
				enemy_model->setEnemyPosition(currentPosition);
			}
		}
	}
}