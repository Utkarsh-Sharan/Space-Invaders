#include<SFML/Graphics.hpp>
using namespace sf;

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

        window->clear(Color::Red); //clearing the window with color blue

        window->display();      //displaying objects on the window
    }

    return 0;
}