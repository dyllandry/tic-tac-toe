#include "entity.hpp"
#include "TextComponent.hpp"
#include <iostream>

int main()
{
	Entity *entity = new Entity();

	auto& textComponent {entity->addComponent<TextComponent>()};
	textComponent.sfmlText.setString("Tic-Tac-Toe");

	std::cout << "Hello world." << std::endl;
	return 0;
}
