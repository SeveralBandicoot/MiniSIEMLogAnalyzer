CC=clang++

compile_all: compile_main compile_logparser compile_alertengine compile_hashtable compile_filereader

compile_main: main.cpp 
	$(CC) main.cpp -o main

compile_logparser: logParser.cpp
	$(CC) logParser.cpp -o logParser

compile_alertengine: AlertEngine.cpp
	$(CC) AlertEngine.cpp -o AlertEngine

compile_hashtable: HashTable.cpp
	$(CC) HashTable.cpp -o HashTable

compile_filereader: FileReader.cpp
	$(CC) FileReader.cpp -o FileReader