//
//  main.cpp
//  rec13
//
//  Created by Sarah Xiao on 5/1/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;

//task 9
void printlst(const list<int>& mylst){
//    for (list<int>::iterator iter = mylst.begin(); iter != mylst.end(); iter++){
//           cout << *iter << " ";
//       }
    for (list<int>::const_iterator iter = mylst.begin(); iter != mylst.end(); iter++){
           cout << *iter << " ";
       }
    cout << endl;
}

//task 10
void forprintlst(const list<int>& lst){
    for (int item : lst){
        cout << item << " ";
    }
    cout << endl;
}

//task 11
void lstalterauto(const list<int>& lst){
    for (auto iter = lst.begin(); iter != lst.end(); iter++){
        cout << *iter << " ";
        iter++;
    }
    cout << endl;
}
//task 12
list<int>::const_iterator lst_find(const list<int>& lst, int val){
    for (list<int>::const_iterator iter = lst.begin(); iter != lst.end(); iter++){
        if (*iter == val){
            return iter;
        }
    }
    return lst.end();
}
void itertest(const list<int>& lst, int val){
    if (lst_find(lst, val) == lst.end()){
        cout << "number not found";
    }
    else {
        cout << "number present!";
    }
    cout << endl;
}
//task 13
auto autolst_find(const list<int>& lst, int val){
    for (auto iter = lst.begin(); iter != lst.end(); iter++){
        if (*iter == val){
            return iter;
        }
    }
    return lst.end();
}
void autoitertest(const list<int>& lst, int val){
    if (autolst_find(lst, val) == lst.end()){
        cout << "number not found";
    }
    else {
        cout << "number present!";
    }
    cout << endl;
}
//task 14 calls generic find algorithm
void finditertest(const list<int>& lst, int val){
    if (find(lst.begin(), lst.end(), val) == lst.end()){
        cout << "number not found";
    }
    else {
        cout << "number present!";
    }
}
//task 15 calls find_if algorithm
bool ifEven(int val){
    if (val % 2 == 0){
        return true;
    }
    return false;
}

void find_if_itertest(const list<int>& lst){
    list<int>::const_iterator myiter = find_if(lst.begin(), lst.end(), ifEven);
    if (myiter == lst.end()){
        cout << "No even number found" << endl;
    }
    else {
        cout << "First even number is: " << *myiter << endl;
    }
}

//task 16 calls find_if algorithm
class ifEven_functor{
public:
    bool operator() (int val) const {
        return (val % 2 == 0);
    }
};
void functor_find_if_test(const list<int>& lst){
    list<int>::const_iterator myiter = find_if(lst.begin(), lst.end(), ifEven_functor());
    if (myiter == lst.end()){
        cout << "No even number found" << endl;
    }
    else {
        cout << "First even number is: " << *myiter << endl;
    }
}
//task 17
void lambda_find_if_test(const list<int>& lst){
    list<int>::const_iterator myiter = find_if(lst.begin(), lst.end(), [](int val) {return (val % 2 == 0);});
    if (myiter == lst.end()){
        cout << "No even number found" << endl;
    }
    else {
        cout << "First even number is: " << *myiter << endl;
    }
}

