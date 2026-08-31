CXX = g++

CXXFLAGS = -std=c++11 -Wall -Wextra -Isrc -Isrc/composite -Isrc/event -Isrc/observer

TARGET = eventflow

SOURCES = \
	main.cpp \
	src/composite/EventGroup.cpp \
	src/composite/Leaves.cpp \
	src/event/Visitor.cpp \
	src/observer/EventNotice.cpp \
	src/observer/EventControl.cpp \
	src/observer/EventNotificationHandler.cpp \
	src/observer/EmergencyAlert.cpp \
	src/observer/CapacityAlert.cpp \
	src/observer/AllergenAlert.cpp \
	src/observer/RoomChangeNotice.cpp \
	src/observer/DepartmentMismatch.cpp \
	src/observer/CapacityUpdateNotice.cpp \
	src/observer/VenueClosureNotice.cpp

OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q $(subst /,\,$(OBJECTS)) $(TARGET).exe 2>nul || exit 0

.PHONY: clean