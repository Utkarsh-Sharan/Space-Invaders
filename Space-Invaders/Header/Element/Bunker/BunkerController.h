#pragma once

#include "Element/Bunker/BunkerModel.h"
#include "Element/Bunker/BunkerView.h"

#include <SFML/Graphics.hpp>

namespace Element
{
	//class BunkerView;

	namespace Bunker
	{
		class BunkerController
		{
		private:
			BunkerView* bunker_view;
			BunkerData bunker_data;

		public:
			BunkerController();
			~BunkerController();

			void initialize(BunkerData data);
			void update();
			void render();

			sf::Vector2f getBunkerPosition();
		};
	}
}