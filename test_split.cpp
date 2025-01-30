/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include <iostream>
#include <string>

#include "split.h"

void print_list(Node* list) {

    if (list == nullptr) {
        std::cout << "nullptr" << std::endl;
        return;
    }

    for (Node* p = list; p != nullptr; p = p->next) {
        std::cout << p -> value << " ";
        std::cout << std::endl;
    }
}

void delete_list(Node* list) {
    if (list != nullptr) {
        for (Node* p  = list; p != nullptr;) {
            Node* temp = p;
            p = p->next;
            delete p;
        }
    }
}

int main(int argc, char* argv[])
{
    Node* test_evens = nullptr;
    Node* test_odds = nullptr;
    
    Node* test_in = nullptr;

    // test if all three are null inputs
    split(test_in, test_evens, test_odds);

    // test if split deletes test_in correctly
    test_in = new Node(2, nullptr);
    split(test_in, test_evens, test_odds);

    print_list(test_in);
    print_list(test_evens);

    delete_list(test_evens);
    

    // test normal case
    test_in = new Node(9, nullptr);
    test_in = new Node(8, test_in);
    test_in = new Node(5, test_in);
    test_in = new Node(2, test_in);

    split(test_in, test_evens, test_odds);

    print_list(test_in);
    print_list(test_evens);
    print_list(test_odds);

    delete_list(test_evens);
    delete_list(test_odds);

}
