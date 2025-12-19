CC=clang++

compile_all: compile_m compile_lp compile_ae compile_ht compile_fr

compile_m: main.cpp 
	$(CC) main.cpp -o main

compile_lp: logParser.cpp
	$(CC) logParser.cpp -o logParser

compile_ae: AlertEngine.cpp
	$(CC) AlertEngine.cpp -o AlertEngine

compile_ht: HashTable.cpp
	$(CC) HashTable.cpp -o HashTable

compile_fr: FileReader.cpp
	$(CC) FileReader.cpp -o FileReader