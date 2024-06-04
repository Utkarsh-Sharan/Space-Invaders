#pragma once

#include "Bullet/BulletConfig.h"

#include <SFML/Graphics.hpp>

namespace Projectile
{
	enum class MovementDirection;

	class IProjectile
	{
	public:
		virtual void initialize(sf::Vector2f position, Bullet::MovementDirection direction) = 0;
		virtual void update() = 0;
		virtual void render() = 0;

		virtual void updateProjectilePosition() = 0;
		virtual sf::Vector2f getProjectilePosition() = 0;

		virtual ~IProjectile() {};
	};
}