# === Compiler and Flags ===
CXX = g++
CXXFLAGS = -std=c++17  -g

# === Files ===
SRC = Matrix_nxn.cpp
MAIN = Matrix_output.cpp
TEST = Matrix_tests.cpp
TARGET = Matrix_output

# === Main Build ===
Main: $(SRC) $(MAIN)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(MAIN)

# === Unit Test Build ===
test: $(SRC) $(TEST)
	$(CXX) $(CXXFLAGS) -o test_exec $(SRC) $(TEST)
	./test_exec

# === Valgrind Check ===
valgrind: $(SRC) $(MAIN)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(MAIN)
	valgrind --leak-check=full ./$(TARGET)

# === Clean Generated Files ===
clean:
	rm -f $(TARGET) test_exec *.o *.out *.txt
