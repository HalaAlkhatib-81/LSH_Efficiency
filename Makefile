# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
EXECUTABLE = similitud
SRC_DIR = .
OBJ_DIR = obj

# Archivos fuente y objetos
SRCS = $(SRC_DIR)/program.cc \
       $(SRC_DIR)/contpalabras.cc \
       $(SRC_DIR)/docbase.cc \
       $(SRC_DIR)/JaccardSimilarityCalculator.cc \
       $(SRC_DIR)/K_Shingles.cc \
       $(SRC_DIR)/K_Shingles_Permutator.cc \
       $(SRC_DIR)/Text_permutator.cc \
       $(SRC_DIR)/Text_processor.cc \
       $(SRC_DIR)/Text_utils.cc \
       $(SRC_DIR)/Word_counter.cc

OBJS = $(SRCS:$(SRC_DIR)/%.cc=$(OBJ_DIR)/%.o)

# Regla principal
all: $(EXECUTABLE)

# Compilar el ejecutable
$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilar archivos .cc a .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Crear directorio de objetos si no existe
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Ejecutar el programa con argumentos
run: $(EXECUTABLE)
	@echo "Ejecutando el programa..."
	@./$(EXECUTABLE)

# Limpiar archivos generados
clean:
	rm -rf $(OBJ_DIR) $(EXECUTABLE)

.PHONY: all run clean
