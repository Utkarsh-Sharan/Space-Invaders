#include "UI/GameplayUI/GameplayUIController.h"

#include "Global/Config.h"
#include "Global/ServiceLocator.h"

#include "Gameplay/GameplayService.h"
#include "Sound/SoundService.h"
#include "Main/GameService.h"
#include "Player/PlayerModel.h"

namespace UI
{
	namespace GameplayUI
	{
		using namespace Main;
		using namespace Sound;
		using namespace Player;
		using namespace UI::UIElement;

		GameplayUIController::GameplayUIController()
		{
			createUIElements();
		}

		GameplayUIController::~GameplayUIController()
		{
			destroy();
		}

		void GameplayUIController::createUIElements()
		{
			player_image = new ImageView();

			enemies_killed_text = new TextView();
		}

		void GameplayUIController::initialize()
		{
			initializeImage();
			initializeText();
		}

		void GameplayUIController::initializeImage()
		{
			player_image->initialize(Global::Config::player_texture_path, player_sprite_width, player_sprite_height, sf::Vector2f(0, 0));
		}

		void GameplayUIController::initializeText()
		{
			sf::String enemies_killed_string = "Enemies Killed  :  0";

			enemies_killed_text->initialize(enemies_killed_string, sf::Vector2f(enemies_killed_text_x_position, text_y_position), FontType::BUBBLE_BOBBLE, font_size, text_color);
		}

		void GameplayUIController::update()
		{
			updateEnemiesKilledText();
		}

		void GameplayUIController::render()
		{
			enemies_killed_text->render();
			drawPlayerLives();
		}

		void GameplayUIController::show()
		{

		}

		void GameplayUIController::updateEnemiesKilledText()
		{
			sf::String enemies_killed_string = "Enemies Killed  :  " + std::to_string(PlayerModel::enemies_killed);
			enemies_killed_text->setText(enemies_killed_string);
		}

		void GameplayUIController::drawPlayerLives()
		{
			sf::RenderWindow* game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			for (int i = 0; i < PlayerModel::player_lives; i++)
			{
				player_image->setPosition(sf::Vector2f(player_lives_x_offset - (i * player_lives_spacing), player_lives_y_offset));
				player_image->render();
			}
		}

		void GameplayUIController::destroy()
		{
			delete(player_image);
			delete(enemies_killed_text);

			player_image = nullptr;
			enemies_killed_text = nullptr;
		}
	}
}