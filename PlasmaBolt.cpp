
#include "PlasmaBolt.h"

PlasmaBoltModel::PlasmaBoltModel(Plasma color) : velocity_(-100.f)
{
	switch (color)
	{
	case Plasma::RED:
		texture_.loadFromFile("images/fire_red.png");
		break;
	case Plasma::BLUE:
	default:
		texture_.loadFromFile("images/fire_blue.png");
		break;
	}
	texture_.setSmooth(true);
	sprite_.setTexture(texture_);
	sprite_.setTextureRect(sf::IntRect(0, 0, 16, 8));
	sprite_.setOrigin(8, 4);
}

PlasmaBolt::PlasmaBolt(const std::shared_ptr<PlasmaBoltModel>& model)
{
	model_ = model;
}

void PlasmaBolt::moveTo(float xpos, float ypos)
{
	transform_.setPosition(xpos, ypos);
}

void PlasmaBolt::move(float dx, float dy)
{
	transform_.move(dx, dy);
}

void PlasmaBolt::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*(model_->getSprite()), transform_.getTransform());
}