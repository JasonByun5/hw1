#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_front(const std::string& val){
  //look at the head_ pointer, 
  //then look at first in the head_ pointer
  // if it is pointing at nothing then put it into last and then move last
  // if there is space in the front (ie if not out of bounds.. how do i check?) 
  // then put in the front space and move the front potiner
  // if there is no space allocate a new item and and put it in the back.
  
  if (head_ == NULL && tail_ == NULL){ // checks if the array is empty head_ -> first == 0 && head_ ->last == 0
    head_ = new Item;
    tail_ = head_;
    head_ -> val[ARRSIZE-1] = val;
    head_ -> first = ARRSIZE-1;
    head_ -> last = ARRSIZE;
    head_->next = NULL;
    head_->prev = NULL;
  }
  else if(head_->first > 0){ // checks to see if there is space in front and then just puts it there
    head_ -> val[head_->first-1] = val;
    head_ -> first = head_ -> first - 1;
  }
  else { //checks to see if there is space in front and if not then makes a new node
    Item* newItem = new Item;
    newItem -> val[ARRSIZE-1] = val;
    newItem -> first = ARRSIZE-1;
    newItem -> last = ARRSIZE;

    newItem -> next = head_;
    head_ -> prev = newItem;
    head_ = newItem;
  }

  size_++;

}


void ULListStr::push_back(const std::string& val){
  if (head_ == NULL && tail_ == NULL){ //this part is the same as push front
    head_ = new Item;
    tail_ = head_;
    head_ -> val[0] = val;
    head_ -> first = 0;
    head_ -> last = 1;
    head_->next = NULL;
    head_->prev = NULL;
  }
  else if((tail_->last) < ARRSIZE){ // checks to see if there is space in front and then just puts it there
    tail_ -> val[tail_ -> last] = val;
    tail_ -> last = tail_ -> last + 1;
  }
  else { //checks to see if there is space in front and if not then makes a new node
    Item* newItem = new Item;
    newItem -> val[0] = val;
    newItem -> first = 0;
    newItem -> last = 1;

    newItem -> prev = tail_;
    tail_ -> next = newItem;
    tail_ = newItem;
  }
  
  size_++;
}

void ULListStr::pop_front(){ // can i assume that the head_ will not be null
  if(head_ == NULL){
    return;
  }
  
  size_--;

  if ((head_ -> first) + 1  == ARRSIZE){ //checks to see if the first was at the last spot
    // destroy the node

    Item* temp = head_;
    head_ = head_ -> next;

    if (head_ != NULL){
      head_ -> prev = NULL;
    }
    else{
      tail_ = NULL;
    }

    delete temp;
  }
  else{
    head_ -> first = head_ -> first + 1;
  }
}

void ULListStr::pop_back(){
  if(tail_ == NULL){
    return;
  }

   size_--;

  if((tail_ -> last) - 1  == 0){
    Item* temp = tail_;
    tail_ = tail_ -> prev;

    if(tail_ != NULL){
      tail_ -> next = NULL;
    }else{
      head_ = NULL;
    }
    
    delete temp;
  }
  else{
    tail_ -> last = tail_ -> last -1;
  }
}


std::string const & ULListStr::back() const{
  return tail_ -> val[tail_ ->last-1];
}

std::string const & ULListStr::front() const{
  return head_ -> val[head_->first];
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


std::string* ULListStr:: getValAtLoc(size_t loc) const{
  if (loc >= size_){
    return nullptr;
  }

  Item* temp = head_;
  size_t remaining = loc;

  while(temp != NULL){
    size_t nodeSize = temp -> last - temp -> first;
    if(remaining < nodeSize ){
      return &(temp -> val[temp-> first + remaining]);
    }
    remaining -= nodeSize;
    temp = temp->next;
  }

  return nullptr;
}