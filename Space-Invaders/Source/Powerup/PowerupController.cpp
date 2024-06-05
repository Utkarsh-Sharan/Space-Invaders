#include "Powerup/PowerupController.h"
#include "Powerup/PowerupModel.h"
#include "Powerup/PowerupView.h"

#include "Global/ServiceLocator.h"

namespace Powerup
{
	using namespace Global;

	PowerupController::PowerupController(PowerupType type)
	{
		powerup_model = new PowerupModel(type);
		powerup_view = new PowerupView();
	}

	PowerupController::~PowerupController()
	{
		delete(powerup_model);
		delete(powerup_view);

		powerup_model = nullptr;
		powerup_view = nullptr;
	}

	void PowerupController::initialize(sf::Vector2f position)
	{
		powerup_model->initialize(position);
		powerup_view->initialize(this);
	}

	void PowerupController::update()
	{
		updatePowerupPosition();
		powerup_view->update();
	}

	void PowerupController::updatePowerupPosition()
	{
		sf::Vector2f current_position = powerup_model->getPowerupPosition();
		current_position.y += powerup_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		powerup_model->setPowerupPosition(current_position);
	}

	void PowerupController::handleOutOfBounds()
	{
		sf::Vector2f powerup_position = getCollectiblePosition();
		sf::Vector2u window_size = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		if (powerup_position.x < 0 || powerup_position.x > window_size.x || powerup_position.y < 0 || powerup_position.y > window_size.y)
		{
			ServiceLocator::getInstance()->getPowerupService()->destroyPowerup(this);
		}
	}

	void PowerupController::render()
	{
		powerup_view->render();
	}

	void PowerupController::onCollected()
	{

	}

	sf::Vector2f PowerupController::getCollectiblePosition()
	{
		return powerup_model->getPowerupPosition();;
	}

	PowerupType PowerupController::getPowerupType()
	{
		return powerup_model->getPowerupType();
	}
}