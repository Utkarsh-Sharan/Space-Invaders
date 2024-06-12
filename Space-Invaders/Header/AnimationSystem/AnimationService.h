#pragma once

#include "AnimationSystem/AnimationSystem.h"
#include <vector>

namespace Animation
{
	enum class AnimationType
	{
		EXPLOSION,
	};

	class AnimationService
	{
	private:
		std::vector<AnimationSystem*> animation_system_list;
		std::vector<AnimationSystem*> flagged_animation_system_list;

		AnimationSystemConfig getAnimationSystemConfig(AnimationType type);

		void destroyFlaggedAnimationSystem();
		void destroy();

	public:
		AnimationService();
		virtual ~AnimationService();

		void initialize();
		void update();
		void render();

		void reset();

		void spawnAnimationSystem(sf::Vector2f position, AnimationType type);
		void destroyAnimationSystem(AnimationSystem* animation_system);
	};
}