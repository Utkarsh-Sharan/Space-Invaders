#include "Main/GameService.h"
#include "Graphic/GraphicService.h"
#include "Global/ServiceLocator.h"

namespace Main
{
	using namespace Global;

	GameState GameService::current_state = GameState::BOOT;

	GameService::GameService()
	{
		service_locator = nullptr; // Set service locator to null
		game_window = nullptr; // Set game window to null
	}

	GameService::~GameService()
	{
		destroy(); // Clean up and release resources
	}

	// Prepares the game service for use by obtaining the service locator instance and initializing services.
	void GameService::ignite()
	{
		service_locator = Global::ServiceLocator::getInstance(); // Get ServiceLocator
		initialize(); // Initialize services.
	}

	void GameService::initialize()
	{
		service_locator->getInstance()->initialize();
		initializeVariables();
	}

	void GameService::initializeVariables()
	{
		game_window = service_locator->getGraphicService()->getGameWindow();
		game_window->setFramerateLimit(frame_rate);
	}

	void GameService::destroy()
	{
		//delete(service_locator);
		delete(game_window);
		service_locator = nullptr;
		game_window = nullptr;
	}

	// Updates the game logic by delegating to the service locator's update method.
	void GameService::update()
	{
		service_locator->getEventService()->processEvents();
		service_locator->getInstance()->update(); // Call update on the service locator which then updates all its managed services
	}

	// Clears the window then display it.
	void GameService::render()
	{
		// Clears the game window with the background color provided by the graphic service
		game_window->clear(service_locator->getGraphicService()->getWindowColor());
		service_locator->getInstance()->render(); // Render the current frame using the service locator
		game_window->display(); // Display the rendered frame on the game window
	}

	// Checks if the game is still running by querying the graphic service's window open status.
	bool GameService::isRunning()
	{
		// Returns true if the game window is open, indicating the game is still running
		return service_locator->getGraphicService()->isGameWindowOpen();
	}
	void GameService::setGameState(GameState new_state)
	{
		current_state = new_state;
	}
	GameState GameService::getGameState()
	{
		return current_state;
	}
}