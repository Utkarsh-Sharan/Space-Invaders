#include "Enemy/EnemyService.h"
#include "Enemy/EnemyController.h"

namespace Enemy
{
	EnemyService::EnemyService()
	{
		enemy = nullptr;
	}

	EnemyService::~EnemyService()
	{
		destroy();
	}

	void EnemyService::destroy()
	{
		delete(enemy);

		enemy = nullptr;
	}

	void EnemyService::initialize()
	{
		spawnEnemy();
	}

	void EnemyService::update()
	{
		enemy->update();
	}

	void EnemyService::render()
	{
		enemy->render();
	}

	EnemyController* EnemyService::spawnEnemy()
	{
		enemy = new EnemyController();
		enemy->initialize();

		return enemy;
	}
}