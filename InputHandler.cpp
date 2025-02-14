#include "InputHandler.h"

Command * InputHandler::handleInput()
{
	for (auto command_binding : command_bindings_)
	{
		if (sf::Keyboard::isKeyPressed(command_binding.first))
		{
			auto secondary_cmd = secondary_commands_.find(command_binding.first);
			if (secondary_cmd != secondary_commands_.end())
			{
				sf::Keyboard::Key secondary_key = secondary_cmd->second; 
				if (sf::Keyboard::isKeyPressed(secondary_key))
				{
					auto secondary_binding = command_bindings_.find(secondary_key);
					if (secondary_binding != command_bindings_.end())
					{
						return new CombinedCommand(command_binding.second, secondary_binding->second);
					}
				}
			}
			return command_binding.second;
		}
	}
	return &void_cmd;
}

void InputHandler::registerBinding(sf::Keyboard::Key key, Command* command)
{
	command_bindings_[key] = command;
}

void InputHandler::registerSecondaryCommand(sf::Keyboard::Key key, sf::Keyboard::Key secondaryKey)
{
	secondary_commands_[key] = secondaryKey;
}

void InputHandler::swapBinding(sf::Keyboard::Key old_key, sf::Keyboard::Key new_key)
{
	auto old_binding = command_bindings_.find(old_key);
	if (old_binding != command_bindings_.end())
	{
		command_bindings_[new_key] = command_bindings_[old_key];
		command_bindings_.erase(old_binding);
	}
}