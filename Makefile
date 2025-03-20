# Variables
CXX = g++
CXXFLAGS = -std=c++11 -I/usr/include/opencv4 -I/usr/include/x86_64-linux-gnu/Qt5Widgets -I/usr/include/x86_64-linux-gnu/Qt5Core
LDFLAGS = -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc -lQt5Widgets -lQt5Core
SOURCES = main.cpp image_model.cpp
HEADERS = image_model.hpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = image_viewer

# Règle par défaut
all: $(TARGET)

# Compilation
$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compilation des fichiers objets
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -f $(OBJECTS) $(TARGET)