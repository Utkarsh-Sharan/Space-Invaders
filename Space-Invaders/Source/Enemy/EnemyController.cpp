#include "Enemy/EnemyController.h"
#include "Enemy/EnemyModel.h"
#include "Enemy/EnemyView.h"
#include "Global/ServiceLocator.h"
#include "Enemy/EnemyConfig.h"

namespace Enemy
{
	using namespace Global;

	EnemyController::EnemyController(EnemyType type)
	{
		enemy_model = new EnemyModel(type);
		enemy_view = new EnemyView();
	}

	EnemyController::~EnemyController()
	{
		delete(enemy_model);
		delete(enemy_view);
	}

	void EnemyController::initialize()
	{
		enemy_model->setEnemyPosition(getRandomInitialPosition());

		enemy_model->initialize();
		enemy_view->initialize(this);
	}

	void EnemyController::update()
	{
		enemy_view->update();
		move();
		handleOutOfBounds();
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
}