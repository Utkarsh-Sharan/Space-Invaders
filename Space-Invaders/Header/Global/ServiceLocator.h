#pragma once

#include "Graphic/GraphicService.h"
#include "Event/EventService.h"
#include "Player/PlayerService.h"
#include "Time/TimeService.h"
#include "UI/UIService.h"
#include "Enemy/EnemyService.h"
#include "Gameplay/GameplayService.h"
#include "Element/ElementService.h"
#include "Bullet/BulletService.h"
#include "Sound/SoundService.h"
#include "Powerup/PowerupService.h"
#include "Collision/CollisionService.h"
#include "AnimationSystem/AnimationService.h"

namespace Global
{
    class ServiceLocator
    {
    private:
        // Private Attributes:
        Graphic::GraphicService* graphic_service;
        Event::EventService* event_service;
        Player::PlayerService* player_service;
        Time::TimeService* time_service;
        UI::UIService* ui_service;
        Enemy::EnemyService* enemy_service;
        Gameplay::GameplayService* gameplay_service;
        Element::ElementService* element_service;
        Bullet::BulletService* bullet_service;
        Sound::SoundService* sound_service;
        Powerup::PowerupService* powerup_service;
        Collision::CollisionService* collision_serivce;
        Animation::AnimationService* animation_service;

        // Private Constructor and Destructor:
        ServiceLocator();
        // Constructor for initializing the ServiceLocator.
        ~ServiceLocator(); 	// Destructor for cleaning up resources upon object deletion.

        // Private Methods:
        void createServices(); 			// Creates instances of all services.
        void clearAllServices(); 		//	Deletes and deallocates memory for all services.

    public:
        // Public Methods:
        static ServiceLocator* getInstance(); 			// Provides a method to access the unique ServiceLocator instance (object).
        void initialize(); 			//	Initializes the ServiceLocator.
        void update(); 				//	Updates all services.
        void render(); 				//	Renders using the services.

        // Methods to Get Specific Services: 
        Graphic::GraphicService* getGraphicService();
        Event::EventService* getEventService();
        Player::PlayerService* getPlayerService();
        Time::TimeService* getTimeService();
        UI::UIService* getUIService();
        Enemy::EnemyService* getEnemyService();
        Gameplay::GameplayService* getGameplayService();
        Element::ElementService* getElementService();
        Bullet::BulletService* getBulletService();
        Sound::SoundService* getSoundService();
        Powerup::PowerupService* getPowerupService();
        Collision::CollisionService* getCollisionService();
        Animation::AnimationService* getAnimationService();
    };
}