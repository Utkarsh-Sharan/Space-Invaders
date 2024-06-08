#pragma once

#include "Projectile/IProjectile.h"
#include "Collision/ICollider.h"

#include "Bullet/BulletConfig.h"
#include "Entity/EntityConfig.h"

namespace Bullet
{
	class BulletModel;
	class BulletView;

	class BulletController : public Projectile::IProjectile, public Collision::ICollider
	{
	protected:
		BulletModel* bullet_model;
		BulletView* bullet_view;

		void updateProjectilePosition() override;

		void processBulletCollision(ICollider* other_collider);
		void processEnemyCollision(ICollider* other_collider);
		void processPlayerCollision(ICollider* other_collider);
		void processBunkerCollision(ICollider* other_collider);

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

		const sf::Sprite& getColliderSprite() override;
		void onCollision(ICollider* other_collider) override;
	};
}