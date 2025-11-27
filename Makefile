# --- Variáveis de Compilação ---
CXX = g++
CXXFLAGS = -Wall -Wextra

# --- Variáveis do Projeto ---
BIN_DIR = bin

# --- Biblioteca (DLL/SO) ---
LIB_NAME = libmyv.so
LIB_TARGET = $(BIN_DIR)/$(LIB_NAME)
LIB_SOURCES = src/lib/fluxo.cpp src/lib/modelo.cpp src/lib/sistema.cpp

# --- Testes Unitários (NOVA LISTA DE ARQUIVOS) ---
# Aqui listamos todos os arquivos .cpp criados para o teste unitário
UNIT_SOURCES = test/unit/main.cpp \
               test/unit/unit_Sistema.cpp \
               test/unit/unit_Fluxo.cpp \
               test/unit/unit_Modelo.cpp

# --- Flags de Linkagem ---
LDFLAGS = -L$(BIN_DIR)
LDLIBS = -lmyv

# --- Alvos (Targets) ---

.PHONY: all
all: $(BIN_DIR)/main

# 1. Compila a Biblioteca
$(LIB_TARGET): $(LIB_SOURCES)
	@echo "--- Compilando a Biblioteca ($(LIB_TARGET)) ---"
	@mkdir -p $(BIN_DIR)
	$(CXX) -shared -fPIC $(LIB_SOURCES) -o $(LIB_TARGET)

# 2. Compila o App Principal
$(BIN_DIR)/main: src/main.cpp $(LIB_TARGET)
	@echo "--- Compilando o Aplicativo Principal (main) ---"
	$(CXX) $(CXXFLAGS) src/main.cpp $(LDFLAGS) $(LDLIBS) -o $(BIN_DIR)/main

# 3. Compila Testes Funcionais
.PHONY: test_func
test_func: $(BIN_DIR)/funcional_test

$(BIN_DIR)/funcional_test: test/funcional/main.cpp test/funcional/funcional_tests.cpp $(LIB_TARGET)
	@echo "--- Compilando Testes Funcionais ---"
	$(CXX) $(CXXFLAGS) test/funcional/main.cpp test/funcional/funcional_tests.cpp $(LDFLAGS) $(LDLIBS) -o $(BIN_DIR)/funcional_test

# 4. Compila Testes Unitários (ATUALIZADO)
.PHONY: test_unit
test_unit: $(BIN_DIR)/unit_tests

# Agora depende da variável $(UNIT_SOURCES) que contém todos os arquivos novos
$(BIN_DIR)/unit_tests: $(UNIT_SOURCES) $(LIB_TARGET)
	@echo "--- Compilando Testes Unitários ---"
	$(CXX) $(CXXFLAGS) $(UNIT_SOURCES) $(LDFLAGS) $(LDLIBS) -o $(BIN_DIR)/unit_tests

# 5. Executa os Testes
.PHONY: run_tests
run_tests: test_func test_unit
	@echo "--- Executando Testes (Funcional e Unitário) ---"
	@export LD_LIBRARY_PATH=$(BIN_DIR) && \
	$(BIN_DIR)/funcional_test && \
	$(BIN_DIR)/unit_tests

# 6. Limpeza
.PHONY: clean
clean:
	@echo "--- Limpando o diretório bin ---"
	-rm -f $(BIN_DIR)/*

# 7. Executa o App Principal
.PHONY: run
run: $(BIN_DIR)/main
	@echo "--- Executando Aplicativo Principal ---"
	@export LD_LIBRARY_PATH=$(BIN_DIR) && \
	$(BIN_DIR)/main