#pragma once

#include "Enemy/EnemyController.h"

namespace Enemy
{
	namespace Controller
	{
		//Zapper will move in a left-down-right (repeat) motion from top to down
		class ZapperController : public EnemyController
		{
		private:
			const float vertical_travel_distance = 100.0f;
			const float zapper_rate_of_fire = 2.0f;

			void move() override;
			void moveLeft();
			void moveRight();
			void moveDown();

			void fireBullet() override;

		public:
			ZapperController(EnemyType type);
			~ZapperController();

			void initialize() override;
		};
	}
}