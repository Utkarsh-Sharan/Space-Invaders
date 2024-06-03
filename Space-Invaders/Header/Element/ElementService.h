#pragma once

#include<SFML/Graphics.hpp>

namespace Element
{
	class ElementService
	{
	public:
		ElementService();
		~ElementService();

		void initialize();
		void update();
		void render();
	};
}