#pragma once

#include "AnimationSystemConfig.h"
#include "Global/Config.h"

namespace Animation
{
	//a const object of the struct with the needed arguments
	const AnimationSystemConfig explosion_animation_config(Global::Config::explosion_texture_path, 70.0f, 80.0f, 14.28f, 20.0f, 7, 0.03f);
}