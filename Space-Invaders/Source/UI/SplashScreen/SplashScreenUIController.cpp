#include "UI/SplashScreen/SplashScreenUIController.h"
#include "Main/GameService.h"
#include "Global/ServiceLocator.h"
#include "Graphic/GraphicService.h"
#include "Sound/SoundService.h"
#include "Global/Config.h"

namespace UI
{
	namespace SplashScreen
	{
		using namespace Main;
		using namespace Graphic;
		using namespace UIElement;
		using namespace Sound;

		SplashScreenUIController::SplashScreenUIController()
		{
			outscal_logo_view = new AnimatedImageView();
		}

		SplashScreenUIController::~SplashScreenUIController()
		{
			delete (outscal_logo_view);

			outscal_logo_view = nullptr;
		}

		void SplashScreenUIController::initialize()
		{
			initializeOutscalLogo();
		}

		void SplashScreenUIController::initializeOutscalLogo()
		{
			sf::Vector2f position = getLogoPosition();
			outscal_logo_view->initialize(Global::Config::outscal_logo_texture_path, logo_width, logo_height, position);
		}

		sf::Vector2f SplashScreenUIController::getLogoPosition()
		{
			sf::RenderWindow* game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			float x_position = (game_window->getSize().x - logo_width) / 2.0f;
			float y_position = (game_window->getSize().y - logo_height) / 2.0f;

			return sf::Vector2f(x_position, y_position);
		}

		void SplashScreenUIController::update()
		{
			outscal_logo_view->update();
		}

		void SplashScreenUIController::fadeInAnimationCallback()
		{
			outscal_logo_view->playAnimation(AnimationType::FADE_OUT, splash_screen_duration, std::bind(&SplashScreenUIController::fadeOutAnimationCallback, this));
		}

		void SplashScreenUIController::fadeOutAnimationCallback()
		{
			Global::ServiceLocator::getInstance()->getSoundService()->playBackgroundMusic();
			GameService::setGameState(GameState::MAIN_MENU);
		}

		void SplashScreenUIController::render()
		{
			outscal_logo_view->render();
		}

		void SplashScreenUIController::show()
		{
			outscal_logo_view->playAnimation(AnimationType::FADE_IN, splash_screen_duration, std::bind(&SplashScreenUIController::fadeInAnimationCallback, this));
		}
	}
}