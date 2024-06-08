#pragma once

#include "Powerup/PowerupController.h"

namespace Powerup
{
	namespace Controller
	{
		class ShieldController : public PowerupController
		{
		public:
			ShieldController(PowerupType type);
			virtual ~ShieldController();

			void applyPowerup() override;
		};
	}
}