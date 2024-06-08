#include "Bullet/BulletController.h"
#include "Bullet/BulletModel.h"
#include "Bullet/BulletView.h"
#include "Bullet/BulletConfig.h"

#include "Global/ServiceLocator.h"

#include "Player/PlayerController.h"
#include "Enemy/EnemyController.h"
#include "Element/Bunker/BunkerController.h"

namespace Bullet
{
	using namespace Global;
	using namespace Player;
	using namespace Enemy;
	using namespace Element::Bunker;

	BulletController::BulletController(BulletType type, Entity::EntityType owner_type)
	{
		bullet_model = new BulletModel(type, owner_type);
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

	void BulletController::onCollision(ICollider* other_collider)
	{
		processPlayerCollision(other_collider);
		processEnemyCollision(other_collider);
		processBunkerCollision(other_collider);
		processBulletCollision(other_collider);
	}

	void BulletController::processBulletCollision(ICollider* other_collider)
	{
		BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);

		if (bullet_controller)
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
	}

	void BulletController::processEnemyCollision(ICollider* other_collider)
	{
		EnemyController* enemy_controller = dynamic_cast<EnemyController*>(other_collider);

		if (enemy_controller && getOwnerEntityType() != Entity::EntityType::ENEMY)
		{
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	}

	void BulletController::processPlayerCollision(ICollider* other_collider)
	{
		PlayerController* player_controller = dynamic_cast<PlayerController*>(other_collider);

		if (player_controller && getOwnerEntityType() != Entity::EntityType::PLAYER)
		{
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	}

	void BulletController::processBunkerCollision(ICollider* other_collider)
	{
		BunkerController* bunker_controller = dynamic_cast<BunkerController*>(other_collider);

		if (bunker_controller)
			ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
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

	Entity::EntityType BulletController::getOwnerEntityType()
	{
		return bullet_model->getOwnerEntityType();
	}

	const sf::Sprite& BulletController::getColliderSprite()
	{
		return bullet_view->getBulletSprite();
	}
}