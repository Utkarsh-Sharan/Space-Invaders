#include "Player/PlayerController.h"
#include "Player/PlayerView.h"
#include "Player/PlayerModel.h"

#include "Event/EventService.h"
#include "Global/ServiceLocator.h"
#include "Enemy/EnemyController.h"
#include "Powerup/PowerupController.h"
#include "Entity/EntityConfig.h"

#include "Bullet/BulletConfig.h"
#include "Bullet/BulletController.h"

#include <algorithm>

namespace Player
{
	using namespace Time;
	using namespace Bullet;
	using namespace Entity;
	using namespace Enemy;
	using namespace Powerup;

	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
		player_view = new PlayerView();
	}

	PlayerController::~PlayerController()
	{
		delete(player_model);
		delete(player_view);

		player_model = nullptr;
		player_view = nullptr;
	}

	void PlayerController::initialize()
	{
		player_model->initialize();
		player_view->initialize(this); // 'this' refers to the class we are currently inside
	}

	void PlayerController::update()
	{
		switch (player_model->getPlayerState())
		{
		case PlayerState::ALIVE:
			processPlayerInput();
			break;

		case PlayerState::FROZEN:
			updateFreezeDuration();
			break;
		}

		updatePowerupDuration();
		updateFireDuration();

		player_view->update();
	}

	void PlayerController::render()
	{
		player_view->render();
	}

	void PlayerController::processPlayerInput()
	{
		Event::EventService* event_service = Global::ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedLeftKey() || event_service->pressedAKey())
		{
			moveLeft();
		}
		
		if (event_service->pressedRightKey() || event_service->pressedDKey())
		{
			moveRight();
		}

		if (event_service->pressedLeftMouseButton())
		{
			processBulletFire();
		}
	}

	void PlayerController::processBulletFire()
	{
		if (player_model->elapsed_fire_duration > 0) 
			return;

		if (player_model->isTripleLaserEnabled())
			fireBullet(true);

		else 
			fireBullet();

		if (player_model->isRapidFireEnabled())
			player_model->elapsed_fire_duration = player_model->rapid_fire_cooldown_duration;

		else 
			player_model->elapsed_fire_duration = player_model->fire_cooldown_duration;
	}

	void PlayerController::fireBullet(bool b_tripple_laser)
	{
		sf::Vector2f bullet_position = player_model->getPlayerPosition() + player_model->barrel_position_offset;
		fireBullet(bullet_position);

		if (b_tripple_laser)
		{
			fireBullet(bullet_position + player_model->second_weapon_position_offset);
			fireBullet(bullet_position + player_model->third_weapon_position_offset);
		}
	}

	void PlayerController::fireBullet(sf::Vector2f position)
	{
		Global::ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::LASER_BULLET, player_model->getEntityType(), position, Bullet::MovementDirection::UP);
	}

	void PlayerController::moveLeft()
	{
		sf::Vector2f current_position = player_model->getPlayerPosition();
		current_position.x -= player_model->player_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		current_position.x = std::max(current_position.x, player_model->left_most_position.x);
		player_model->setPlayerPosition(current_position);
	}

	void PlayerController::moveRight()
	{
		sf::Vector2f current_position = player_model->getPlayerPosition();
		current_position.x += player_model->player_movement_speed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		current_position.x = std::min(current_position.x, player_model->right_most_position.x);
		player_model->setPlayerPosition(current_position);
	}

	void PlayerController::updateFreezeDuration()
	{
		if (player_model->elapsed_freeze_duration > 0)
		{
			player_model->elapsed_fire_duration -= Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (player_model->elapsed_freeze_duration <= 0)
				player_model->setPlayerState(PlayerState::ALIVE);
		}
	}

	void PlayerController::updatePowerupDuration()
	{
		if (player_model->elapsed_shield_duration > 0)
		{
			player_model->elapsed_shield_duration -= Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (player_model->elapsed_shield_duration <= 0)
				disableShield();
		}

		if (player_model->elapsed_rapid_fire_duration > 0)
		{
			player_model->elapsed_rapid_fire_duration -= Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (player_model->elapsed_rapid_fire_duration <= 0)
				disableRapidFire();
		}

		if (player_model->elapsed_triple_laser_duration > 0)
		{
			player_model->elapsed_triple_laser_duration -= Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (player_model->elapsed_triple_laser_duration <= 0)
				disableTripleLaser();
		}
	}

	void PlayerController::updateFireDuration()
	{
		if (player_model->elapsed_fire_duration >= 0)
		{
			player_model->elapsed_fire_duration -= Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		}
	}

	void PlayerController::enableShield()
	{
		player_model->elapsed_shield_duration = player_model->shiled_powerup_duration;
		player_model->setShieldState(true);
	}
	void PlayerController::enableRapidFire()
	{
		player_model->elapsed_rapid_fire_duration = player_model->rapid_fire_powerup_duration;
		player_model->setRapidFireState(true);
	}

	void PlayerController::enableTripleLaser()
	{
		player_model->elapsed_triple_laser_duration = player_model->triple_laser_powerup_duration;
		player_model->setTripleLaserState(true);
	}

	void PlayerController::disableShield()
	{
		player_model->setShieldState(false);
	}

	void PlayerController::disableRapidFire()
	{
		player_model->setRapidFireState(false);
	}

	void PlayerController::disableTripleLaser()
	{
		player_model->setTripleLaserState(false);
	}

	void PlayerController::onCollision(ICollider* other_collider)
	{
		if (processPowerupCollision(other_collider))
			return;

		if (processBulletCollision(other_collider))
			return;

		processEnemyCollision(other_collider);
	}

	bool PlayerController::processBulletCollision(ICollider* other_collider)
	{
		if (player_model->isShieldEnabled())
			return false;

		BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);

		if (bullet_controller && bullet_controller->getOwnerEntityType() != EntityType::PLAYER)
		{
			if (bullet_controller->getBulletType() == BulletType::FROST_BULLET)
			{
				player_model->setPlayerState(PlayerState::FROZEN);
				player_model->elapsed_freeze_duration = player_model->freeze_duration;
			}
			else
			{
				decreasePlayerLive();
				//Global::ServiceLocator::getInstance()->getGameplayService()->restart();
			}

			return true;
		}

		return false;
	}

	bool PlayerController::processPowerupCollision(ICollider* other_collider)
	{
		PowerupController* powerup_controller = dynamic_cast<PowerupController*>(other_collider);
		if (powerup_controller)
		{
			return true;
		}

		return false;
	}

	bool PlayerController::processEnemyCollision(ICollider* other_collider)
	{
		if (player_model->isShieldEnabled())
			return false;

		EnemyController* enemy_controller = dynamic_cast<EnemyController*>(other_collider);
		if (enemy_controller)
		{
			//Global::ServiceLocator::getInstance()->getGameplayService()->restart();
			decreasePlayerLive();
			return true;
		}

		return false;
	}

	void PlayerController::freezePlayer()
	{

	}

	sf::Vector2f PlayerController::getPlayerPosition()
	{
		return player_model->getPlayerPosition();
	}

	PlayerState PlayerController::getPlayerState()
	{
		return player_model->getPlayerState();
	}

	void PlayerController::decreasePlayerLive()
	{
		PlayerModel::player_lives -= 1;
		if (PlayerModel::player_lives <= 0)
		{
			//reset();
			Global::ServiceLocator::getInstance()->getGameplayService()->restart();
		}
	}

	const sf::Sprite& PlayerController::getColliderSprite()
	{
		return player_view->getPlayerSprite();
	}

	void PlayerController::reset()
	{
		player_model->reset();
	}
}