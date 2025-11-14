# compilar biblioteca
dentro de src/lib execute: 
``g++ -shared -fPIC src/lib/fluxo.cpp src/lib/modelo.cpp src/lib/sistema.cpp -o bin/libmyv.so``

# compilar teste funcional
dentro de test/funcional execute: ``g++ -Wall -Wextra test/funcional/main.cpp test/funcional/funcional_tests.cpp -Lbin -lmyv -o bin/funcional_test``

# compilar testes unitários
dentro de test/unit execute: ``g++ -Wall -Wextra test/unit/main.cpp test/unit/unit_tests.cpp -Lbin -lmyv -o bin/unit_tests``

# compilar a main
dentro de src execute: ``g++ main.cpp -L..\bin -lmyv -o ..\bin\main.exe``

# execução
Os executaveis e as bibliotecas serão direcionados ao diretorio bin, as vezes ao executar os exe esta dando erro de linkagem, porem é somente rodar o comando ``export LD_LIBRARY_PATH=.`` dentro do bin e rodar os executaveis

# makefile 
``make`` : Compila a biblioteca libmyv.so e o executável principal main, colocando-os em bin/

``make test_func`` : Compila a biblioteca (se necessário) e o executável funcional_test

``make test_unit`` : Compila a biblioteca (se necessário) e o executável unit_test

``make run_tests`` : Ele vai compilar os dois testes (se necessário) e depois executá-los, cuidando automaticamente do LD_LIBRARY_PATH

``make clean`` : Limpa a pasta bin/, removendo todos os arquivos compilados