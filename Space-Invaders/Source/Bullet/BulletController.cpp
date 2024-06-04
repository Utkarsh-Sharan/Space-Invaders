#include "Bullet/BulletController.h"
#include "Bullet/BulletModel.h"
#include "Bullet/BulletView.h"
#include "Bullet/BulletConfig.h"

#include "Global/ServiceLocator.h"

namespace Bullet
{
	using namespace Global;

	BulletController::BulletController(BulletType type)
	{
		bullet_model = new BulletModel(type);
		bullet_view = new BulletView();
	}

	BulletController::~BulletController()
	{
		delete(bullet_view);
		delete(bullet_model);

		bullet_view = nullptr;
		bullet_model = nullptr;
	}

	void BulletController::initialize(sf::Vector2f position, Bullet::MovementDirection direction)
	{
		bullet_view->initialize(this);
		bullet_model->initialize(position, direction);
	}

	void BulletController::update()
	{
		updateProjectilePosition();
		bullet_view->update();
		handleOutOfBounds();
	}

	void BulletController::render()
	{
		bullet_view->render();
	}

	void BulletController::updateProjectilePosition()
	{
		switch (bullet_model->getMovementDirection())
		{
		case MovementDirection::UP:
			moveUp();
			break;

		case MovementDirection::DOWN:
			moveDown();
			break;
		}
	}

	void BulletController::moveUp()
	{
		sf::Vector2f currentPosition = bullet_model->getBulletPosition();
		currentPosition.y -= bullet_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		bullet_model->setBulletPosition(currentPosition);
	}

	void BulletController::moveDown()
	{
		sf::Vector2f currentPosition = bullet_model->getBulletPosition();
		currentPosition.y += bullet_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		bullet_model->setBulletPosition(currentPosition);
	}

	void BulletController::handleOutOfBounds()
	{
		sf::Vector2f bullet_position = getProjectilePosition();
		sf::Vector2u window_size = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		if (bullet_position.x < 0 || bullet_position.x > window_size.x || bullet_position.y < 0 || bullet_position.y > window_size.y)
		{
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	}

	sf::Vector2f BulletController::getProjectilePosition()
	{
		return bullet_model->getBulletPosition();
	}

	BulletType BulletController::getBulletType()
	{
		return bullet_model->getBulletType();
	}
}