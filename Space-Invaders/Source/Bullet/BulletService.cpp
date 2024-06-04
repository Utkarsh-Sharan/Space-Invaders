#include "Bullet/BulletService.h"
#include "Bullet/BulletController.h"
#include "Bullet/BulletConfig.h"
#include "Bullet/Controllers/FrostBulletController.h"
#include "Bullet/Controllers/LaserBulletController.h"
#include "Bullet/Controllers/TorpedoController.h"

namespace Bullet
{
	using namespace Controller;
	using namespace Projectile;

	BulletService::BulletService()
	{

	}

	BulletService::~BulletService()
	{
		destroy();
	}

	void BulletService::initialize()
	{

	}

	void BulletService::update()
	{
		for (int i = 0; i < bullet_list.size(); i++)
			bullet_list[i]->update();
	}

	void BulletService::render()
	{
		for (int i = 0; i < bullet_list.size(); i++)
			bullet_list[i]->render();
	}

	BulletController* BulletService::createBullet(BulletType bullet_type)
	{
		switch (bullet_type)
		{
		case BulletType::LASER_BULLET:
			return new LaserBulletController(BulletType::LASER_BULLET);

		case BulletType::TORPEDO:
			return new LaserBulletController(BulletType::TORPEDO);

		case BulletType::FROST_BULLET:
			return new LaserBulletController(BulletType::FROST_BULLET);
		}
	}

	void BulletService::destroy()
	{
		for (int i = 0; i < bullet_list.size(); i++) 
			delete(bullet_list[i]);
	}

	BulletController* BulletService::spawnBullet(BulletType bullet_type, sf::Vector2f position, MovementDirection direction)
	{
		BulletController* bullet_controller = createBullet(bullet_type);

		bullet_controller->initialize(position, direction);
		bullet_list.push_back(bullet_controller);

		return bullet_controller;
	}

	void BulletService::destroyBullet(BulletController* bullet_controller)
	{
		bullet_list.erase(std::remove(bullet_list.begin(), bullet_list.end(), bullet_controller), bullet_list.end());
		delete(bullet_controller);
	}
}