//
//  main.cpp
//  rec14
//
//  Created by Sarah Xiao on 5/8/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

struct Node{
    Node(int data = 0, Node* next = nullptr) : data(data), next(next){}
    int data;
    Node* next;
};

struct TNode {
  TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
  int data;
  TNode *left, *right;
};

//task 1
bool binaryEvenOnes(int n){
    if (n == 0){
        return true;
    }
    if (n == 1){
        return false;
    }
    bool even = (n%2 == 0);
    if (even){
        return binaryEvenOnes(n/2);
    }
    else {
        return !binaryEvenOnes(n/2);
    }
}

//task 2
Node* addtwo(Node* l1, Node* l2){
    Node* head;
    Node* nextnode;
    if (!l2 && !l1){
        return nullptr;
    }
    else if (!l2){
        nextnode = addtwo(l1->next, l2);
        head = new Node(l1->data, nextnode);
        return head;
    }
    else if (!l1){
        nextnode = addtwo(l1, l2->next);
        head = new Node(l2->data, nextnode);
        return head;
    }
    nextnode = addtwo(l1->next, l2->next);
    head = new Node(l1->data + l2->data, nextnode);
    return head;
}

Node* findTail(Node* headPtr) {
    if (headPtr == nullptr) return nullptr;
    Node* p = headPtr;
    while (p->next != nullptr) {
        p = p->next;
    }
    return p;
}

void listDisplay(Node* headPtr) {
    for (Node* p = headPtr; p != nullptr; p = p->next) {
        cout << p->data << ' ';
        p->data = 42;
    }
    cout << endl;
}

void listAddTail(Node*& headPtr, int data) {
    if (headPtr == nullptr) {
        headPtr = new Node(data);
    }
    else {
        Node* tail = findTail(headPtr);
        tail->next = new Node(data);
    }
}

//task 3
int max(TNode* root) {
    if (root == nullptr){
        throw invalid_argument ("Tree is empty");
    }
    int king = root->data;
    if (root->left != nullptr && root->right != nullptr){
        int him = max(root->right);
        int her = max(root->left);
        if (him > king && him > her){
            king = him;
        }
        else if (her > king && her > him){
            king = her;
        }
        return king;
    }
    else if (root->left != nullptr){
        int him = max(root->right);
        if (him > king){
            king = him;
        }
        return king;
    }
    else if (root->right != nullptr){
        int her = max(root->left);
        if (her > king){
            king = her;
        }
        return king;
    }
    return king;
}

//task 4

bool palindrome(char letters[], int size){
    if (size <= 1){
        return true;
    }
    else if (letters[0] == letters[size-1]){
        return palindrome(letters+1, size-2);
    }
    return false;
}

//task 5

int towers(int n, char start , char target, char spare){
    if (n == 0){
        return 0;
    }
    return towers(n-1, start, spare, target) + towers(n-1, spare, target, start) + 1;
}

//task 6
void mystery(int n) {
   if (n > 1) {
      cout << 'a';
      mystery(n/2);
      cout << 'b';
      mystery(n/2);
   }
   cout << 'c';
}


int main() {
//    task1
    cout << binaryEvenOnes(2) <<endl;
    cout << binaryEvenOnes(4) <<endl;
    cout << binaryEvenOnes(5) <<endl;
    
//    task2
    Node* list1 = new Node(1,nullptr);
    Node* list2 = new Node(2, nullptr);
    listAddTail(list1, 3);
    listAddTail(list1, 5);
    listAddTail(list2, 4);
    listAddTail(list2, 6);
    listAddTail(list2, 8);
    Node* l3 = addtwo(list1, list2);
    listDisplay(l3);
    
//    task3
    TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
    try {
        cout << max(&f) << endl;
    }
    catch (invalid_argument ex){
        cerr << "Caught exception " << ex.what() << endl;
    }
    TNode* test= nullptr;
    try {
        cout << max(test) << endl;
    }
    catch (invalid_argument ex){
        cerr << "Caught exception " << ex.what() << endl;
    }
//    task4
    char s[] = "racecar";
    if (palindrome(s, 7)) { cout << "Yes!\n"; }
    char y[] = "noon";
    if (palindrome(y, 4)) { cout << "Yes!\n"; }
    char m[] = "mom";
    if (palindrome(m, 3)) { cout << "Yes!\n"; }
    
//    task5 Testing towers
    cout << "the result: "<< towers(1, 'a', 'b', 'c') << " should be 1\n";
    cout << "the result: "<< towers(2, 'a', 'b', 'c')<< " should be 3\n";
    cout << "the result: "<< towers(3, 'a', 'b', 'c')<< " should be 7\n";
    cout << "the result: "<< towers(4, 'a', 'b', 'c')<< " should be 15\n";
    cout << "the result: "<< towers(5, 'a', 'b', 'c')<< " should be 31\n";
    cout << "the result: "<< towers(6, 'a', 'b', 'c')<< " should be 63\n";
    cout << "the result: "<< towers(7, 'a', 'b', 'c')<< " should be 127\n";
    cout << "the result: "<< towers(8, 'a', 'b', 'c')<< " should be 255\n";
    cout << "the result: "<< towers(9, 'a', 'b', 'c')<< " should be 511\n";
    cout << "the result: "<< towers(10, 'a', 'b', 'c')<< " should be 1023\n";
//    task6 mystery
    cout << "Mystery 0 prediction is " << "c, " << "test result: ";
    mystery(0);
    cout << endl;
    cout << "Mystery 1 prediction is " << "c, " << "test result: ";
    mystery(1);
    cout << endl;
    cout << "Mystery 2 prediction is " << "acbcc, " << "test result: ";
    mystery(2);
    cout << endl;
    cout << "Mystery 3 prediction is " << "acbcc, " << "test result: ";
    mystery(3);
    cout << endl;
    cout << "Mystery 4 prediction is " << "aacbccbacbccc, " << "test result: ";
    mystery(4);
    cout << endl;
    cout << "Mystery 5 prediction is " << "aacbccbacbccc, " << "test result: ";
    mystery(5);
    cout << endl;
    cout << "Mystery 6 prediction is " << "aacbccbacbccc, " << "test result: ";
    mystery(6);
    cout << endl;
    cout << "Mystery 7 prediction is " << "aacbccbacbccc, " << "test result: ";
    mystery(7);
    cout << endl;
    cout << "Mystery 8 prediction is " << "aaacbccbacbcccbaacbccbacbcccc, " << "test result: ";
    mystery(8);
    cout << endl;
    cout << "Mystery 9 prediction is " << "aaacbccbacbcccbaacbccbacbcccc, " << "test result: ";
    mystery(9);
    cout << endl;
    cout << "Mystery 10 prediction is " << "aaacbccbacbcccbaacbccbacbcccc, " << "test result: ";
    mystery(10);
    cout << endl;
}
