#include "Enemy/EnemyController.h"
#include "Enemy/EnemyModel.h"
#include "Enemy/EnemyView.h"
#include "Global/ServiceLocator.h"
#include "Enemy/EnemyConfig.h"

namespace Enemy
{
	using namespace Global;

	EnemyController::EnemyController()
	{
		enemy_model = new EnemyModel(EnemyType::ZAPPER); //random for now so that it stops giving error(s)
		enemy_view = new EnemyView();
	}

	EnemyController::~EnemyController()
	{
		delete(enemy_model);
		delete(enemy_view);
	}

	void EnemyController::initialize()
	{
		enemy_model->initialize();
		enemy_view->initialize(this);
	}

	void EnemyController::update()
	{
		enemy_view->update();
		move();
	}

	void EnemyController::render()
	{
		enemy_view->render();
	}

	/*void EnemyController::move()
	{
		switch(enemy_model->getMovementDirection())
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
	}*/

	void EnemyController::moveLeft()
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

	void EnemyController::moveRight()
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

	void EnemyController::moveDown()
	{
		sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
		currentPosition.y += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		//check if enemy has moved the specified distance downwards
		if (currentPosition.y >= enemy_model->getReferencePosition().y + enemy_model->vertical_travel_distance)
		{
			//check where to move them based on position
			if (enemy_model->getReferencePosition().x <= enemy_model->left_most_position.x) 
				enemy_model->setMovementDirection(MovementDirection::RIGHT);
			else 
				enemy_model->setMovementDirection(MovementDirection::LEFT);
		}
		else
		{
			enemy_model->setEnemyPosition(currentPosition);
		}
	}

	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyPosition();
	}
}