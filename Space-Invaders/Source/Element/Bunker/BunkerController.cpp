#include "Element/Bunker/BunkerController.h"
#include "Element/Bunker/BunkerView.h"

namespace Element
{
	namespace Bunker
	{
		BunkerController::BunkerController()
		{
			bunker_view = new BunkerView();
		}

		BunkerController::~BunkerController()
		{
			delete(bunker_view);

			bunker_view = nullptr;
		}

		void Element::Bunker::BunkerController::initialize(BunkerData data)
		{
			bunker_data = data;
			bunker_view->initialize(this);
		}

		void Element::Bunker::BunkerController::update()
		{
			bunker_view->update();
		}

		void Element::Bunker::BunkerController::render()
		{
			bunker_view->render();
		}

		sf::Vector2f Element::Bunker::BunkerController::getBunkerPosition()
		{
			return bunker_data.position;
		}
	}
}
