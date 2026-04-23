CXX = g++
TARGET = main.exe
SRC = $(wildcard *.cpp)
# Thêm dòng này để bật chuẩn C++11
CXXFLAGS = -std=c++11

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: all
	.\$(TARGET)

clean:
	cmd /c if exist $(TARGET) del /Q $(TARGET)