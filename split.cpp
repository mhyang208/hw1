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

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

  // remember recursion means calling the function again with a smaller section of the list
  // need to delete the pointer of the Node we've already processed
  // PROBLEM: if we just push_front to odds and evens, these lists will be reverse sorted
    // could push to end but would need to iterate to end of list every time...
    // can't use a loop either so maybe not
    // well maybe can recursively find end of list...
    // or reverse the two new lists afterward

  // check if in is null to avoid segfaults
  if (in != nullptr) {
    // sort the given Node
    if (in -> value % 2 == 0) {
        if (evens == nullptr) {
          evens = new Node{in->value, nullptr};
        }
        else {
          evens = new Node{in->value, evens};
        }
    }
    else {
      if (odds == nullptr) {
          odds = new Node{in->value, nullptr};
        }
        else {
          odds = new Node{in->value, odds};
        }
    }

    // skips this if it's the base case (end of list)
    if (in -> next != nullptr) {
      // delete the processed Node
      // NOTE: in now points to the Node that originally came after it
      Node* temp = in;
      in = in -> next;
      delete temp;
      
      // recursive call
      split(in, odds, evens);
    }
    else {
      // we've reached the end of this list, simply delete the processed Node
      delete in;
      in = nullptr;
    }
  }


}

/* If you needed a helper function, write it here */
