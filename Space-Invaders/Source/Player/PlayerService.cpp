#include "Player/PlayerService.h"
#include "Global/ServiceLocator.h"

#include "Player/PlayerController.h"

PlayerService::PlayerService()
{
	player_controller = new PlayerController();
}

PlayerService::~PlayerService()
{
	delete(player_controller);
	player_controller = nullptr;
}

void PlayerService::initialize()
{
	player_controller->initialize();
}

void PlayerService::update()
{
	player_controller->update();
}

void PlayerService::render()
{
	player_controller->render();
}