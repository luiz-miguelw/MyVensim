# --- Variáveis de Compilação ---
# Define o compilador que queremos usar (GNU C++)
CXX = g++

# Define as flags do compilador (mostra todos os avisos)
CXXFLAGS = -Wall -Wextra

# --- Variáveis do Projeto ---
# Diretório de saída para os arquivos compilados
BIN_DIR = bin

# Nome da nossa biblioteca compartilhada (Shared Object do Linux)
LIB_NAME = libmyv.so
LIB_TARGET = $(BIN_DIR)/$(LIB_NAME)

# Arquivos .cpp que compõem a biblioteca
LIB_SOURCES = src/lib/fluxo.cpp src/lib/modelo.cpp src/lib/sistema.cpp

# --- Flags de Linkagem ---
# Diz ao linker para procurar bibliotecas no diretório 'bin'
LDFLAGS = -L$(BIN_DIR)

# O nome da biblioteca que queremos linkar (o 'make' entende que -lmyv procura por 'libmyv.so')
LDLIBS = -lmyv

# --- Alvos (Targets) ---

# O alvo padrão (o que é executado quando você digita apenas 'make')
# .PHONY significa que 'all' não é um nome de arquivo real.
.PHONY: all
all: $(BIN_DIR)/main

# 1. Alvo para construir a BIBLIOTECA (.so)
# Este alvo depende dos arquivos .cpp da biblioteca.
# Se qualquer um deles mudar, a biblioteca será recriada.
$(LIB_TARGET): $(LIB_SOURCES)
	@echo "--- Compilando a Biblioteca ($(LIB_TARGET)) ---"
	@mkdir -p $(BIN_DIR)
	$(CXX) -shared -fPIC $(LIB_SOURCES) -o $(LIB_TARGET)


# 2. Alvo para construir o APLICATIVO PRINCIPAL (main)
# Este alvo depende do 'src/main.cpp' e da nossa biblioteca.
# O 'make' irá garantir que $(LIB_TARGET) seja construído ANTES deste.
$(BIN_DIR)/main: src/main.cpp $(LIB_TARGET)
	@echo "--- Compilando o Aplicativo Principal (main) ---"
	# O comando para compilar o 'main' e linká-lo com a biblioteca
	$(CXX) $(CXXFLAGS) src/main.cpp $(LDFLAGS) $(LDLIBS) -o $(BIN_DIR)/main


# 3. Alvo para construir o TESTE FUNCIONAL
# .PHONY para criar um "apelido"
.PHONY: test_func
test_func: $(BIN_DIR)/funcional_test

$(BIN_DIR)/funcional_test: test/funcional/main.cpp test/funcional/funcional_tests.cpp $(LIB_TARGET)
	@echo "--- Compilando Testes Funcionais ---"
	$(CXX) $(CXXFLAGS) test/funcional/main.cpp test/funcional/funcional_tests.cpp $(LDFLAGS) $(LDLIBS) -o $(BIN_DIR)/funcional_test


# 4. Alvo para construir o TESTE UNITÁRIO
.PHONY: test_unit
test_unit: $(BIN_DIR)/unit_tests

$(BIN_DIR)/unit_tests: test/unit/main.cpp test/unit/unit_tests.cpp $(LIB_TARGET)
	@echo "--- Compilando Testes Unitários ---"
	$(CXX) $(CXXFLAGS) test/unit/main.cpp test/unit/unit_tests.cpp $(LDFLAGS) $(LDLIBS) -o $(BIN_DIR)/unit_tests


# 5. Alvo para EXECUTAR os testes (já resolve o problema do LD_LIBRARY_PATH)
.PHONY: run_tests
run_tests: test_func test_unit
	@echo "--- Executando Testes (Funcional e Unitário) ---"
	@export LD_LIBRARY_PATH=$(BIN_DIR) && \
	$(BIN_DIR)/funcional_test && \
	$(BIN_DIR)/unit_tests


# 6. Alvo para LIMPAR o projeto
# Remove todos os arquivos do diretório 'bin'
.PHONY: clean
clean:
	@echo "--- Limpando o diretório bin ---"
	-rm -f $(BIN_DIR)/*


# 7. (NOVO) Alvo para EXECUTAR a aplicação principal
.PHONY: run
run: $(BIN_DIR)/main
	@echo "--- Executando Aplicativo Principal ---"
	@# Exporta o caminho da biblioteca e executa o 'main'
	@export LD_LIBRARY_PATH=$(BIN_DIR) && \
	$(BIN_DIR)/main