#pragma once

#include <SFML/Graphics.hpp>
#include "Player/PlayerModel.h"
#include "Player/PlayerView.h"

class PlayerController
{
private:
	PlayerModel* player_model;
	PlayerView* player_view;

	void processPlayerInput();
	void moveLeft();
	void moveRight();

public:
	PlayerController();
	~PlayerController();

	void initialize();
	void update();
	void render();

	sf::Vector2f getPlayerPosition();
};