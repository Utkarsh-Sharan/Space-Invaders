#pragma once

#include "Enemy/EnemyController.h"

namespace Enemy
{
	namespace Controller
	{
		//Sub Zero will only have vertical movement and can fire frozen bullets to stop player form moving for a short period of time.
		class SubZeroController: public EnemyController
		{
		private:
			const float movement_speed = 100.0f;
			const float subzero_rate_of_fire = 2.0f;

			void move() override;
			void moveDown();

			void fireBullet() override;

		public:
			SubZeroController(EnemyType type);
			~SubZeroController();

			void initialize() override;
		};
	}
}