#include "Event/EventService.h"
#include "Main/GameService.h"
#include "Graphic/GraphicService.h"

EventService::EventService()
{
	game_window = nullptr;
}

EventService::~EventService() = default;	//calls default destructor.

void EventService::initialize()
{
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
}

void EventService::update()
{

}

void EventService::processEvents()
{
	if (isGameWindowOpen())
	{
		while (game_window->pollEvent(game_event))
		{
			if (gameWindowWasClosed() || hasQuitGame())
			{
				game_window->close();
			}
		}
	}
}

bool EventService::isGameWindowOpen()
{
	return (game_window != nullptr);
}

bool EventService::gameWindowWasClosed()
{
	return (game_event.type == sf::Event::Closed);
}

bool EventService::hasQuitGame()
{
	return (isKeyboardEvent() && pressedEscapeKey());
}

bool EventService::isKeyboardEvent()
{
	return (game_event.type == sf::Event::KeyPressed);
}

bool EventService::pressedEscapeKey()
{
	return (game_event.key.code == sf::Keyboard::Escape);
}

bool EventService::pressedLeftKey()
{
	return (game_event.key.code == sf::Keyboard::Left);
}

bool EventService::pressedRightKey()
{
	return (game_event.key.code == sf::Keyboard::Right);
}