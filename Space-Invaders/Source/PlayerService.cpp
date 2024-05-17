#include "PlayerService.h"
#include "ServiceLocator.h"

PlayerService::PlayerService()
{
	game_window = nullptr;
}

PlayerService::~PlayerService() = default;

void PlayerService::initialize()
{
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	initializePlayerSprite();
}

void PlayerService::initializePlayerSprite()
{
	if (player_texture.loadFromFile(player_texture_path))
	{
		player_sprite.setTexture(player_texture);
	}
}

void PlayerService::update()
{
	processPlayerInput();
	player_sprite.setPosition(getPlayerPosition());
}

void PlayerService::processPlayerInput()
{
	EventService* event_service = ServiceLocator::getInstance()->getEventService();

	if (event_service->pressedLeftKey()) {
		move(-1.0f * getMoveSpeed());
	}

	if (event_service->pressedRightKey()) {
		move(1.0f * getMoveSpeed());
	}
}

sf::Vector2f PlayerService::getPlayerPosition()
{
	return position;
}

void PlayerService::move(float offset)
{
	position.x += offset;
}

int PlayerService::getMoveSpeed()
{
	return movement_speed;
}

void PlayerService::render()
{
	game_window->draw(player_sprite);
}