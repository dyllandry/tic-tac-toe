LDFLAGS  := -L lib/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS := -I lib/SFML-2.5.1/include
SRCDIR   := src
OBJDIR   := bin
MAIN_OBJ_REQS := $(OBJDIR)/main.o $(OBJDIR)/entity.o $(OBJDIR)/text-component-system.o $(OBJDIR)/event.o $(OBJDIR)/main-menu.o $(OBJDIR)/input-event-dispatcher.o

$(OBJDIR)/main: $(MAIN_OBJ_REQS) $(OBJDIR)
	g++ -o $(OBJDIR)/main $(MAIN_OBJ_REQS) $(LDFLAGS)

# for each .o prerequisite specified by previous rules, expands to: 
# bin/entity.o: src/entity.cpp bin
# 	g++ -c -I lib/SFML-2.5.1/include src/entity.cpp -o bin/entity.o
# 	$< is first prerequisite
# 	$@ is the matched target
# 	% is wildcard matcher in target, and replaced with match in prerequisites and commands
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(OBJDIR)
	g++ -c $(CXXFLAGS) $< -o $@

$(OBJDIR):
	mkdir -p bin

