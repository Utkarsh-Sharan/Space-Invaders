#include "Enemy/Controllers/UFOController.h"
#include "Enemy/EnemyModel.h"
#include "Enemy/EnemyConfig.h"

#include "Powerup/PowerupConfig.h"

#include "Global/ServiceLocator.h"

namespace Enemy
{
	namespace Controller
	{
		using namespace Powerup;
		using namespace Global;

		UFOController::UFOController(EnemyType type) : EnemyController(type)
		{

		}

		UFOController::~UFOController()
		{

		}

		void UFOController::initialize()
		{
			EnemyController::initialize();
		}

		void UFOController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case MovementDirection::LEFT:
				moveLeft();
				break;

			case MovementDirection::RIGHT:
				moveRight();
				break;
			};
		}

		void UFOController::moveLeft()
		{
			sf::Vector2f current_position = enemy_model->getEnemyPosition();

			current_position.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

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

		void UFOController::moveRight()
		{
			sf::Vector2f current_position = enemy_model->getEnemyPosition();

			current_position.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

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

		void UFOController::fireBullet()
		{

		}

		PowerupType UFOController::getRandomPowerupType()
		{
			std::srand(static_cast<unsigned int>(std::time(nullptr)));

			//We add '1'  to OutscalBomb below because enum has a 0 index, making the bomb number 3, we need to add 1 to make it 4 

			int random_value = std::rand() % (static_cast<int>(Powerup::PowerupType::OUTSCAL_BOMB) + 1);
			return static_cast<Powerup::PowerupType>(random_value);
		}
	}
}