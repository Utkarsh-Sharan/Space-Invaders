#pragma once

#include "Enemy/EnemyController.h"

namespace Enemy
{
	namespace Controller
	{
		//Thunder Snake will move downwards in a zig-zag motion
		class ThunderSnakeController : public EnemyController
		{
		private:
			const float vertical_travel_distance = 100.0f;

			void move() override;
			void moveLeft();
			void moveRight();

		public:
			ThunderSnakeController(EnemyType type);
			~ThunderSnakeController();

			void initialize() override;
		};
	}
}