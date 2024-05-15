#include<iostream>
#include<SFML/Graphics.hpp>

using namespace sf;

class Player
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

    Vector2f GetPosition()
    {
        return _position;
    }

    void TakeDamage()
    {

    }

    void Movement()
    {

    }

    void ShootBullets()
    {

    }
};

int main()
{
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
            player.Movement();
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            player.Movement();
        }

        window->clear(Color::Blue); //clearing the window with color blue

        player.playerSprite.setPosition(player.GetPosition());

        window->draw(player.playerSprite);
        window->display();      //displaying objects on the window
    }

    return 0;
}