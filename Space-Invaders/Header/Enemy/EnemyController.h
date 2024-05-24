#pragma once

#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyModel;
	class EnemyView;

	class EnemyController
	{
	private:
		EnemyModel* enemy_model;
		EnemyView* enemy_view;

	public:
		EnemyController();
		~EnemyController();

		void initialize();
		void update();
		void render();

		sf::Vector2f getEnemyPosition();
	};
}