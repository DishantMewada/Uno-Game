//============================================================================
// implementation of Card Class
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include "Card.h"

// default constructor create a card with empty shape and value
Card::Card(){
		shape="";
		value="";
	}
// parameter constructor create a card with shape and value
Card::Card(std::string _shape,std::string _value):shape(_shape),value(_value){}

//getter function for shape variable of Card Class 
std::string Card::getShape(){
		return shape;
}

//getter function for value variable of Card Class
std::string Card::getValue(){
		return value;
}
