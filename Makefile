.PHONY:clean all
CC=occlum-gcc
CXX=occlum-g++
BIN=generate 01_leastSquare 02_cosineMeasure 03_count 04_extremum 05_slotsmean
all:$(BIN)
%.o:%.cpp
	$(CXX) -c $< -o $@
clean:
	rm -rf *.o $(BIN)

