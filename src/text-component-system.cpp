#include "text-component.hpp"
#include "text-component-system.hpp"

using namespace std::placeholders;

TextComponentSystem::TextComponentSystem()
{
	Dispatcher::getInstance().subscribe(
		TextComponentCreated::descriptor,
		std::bind(&TextComponentSystem::_handleComponentCreated, this, _1));

	Dispatcher::getInstance().subscribe(
		TextComponentDestroyed::descriptor,
		std::bind(&TextComponentSystem::_handleComponentDestroyed, this, _1));

	_defaultFont.loadFromFile("res/FreeSans.otf");
}

void TextComponentSystem::Render(sf::RenderWindow &window)
{
	for (auto component : _components)
	{
		window.draw(component->sfmlText);
	}
}

void TextComponentSystem::_handleComponentCreated(const Event& event)
{
	const TextComponentCreated& textComponentCreated {static_cast<const TextComponentCreated&>(event)};
	TextComponent& component {textComponentCreated.component()};
	_components.push_back(&component);

	component._setDefaultFont(_defaultFont);
}

void TextComponentSystem::_handleComponentDestroyed(const Event& event)
{
	const TextComponentDestroyed& textComponentDestroyed {static_cast<const TextComponentDestroyed&>(event)};
	for (auto it = _components.begin(); it != _components.end(); ++it)
	{
		auto component = *it;
		
		if (component == &textComponentDestroyed.component())
		{
			_components.erase(it);
			return;
		}
	}
}
