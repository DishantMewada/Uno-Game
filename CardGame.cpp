//============================================================================
// implementation of game logic
//============================================================================

#include <iostream>
#include <vector>
#include "CardDeck.h"
#include "Card.h"

class CardGame{

private:
	int numPlayers,numSets;		//two int variables- numPlayers : number of players and numSets : number of decks
	CardDeck* mainDeck;			//mainDeck is an object of CardDeck* which is the main deck of cards
	CardDeck* playedDeck;       //playedDeck is an object of CardDeck* which is the played deck of cards
	std::vector<CardDeck*> players; // players is a vector of CardDeck* 
public:
	// parameterized constructor
	// set the number of deck(numSets) and the number of player(numPlayers)
	CardGame(int iNumSets,int iNumPlayers){
		numSets=iNumSets;
		numPlayers=iNumPlayers;
		// create a new CardDeck object for every players 
		for(int player=0;player<numPlayers;player++)
			players.push_back(new CardDeck());
		//initialize MainDeck
		mainDeck=new CardDeck();
		//initialize PlayedDeck
		playedDeck=new CardDeck();
	}

	//Initilize MainDeck from CardDeck
	void initializeMainDeck(){
		//  create number of decks and points to maindeck 
		mainDeck->createInitialisedCardDeck(numSets);
		//  randomly shuffle maindeck
		mainDeck->shuffleDeck();	
	}

	//  function to check the top card of the deck and played card and return true if shape or value or both matched
	bool isItMatch(Card* topCard,Card* playerCard){
    		return topCard->getShape() == playerCard->getShape() || topCard->getValue() == playerCard->getValue();
	}
	
	//  playGame function 
	void playGame(){
		int tPlayerCount=numPlayers*7;

		while(tPlayerCount--){
			players[tPlayerCount%numPlayers]->addCard(mainDeck->getTopCard());
		}

		Card* topCard=NULL;
		while(true){
			//topCard assign with the top card of the maindeck
			topCard=mainDeck->getTopCard();
			//add the top card of the main deck to playedDeck 
			playedDeck->addCard(topCard);
			//gameOver flag to see the status of game
			bool gameOver=false;
			//Print the shape and value of top card 
			std::cout<<"Deck top card : "<<topCard->getShape()<<" "<<topCard->getValue()<<std::endl;
			//for loop for pIndex =0 to number of players
			for(int pIndex=0;pIndex<numPlayers;pIndex++){
				//playerCard the card played by pIndex player
				Card* playerCard=players[pIndex]->getTopCard();
				//add playerCard to playedDeck
				playedDeck->addCard(playerCard);
				//check whether top card of the deck matches with playercard
				if(!isItMatch(topCard,playerCard)){
					std::cout<<"Player "<<pIndex+1<<" takes card from the shuffled deck "<<std::endl;
					players[pIndex]->addCard(mainDeck->getTopCard());
					players[pIndex]->printDeck();
					//topCard=mainDeck->getTopCard();
				}else{
					std::cout<<"Player "<<pIndex+1<<" played card : "<<topCard->getShape()<<" "<<topCard->getValue()<<std::endl;
					if(players[pIndex]->getNumberOfCards() == 0){
						std::cout<<"Player "<<pIndex+1<<" won the Game\n";
						gameOver=true;
						break;
					}
				}

				//checks the number of cards in main deck
				if(mainDeck->getNumberOfCards() == 0){
					//transfer playedDeck cards to maindeck
					mainDeck->moveAllCards(playedDeck,mainDeck);
					//randomly shuffle maindeck
					mainDeck->shuffleDeck();
				}
			}
			if(gameOver)
				break;
		}
	}

	//destructor of CardGame
	//Delete decks of Players and Played Card Deck
	~CardGame(){
		delete mainDeck;
		delete playedDeck;
		for(int pos=0;pos<players.size();pos++)
			delete players[pos];
	}
};

//  main() function 
int main(){
	bool q = false;  //ch is String intialized to "a"
		while(q == false){
		int numPlayers,numSets;		// two integer variables numPlayers(number of players) and numSets(number of decks)
		int quit;		//  String variable use to quit or restart the game
		std::cout<<"Enter number of sets to play : ";
		std::cin>>numSets;
		std::cout<<"\nEnter number of players for the game : ";
		std::cin>>numPlayers;
			if(numSets<1){
				std::cout<<"Number of sets must be positive integer(>0)";
			}else if(numPlayers<2){
				std::cout<<"Number of players must be greater than integer 1";
			}else{
			
			CardGame* gameObj=new CardGame(numSets,numPlayers);
			//initialize maindeck
			gameObj->initializeMainDeck();
			//game starts 
			gameObj->playGame();
			delete gameObj;
			}
		std::cout<<"\nEnter 0 to stop the game or any other digit to restart the game: ";
		std::cout<<"\nNote:if entered any other character or any symbols then also game is stopped \n";
		std::cin>>quit;
			if(quit == 0)
				q=true;
			else if(quit >= 1)
				q=false;

		}
	return 0;
}
