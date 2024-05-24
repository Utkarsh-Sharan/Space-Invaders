#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

namespace Enemy
{
	class EnemyController;

	class EnemyService
	{
	private:
		const float spawn_interval = 3.0f;

		std::vector<EnemyController*>  enemy_list;
		float spawn_timer;

		void updateSpawnTimer();
		void processEnemySpawn();
		void destroy();

	public:
		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();

		void spawnEnemy();
	};
}