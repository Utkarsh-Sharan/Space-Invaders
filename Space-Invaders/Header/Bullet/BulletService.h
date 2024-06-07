#pragma once

#include "Projectile/IProjectile.h"
#include "Entity/EntityConfig.h"

#include <vector>
#include "SFML/System/Vector2.hpp"

namespace Bullet
{
	class BulletController;
	enum class BulletType;
	enum class MovementDirection;

	class BulletService
	{
	private:
		std::vector<Projectile::IProjectile*> bullet_list;

		BulletController* createBullet(BulletType bullet_type, Entity::EntityType owner_type);
		void destroy();

	public:
		BulletService();
		~BulletService();

		void initialize();
		void update();
		void render();

		BulletController* spawnBullet(BulletType bullet_type, sf::Vector2f position, MovementDirection direction, Entity::EntityType owner_type);
		void destroyBullet(BulletController* bullet_controller);
	};
}