//Task 18
void array_print(int arr[], size_t size){
    if (arr){
        for (size_t i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void array_find(int arr[], int val, size_t size){
    if (find(arr, arr+size -1, 2) == arr+size -1){
        cout << "number not found";
        }
    else {
        cout << "number present!";
        }
    cout << endl;
}

//task 19
list<int>::const_iterator ourFind (list<int>::const_iterator begin, list<int>::const_iterator end, int val){
    cout << "my function!" << endl;
    for (list<int>::const_iterator iter = begin; iter != end; iter++){
        if (*iter == val){
            return iter;
        }
    }
    return end;
    
}
void ourFindtest(const list<int>& lst, int val){
    if (ourFind(lst.begin(), lst.end(), val) == lst.end()){
        cout << "number not found";
    }
    else {
        cout << "number present!";
    }
    cout << endl;
}

//task 20

template <typename T, typename Y>
T ourFind(T begin, T end, Y val){
    cout << "template function!" << endl;
    for (T iter = begin; iter != end; iter++){
        if (*iter == val){
            return iter;
        }
    }
    return end;
}

void ourFind_vectortest(const vector<int>& vec, int val){
    if (ourFind(vec.begin(), vec.end(), val) == vec.end()){
        cout << "number not found";
    }
    else {
        cout << "number present!";
    }
    cout << endl;
}

int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 8, 9};
    for (int val : v1){
        cout << val << " ";
    }
    cout << "\n=======\n";

    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> mylist(v1.begin(),v1.end());
    for (int item : mylist){
        cout << item << " ";
    }
    cout << "\n=======\n";

    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort(v1.begin(), v1.end());
//    list cannot be sorted the same way
    for (int val : v1){
        cout << val << " ";
    }
    cout << endl;
    for (int item : mylist){
        cout << item << " ";
    }

    cout << "\n=======\n";

    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    for (size_t i = 0; i< v1.size(); i+=2){
        cout << v1[i] << " ";
    }
    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
//    for (size_t i = 0; i< v1.size(); i+=2){
//        cout << mylist[i] << " ";
//    }
    cout << "\n=======\n";

    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    for (vector<int>::iterator iter = v1.begin(); iter != v1.end(); iter+=2){
        cout << *iter << " ";
    }
    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    for (list<int>::iterator iter = mylist.begin(); iter != mylist.end(); iter++){
        cout << *iter << " ";
        iter++;
    }
    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
    mylist.sort();
    for (int item : mylist){
        cout << item << " ";
    }
    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    printlst(mylist);
    cout << "=======\n";

    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    forprintlst(mylist);
    cout << "=======\n";

    //
    // Auto
    //
    
    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    lstalterauto(mylist);
    cout << "=======\n";

    
    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    cout << "Test result for item 2: ";
    itertest(mylist, 2);
    cout << "Test result for item 90: ";
    itertest(mylist, 90);
    cout << "=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    cout << "auto Test result for item 2: ";
    autoitertest(mylist, 2);
    cout << "auto Test result for item 90: ";
    autoitertest(mylist, 90);
    cout << "=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    cout << "find Test result for item 2: ";
    finditertest(mylist, 2);
    cout << endl;
    cout << "find Test result for item 90: ";
    finditertest(mylist, 90);
    cout << endl;
    cout << "=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    find_if_itertest(mylist);
//    case in which no even number is found
//    find_if_itertest(list2);
    cout << "=======\n";

    // 16. Functor
    cout << "Task 16:\n";
    functor_find_if_test(mylist);
    cout << "=======\n";
    
    // 17. Lambda
    cout << "Task 17:\n";
    [] { cout << "Hello Lambda!" << endl; }();
    lambda_find_if_test(mylist);
    cout << "=======\n";
    
    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int* arr = new int[v1.size()];
    copy(v1.begin(), v1.end(), arr);
    array_print(arr, v1.size());
    cout << "find Test result for item 2: " << endl;
    array_find(arr, 2, v1.size());
    cout << "find Test result for item 90: " << endl;
    array_find(arr, 90, v1.size());
    delete[] arr;
    arr = nullptr;
    // check if array is deleted
    array_print(arr, v1.size());
    cout << "=======\n";

    //
    // Templated Functions
    //

    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    cout << "find Test result for item 2: " << endl;
    ourFindtest(mylist, 2);
    cout << "find Test result for item 90: " << endl;
    ourFindtest(mylist, 90);
    cout << "=======\n";
    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    cout << "find Test result for item 2: " << endl;
    ourFind_vectortest(v1, 2);
    cout << "find Test result for item 90: " << endl;
    ourFind_vectortest(v1, 90);
    cout << "find Test result for item 2: " << endl;
    if (ourFind(mylist.begin(), mylist.end(), 2) == mylist.end()){
        cout << "number not found";
    }
    else {
        cout << "number present!";
    }
    cout << endl;
    cout << "find Test result for item 90: " << endl;
    if (ourFind(mylist.begin(), mylist.end(), 90) == mylist.end()){
        cout << "number not found";
    }
    else {
        cout << "number present!";
    }
    cout << endl;
    cout << "=======\n";
    
    //
    // Associative collections
    //

    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
    ifstream ifs("pooh-nopunc.txt");
    if (!ifs) {
        cerr << "Could not open file." << endl;
        exit(1);
    }
    vector<string> Allwords;
    string word;
    while (ifs >> word){
        bool wordpresent = false;
        for (size_t index = 0; index < Allwords.size(); ++index){
            if (Allwords[index] == word){
                wordpresent = true;
            }
        }
        if (!wordpresent){
            Allwords.push_back(word);
        }
    }
    cout << "Distinct word count: " << Allwords.size();
    ifs.close();
//    print all the words
//    for (string myword : Allwords) {
//       cout<< myword <<" ";
//    }

    cout << "\n=======\n";

    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    ifstream oneifs("pooh-nopunc.txt");
    if (!oneifs) {
        cerr << "Could not open file." << endl;
        exit(1);
    }
    set<string>myset;
    string aword;
    while (oneifs >> aword){
//        if (myset.find(aword) == myset.end()){
        myset.insert(aword);
//      }
    }
    cout << "Distinct word count: " << myset.size() << endl;
    oneifs.close();
//    print all the words
    //    for (string uword : myset) {
    //        cout<< uword <<" ";
    //    }
    cout << "=======\n";

    // 23. Word co-occurence using map
    cout << "Task 23:\n";
    ifstream otherifs("pooh-nopunc.txt");
    if (!otherifs) {
        cerr << "Could not open file." << endl;
        exit(1);
    }
    map<string, vector<int>> wordMap;
    string words;
    int count = 1;
    while (otherifs >> words){
        wordMap[words].push_back(count);
        count+= 1;
        }
    for (auto pair: wordMap){
        cout << pair.first;
        cout << ": positions: ";
        for (int m: pair.second){
            cout << m << " ";
        }
        cout << endl;
    }
    otherifs.close();
    cout << "=======\n";
}
