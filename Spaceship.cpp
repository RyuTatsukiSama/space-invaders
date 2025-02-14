#include "Spaceship.h"

Spaceship::Spaceship(EnergyBoltPool * pool) : bolt_pool_(pool)
{
	transform_.setPosition(1000, 500);
	w_ = h_ = 40;

	texture_.loadFromFile("images/spaceship.png");
	texture_.setSmooth(true);
	sprite_.setTexture(texture_);
	sprite_.setTextureRect(sf::IntRect(40, 0, w_, h_));
	sprite_.setOrigin(w_ / 2, h_ / 2);
}

Spaceship::~Spaceship()
{
}

void Spaceship::openFire()
{
	PlasmaBolt* bolt = bolt_pool_->createBolt(Plasma::BLUE);
	if (bolt)
		bolt->moveTo(transform_.getPosition().x-w_/4, transform_.getPosition().y - h_/2);
}

void Spaceship::moveTo(float xpos, float ypos)
{
	transform_.setPosition(xpos, ypos);
}

void Spaceship::move(float dx, float dy)
{
	transform_.move(dx, dy);
}

void Spaceship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite_, transform_.getTransform());
}
