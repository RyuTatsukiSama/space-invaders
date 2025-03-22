#pragma once

#include "SFML/Graphics.hpp"

enum class Plasma
{
	RED = 0, 
	BLUE,
	MODEL_COUNT
};

class PlasmaBoltModel
{
public:
	PlasmaBoltModel(Plasma color);
	const sf::Sprite* getSprite() const { return &sprite_; }
	float getVelocity() const { return velocity_; }

private:
	float velocity_;

	sf::Texture texture_;
	sf::Sprite sprite_;
};

class PlasmaBolt : public sf::Drawable
{
public:
	PlasmaBolt(const std::shared_ptr<PlasmaBoltModel>& model);

	float getVelocity() const { return model_->getVelocity(); }

	void moveTo(float xpos, float ypos);
	void move(float dx, float dy);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	bool isActive() const { return is_active_; }

private:
	bool is_active_;
	sf::Transformable transform_;
	std::shared_ptr<PlasmaBoltModel> model_;
};