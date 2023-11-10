#include "LinkedList.h"
#include <iostream>
#include <string>


using namespace std;

void run_LinkedList()
{
    LinkedList<int>* List = new LinkedList<int>(5);
    List->Insert(&List, 8);
    List->Insert(&List, 10);
    List->Insert(&List, 3);
    List->Insert(&List, 24);
    List->PrintList(List);

    // is 10 in list?
    LinkedList<int>* temp = List->Search(List, 10);
    if (temp != nullptr && temp->data == 10)
        cout << "10 is in the List" << endl;
    else
        cout << "10 is not in the List" << endl;
    // is 12 in the list?
    temp = List->Search(List, 12);
    if (temp != nullptr && temp->data == 12)
        cout << "12 is in the List" << endl;
    else
        cout << "12 is not in the List" << endl;
    // check predecessor works
    temp = List->PredecessorList(List, 10);
    if (temp != nullptr && temp->data == 3)
        cout << "Predecessor function works!" << endl;
    else
        cout << "Predecessor function does not work" << endl;
    List->PrintList(List);

    cout << "Deleting 10" << endl;
    List->Delete_List(&List, 10);
    List->PrintList(List);

    cout << "Deleting 5" << endl;
    List->Delete_List(&List, 5);
    List->PrintList(List);

    cout << "Deleting 24" << endl;
    List->Delete_List(&List, 24);
    List->PrintList(List);

    delete List;
}

int main()
{
    string options[] = {"LinkedList"};
    int k = sizeof(options) / sizeof(options[0]);    
    cout<< "What would you like to run?" << endl;
    for (int i = 0; i<k; i++)
    {
        cout << i+1 << ". " << options[i] << endl;
    }
    int choice;
    cout << "Select your choice (1-k): ";
    cin >> choice;

    switch (choice) 
    {
        case 1:
            run_LinkedList();
            break;
        default:
            cout << "Invalid choice" << endl;
    }

    return 0;

}