#include<iostream>
#include<SFML/Graphics.hpp>
#include "Main/GameService.h"

using namespace sf;
using namespace Main;

/*class Player
{
private:
    int _health = 3;
    int _playerScore = 0;
    int _movementSpeed = 5;
    Vector2f _position = Vector2f(200.0f, 100.0f);

public:
    Texture playerTexture;
    Sprite playerSprite;

    int GetScore()
    {
        return _playerScore;
    }

    void SetScore(int newScore)
    {
        _playerScore = newScore;
    }

    int GetMovementSpeed()
    {
        return _movementSpeed;
    }

    Vector2f GetPosition()
    {
        return _position;
    }

    void TakeDamage()
    {

    }

    void Movement(float offset)
    {
        _position.x += offset;
    }

    void ShootBullets()
    {

    }
};*/

int main()
{/*
    //defining dimensions of video mode
    VideoMode videoMode = *(new VideoMode(800, 600));

    //rendering window of specified size
    RenderWindow* window = new RenderWindow(videoMode, "My SFML Window!");

    Player player;

    player.playerTexture.loadFromFile("assets/textures/player_ship.png");
    player.playerSprite.setTexture(player.playerTexture);

    //Game loop to keep window open
    while(window->isOpen()) 
    {
        Event event;
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)    //checking if window closed
            {
                window->close();
            }
        }

        //handling player movement here
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            player.Movement(-1.0f * player.GetMovementSpeed());
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            player.Movement(1.0f * player.GetMovementSpeed());
        }

        window->clear(Color::Blue); //clearing the window with color blue

        player.playerSprite.setPosition(player.GetPosition());

        window->draw(player.playerSprite);
        window->display();      //displaying objects on the window
    }*/

    GameService* game_service = new GameService();

    game_service->ignite();

    while (game_service->isRunning())
    {
        game_service->update();
        game_service->render();
    }

    return 0;
}