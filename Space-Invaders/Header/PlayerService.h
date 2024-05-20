#pragma once

#include <SFML/Graphics.hpp>
#include "Player/PlayerController.h"

class PlayerService
{
private:
	PlayerController* player_controller;

public:
	PlayerService();
	~PlayerService();

	void initialize();
	void update();
	void render();
};
