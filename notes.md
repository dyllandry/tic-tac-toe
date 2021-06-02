# Todo

- [x] add makefile for building src/main.cpp into /bin directory
	- [x] compile & link main.cpp
	- [x] build main.cpp into /bin
	- [x] build src/main.cpp into /bin
	- [x] create bin directory if it doesn't exist @done(2021-06-02)
	- <https://makefiletutorial.com/>

- Events
	- [x] Event
	- [x] Dispatcher
	- [x] review code for any parts I don't understand
		- [x] what an r value and r value reference is
		- [x] why does std::bind and std::function used for callbacks?
			- We use std::bind just to create a member function pointer to DemoObserver handle function
	- <https://bastian.rieck.ru/blog/posts/2015/event_system_cxx11/>

- Git
	- [x] create repo
	- [x] push to master

- neovim
	- Considering neovim can crash and delete my open file, I don't want that to happen.
	- [ ] Look into backup system for neovim, like keeping last several saved versions of any edited file.

- Basic Entity
	- First, skim through what's out there to see what usually makes up an entity.
		- If I eventually just want to do an ID and method for adding components, fine.
		- But at least at first we would have been exposed to what others are doing.
	- [ ] Entity
	- [ ] EntityManager

- Basic rendering ecs
	- should I start with a simpler component other than graphics?
	- Remember Jasson said some components are simple and can just be data.
	- Remember Jasson had a SystemManager to run update on all the Systems
		- And I think the EntityManager called update on the SystemManager
	- [ ] RenderComponent
	- [ ] RenderTextComponent
	- [ ] RenderTextComponentSystem

- [ ] makefile improvements
	- [ ] use path variables instead of typing src/ and bin/

# Scratch Notes

I've got a Tic-Tac-Toe game.

The game is turn based, things don't happen unless the user provides input.

Input:

- Keys 1-9 pick which square to play on
- Up and down arrows and Enter to select a number of rounds

Capabilities:

- Render text
- Keyboard input
- Menu navigation
- Swapping between the Tic-Tac-Toe game and the menu
- Computer AI
- Tic-Tac-Toe logic
- Render X & O's
- Render Tic-Tac-Toe grid

Entites:

Just ids, they are the interface for adding components at runtime.

Components:

- RenderComponent: Provides interface `virtual void Render() = 0;`.
	- RenderTextComponent
	- RenderXOComponent
	- RenderGridComponent
- InputComponent: Provides function pointers that get called on inputs `public: void (*OnEnterPress)()`

System:

Systems contain the actual components for each entity, provide a function for returning these components, and interate components so they can each get updated.

- ComponentManager: Provides interface ???
	- RenderTextComponentManager
	- RenderXOComponentManager
	- RenderGridComponentManager

- Menu entity creates multiple entities for menu items, giving each MenuItem a InputComponent with void (*OnEnterPress)() set to a different action (start game w/ 1 round, 2 rounds, 3 rounds)

Other:

- Entity `class Entity & int id`
- Event `base class Event & class Dispatcher`<https://bastian.rieck.ru/blog/posts/2015/event_system_cxx11/>
	- idk how to make dispatcher available to both RenderSystem (for subscribing) & RenderComponent (for posting)

