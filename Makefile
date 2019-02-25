all: exacutable

libs:
	mkdir lib || true
	g++ -c src/embeddings.cpp -o lib/embeddings.o
	g++ -c src/main.cpp -o lib/main.o
	g++ -c src/mathop.cpp -o lib/mathop.o
	g++ -c src/thread_data.cpp -o lib/thread_data.o
	g++ -c src/triplets.cpp -o lib/triplets.o
	g++ -c src/files.cpp -o lib/files.o

exacutable: libs
	g++ -O2 lib/*.o -lpthread -o prepare_triplets.o

clean:
	rm lib/*.o || true
	rm lib/*.out || true