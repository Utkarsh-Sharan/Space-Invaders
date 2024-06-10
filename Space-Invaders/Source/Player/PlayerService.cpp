#include "Player/PlayerService.h"
#include "Global/ServiceLocator.h"
#include "Collision/ICollider.h"
#include "Player/PlayerController.h"

namespace Player
{
	using namespace Global;
	using namespace Collision;

	PlayerService::PlayerService()
	{
		player_controller = new PlayerController();
	}

	PlayerService::~PlayerService()
	{
		ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(player_controller));
		delete(player_controller);

		player_controller = nullptr;
	}

	void PlayerService::initialize()
	{
		player_controller->initialize();
		ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<ICollider*>(player_controller));
	}

	void PlayerService::update()
	{
		player_controller->update();
	}

	void PlayerService::render()
	{
		player_controller->render();
	}

	void PlayerService::enableShield()
	{
		player_controller->enableShield();
	}

	void PlayerService::enableRapidFire()
	{
		player_controller->enableRapidFire();
	}

	void PlayerService::enableTripleLaser()
	{
		player_controller->enableTripleLaser();
	}

	void PlayerService::increaseEnemiesKilled(int val)
	{
		player_controller->increaseEnemiesKilled(val);
	}

	void PlayerService::reset()
	{
		player_controller->reset();
	}
}