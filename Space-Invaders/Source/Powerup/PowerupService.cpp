#include "Powerup/PowerupService.h"
#include "Powerup/PowerupController.h"
#include "Powerup/PowerupConfig.h"
#include "Global/ServiceLocator.h"
#include "Powerup/Controllers/OutscalBombController.h"
#include "Powerup/Controllers/RapidFireController.h"
#include "Powerup/Controllers/ShieldController.h"
#include "Powerup/Controllers/TripleLaserController.h"

namespace Powerup
{
	using namespace Global;
	using namespace Controller;
	using namespace Collectible;

	PowerupService::PowerupService()
	{

	}

	PowerupService::~PowerupService()
	{
		destroy();
	}

	void PowerupService::destroy()
	{
		for (int i = 0; i < powerup_list.size(); i++) 
			delete (powerup_list[i]);
	}

	void PowerupService::initialize()
	{

	}

	void PowerupService::update()
	{
		for (int i = 0; i < powerup_list.size(); i++) 
			powerup_list[i]->update();
	}

	void PowerupService::render()
	{
		for (int i = 0; i < powerup_list.size(); i++) 
			powerup_list[i]->render();
	}

	PowerupController* PowerupService::spawnPowerup(PowerupType type, sf::Vector2f position)
	{
		PowerupController* powerup_controller = createPowerup(type);

		powerup_controller->initialize(position);
		powerup_list.push_back(powerup_controller);

		return powerup_controller;
	}

	PowerupController* PowerupService::createPowerup(PowerupType type)
	{
		switch (type)
		{
		case PowerupType::SHIELD:
			return new ShieldController(Powerup::PowerupType::SHIELD);

		case PowerupType::RAPID_FIRE:
			return new RapidFireController(Powerup::PowerupType::RAPID_FIRE);

		case PowerupType::TRIPLE_LASER:
			return new TripleLaserController(Powerup::PowerupType::TRIPLE_LASER);

		case PowerupType::OUTSCAL_BOMB:
			return new OutscalBombController(Powerup::PowerupType::OUTSCAL_BOMB);
		}
	}

	void PowerupService::destroyPowerup(PowerupController* controller)
	{
		powerup_list.erase(std::remove(powerup_list.begin(), powerup_list.end(), controller), powerup_list.end());
		delete(controller);
	}
}