CC=g++
OUT=./out

make:Card.o CardDeck.o CardGame.o
	$(CC) $(OUT)/Card.o $(OUT)/CardDeck.o $(OUT)/CardGame.o -o $(OUT)/CardGame


Card.o: Card.cpp
	$(CC) -c -std=c++11 Card.cpp -o $(OUT)/Card.o 

CardDeck.o: CardDeck.cpp
	$(CC) -c -std=c++11 CardDeck.cpp -o $(OUT)/CardDeck.o

CardGame.o: CardGame.cpp
	$(CC) -c -std=c++11 CardGame.cpp -o $(OUT)/CardGame.o


clean:
	rm -rf $(OUT)/*.o
