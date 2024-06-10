#include "Enemy/EnemyService.h"
#include "Enemy/EnemyController.h"
#include "Enemy/EnemyConfig.h"

#include "Enemy/Controllers/ZapperController.h"
#include "Enemy/Controllers/SubZeroController.h"
#include "Enemy/Controllers/ThunderSnakeController.h"
#include "Enemy/Controllers/UFOController.h"

#include "Global/ServiceLocator.h"
#include "Collision/ICollider.h"

namespace Enemy
{
	using namespace Global;
	using namespace Controller;
	using namespace Collision;

	EnemyService::EnemyService()
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	EnemyService::~EnemyService()
	{
		destroy();
	}

	void EnemyService::initialize()
	{
		spawn_timer = spawn_interval;
	}

	void EnemyService::update()
	{
		updateSpawnTimer();
		processEnemySpawn();

		for (int i = 0; i < enemy_list.size(); i++)
		{
			enemy_list[i]->update();
		}

		destroyFlaggedEnemies();
	}

	void EnemyService::updateSpawnTimer()
	{
		spawn_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void EnemyService::processEnemySpawn()
	{
		if (spawn_timer >= spawn_interval)
		{
			spawnEnemy();
			spawn_timer = 0.0f;
		}
	}

	void EnemyService::render()
	{
		for (int i = 0; i < enemy_list.size(); i++)
		{
			enemy_list[i]->render();
		}
	}

	EnemyController* EnemyService::spawnEnemy()
	{
		EnemyController* enemy_controller = createEnemy(getRandomEnemyType());
		enemy_controller->initialize();

		ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<ICollider*>(enemy_controller));
		enemy_list.push_back(enemy_controller);

		return enemy_controller;
	}

	EnemyController* EnemyService::createEnemy(EnemyType enemy_type)
	{
		switch (enemy_type)
		{
		case EnemyType::ZAPPER:
			return new ZapperController(EnemyType::ZAPPER);

		case EnemyType::THUNDER_SNAKE:
			return new ThunderSnakeController(Enemy::EnemyType::THUNDER_SNAKE);

		case EnemyType::SUBZERO:
			return new SubZeroController(EnemyType::SUBZERO);

		case EnemyType::UFO:
			return new UFOController(Enemy::EnemyType::UFO);
		}
	}

	EnemyType EnemyService::getRandomEnemyType()
	{
		int randomType = std::rand() % 4;

		return static_cast<EnemyType>(randomType);  //cast int to EnemyType enum class
	}

	void EnemyService::destroy()
	{
		for (int i = 0; i < enemy_list.size(); i++)
		{
			delete(enemy_list[i]);

			enemy_list[i] = nullptr;
		}
	}

	void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	{
		if (std::find(flagged_enemy_list.begin(), flagged_enemy_list.end(), enemy_controller) == flagged_enemy_list.end())
		{
			flagged_enemy_list.push_back(enemy_controller);
			enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());
		}
	}

	void EnemyService::destroyFlaggedEnemies()
	{
		for (int i = 0; i < flagged_enemy_list.size(); i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(flagged_enemy_list[i]));
			delete (flagged_enemy_list[i]);
		}
		flagged_enemy_list.clear();
	}

	void EnemyService::reset()
	{
		destroy();
		spawn_timer = 0.0f;
	}
}