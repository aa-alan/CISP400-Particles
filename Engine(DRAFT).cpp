#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
using namespace std;
using namespace sf;

Engine()
{
	float desktopWidth = VideoMode::getDesktopMode().width;
	float desktopHeight = VideoMode::getDesktopMode().height;
	m_window.create(VideoMode(desktopWidth, desktopHeight));
}

run()
{
	Clock clock;

	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
	p.unitTests();
	cout << "Unit tests complete.  Starting engine..." << endl;

	while (m_Window.isOpen())
	{
		// return time elapsed since last frame
		Time elapsed = clock.getElapsedTime();
		return elapsed.asSeconds();
		clock.restart();
		window.input();
		window.run();
		window.update();
		window.draw();
	}
}

input()
{
	//int particleCount = 0;
	if (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		if (event.type == Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == Mouse::Left)
			{
				/*while (particleCount < 5)
				{

				}
				*/
			}
		}
	}
}