#include "Player/PlayerView.h"
#include "Player/PlayerController.h"

#include "Global/ServiceLocator.h"
#include "Global/Config.h"

namespace Player
{
	using namespace Global;
	using namespace UI::UIElement;

	PlayerView::PlayerView()
	{
		createUIElements();
	}

	PlayerView::~PlayerView()
	{
		destroy();
	}

	void PlayerView::createUIElements()
	{
		player_image = new ImageView();
	}

	void PlayerView::initialize(PlayerController* controller)
	{
		player_controller = controller;

		initializeImage();
	}

	void PlayerView::initializeImage()
	{
		player_image->initialize(getPlayerTexturePath(), player_sprite_width, player_sprite_height, player_controller->getPlayerPosition());
	}

	sf::String PlayerView::getPlayerTexturePath()
	{
		return Config::player_texture_path;
	}

	void PlayerView::update()
	{
		player_image->setPosition(player_controller->getPlayerPosition());
	}

	void PlayerView::render()
	{
		player_image->render();
	}

	void PlayerView::destroy()
	{
		delete(player_image);

		player_image = nullptr;
	}
}