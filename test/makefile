.PHONY = Rules_Interpreter_test Generator_CreateGen_test Reader_test

CC = gcc

OBJECTS := Rules_Interpreter_test.o Rules.o Generator_CreateGen_test.o Generator.o Grid.o Reader.o ReaderTest.o

Rules_Interpreter_test: Rules_Interpreter_test.c ../src/Rules.c
	$(CC) -o Rules_Interpreter_test $^

Generator_CreateGen_test: Generator_CreateGen_test.c ../src/Generator.c ../src/Rules.c ../src/Grid.c ../src/Reader.c
	$(CC) -o Generator_CreateGen_test $^

Reader_test: Reader_test.c ../src/Reader.c ../src/Grid.c
	$(CC) -o Reader_test $^

clean:
	rm  $(OBJECTS) Reader_test Generator_CreateGen_test Rules_Interpreter_test
