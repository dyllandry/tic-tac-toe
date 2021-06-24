#ifndef TEXT_COMPONENT_SYSTEM_H
#define TEXT_COMPONENT_SYSTEM_H

#include "component.hpp"
#include "text-component.hpp"
#include <vector>
#include <SFML/Window.hpp>

class TextComponentSystem : public ComponentSystem
{
public:
	TextComponentSystem();
	void Render(sf::RenderWindow &window);

private:
	std::vector<TextComponent*> _components;
	void _handleComponentCreated(const Event& event);
	void _handleComponentDestroyed(const Event& event);
	sf::Font _defaultFont;
};

#endif // TEXT_COMPONENT_SYSTEM_H
