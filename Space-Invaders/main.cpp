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
    Texture _playerTexture;
    Sprite _playerSprite;

    int GetScore()
    {
        return _playerScore;
    }

    void SetScore(int newScore)
    {
        _playerScore = newScore;
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

        window->clear(Color::Blue); //clearing the window with color blue

        

        window->display();      //displaying objects on the window
    }

    return 0;
}