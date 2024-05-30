#pragma once

#include "Enemy/EnemyController.h"

namespace Enemy
{
	namespace Controller
	{
		//Zapper will move in a zig-zag motion from top to down
		class ZapperController : public EnemyController
		{
		private:
			const float vertical_travel_distance = 100.0f;

			void move() override;
			void moveLeft();
			void moveRight();
			void moveDown();

		public:
			ZapperController(EnemyType type);
			~ZapperController();

			void initialize() override;
		};
	}
}