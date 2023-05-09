#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
using namespace std;
using namespace sf;

Engine::Engine()
{
	float desktopWidth = VideoMode::getDesktopMode().width;
	float desktopHeight = VideoMode::getDesktopMode().height;
	VideoMode vm(desktopWidth, desktopHeight);
	m_Window.create(vm, "Particles", Style::Default);
}

void Engine::run()
{
	Clock clock;

	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
	p.unitTests();
	cout << "Unit tests complete.  Starting engine..." << endl;

	while (m_Window.isOpen())
	{
		// return time elapsed since last frame
		Time dt = clock.restart();

		input();
		update(dt.asSeconds());
		draw();
	}
}

void Engine::input()
{
	sf::Event event;

	if (m_Window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			m_Window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			m_Window.close();
		}

		if (event.type == Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == Mouse::Left)
			{
				for (int i = 0; i < 5; i++)
				{
					int numPoints = rand() % (50 - 25) + 25;
					Vector2i clickPos = sf::Mouse::getPosition(m_Window);
					Particle p(m_Window, numPoints, clickPos);
					m_particles.push_back(p);
				}
			}
		}
	}
}

void Engine::update(float dtAsSeconds)
{
	auto iter = m_particles.begin();
	while (iter != m_particles.end())
	{
		if (iter->getTTL() > 0.0)
		{
			iter->update(dtAsSeconds);
			iter++;
		}
		else
		{
			iter = m_particles.erase(iter);
		}
	}
}

void Engine::draw()
{
	m_Window.clear();
	for (int i = 0; i < m_particles.size(); i++)
	{
		m_Window.draw(m_particles[i]);
	}
	m_Window.display();
}