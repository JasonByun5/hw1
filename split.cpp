/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */
void goThrough(Node*& list, int value);

void split(Node*& in, Node*& odds, Node*& evens)
{
  if (in == nullptr) { //base case!
    return;
  }
  
  Node* temp = in;
  in = in->next;
  
  if (temp->value % 2 == 0){ //checks if even
    goThrough(evens, temp->value);
  }else{ //for odd ones
   goThrough(odds, temp->value);
  }

  delete temp;
  split(in, odds, evens);
}

/* If you needed a helper function, write it here */
void goThrough(Node*& list, int value){
  if(list == nullptr){
    list = new Node(value,nullptr);
  } else if (list->next == nullptr) {
    list->next = new Node(value, nullptr);
  } else {
    goThrough(list->next, value);
  }
}