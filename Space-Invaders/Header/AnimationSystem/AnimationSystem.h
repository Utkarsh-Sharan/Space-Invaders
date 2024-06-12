#pragma once

#include "AnimationSystem/AnimationSystemConfig.h"
#include "UI/UIElement/ImageView.h"

namespace Animation
{
	class AnimationSystem
	{
	private:
		AnimationSystemConfig animation_system_config;
		sf::Vector2f animation_position;
		UI::UIElement::ImageView* animation_image;

		void createUIElements();
		void initializeImage();

		int current_frame;
		sf::Clock clock;
		sf::Time frame_time;

	public:
		AnimationSystem(AnimationSystemConfig config);
		~AnimationSystem();

		void initialize(sf::Vector2f position);
		void update();
		void render();

		void destroy();
	};
}