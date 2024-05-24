#pragma once

#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyController;

	class EnemyService
	{
	private:
		EnemyController* enemy;

		void destroy();

	public:
		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();

		EnemyController* spawnEnemy();
	};
}