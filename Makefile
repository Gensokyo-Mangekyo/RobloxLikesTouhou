TARGET = Program #Название exe файла

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

$(TARGET) : $(OBJ)
	g++ $(OBJ) -o $(TARGET) -lpsapi

%.o : %.cpp
	g++ -c $< -o $@

