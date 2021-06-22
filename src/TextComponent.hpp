#ifndef TEXT_COMPONENT_H
#define TEXT_COMPONENT_H

#include "component.hpp"
#include <SFML/Graphics.hpp>

class TextComponent : public Component
{
public:
	sf::Text sfmlText;

	TextComponent(Id entityId) : Component(entityId)
	{
		sf::Font font;
		font.loadFromFile("res/FreeSans.otf");
		sfmlText.setFont(font);
	}

	static constexpr DescriptorType descriptor {"TextComponent"};
	virtual DescriptorType type() const { return descriptor; }
};

#endif
