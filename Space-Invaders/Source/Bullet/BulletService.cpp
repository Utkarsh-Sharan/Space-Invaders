#include "Bullet/BulletService.h"
#include "Bullet/BulletController.h"
#include "Bullet/BulletConfig.h"

#include "Bullet/Controllers/FrostBulletController.h"
#include "Bullet/Controllers/LaserBulletController.h"
#include "Bullet/Controllers/TorpedoController.h"

#include "Collision/ICollider.h"
#include "Global/ServiceLocator.h"

namespace Bullet
{
	using namespace Controller;
	using namespace Projectile;
	using namespace Global;
	using namespace Collision;

	BulletService::BulletService()
	{

	}

	BulletService::~BulletService()
	{
		destroy();
	}

	void BulletService::initialize()
	{
		bullet_list.clear();
		flagged_bullet_list.clear();
	}

	void BulletService::update()
	{
		for (int i = 0; i < bullet_list.size(); i++)
			bullet_list[i]->update();

		destroyFlaggedBullets();
	}

	void BulletService::render()
	{
		for (int i = 0; i < bullet_list.size(); i++)
			bullet_list[i]->render();
	}

	BulletController* BulletService::spawnBullet(BulletType bullet_type, Entity::EntityType owner_type, sf::Vector2f position, MovementDirection direction)
	{
		BulletController* bullet_controller = createBullet(bullet_type, owner_type);

		bullet_controller->initialize(position, direction);
		bullet_list.push_back(bullet_controller);

		return bullet_controller;
	}

	BulletController* BulletService::createBullet(BulletType bullet_type, Entity::EntityType owner_type)
	{
		switch (bullet_type)
		{
		case BulletType::LASER_BULLET:
			return new LaserBulletController(BulletType::LASER_BULLET, owner_type);

		case BulletType::TORPEDO:
			return new TorpedoController(BulletType::TORPEDO, owner_type);

		case BulletType::FROST_BULLET:
			return new FrostBulletController(BulletType::FROST_BULLET, owner_type);
		}
	}

	void BulletService::destroyFlaggedBullets()
	{
		for (int i = 0; i < flagged_bullet_list.size(); i++)
		{
			if (!isValidBullet(i, flagged_bullet_list))
				continue;

			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(flagged_bullet_list[i]));
			delete (flagged_bullet_list[i]);
		}

		flagged_bullet_list.clear();
	}

	bool BulletService::isValidBullet(int index, std::vector<Projectile::IProjectile*>& bullet_list)
	{
		return index >= 0 && index < bullet_list.size() && bullet_list[index] != nullptr;
	}

	void BulletService::destroy()
	{
		for (int i = 0; i < bullet_list.size(); i++)
		{
			if (!isValidBullet(i, bullet_list)) 
				continue;

			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(bullet_list[i]));
			delete (bullet_list[i]);
		}

		bullet_list.clear();
	}

	void BulletService::destroyBullet(BulletController* bullet_controller)
	{
		if (std::find(flagged_bullet_list.begin(), flagged_bullet_list.end(), bullet_controller) == flagged_bullet_list.end())
		{
			flagged_bullet_list.push_back(bullet_controller);
			bullet_list.erase(std::remove(bullet_list.begin(), bullet_list.end(), bullet_controller), bullet_list.end());
		}
	}

	void BulletService::reset()
	{
		destroy();
	}
}