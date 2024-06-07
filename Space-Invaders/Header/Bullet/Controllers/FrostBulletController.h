#pragma once

#include "Bullet/BulletController.h"

namespace Bullet
{
	namespace Controller
	{
		class FrostBulletController : public BulletController
		{
		private:
			const float frost_bullet_movement_speed = 500.0f;

		public:
			FrostBulletController(BulletType type, Entity::EntityType owner_type);
			~FrostBulletController();

			void initialize(sf::Vector2f position, MovementDirection direction) override;
		};
	}
}