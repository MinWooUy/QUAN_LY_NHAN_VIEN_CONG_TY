CXX = g++
TARGET = main.exe
SRC = $(wildcard *.cpp)
CXXFLAGS = -std=c++11

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: all
	.\$(TARGET)

clean:
	cmd /c if exist $(TARGET) del /Q $(TARGET)