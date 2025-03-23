OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

main.exe: main.o DocumentsManager.o SimilarityAlgorithms.o xxhash.o
	g++ -o main.exe main.o DocumentsManager.o SimilarityAlgorithms.o xxhash.o

DocumentsManager.o: DocumentsManager.cc DocumentsManager.hh
	g++ -c DocumentsManager.cc $(OPCIONS)

SimilarityAlgorithms.o: SimilarityAlgorithms.cc SimilarityAlgorithms.hh
	g++ -c SimilarityAlgorithms.cc $(OPCIONS)

xxhash.o: xxhash.c xxhash.h
	g++ -c xxhash.c $(OPCIONS)

main.o: main.cc
	g++ -c main.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
