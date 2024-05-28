#include "Enemy/Controllers/SubZeroController.h"
#include "Enemy/EnemyModel.h"
#include "Enemy/EnemyConfig.h"
#include "Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;

	namespace Controller
	{
		SubZeroController::SubZeroController()
		{

		}

		SubZeroController::~SubZeroController()
		{

		}

		void SubZeroController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setMovementDirection(MovementDirection::DOWN);
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