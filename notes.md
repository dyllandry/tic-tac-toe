# Todo 

Start trying to primarily use Jira Board: <https://dyllandry.atlassian.net/jira/software/projects/TTT/boards/1>

- [ ] makefile improvements
	- [ ] learn solution that doesn't require me to add each file manually
	- [ ] double check that files that don't need recompilation aren't being recompiled

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

