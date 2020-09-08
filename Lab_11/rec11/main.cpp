//
//  main.cpp
//  rec11
//
//  Created by Sarah Xiao on 4/17/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

void listAddHead(Node*& headPtr, int entry) {
    headPtr = new Node(entry, headPtr);
}

Node* listBuild(const vector<int>& vals) {
    Node* result = nullptr;
    for (size_t index = vals.size(); index > 0; --index) {
        listAddHead(result, vals[index-1]);
    }
    return result;
}

void listClear(Node*& headPtr) {
    while (headPtr) {
        Node* next = headPtr->next;
        delete headPtr;
        headPtr = next;
    }
}

// Task One
    
void splice(Node* l1, Node* loc){
    Node* end = loc-> next;
    loc-> next = l1;
    while (l1 ->next != nullptr) {
        l1 = l1->next;
    }
    l1->next = end;
}

// Task Two
    
bool helper (Node* l1, Node* l2){
   while ((l1 != nullptr) && (l2 != nullptr)) {
    if (l1->data == l2->data) {
        l1 = l1->next;
        l2 = l2->next;
           }
    else {
        return false;
    }
   }
    if (l1 == nullptr){
        return true;
    }
    else {
        return false;
    }
}

Node* isSublist (Node* sub, Node* big){
    while (big != nullptr){
        if (helper (sub, big)){
            return big;
        }
        if (helper (sub, big) == false) {
            big = big->next;
        }
    }
    return nullptr;
    }

void display(Node* node){
    while (node->next != nullptr){
        cout << node->data << " ";
        node = node->next;
    }
    cout << node->data << " " << endl;
}
    
int main() {
    cout << "Part 1"<< endl;
    Node* l1 = listBuild({5, 7, 9, 1});
    display(l1);
    Node* l2 = listBuild({6, 3, 2});
    display(l2);
    splice(l2, l1->next);
    display(l1);
    display(l2);
    
    cout << "Part 2"<< endl;
    Node* big = listBuild({1, 2, 3, 2, 3, 2, 4, 5, 6});
    display(big);
    Node* small1 = listBuild({2, 3});
    Node* small2 = listBuild({2, 3, 2, 4, 5, 6});
    Node* small3 = listBuild({3, 9});
    display(isSublist(small1, big));
    display(isSublist(small2, big));
    if (isSublist(small3, big) != nullptr){
        display(isSublist(small3, big));
    }
    else {
        cout << "no" << endl;
    }
    void listClear(Node*& l1);
    void listClear(Node*& small2);
    void listClear(Node*& small3);
    }
           //    list = (3, 9)
           //    2, 3
           //
           //    "2", 3, 4, "2", 3,  4, "5", 6
           //        }
           //    2, 3, 4,

//Node* isSublist (Node* sub, Node* big){
//    Node* start = nullptr;
//    Node* initial = sub;
//    while (sub != nullptr){
////           && (big.size > sub.size())
//        if (big->data == sub->data) {
//            start = big;
//            sub = sub->next;
//            big = big->next;
//        }
//        else if (start == nullptr) {
//            big = big->next;
//        }
//        else if (big->data == start->data){
//            Node* newstart = big;
//            Node* newlist = newstart;
//            while (newstart->data == start->data){
//                newstart = newstart->next;
//                start = start->next;
//            }
//            if (start->next == nullptr){
//                return newlist;
//            }
//            else {
//                big = newstart->next;
//                sub = initial;
//            }
//        }
//        else{
//            cout << "Failed to match" << endl;
//            return nullptr;
//        }
//    }
//     return start;
//}
