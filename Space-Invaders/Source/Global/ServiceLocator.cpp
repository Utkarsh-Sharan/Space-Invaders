#include "Global/ServiceLocator.h"
#include "Graphic/GraphicService.h"
#include "Main/GameService.h"

namespace Global
{
	using namespace Graphic;
	using namespace Time;
	using namespace Event;
	using namespace Player;
	using namespace UI;
	using namespace Enemy;
	using namespace Main;
	using namespace Gameplay;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr; // Initialize graphic_service to null
		event_service = nullptr;
		player_service = nullptr;
		time_service = nullptr;
		ui_service = nullptr;
		enemy_service = nullptr;
		gameplay_service = nullptr;

		createServices(); // Call createServices to instantiate services
	}

	// Destructor: Cleans up resources by clearing all services.
	ServiceLocator::~ServiceLocator()
	{
		clearAllServices(); // Call clearAllServices to delete any allocated services	
	}

	// Creates service instances, specifically the graphic service in this case.
	void ServiceLocator::createServices()
	{
		graphic_service = new GraphicService(); // Dynamically create a GraphicService instance
		event_service = new EventService();
		player_service = new PlayerService();
		time_service = new TimeService();
		ui_service = new UIService();
		enemy_service = new EnemyService();
		gameplay_service = new GameplayService();
	}

	// Deletes allocated services to prevent memory leaks, specifically the graphic service.
	void ServiceLocator::clearAllServices()
	{
		delete(graphic_service); // Delete the graphic_service instance
		delete(event_service);
		delete(player_service);
		delete(time_service);
		delete(ui_service);
		delete(enemy_service);
		delete(gameplay_service);

		graphic_service = nullptr; // Reset pointer to null to avoid dangling pointer
		event_service = nullptr;
		player_service = nullptr;
		time_service = nullptr;
		ui_service = nullptr;
		enemy_service = nullptr;
		gameplay_service = nullptr;
	}

	// Returns a pointer to ServiceLocator.
	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance; // Return address of the instance
	}

	// Calls initialize on the graphic service, readying it for use.
	void ServiceLocator::initialize()
	{
		graphic_service->initialize(); // Initialize graphic service
		event_service->initialize();
		player_service->initialize();
		time_service->initialize();
		ui_service->initialize();
		enemy_service->initialize();
		gameplay_service->initialize();
	}

	// Updates the state of the graphic service.
	void ServiceLocator::update()
	{
		graphic_service->update(); // Update graphic service
		event_service->update();
		time_service->update();

		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			gameplay_service->update();
			player_service->update();
			enemy_service->update();
		}

		ui_service->update();
	}

	// Renders using the graphic service.
	void ServiceLocator::render()
	{
		graphic_service->render(); // Render graphic service

		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			gameplay_service->render();
			player_service->render();
			enemy_service->render();
		}

		ui_service->render();
	}

	// Returns a pointer to the currently set graphic service.
	GraphicService* ServiceLocator::getGraphicService()
	{
		return graphic_service;
	}

	EventService* ServiceLocator::getEventService()
	{
		return event_service;
	}

	PlayerService* ServiceLocator::getPlayerService()
	{
		return player_service;
	}

	TimeService* ServiceLocator::getTimeService()
	{
		return time_service;
	}

	UI::UIService* ServiceLocator::getUIService()
	{
		return ui_service;
	}

	Enemy::EnemyService* ServiceLocator::getEnemyService()
	{
		return enemy_service;
	}

	Gameplay::GameplayService* ServiceLocator::getGameplayService()
	{
		return gameplay_service;
	}
}