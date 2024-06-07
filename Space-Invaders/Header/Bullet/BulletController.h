#pragma once

#include "Projectile/IProjectile.h"
#include "Bullet/BulletConfig.h"
#include "Entity/EntityConfig.h"

namespace Bullet
{
	class BulletModel;
	class BulletView;

	class BulletController : public Projectile::IProjectile
	{
	protected:
		BulletModel* bullet_model;
		BulletView* bullet_view;

		void updateProjectilePosition() override;

		void moveUp();
		void moveDown();
		void handleOutOfBounds();

	public:
		BulletController(BulletType type, Entity::EntityType owner_type);
		virtual ~BulletController();

		void initialize(sf::Vector2f position, Bullet::MovementDirection direction) override;
		void update() override;
		void render() override;

		sf::Vector2f getProjectilePosition() override;
		BulletType getBulletType();
		Entity::EntityType getOwnerEntityType();
	};
}