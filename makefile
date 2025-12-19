CC=clang++

compile_all: run_m run_lp run_ae run_ht run_fr

run_m: main.cpp 
	$(CC) main.cpp -o main
	./main
run_lp: logParser.cpp
	$(CC) logParser.cpp -o logParser
	./logParser
run_ae: AlertEngine.cpp
	$(CC) AlertEngine.cpp -o AlertEngine
	./AlertEngine
run_ht: HashTable.cpp
	$(CC) HashTable.cpp -o HashTable
	./HashTable
run_fr: FileReader.cpp
	$(CC) FileReader.cpp -o FileReader
	./FileReader