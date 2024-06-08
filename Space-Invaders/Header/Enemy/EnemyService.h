#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

namespace Enemy
{
	class EnemyController;
	enum class EnemyType;

	class EnemyService
	{
	private:
		const float spawn_interval = 2.0f;

		std::vector<EnemyController*>  enemy_list;
		std::vector<EnemyController*> flagged_enemy_list;
		float spawn_timer;

		EnemyType getRandomEnemyType();
		EnemyController* createEnemy(EnemyType enemy_type);

		void updateSpawnTimer();
		void processEnemySpawn();

		void destroyFlaggedEnemies();
		void destroy();

	public:
		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();

		void reset();

		EnemyController* spawnEnemy();
		void destroyEnemy(EnemyController* enemy_controller);
	};
}