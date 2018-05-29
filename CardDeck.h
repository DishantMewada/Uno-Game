//============================================================================
// interface for CardDeck Class.
//============================================================================

#ifndef CARDDECK_H
#define CARDDECK_H
#include "Card.h"

class CardDeck{
private:
        std::vector<Card*> cDeck;	//private pointer cDeck: a vector of Card*
        Card* cardObj;				//private pointer cardObj: an object of class Card
public:
	CardDeck();		//default constructor of CardDeck Class
	~CardDeck();	//default destructor of CardDeck Class
	
        
		//	Purpose Creates an empty deck of cards
		void createEmptyCardDeck();     
		//	Purpose Creates and initialises a new card deck.
        void createInitialisedCardDeck(int);	
		//	Purpose Initialises an existing card deck
        void initialiseCardDeck(int,CardDeck*);
		//	Purpose Deletes a deck of card
        void deleteCardDeck(CardDeck*);	
		
		
		//	Returns the number of cards in the deck
		//
		//	@param 
		//	@return The number of cards
		//
        int getNumberOfCards();	
        
		//	Returns the number of cards in the deck
		//
		//	@param CardDeck* pointer object of CardDeck Class
		//	@return The number of cards
		//
        int getNumberOfCards(CardDeck*);
		
		//	Returns (and removes) the topmost card of the deck
		//
		//	@param 
		//	@return The topmost card of the deck
		//
        Card* getTopCard();				
		
		//	Returns (and removes) the topmost card of the deck
		//
		//	@param CardDeck* pointer object of CardDeck Class
		//	@return The topmost card of the deck
		//
        Card* getTopCard(CardDeck*);	
		
		//	Returns (and removes) the number-th card of the deck (from the top)
		//
		//  @param1 int any number in the range of 0 to total number of cards in the deck 
		//	@param2 CardDeck* pointer object of CardDeck Class
		//	@return The number-th card of the deck
		//
        Card* getACard(int,CardDeck*);	
		
		//	Returns (but leaves it in the deck) the number-th card of the deck (from the top)
		//
		//  @param1 int any number in the range of 0 to total number of cards in the deck 
		//	@param2 CardDeck* pointer object of CardDeck Class
		//	@return The number-th card of the deck
		//
        Card* lookAtCard(int,CardDeck*);
		
		//	Purpose Moves all cards from the CardDeck source to CardDeck destination
		//
		//  @param1 CardDeck* pointer object of CardDeck Class as a source location
		//	@param2 CardDeck* pointer object of CardDeck Class as a destination location
		//	@return 
		//
        void moveAllCards(CardDeck*,CardDeck*);
		
		//	Purpose Adds the card to the top of the deck
		//
		//  @param1 Card* pointer object of Card Class
		//	@return 
		//
        void addCard(Card*);

		//	Purpose Adds the card to the top of the deck
		//
		//  @param1 Card* pointer object of Card Class
		//  @param2 CardDeck* pointer object of CardDeck Class
		//	@return 
		//
        void addCard(Card*,CardDeck*);
		
		//	Purpose Shuffles the cards of Deck
        void shuffleDeck();		
		//	Purpose Shuffles the cards of Deck
		//
		//  @param CardDeck* pointer object of CardDeck Class		
		//	@return 
		//
		//shuffleDeck shuffles the cards of Deck
        void shuffleDeck(CardDeck*);
		
	//	Print function to print the CardDeck		
	void printDeck();		
};
#endif
