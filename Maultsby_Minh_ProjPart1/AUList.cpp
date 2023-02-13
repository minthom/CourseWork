#include <iostream>
#include <stdexcept>
#include "AUList.h"

AUList::AUList() {
  length = 0; 
}
bool AUList::IsFull() const {
  return (length == MAXSIZE); 
}
int AUList::GetLength() const {
  return length;
}

void AUList::MakeEmpty() {
  length = 0; 
}
void AUList::PutItem(LouWeather2021 item) { //This function assumes the "IsFull" condition hasn't been met.
  ListItems[length] = item; 
  length++;
}

void AUList::ResetList() {
  currentPos = -1; //We want the position BEFORE the first element, since incrementation in GetNextItems happens first
}

bool AUList::HasNextItem() {
  return currentPos<(length-1);
}

LouWeather2021 AUList::GetNextItem() {
  currentPos++; //Remember that currentPos is a class member variable
  return ListItems[currentPos];
}

void AUList::PrintList() { //simple function to print a list's items in stored order
  for (int loc=0; loc<length; loc++) {
  	LouWeather2021 curitem=ListItems[loc];
	std::cout<< "Rec " << loc << ": " <<curitem.temperature<<", "<<curitem.feelslike<<", "
	<<curitem.dewpoint<<','<<curitem.humidity<<','<<curitem.precipitation<<','<<curitem.windspeed<<std::endl;
  }
}

