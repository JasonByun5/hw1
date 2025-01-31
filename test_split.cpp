/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  
  Node* odds = nullptr;
  Node* evens = nullptr;

  Node* ins = new Node(0, nullptr);
  Node* temp = ins;

  for(int i = 1; i < 10; i++){
    
    Node* newNode = new Node(i, nullptr);
    temp -> next = newNode;
    temp = temp -> next;
  }

  Node* tempIns = ins;
  cout<< "This is the stuff in Ins" << endl;
  while(tempIns != nullptr){
    cout << tempIns -> value << endl;
    tempIns = tempIns -> next;
  }

  split(ins, odds, evens);

  Node* tempOdd = odds;
  cout<< "This is the stuff in Odds" << endl;
  while(tempOdd != nullptr){
    cout << tempOdd -> value << endl;
    tempOdd = tempOdd -> next;
  }

  cout << endl;
  cout << endl;

  Node* tempEven = evens;
  cout<< "This is the stuff in Even" << endl;
  while(tempEven != nullptr){
    cout << tempEven -> value << endl;
    tempEven = tempEven -> next;
  }

  while (odds != nullptr) {
    Node* temp = odds;
    odds = odds->next;
    delete temp;
  }
  
  while (evens != nullptr) {
    Node* temp = evens;
    evens = evens->next;
    delete temp;
  }






}
