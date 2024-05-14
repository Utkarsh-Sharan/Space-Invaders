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

        window->clear(Color::Black); //clearing the window with color blue

        //drawing a circle
        CircleShape circle(50);
        circle.setFillColor(Color::Green);
        circle.setPosition(300, 300);
        window->draw(circle);

        //drawing a square
        RectangleShape rectangle;
        rectangle.setSize(Vector2f(100, 100));
        rectangle.setFillColor(Color::Red);
        rectangle.setPosition(100, 100);
        window->draw(rectangle);

        //drawing a triangle
        ConvexShape triangle;
        triangle.setPointCount(3);
        triangle.setPoint(0, Vector2f(500, 100));
        triangle.setPoint(1, Vector2f(450, 200));
        triangle.setPoint(2, Vector2f(550, 200));
        triangle.setFillColor(Color::Blue);
        window->draw(triangle);

        //rendering image and text
        Texture outscalTexture;
        outscalTexture.loadFromFile("assets/textures/outscal_logo.png");

        Sprite outscalSprite;
        outscalSprite.setTexture(outscalTexture);

        outscalSprite.setPosition(200, 350);
        outscalSprite.setRotation(45);
        outscalSprite.setScale(0.4, 0.4);

        window->draw(outscalSprite);

        //now the text
        Font font;
        font.loadFromFile("assets/fonts/DS_DIGIB.TTF");
        Text text("SFML is awesome.", font, 30);
        text.setFillColor(Color::White);
        window->draw(text);

        window->display();      //displaying objects on the window
    }

    return 0;
}