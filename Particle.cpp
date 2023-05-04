#include "Particle.h"
Particle::Particle(RenderTarget& target, int numPoints, Vector2i mouseClickPosition) 
	: m_A(2, numPoints)
{
	m_ttl = TTL;
	m_numPoints = numPoints;
	m_radiansPerSec = (float)rand() / PI;

	// Cartesian Plane
	m_cartesianPlane.setCenter(0, 0);
	m_cartesianPlane.setSize(target.getSize().x, (-1.0) * target.getSize().y);
	m_centerCoordinate = target.mapPixelToCoords(mouseClickPosition, m_cartesianPlane);
	
	m_vx = rand() % (MAX_VEL - MIN_VEL) + MIN_VEL;
	m_vy = rand() % (MAX_VEL - MIN_VEL) + MIN_VEL;

	Color color1 = { 255, 255, 255 };
	Uint8 r = rand() % 255;
	Uint8 g = rand() % 255;
	Uint8 b = rand() % 255;
	Color color2 = { r, g, b };

	//unfinished

}