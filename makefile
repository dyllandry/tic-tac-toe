LDFLAGS  := -L lib/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS := -I lib/SFML-2.5.1/include
SRCDIR   := src
OBJDIR   := bin

$(OBJDIR)/main: $(OBJDIR)/main.o $(OBJDIR)/entity.o $(OBJDIR)
	g++ -o $(OBJDIR)/main $(OBJDIR)/main.o $(OBJDIR)/entity.o $(LDFLAGS)

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

