#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

#include <iostream>

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

std::string* ULListStr::getValAtLoc(size_t loc) const {
  // hell on earth

  // check if loc is within size
  if (loc >= size_) {
    return nullptr;
  }
  else {

    // every Item has an array of 10
    Item* p = head_;
    
    // placeholder location to edit as we progress
    size_t location;

    // move along Items until we reach the one the location is in
    for (size_t i = 0; i < ((loc + head_->first) / 10); i++) {
      p = p->next;
    }

    // find "index" of element we want within that Item (accounting for the shift from head_->first)
    location = (loc + head_->first) % 10;

    // std::cout << "Head: " << (head_->next == nullptr) << std::endl;

    // std::cout << "Loc: " << loc << std::endl;
    // std::cout << "First: " << head_->first << std::endl;
    // std::cout << "Location: " << location << std::endl;

    // return that element
    // std::cout << "Value: " << p->val[location] << std::endl;
    // std::cout << "Return" << std::endl;
    return &(p->val[location]);


    // evidence of my suffering -->
    // go to the correct Item
    // NOTE:: need to account for if the very first node of the overall list doesn't start from the top
    // for (size_t i = 0; i < (loc / 10); i++) {
    //   // std::cout << (loc + p->first) / 10 << std::endl;
    //   // std::cout << "loop" << std::endl;
    //   p = p->next;
    // }

    // location = loc % 10;

    // // last check since loop doesn't cover all cases
    // if (loc % 10 > (10 - p->first)) {
    //   p = p->next;
    //   location -= p->first;
    // }

    // // we're now at the start of the Item that we want to extract from
    // // return the correct value in that Item
    // // std::cout << "return" << std::endl;
    // // std::cout << location << std::endl;
    // return &(p->val[location]);

    // static std::string* result = &(p->val[(10 - p->first) + (loc % 10)]);
    // return &(p->val[p->first + (loc % (10 - p->first))]);
  }
}

std::string const& ULListStr::back() const {
  return tail_->val[tail_->last-1];
}

std::string const& ULListStr::front() const {
  return head_->val[head_->first];
}

void ULListStr::push_front(const std::string& val) {
  // check if list is empty
  if (head_ == NULL) {
    // create a new item
    head_ = new Item();
    head_->first = 9;
    head_->last = 10;
    head_->prev = nullptr;
    head_->next = nullptr;
    tail_ = head_;

    // add value to the array in the new Item
    head_ ->val[9] = val;
  }

  // check if there's space in the first Item, if not then make a new Item
  else if (head_->first == 0) {
    // std::cout << "new" << std::endl;
    Item* temp = head_;
    head_ = new Item();
    head_->first = 9;
    head_->last = 10;
    head_->prev = nullptr;
    head_->next = temp;
    

    // change head pointer
    temp->prev = head_;

    // std::cout << "next check" << std::endl;
    // std::cout << (head_->next == nullptr) << std::endl;

    // add value to the array in the new Item
    head_->val[9] = val;
  }

  // otherwise push the value to the front of head array
  else {
    head_->first -= 1;
    head_->val[head_->first] = val;
  }

  // update size
  size_ += 1;

}

void ULListStr::push_back(const std::string& val) {
  // check if list is empty
  if (tail_ == NULL) {
    // create a new item
    tail_ = new Item();
    tail_->first = 0;
    tail_->last = 1;
    tail_->prev = nullptr;
    tail_->next = nullptr;
    head_ = tail_;

    // add value to the array in the new Item
    tail_->val[0] = val;
  }
  // check if there's space in the last Item, if not then make a new Item
  else if (tail_->last == 10) {
    // std::cout << "new" << std::endl;
    Item* temp = tail_;
    tail_ = new Item();
    tail_->first = 0;
    tail_->last = 1;
    tail_->prev = temp;
    tail_->next = nullptr;

    // change tail pointer
    temp->next = tail_;

    // std::cout << "next check" << std::endl;
    // std::cout << (head_->next == nullptr) << std::endl;

    // add value to the array in the new Item
    tail_->val[0] = val;
  }

  // otherwise push the value to the front of head array
  else {
    tail_->last += 1;
    tail_->val[tail_->last-1] = val;
  }
  // update size
  size_ += 1;

}

void ULListStr::pop_front() {
  // check if list is empty
  if (head_ != NULL) {
    // check if element to pop is only one in that Item
    if (head_->first == 9) {
      // check if that Item is the only one in the list
      if (head_ == tail_) {
        // delete the Item and set head and tail to NULL
        tail_ = NULL;
        delete head_;
        head_ = NULL;
      }
      else {
        // delete the Item when we pop
        Item* temp = head_;
        head_ = head_->next;
        head_->prev = nullptr;
        delete temp;
      }
    }
    else {
      // "remove" the last element in that Item
      head_->first += 1;
    }

    // edit size
    size_ -= 1;
  }
}

void ULListStr::pop_back() {
  // check if list is empty
  if (head_ != NULL) {
    // check if element to pop is only one in that Item
    if (tail_->last == 1) {
      // check if that Item is the only one in the list
      if (head_ == tail_) {
        // delete the Item and set head and tail to NULL
        tail_ = NULL;
        delete head_;
        head_ = NULL;
      }
      else {
        // delete the Item when we pop
        Item* temp = tail_;
        tail_ = tail_->prev;
        tail_->next = nullptr;
        delete temp;
      }
    }
    else {
      // "remove" the first element in that Item
      tail_->last -= 1;
    }

    // edit size
    size_ -= 1;
  }
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
