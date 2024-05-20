#include "PlayerService.h"
#include "ServiceLocator.h"

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