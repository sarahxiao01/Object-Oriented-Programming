//
//  main.cpp
//  rec12_01
//
//  Created by Sarah Xiao on 4/25/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

class List {
    friend ostream& operator<<(ostream& os, const List& mylist){
        for (Node* p = mylist.Sentinelfront->next; p != mylist.Sentinelback; p = p->next) {
            os << p->data << ' ';
        }
        os << endl;
        return os;
    }
    
    struct Node {
        Node(int data = 0, Node* prev = nullptr, Node* next = nullptr) : data(data), next(next), prev(prev) {}
        int data;
        Node* next;
        Node* prev;
    };
    
public:
     //Task5
     class iterator{
         friend List;
         friend ostream& operator<< (ostream& os, const iterator& it){
             os << "Node" << it.ptr << " ";
             os << *it << endl;
             return os;
         }
         friend bool operator== (const iterator& lhs, const iterator& rhs){
             return (lhs.ptr == rhs.ptr);
         }
         friend bool operator!=  (const iterator& lhs, const iterator& rhs){
             return (lhs.ptr != rhs.ptr);
         }
     public:
         iterator(Node* nodeptr= nullptr): ptr(nodeptr){}
         iterator& operator++(){
             if ((ptr) && (ptr-> next)){
                 ptr = ptr->next;
             }
             return *this;
         }
         
         iterator& operator--(){
             if ((ptr) && (ptr-> prev)){
                 ptr = ptr-> prev;
             }
             return *this;
         }
         
         int& operator*() const{
             return ptr->data;
         }
             
         int operator*() {
                 return ptr->data;
             }
                          
     private:
         Node* ptr;
     };
    
         
    // Task1
    List() : mysize(0){
        Sentinelfront = new Node(0, nullptr, nullptr);
        Sentinelback = new Node(0, nullptr, nullptr);
        Sentinelfront->next = Sentinelback;
        Sentinelback->prev = Sentinelfront;
    }
    
    void push_back(int mydata){
        Node* newnode = new Node(mydata, Sentinelback->prev, Sentinelback);
        Sentinelback->prev->next = newnode;
        Sentinelback->prev = newnode;
        mysize++;
    }

    void pop_back(){
        if(mysize){
            Node* victim = Sentinelback->prev;
            Sentinelback->prev = Sentinelback->prev->prev;
            Sentinelback->prev->next = Sentinelback;
            delete victim;
            --mysize;
        }
    }
    
    int& front(){
        return Sentinelfront->next->data;
    }
    int front() const{
        return Sentinelfront->next->data;
    }

    int& back(){
        return Sentinelback->prev->data;
    }
    int back()const {
        return Sentinelback->prev->data;
    }

    size_t size() const{
        return mysize;
    }

    // Task2
    void push_front(int mydata){
        Node* newnode = new Node(mydata, Sentinelfront, Sentinelfront->next);
        Sentinelfront->next->prev = newnode;
        Sentinelfront->next = newnode;
        mysize++;
        }
    
    void pop_front(){
        if (mysize != 0){
            Node* node = Sentinelfront->next;
            Node* temp = node->next;
            temp->prev = Sentinelfront;
            Sentinelfront->next = temp;
            delete node;
            mysize-=1;
        }
    }
//     Task3

    void clear(){
        while (mysize != 0){
            pop_back();
        }
    }
    
        // Task4

    int& operator[](size_t index){
        Node* node =Sentinelfront->next;
        for (size_t i =0; i < index; ++i){
            node = node->next;
        }
        return node->data;
    }
    
    const int& operator[](size_t index) const {
        Node* node =Sentinelfront->next;
        for (size_t i =0; i < index; ++i){
            node = node->next;
        }
        return node->data;
    }
    // Task5
     iterator begin(){
         return iterator(Sentinelfront->next);
     }
     iterator end(){
         return iterator(Sentinelback);
     }

//     Task6

    iterator insert(iterator iter, int myval){
        Node* mynode = iter.ptr;
        Node* newnode = new Node(myval, mynode->prev, mynode);
        mynode->prev->next = newnode;
        mynode->prev = newnode;
        ++mysize;
        return --iter;
    }

    // Task7
    iterator erase(iterator iter){
        if (mysize == 0){
            return iter;
        }
        Node* denode = iter.ptr;
        denode->next->prev = denode->prev;
        denode->prev->next = denode->next;
        Node* mynext = denode->next;
        delete denode;
        --mysize;
        return iterator(mynext);
    }

private:
        Node* Sentinelfront;
        Node* Sentinelback;
        size_t mysize;
};


// Task 1
void printListInfo(const List& myList) {
        cout << "size: " << myList.size()
             << ", front: " << myList.front()
             << ", back(): " << myList.back()
             << ", list: " << myList << endl;
}

