//============================================================================
// interface for Card Class.
//============================================================================

#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <vector>
#include <string>

class Card{
private:
	std::string shape,value;	//private variable shape and value of Class Card   
public:
	//put all the suits values in cardSuits variable: a const Vector of strings
	const std::vector<std::string> cardSuits{"Club","Spade","Heart","Diamond"};
	//put all the face values in cardVals variable: a const Vector of strings
	const std::vector<std::string> cardVals={"Ace","King","Queen","Jack","Ten","Nine","Eight","Seven","Six","Five","Four","Three","Two"};
	//default constructer
	Card();	
	//constructer with parameters
	Card(std::string ,std::string );
	
	//getter functions defination for shape and value variables
	std::string getShape();
	std::string getValue();
};
#endif
