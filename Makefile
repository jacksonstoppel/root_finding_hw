CXX := g++ # Flag for implicit rules
CXXFLAGS := -Wall -Wextra -g # Flag for implicit rules. Turn on debug info
CPPFLAGS := -MMD -MP $(shell pkg-config --cflags gsl)
LDLIBS := $(shell pkg-config --libs gsl)

# Define the target and the objects to be run unto the target
TARGET := prog
OBJECTS := main.o root_finder.o
DEPS := $(OBJECTS:.o=.d)

# Tell make that clean and all are to always be run, even if no changes are made
.PHONY: clean all 

# Create the all file. The $^ expands to all prereqs, and the $@ expands to all targets
# This should run when just typing "make" in the command line
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDLIBS)

# The % command matches all file names of the o files to the file names of the .cpp files. 
# This command should only be run if the dependants of all change
# The $< selects all prereqs and the $@ selects all targets. 
%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# The -include tell make to include any header files of my dependants. The - tell make it can skip over if none exist
-include $(DEPS)

# Cleans/deletes all .o files
clean:
	rm -f $(OBJECTS) $(DEPS) $(TARGET)