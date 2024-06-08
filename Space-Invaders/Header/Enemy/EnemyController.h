#pragma once

#include "Collision/ICollider.h"

#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyModel;
	class EnemyView;
	enum class EnemyState;
	enum class EnemyType;

	class EnemyController : public Collision::ICollider
	{
	protected:
		float rate_of_fire = 3.f;
		float elapsed_fire_duration = 0.f;

		EnemyModel* enemy_model;
		EnemyView* enemy_view;

		void updateFireTime();
		void processBulletFire();
		virtual void fireBullet() = 0;

		virtual void move() = 0;

		sf::Vector2f getRandomInitialPosition();
		void handleOutOfBounds();

		virtual void destroy();

	public:
		EnemyController(EnemyType type);
		virtual ~EnemyController();

		virtual void initialize();
		void update();
		void render();

		sf::Vector2f getEnemyPosition();

		EnemyState getEnemyState();
		EnemyType getEnemyType();

		const sf::Sprite& getColliderSprite() override;
		virtual void onCollision(ICollider* other_collider) override;
	};
}