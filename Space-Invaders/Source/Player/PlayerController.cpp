#include "Player/PlayerController.h"
#include "Player/PlayerView.h"
#include "Player/PlayerModel.h"

#include "Event/EventService.h"
#include "Global/ServiceLocator.h"
#include "Bullet/BulletConfig.h"

#include <algorithm>

namespace Player
{
	using namespace Bullet;

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
		processPlayerInput();
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
			fireBullet();
		}
	}

	void PlayerController::fireBullet()
	{
		Global::ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::LASER_BULLET,
			player_model->getPlayerPosition() - player_model->barrel_position_offset, Bullet::MovementDirection::UP);
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

	sf::Vector2f PlayerController::getPlayerPosition()
	{
		return player_model->getPlayerPosition();
	}
}