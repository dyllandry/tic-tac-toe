#ifndef TEXT_COMPONENT_H
#define TEXT_COMPONENT_H

#include "component.hpp"
#include "event.hpp"
#include <SFML/Graphics.hpp>

// Forward declarations
class TextComponent;
class TextComponentSystem;

class TextComponentCreated : public Event
{
public:
	TextComponentCreated(TextComponent &component) : _component{component} {}
	TextComponent& component() const { return _component; }

	using DescriptorType = const char*;
	static constexpr DescriptorType descriptor { "TextComponentCreated" };
	virtual DescriptorType type() const { return descriptor; }

private:
	TextComponent &_component;
};

class TextComponentDestroyed : public Event
{
public:
	TextComponentDestroyed(TextComponent &component) : _component{component} {}
	TextComponent& component() const { return _component; }

	using DescriptorType = const char*;
	static constexpr DescriptorType descriptor { "TextComponentDestroyed" };
	virtual DescriptorType type() const { return descriptor; }

private:
	TextComponent &_component;
};

class TextComponent : public Component
{
public:
	sf::Text sfmlText;

	TextComponent(Id entityId) : Component(entityId)
	{
		TextComponentCreated createdEvent(*this);
		Dispatcher::getInstance().post(createdEvent);
	}

	virtual ~TextComponent()
	{
		TextComponentDestroyed destroyedEvent(*this);
		Dispatcher::getInstance().post(destroyedEvent);
	}

	static constexpr DescriptorType descriptor {"TextComponent"};
	virtual DescriptorType type() const { return descriptor; }
private:
	friend TextComponentSystem;
	void _setDefaultFont(sf::Font &font) { sfmlText.setFont(font); }
};

#endif
