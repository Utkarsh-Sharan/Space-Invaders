#pragma once

#include <SFML/Graphics.hpp>

class PlayerService
{
private:
	sf::Vector2f position = sf::Vector2f(200, 100);
	int health = 3;
	int movement_speed = 5;
	int player_score = 0;

	const sf::String player_texture_path = "assets/textures/player_ship.png";

	sf::Texture player_texture;
	sf::Sprite player_sprite;

	sf::RenderWindow* game_window;

	void initializePlayerSprite();
	void processPlayerInput();

public:
	PlayerService();
	~PlayerService();

	void initialize();
	void update();
	void render();

	void move(float offset);
	int getMoveSpeed();
	sf::Vector2f getPlayerPosition();
};