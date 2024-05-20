#include "Player/PlayerController.h"
#include "EventService.h"
#include "ServiceLocator.h"
#include <algorithm>

PlayerController::PlayerController()
{
	player_model = nullptr;
	player_view = nullptr;
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
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
	{
		moveLeft();
	}
	// we will move this to event service at a later time
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
	{
		moveRight();
	}
}

void PlayerController::moveLeft()
{
	sf::Vector2f current_position = player_model->getPlayerPosition();
	current_position.x -= player_model->player_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

	current_position.x = std::max(current_position.x, player_model->left_most_position.x);
	player_model->setPlayerPosition(current_position);
}

void PlayerController::moveRight()
{
	sf::Vector2f current_position = player_model->getPlayerPosition();
	current_position.x += player_model->player_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

	current_position.x = std::min(current_position.x, player_model->left_most_position.x);
	player_model->setPlayerPosition(current_position);
}

sf::Vector2f PlayerController::getPlayerPosition()
{
	return player_model->getPlayerPosition();
}
