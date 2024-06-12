#include "AnimationSystem/AnimationService.h"
#include "AnimationSystem/AnimationSystemConfigData.h"

namespace Animation
{
	AnimationService::AnimationService()
	{

	}

	AnimationService::~AnimationService()
	{
		destroy();
	}

	void AnimationService::initialize()
	{

	}

	void AnimationService::update()
	{
		for (AnimationSystem* animation_system : animation_system_list)
			animation_system->update();

		destroyFlaggedAnimationSystem();
	}

	void AnimationService::render()
	{
		for (AnimationSystem* animation_system : animation_system_list)
			animation_system->render();
	}

	void AnimationService::spawnAnimationSystem(sf::Vector2f position, AnimationType type)
	{
		AnimationSystem* animation_system = new AnimationSystem(getAnimationSystemConfig(type));

		animation_system->initialize(position);
		animation_system_list.push_back(animation_system);
	}

	AnimationSystemConfig AnimationService::getAnimationSystemConfig(AnimationType type)
	{
		switch (type)
		{
		case AnimationType::EXPLOSION:
			return explosion_animation_config;
		}
	}

	void AnimationService::destroyAnimationSystem(AnimationSystem* animation_system)
	{
		flagged_animation_system_list.push_back(animation_system);
		animation_system_list.erase(std::remove(animation_system_list.begin(), animation_system_list.end(), animation_system), animation_system_list.end());
	}

	void AnimationService::destroyFlaggedAnimationSystem()
	{
		for (AnimationSystem* particle_system : flagged_animation_system_list)
			delete (particle_system);

		flagged_animation_system_list.clear();
	}

	void AnimationService::destroy()
	{
		for (AnimationSystem* animation_system : animation_system_list)
			delete (animation_system);
	}

	void AnimationService::reset()
	{
		destroy();
	}
}