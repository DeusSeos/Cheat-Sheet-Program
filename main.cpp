#include <iostream>
#include <vector>
#include <string>
#include "Tree.hpp"
#include "BinarySearchTree.hpp"


using namespace std;




void sbstMenu(){
    cout << "1. Insert" << endl;
    cout << "2. Remove" << endl;
    cout << "3. Find" << endl;
    cout << "4. Clear" << endl;
    cout << "5. Print" << endl;
    cout << "6. Quit" << endl;
}

void rbtMenu(){
    cout << "1. Insert" << endl;
    cout << "2. Remove" << endl;
    cout << "3. Find" << endl;
    cout << "4. Clear" << endl;
    cout << "5. Print" << endl;
    cout << "6. Quit" << endl;
}



// main menu funtion to select which datastructure to run
// 1. Tree
// 2. Binary Search Tree
// 3. Self Balancing Binary Search Tree
// 4. Red Black Tree
// 5. Exit
void mainMenu(){
    int choice;
    cout << "1. Tree" << endl;
    cout << "2. Binary Search Tree" << endl;
    cout << "3. Self Balancing Binary Search Tree" << endl;
    cout << "4. Red Black Tree" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice){
        case 1:
            treeMenu();
            break;
        case 2:
            BSTmenu();
            break;
        case 3:
            sbstMenu();
            break;
        case 4:
            rbtMenu();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
            mainMenu();
            break;
    }

}


// main function for selecting which data structure to use
int main(int argc, char *argv[]) {
    mainMenu();
    return 0;

}

