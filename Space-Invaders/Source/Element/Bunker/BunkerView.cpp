#include "Element/Bunker/BunkerView.h"
#include "Element/Bunker/BunkerController.h"

#include "Global/ServiceLocator.h"
#include "Global/Config.h"

namespace Element
{
	namespace Bunker
	{
		using namespace Global;
		using namespace UI::UIElement;

		BunkerView::BunkerView()
		{
			createUIElements();
		}

		BunkerView::~BunkerView()
		{
			destroy();
		}

		void BunkerView::createUIElements()
		{
			bunker_image = new ImageView();
		}

		void BunkerView::initialize(BunkerController* controller)
		{
			bunker_controller = controller;

			initializeImage();
		}

		void BunkerView::initializeImage()
		{
			bunker_image->initialize(Config::bunker_texture_path, bunker_sprite_width, bunker_sprite_height, bunker_controller->getBunkerPosition());
		}

		void BunkerView::update()
		{
			bunker_image->setPosition(bunker_controller->getBunkerPosition());
		}

		void BunkerView::render()
		{
			bunker_image->render();
		}

		void BunkerView::destroy()
		{
			delete(bunker_image);

			bunker_image = nullptr;
		}
	}
}