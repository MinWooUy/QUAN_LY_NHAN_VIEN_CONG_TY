CXX = g++
TARGET = main
SRC = *.cpp

all:
	$(CXX) $(SRC) -o $(TARGET)

run: all
	.\$(TARGET).exe

clean:
	cmd /c if exist $(TARGET).exe del /Q $(TARGET).exe