// The following should not compile. Check that it does not.
// void changeFrontAndBackConst(const List& theList){
//     theList.front() = 17;
//     theList.back() = 42;
// }

void changeFrontAndBack(List& theList){
    theList.front() = 17;
    theList.back() = 42;
}

    // Task 4
    void printListSlow(const List& myList) {
        for (size_t i = 0; i < myList.size(); ++i) {
            cout << myList[i] << ' ';
        }
        cout << endl;
    }

//    // Task 8
//    void doNothing(List aList) {
//        cout << "In doNothing\n";
//        printListInfo(aList);
//        cout << endl;
//        cout << "Leaving doNothing\n";
//    }
//
     int main() {

        // Task 1
        cout << "\n------Task One------\n";
        List myList;
        cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
        for (int i = 0; i < 10; ++i) {
            cout << "myList.push_back(" << i*i << ");\n";
            myList.push_back(i*i);
            printListInfo(myList);
        }
        cout << "===================\n";

        cout << "Modify the first and last items, and display the results\n";
        changeFrontAndBack(myList);
        printListInfo(myList);
        cout << "===================\n";

        cout << "Remove the items with pop_back\n";
        while (myList.size()) {
            printListInfo(myList);
            myList.pop_back();
        }
        cout << "===================\n";

        // Task 2
        cout << "\n------Task Two------\n";
        cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
        for (int i = 0; i < 10; ++i) {
            cout << "myList2.push_front(" << i*i << ");\n";
            myList.push_front(i*i);
            printListInfo(myList);
        }
        cout << "===================\n";
        cout << "Remove the items with pop_front\n";
        while (myList.size()) {
            printListInfo(myList);
            myList.pop_front();
        }
        cout << "===================\n";

        // Task 3
        cout << "\n------Task Three------\n";
        cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
        for (int i = 0; i < 10; ++i) {
            myList.push_back(i*i);
        }
        printListInfo(myList);
        cout << "Now clear\n";
        myList.clear();
        cout << "Size: " << myList.size() << ", list: " << myList << endl;
        cout << "===================\n";
//
        // Task 4
        cout << "\n------Task Four------\n";
        cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
        for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
        cout << "Display elements with op[]\n";
        for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
        cout << endl;
        cout << "Add one to each element with op[]\n";
        for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
        cout << "And print it out again with op[]\n";
        for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
        cout << endl;
        cout << "Now calling a function, printListSlow, to do the same thing\n";
        printListSlow(myList);
        cout << "Finally, for this task, using the index operator to modify\n"
             << "the data in the third item in the list\n"
             << "and then using printListSlow to display it again\n";
        myList[2] = 42;
        printListSlow(myList);


        // Task 5
        cout << "\n------Task Five------\n";
        cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
        myList.clear();
        for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
        printListInfo(myList);
        cout << "Now display the elements in a ranged for\n";
        for (int x : myList) cout << x << ' ';
        cout << endl;
        cout << "And again using the iterator type directly:\n";
        // Note you can choose to nest the iterator class or not, your choice.
        //for (iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        for (List::iterator iter = myList.begin(); iter != myList.end(); ++iter) {
            cout << *iter << ' ';
        }
        cout << endl;
        cout << "WOW!!! (I thought it was cool.)\n";

        // Task 6
        cout << "\n------Task Six------\n";
        cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
        myList.clear();
        for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
        printListInfo(myList);
        cout << "Filling an empty list with insert at begin(): "
             << "i*i for i from 0 to 9\n";
        myList.clear();
        for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
        printListInfo(myList);
        // ***Need test for insert other than begin/end***
        cout << "===================\n";

        // Task 7
        cout << "\n------Task Seven------\n";
        cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
        myList.clear();
        for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
        cout << "Erasing the elements in the list, starting from the beginning\n";
        while (myList.size()) {
            printListInfo(myList);
            myList.erase(myList.begin());
        }
        // ***Need test for erase other than begin/end***
        cout << "===================\n";
//
//        // Task 8
//        cout << "\n------Task Eight------\n";
//        cout << "Copy control\n";
//        cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
//        myList.clear();
//        for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
//        printListInfo(myList);
//        cout << "Calling doNothing(myList)\n";
//        doNothing(myList);
//        cout << "Back from doNothing(myList)\n";
//        printListInfo(myList);
//
//        cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
//        List listTwo;
//        for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
//        printListInfo(listTwo);
//        cout << "listTwo = myList\n";
//        listTwo = myList;
//        cout << "myList: ";
//        printListInfo(myList);
//        cout << "listTwo: ";
//        printListInfo(listTwo);
//        cout << "===================\n";
    }

