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

		void move();
		void moveLeft();
		void moveRight();
		void moveDown();

		sf::Vector2f getEnemyPosition();
	};
}