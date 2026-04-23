CXX = g++
TARGET = main.exe
SRC = $(wildcard *.cpp)
<<<<<<< HEAD

=======
# Thêm dòng này để bật chuẩn C++11
>>>>>>> 635cfd988020eefc638e2a643569a2d5e6078d18
CXXFLAGS = -std=c++11

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: all
	.\$(TARGET)

clean:
	cmd /c if exist $(TARGET) del /Q $(TARGET)