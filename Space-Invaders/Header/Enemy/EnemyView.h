#pragma once

#include <SFML/Graphics.hpp>

namespace Enemy
{
	class EnemyController;

	class EnemyView
	{
	private:
		sf::String enemy_texture_path = "assets/textures/zapper.png";

		const float enemy_sprite_width = 60.0f;
		const float enemy_sprite_height = 60.0f;

		sf::Texture enemy_texture;
		sf::Sprite enemy_sprite;
		sf::RenderWindow* game_window;

		EnemyController* enemy_controller;

		void initializeEnemySprite();
		void scaleEnemySprite();

	public:
		EnemyView();
		~EnemyView();

		void initialize(EnemyController* controller);
		void update();
		void render();


	};
}