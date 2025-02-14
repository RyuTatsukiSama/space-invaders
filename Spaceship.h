#pragma once

#include "SFML/Graphics.hpp"
#include "EnergyBoltPool.h"

class Spaceship : public sf::Drawable
{
public:
	Spaceship(EnergyBoltPool * pool);
	~Spaceship();

	void openFire();

	void moveTo(float xpos, float ypos);
	void move(float dx, float dy);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	float w_, h_;
	
	sf::Transformable transform_;

	sf::Texture texture_;
	sf::Sprite sprite_;

	EnergyBoltPool* bolt_pool_;
};
