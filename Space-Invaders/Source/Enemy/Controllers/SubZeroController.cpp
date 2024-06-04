#include "Enemy/Controllers/SubZeroController.h"
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

		SubZeroController::SubZeroController(EnemyType type): EnemyController(type)
		{
			
		}

		SubZeroController::~SubZeroController()
		{

		}

		void SubZeroController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setMovementDirection(MovementDirection::DOWN);

			rate_of_fire = subzero_rate_of_fire;
		}

		void SubZeroController::fireBullet()
		{
			ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::FROST_BULLET,
				enemy_model->getEnemyPosition() + enemy_model->barrel_position_offset, Bullet::MovementDirection::DOWN);
		}

		void SubZeroController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case MovementDirection::DOWN:
				moveDown();
				break;
			}
		}

		void SubZeroController::moveDown()
		{
			sf::Vector2f current_position = enemy_model->getEnemyPosition();
			current_position.y += movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			enemy_model->setEnemyPosition(current_position);
		}
	}
}