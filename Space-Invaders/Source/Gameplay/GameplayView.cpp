#include "Gameplay/GameplayView.h"

#include "Global/ServiceLocator.h"
#include "Global/Config.h"

namespace Gameplay
{
	using namespace Global;
	using namespace UI::UIElement;

	GameplayView::GameplayView()
	{
		createUIElements();
	}

	GameplayView::~GameplayView()
	{
		destroy();
	}

	void GameplayView::createUIElements()
	{
		background_image = new ImageView();
	}

	void GameplayView::initialize()
	{
		initializeImage();
	}

	void GameplayView::initializeImage()
	{
		sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
	}

	void GameplayView::update()
	{
		background_image->update();
	}

	void GameplayView::render()
	{
		background_image->render();
	}

	void GameplayView::destroy()
	{
		delete(background_image);

		background_image = nullptr;
	}
}