#pragma once

#include "Entity/EntityConfig.h"

#include <SFML/Graphics.hpp>

namespace Enemy
{
	enum class EnemyType;
	enum class MovementDirection;
	enum class EnemyState;

	class EnemyModel
	{
	private:
		sf::Vector2f reference_position = sf::Vector2f(50.0f, 50.0f);
		sf::Vector2f enemy_position;

		Entity::EntityType entity_type;
		EnemyType enemy_type;
		EnemyState enemy_state;
		MovementDirection movement_direction;

	public:
		const sf::Vector2f left_most_position = sf::Vector2f(50.f, 50.f);
		const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 50.f);
		const sf::Vector2f barrel_position_offset = sf::Vector2f(20.f, 50.f); //offset position for spawning bullet at right position from the enemy/player

		const float vertical_travel_distance = 100.f;
		const float enemy_movement_speed = 250.0f;

		EnemyModel(EnemyType type);
		~EnemyModel();

		void initialize();
		void update();
		void render();

		sf::Vector2f getEnemyPosition();
		void setEnemyPosition(sf::Vector2f position);

		sf::Vector2f getReferencePosition();
		void setReferencePosition(sf::Vector2f position);

		EnemyType getEnemyType();
		void setEnemyType(EnemyType type);

		EnemyState getEnemyState();
		void setEnemyState(EnemyState state);

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);

		Entity::EntityType getEntityType();
	};
}