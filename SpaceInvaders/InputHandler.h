#pragma once

#include <unordered_map>

#include "SFML/Window.hpp"

#include "Command.h"

class voidCommand : public Command
{
	void execute(const float dt) {};
};

class InputHandler
{
public:

	virtual ~InputHandler() {};

	virtual Command * handleInput();
	void registerBinding(sf::Keyboard::Key key, Command* command);
	void registerSecondaryCommand(sf::Keyboard::Key key, sf::Keyboard::Key secondaryKey);
	void swapBinding(sf::Keyboard::Key old_key, sf::Keyboard::Key new_key);

	virtual CombinedCommand* createCombinedCommand(Command* cmd1, Command* cmd2)
	{
		return new CombinedCommand(cmd1, cmd2);
	}

protected:
	std::unordered_map < sf::Keyboard::Key, Command* > command_bindings_;
	std::unordered_map < sf::Keyboard::Key, sf::Keyboard::Key > secondary_commands_;
	voidCommand void_cmd;
};
