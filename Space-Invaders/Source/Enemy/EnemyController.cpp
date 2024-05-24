#include "Enemy/EnemyController.h"
#include "Enemy/EnemyModel.h"
#include "Enemy/EnemyView.h"

namespace Enemy
{
	EnemyController::EnemyController()
	{
		enemy_model = new EnemyModel();
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
	}

	void EnemyController::render()
	{
		enemy_view->render();
	}

	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyPosition();
	}
}