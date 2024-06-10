#include "Powerup/PowerupService.h"
#include "Powerup/PowerupController.h"
#include "Powerup/PowerupConfig.h"

#include "Powerup/Controllers/OutscalBombController.h"
#include "Powerup/Controllers/RapidFireController.h"
#include "Powerup/Controllers/ShieldController.h"
#include "Powerup/Controllers/TripleLaserController.h"

#include "Global/ServiceLocator.h"
#include "Collision/ICollider.h"

namespace Powerup
{
	using namespace Global;
	using namespace Controller;
	using namespace Collectible;
	using namespace Collision;

	PowerupService::PowerupService()
	{

	}

	PowerupService::~PowerupService()
	{
		destroy();
	}

	void PowerupService::initialize()
	{

	}

	void PowerupService::update()
	{
		for (Collectible::ICollectible* powerup : powerup_list)
			powerup->update();

		destroyFlaggedPowerup();
	}

	void PowerupService::render()
	{
		for (Collectible::ICollectible* powerup : powerup_list)
			powerup->render();
	}

	PowerupController* PowerupService::spawnPowerup(PowerupType type, sf::Vector2f position)
	{
		PowerupController* powerup_controller = createPowerup(type);

		powerup_controller->initialize(position);
		ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<ICollider*>(powerup_controller));
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

	void PowerupService::destroyFlaggedPowerup()
	{
		for (Collectible::ICollectible* powerup : flagged_powerup_list)
			delete (powerup);

		flagged_powerup_list.clear();
	}

	void PowerupService::destroyPowerup(PowerupController* controller)
	{
		ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(controller));

		flagged_powerup_list.push_back(controller);
		powerup_list.erase(std::remove(powerup_list.begin(), powerup_list.end(), controller), powerup_list.end());
	}

	void PowerupService::destroy()
	{
		for (Collectible::ICollectible* powerup : powerup_list)
			delete (powerup);
	}
}