CC=g++ # compilador, troque para gcc se preferir utilizar C
CFLAGS=-Wall -Wextra -g # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./tp03 # nome do executavel que sera gerado, nao troque
TMPOUT=./tp03.testresult

$(EXEC): src/main.cpp Scale.o ScaleManager.o
	$(CC) $(CFLAGS) src/main.cpp Scale.o ScaleManager.o -o $(EXEC)
	rm -rf Scale.o
	rm -rf ScaleManager.o

Scale.o: src/classes/Scale.cpp 
	$(CC) $(CFLAGS) -c src/classes/Scale.cpp  -o Scale.o

ScaleManager.o: src/classes/ScaleManager.cpp
	$(CC) $(CFLAGS) -c src/classes/ScaleManager.cpp -o ScaleManager.o

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf Scale.o
	rm -rf ScaleManager.o