# compilar biblioteca
dentro de src/lib execute: 
``g++ -shared fluxo.cpp modelo.cpp sistema.cpp -o ../../bin/libmyv.so``

# compilar teste funcional
dentro de test/funcional execute: ``g++ main.cpp funcional_tests.cpp -L../../bin -llibmyv -o ../../bin/funcional_test.exe``

# compilar testes unitários
dentro de test/unit execute: ``g++ main.cpp unit_tests.cpp -L../../bin -lmyv -o ../../bin/unit_test.exe``

# execução
Os executaveis e as bibliotecas serão direcionados ao diretorio bin, as vezes ao executar os exe esta dando erro de linkagem, porem é somente rodar o comando ``export LD_LIBRARY_PATH=.`` dentro do bin e rodar os executaveis