//============================================================================
// implementation of CardDeck Class.
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include "CardDeck.h"
#include "Card.h"

//	Creates an empty deck of cards
void CardDeck::createEmptyCardDeck(){
	cDeck={}; //initialise cDeck a vector of Card* to null
}

// default constructor,
// creates object of Card Class
CardDeck::CardDeck(){
	cardObj=new Card();  // initialise the private pointer varcardObj to a new object
}

// destructor,
// destroy Card* variable cardObj and vector of Card* objects cDeck
CardDeck::~CardDeck(){
	delete cardObj;
	for(auto cObj:cDeck)
		delete cObj;
}

//	Creates and initialises a new card deck.
void CardDeck::createInitialisedCardDeck(int setNum){
	//Creating sets of cards , as per parameter value
	while(setNum--){
		//iterating and assigning each value of cardSuits (vector variable of Card class) to sting variable suit
		for(int suitIndex=0;suitIndex<cardObj->cardSuits.size();suitIndex++){
			std::string suit=cardObj->cardSuits[suitIndex];
			//iterating and assigning each value of cardVals (vector variable of Card class) to sting variable variable
			for(int valIndex=0;valIndex<cardObj->cardVals.size();valIndex++){
				std::string value=cardObj->cardVals[valIndex];
				// pushing each Card objects in cDeck vector variable of CardDeck Class
				cDeck.push_back(new Card(suit,value));		  
			}
		}
	} 
}

//  Initialises an existing card deck
void CardDeck::initialiseCardDeck(int setNum,CardDeck* deckObj){
	deckObj->createInitialisedCardDeck(setNum);
}

//  Deletes a deck of card
void CardDeck::deleteCardDeck(CardDeck* deckObj){
	//  create an empty vector of card* object
	std::vector<Card*> empty;
	//  swap() is a member fuction of Vector class use to swap values between two vector variables
	deckObj->cDeck.swap(empty);
}

//  Returns the number of cards in the deck
int CardDeck::getNumberOfCards(){
	//  size() is a member function of Vector class use to return the number of objects held in a vector cDeck
	return cDeck.size();
}

//  Returns the number of cards in the deck
int CardDeck::getNumberOfCards(CardDeck* deckObj){
	return deckObj->cDeck.size();
}

//	Returns (and removes) the topmost card of the deck
Card* CardDeck::getTopCard(){
	//Validating card deck capacity
	if(cDeck.size()){
		Card* returnCard=cDeck.back();
		cDeck.pop_back();
		return returnCard;
	}
	return NULL;
}

//	Returns (and removes) the topmost card of the deck
Card* CardDeck::getTopCard(CardDeck* deckObj){
	//Validating card deck capacity
	if(deckObj->cDeck.size()){
		//  assigning the value of top card to a new Card* variable returnCard 
		Card* returnCard=deckObj->cDeck.back();
		//  pop_back is a member function of Vector Class used to remove the top(last) element in the vector cDeck
		deckObj->cDeck.pop_back();
		return returnCard;
	}
	return NULL;
}

//	Returns (and removes) the number-th card of the deck (from the top)
Card* CardDeck::getACard(int num,CardDeck* deckObj){
	int len=deckObj->cDeck.size();		// len is the number of cards exist in the deck
	Card* returnCard=new Card();		// returnCard: a new Card* Variable
	//  checks the condition where length of card 'len' should be greater_equal to parameter 'num'  
	if(len >= num){
		//  returnCard has the number-th card from the top
		returnCard=deckObj->cDeck[len-(len-num)];
		// erase() and begin() are the member function of Vector Class 
		deckObj->cDeck.erase(deckObj->cDeck.begin()+(len-(len-num)));
	}else{
		//  error occur if num parameter is greater than length of the deck
		std::cout<<"ERROR : CARD is not exist\n";
	}
	return returnCard;
}

//	Returns (but leaves it in the deck) the number-th card of the deck (from the top)
Card* CardDeck::lookAtCard(int num,CardDeck* deckObj){
	int len=deckObj->cDeck.size();		// len is the number of cards exist in the deck
	Card* returnCard=new Card();		// returnCard: a new Card* Variable
	//  checks the condition where length of card 'len' should be greater_equal to parameter 'num' 
	if(len >= num){
		//  returnCard has the number-th card from the top
		returnCard=deckObj->cDeck[len-(len-num)];
	}else{
		//  error occur if num parameter is greater than length of the deck
		std::cout<<"ERROR : CARD is not exist\n";
	}
	return returnCard;
}

//	Moves all cards from the CardDeck source to CardDeck destination
void CardDeck::moveAllCards(CardDeck* source,CardDeck* destination){
	// insert, begin, end are member function of Vector class 
	destination->cDeck.insert(destination->cDeck.end(),source->cDeck.begin(),source->cDeck.end());
	//  create empty Card* variable
	std::vector<Card*> empty;
	//  At source swap the cDeck with empty vector variable 
	source->cDeck.swap(empty);
}

//	Adds the card to the top of the deck
void CardDeck::addCard(Card* tmpCard){
	// push_back is a member function of Vector Class Used to add new cards to the new deck of cards
	cDeck.push_back(tmpCard);
}

//	Adds the card to the top of the deck
void CardDeck::addCard(Card* tmpCard,CardDeck*  deckObj){
		// push_back is a member function of Vector Class Used to add new cards to the existing deck of cards
	deckObj->cDeck.push_back(tmpCard);
}

//	Shuffles the cards of Deck
void CardDeck::shuffleDeck(){
	std::random_shuffle(cDeck.begin(),cDeck.end());
}

//	Shuffles the cards of Deck
void CardDeck::shuffleDeck(CardDeck* deckObj){
	//  random_shuffle is a member function of Algorithm class used to rearranges the cards in deck randomly
	std::random_shuffle(deckObj->cDeck.begin(),deckObj->cDeck.end());
}

//	Print function to print the CardDeck
void CardDeck::printDeck(){
	std::cout<<"Deck consists of below cards..\n";
	//  iterating and displaying cards in the deck
	for(auto card:cDeck)
		std::cout<<card->getShape()<<" "<<card->getValue()<<" ";
	std::cout<<std::endl;
}

