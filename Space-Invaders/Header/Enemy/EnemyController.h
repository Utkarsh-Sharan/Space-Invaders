#pragma once

#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyModel;
	class EnemyView;
	enum class EnemyState;
	enum class EnemyType;

	class EnemyController
	{
	protected:
		EnemyModel* enemy_model;
		EnemyView* enemy_view;

		virtual void move() = 0;
		//void moveLeft();
		//void moveRight();
		//void moveDown();

		sf::Vector2f getRandomInitialPosition();
		void handleOutOfBounds();

	public:
		EnemyController(EnemyType type);
		virtual ~EnemyController();

		virtual void initialize();
		void update();
		void render();

		sf::Vector2f getEnemyPosition();

		EnemyState getEnemyState();
		EnemyType getEnemyType();
	};
}