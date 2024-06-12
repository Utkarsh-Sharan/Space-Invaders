#include "AnimationSystem/AnimationSystem.h"

#include "Global/Config.h"
#include "Global/ServiceLocator.h"

namespace Animation
{
	using namespace Global;
	using namespace UI::UIElement;

	AnimationSystem::AnimationSystem(AnimationSystemConfig config)
	{
		animation_system_config = config;
		createUIElements();
	}

	AnimationSystem::~AnimationSystem()
	{
		delete(animation_image);

		animation_image = nullptr;
	}

	void AnimationSystem::createUIElements()
	{
		animation_image = new ImageView();
	}

	void AnimationSystem::initialize(sf::Vector2f position) //set the pos, initial frame, and frame time to the duration we set.
	{
		animation_position = position;
		current_frame = 0;
		frame_time = sf::seconds(animation_system_config.frame_duration);

		initializeImage();
	}

	void AnimationSystem::initializeImage() //initialize the the image object, set the texture rect, and then the scale.
	{
		animation_image->initialize(Config::explosion_texture_path, 0, 0, animation_position);
		animation_image->setTextureRect(sf::IntRect(0, 0, animation_system_config.tile_width, animation_system_config.tile_height));

		animation_image->setScale(animation_system_config.sprite_sheet_width, animation_system_config.sprite_sheet_height, 
			animation_system_config.tile_width, animation_system_config.tile_height);
	}

	void AnimationSystem::update()
	{
		if (clock.getElapsedTime() >= frame_time)
		{
			if (current_frame + 1 >= animation_system_config.number_of_animation_frames)
				destroy();

			current_frame = (current_frame + 1) % animation_system_config.number_of_animation_frames;
			clock.restart();

			animation_image->setTextureRect(sf::IntRect
			(
				current_frame * animation_system_config.tile_width,
				0,
				animation_system_config.tile_width,
				animation_system_config.tile_height)
			);
		}
		animation_image->update();
	}

	void AnimationSystem::render()
	{
		animation_image->render();
	}

	void AnimationSystem::destroy()
	{
		ServiceLocator::getInstance()->getAnimationService()->destroyAnimationSystem(this);
	}
}