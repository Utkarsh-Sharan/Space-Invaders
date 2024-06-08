#pragma once

#include "Collectible/ICollectible.h"
#include "Collision/ICollider.h"

#include <SFML/System/Vector2.hpp>

namespace Powerup
{
	class PowerupModel;
	class PowerupView;

	enum class PowerupType;

	class PowerupController : public Collectible::ICollectible, public Collision::ICollider
	{
	protected:
		PowerupView* powerup_view;
		PowerupModel* powerup_model;

		virtual void applyPowerup() = 0;

		void updatePowerupPosition();
		void handleOutOfBounds();

	public:
		PowerupController(PowerupType type);
		virtual ~PowerupController();

		void initialize(sf::Vector2f position) override;
		void update() override;
		void render() override;

		void onCollected() override;
		sf::Vector2f getCollectiblePosition() override;

		PowerupType getPowerupType();

		const sf::Sprite& getColliderSprite() override;
		void onCollision(ICollider* other_collider) override;
	};
}