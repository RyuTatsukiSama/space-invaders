#pragma once
#include "Command.h"
#include "InputHandler.h"
#include "Spaceship.h"

constexpr float DELTA = 200.f;

class ShipCommand : public Command
{
public:
	ShipCommand(Spaceship* ship) { ship_ = ship; }

protected:
	Spaceship* ship_;
};

class MoveLeftCommand : public ShipCommand
{
public: 
	MoveLeftCommand(Spaceship* ship) : ShipCommand(ship) {}
	void execute(const float dt) { ship_->move(-DELTA*dt, 0.f); }
};

class MoveRightCommand : public ShipCommand
{
public:
	MoveRightCommand(Spaceship* ship) : ShipCommand(ship) {}
	void execute(const float dt) { ship_->move(DELTA*dt, 0.f); }
};

class OpenFireCommand : public ShipCommand
{
public:
	OpenFireCommand(Spaceship* ship) : ShipCommand(ship) {}
 	void execute(const float dt) { ship_->openFire(); }
};

class PauseCommand : public Command
{
public:
	void execute(const float dt) { ; }
};


class ShipController : public InputHandler
{
public:
	ShipController(Spaceship * ship) : ship_(ship)
	{
		registerBinding(sf::Keyboard::Escape, new PauseCommand());

		registerBinding(sf::Keyboard::Left, new MoveLeftCommand(ship));
		registerSecondaryCommand(sf::Keyboard::Left, sf::Keyboard::Space);

		registerBinding(sf::Keyboard::Right, new MoveRightCommand(ship));
		registerSecondaryCommand(sf::Keyboard::Right, sf::Keyboard::Space);

		registerBinding(sf::Keyboard::Space, new OpenFireCommand(ship));
	}

private:
	Spaceship* ship_;
};