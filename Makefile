CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = eventflow

SOURCES = main.cpp \
          src/composite/EventGroup.cpp \
          src/composite/Leaves.cpp \
          src/observer/EventNotice.cpp \
          src/observer/VenueClosureNotice.cpp \
          src/observer/RoomChangeNotice.cpp \
          src/observer/CapacityUpdateNotice.cpp \
          src/observer/EmergencyAlert.cpp \
          src/observer/CapacityAlert.cpp \
          src/observer/AllergenAlert.cpp \
          src/observer/EventControl.cpp \
          src/observer/EventNotificationHandler.cpp

OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q $(OBJECTS) $(TARGET) 2>nul

.PHONY: clean