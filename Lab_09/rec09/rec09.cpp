//
//  main.cpp
//  rec09
//
//  Created by Sarah Xiao on 4/3/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
public:
    PrintedMaterial( unsigned mynum ): numberOfPages(mynum) {}
//    virtual void displayNumPages() const {
//        cout << numberOfPages << endl;
//    }
      virtual void displayNumPages() const = 0;
protected:
private:
    unsigned numberOfPages;
};

void PrintedMaterial::displayNumPages() const {
  cout << numberOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
    Magazine( unsigned mynum ): PrintedMaterial(mynum) {}
    void displayNumPages() const{
        cout << "Hi, I'm a Magazine object stored\n"
             << "(but I can't know that I am being\n"
             << "stored (by pointer) in a vector of\n"
             << "PrintedMaterial pointers!\n";
        PrintedMaterial::displayNumPages();
        cout << "(and I'm very glossy!\n";
    }

protected:
private:
};

class Book : public PrintedMaterial {
public:
    Book( unsigned mynum ): PrintedMaterial(mynum) {}
protected:
private:
};

class TextBook : public Book {
public:
    TextBook ( unsigned mynum, unsigned indexnum ): Book(mynum), numOfIndexPages(indexnum) {}
    void displayNumPages() const {
        cout << "Pages: ";
        PrintedMaterial::displayNumPages();
        cout << "Index pages: ";
        cout << numOfIndexPages << endl;
    }
    
protected:
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    Novel( unsigned mynum ): Book(mynum) {}
    void displayNumPages() const
    {
        cout << "\nThis is the story of a very\n"
             << " interesting programmer's quest\n"
             << "  understand inheritance.\n"
             << "   The journey is just beginning\n"
             << "    and already the journeyman\n"
             << "      hacker, no - not a hacker! -\n"
             << "         a programmer who reads, and\n"
             << "             studies and understands code\n"
             << "                 Hackers steal and don't even\n"
             << "                      try to understand what they stole\n"
             << "                           before using it.\n"
             << "\n       ...But I digress.\n"
             << "\nThis novel is quite long, there\n"
             << "being this number of pages:\n"
             << "=====================================\n"
             << "                 ";
        PrintedMaterial::displayNumPages();
        cout << "=====================================\n"
             << "Whew!\n"
             << " but there is an exciting\n"
             << "  programming adventure on every\n"
             << "   single one of them!\n"
             << "    And now, let's let the quest continue..."
             << endl << endl << endl;
    }
protected:
private:
};

void displayNumPages(const PrintedMaterial& pm){
    pm.displayNumPages();
}

int main()
{
    TextBook t(5430, 234);
    Novel n(213);
    Magazine m(6);
    // as direct method calls
    cout << "\nEach will now be asked directly,\n"
         << "using the dot member operator to\n"
         << "display its number of pages:\n";
    t.displayNumPages();
    n.displayNumPages();
    m.displayNumPages();
    // Storing generic objects in a vector
    cout << "\n\nNow we'll use a container. Yea!!!\n\n";
    vector< PrintedMaterial* > allThemPrinties;
    allThemPrinties.push_back(&t);
    allThemPrinties.push_back(&n);
    allThemPrinties.push_back(&m);
    for( size_t ndx=0; ndx < allThemPrinties.size(); ++ ndx )
    {
        allThemPrinties[ndx]->displayNumPages();
        cout << endl;
    }
//    cout << "\nA PrintedMaterial material object!\n";
//    pm.displayNumPages();
//    cout << "\nA PrintedMaterial variable containing a TextBook value\n";
//    pm = t; // like putting a t into a vector of PrintedMaterials
//    pm.displayNumPages();
//    cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
//    cout << "Now with the virtual mechanism involved\n";
//    cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
//    cout << "Now with the virtual mechanism involved\n";
//    PrintedMaterial* pmPtr;
//    pmPtr = &t;
//    pmPtr->displayNumPages();
//    cout << "\nUse a generic function for printing\n";
//    displayNumberOfPages(m);
//    displayNumberOfPages(n);
//    displayNumberOfPages(t);
    }
