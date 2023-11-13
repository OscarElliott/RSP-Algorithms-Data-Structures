#include "LinkedList.h"
#include "BST.h"
#include "Graph.h"
#include <iostream>
#include <string>


using namespace std;

void run_Graph()
{
    Graph* g = new Graph();
    g->init_Graph(g, 10, true);
    g->insert_edge(g, 1, 2, true);
    g->insert_edge(g, 1, 3, true);
    g->insert_edge(g, 2, 4, false);
    g->insert_edge(g, 3, 4, true);
    g->insert_edge(g, 10, 4, true);
    g->insert_edge(g, 7, 3, false);
    g->insert_edge(g, 6, 10, true);
    g->print_Graph(g);
    cout << endl;
}

void run_BST()
{
    BST<int>* bst = new BST<int>();
    bst->insert(5, bst);
    bst->insert(10, bst);
    bst->insert(2, bst);
    bst->insert(7, bst);
    bst->inOrder(bst);
    cout << endl;

    // is 10 in BST?
    BST<int>* temp = bst->Search(bst, 10);
    if (temp != nullptr && temp->data == 10)
        cout << "10 is in the BST" << endl;
    else
        cout << "10 is not in the BST" << endl;

    // is 12 in BST?
    temp = bst->Search(bst, 12);
    if (temp != nullptr && temp->data == 12)
        cout << "12 is in the BST" << endl;
    else
        cout << "12 is not in the BST" << endl;

    cout << "Deleting 10" << endl;
    bst->deleteNode(10, bst);
    bst->inOrder(bst);
    cout << endl;

    cout << "Adding 15" << endl;
    bst->insert(15, bst);
    bst->inOrder(bst);
    cout << endl;

    cout << "Adding 25" << endl;
    bst->insert(25, bst);
    bst->inOrder(bst);
    cout << endl;

    cout << "Adding 14" << endl;
    bst->insert(14, bst);
    bst->inOrder(bst);
    cout << endl;

    cout << "Deleting 15" << endl;
    bst->deleteNode(15, bst);
    bst->inOrder(bst);
    cout << endl;

    return;
}

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
    return;
}

int main()
{
    string options[] = {"LinkedList", "Binry Search Tree", "Graph", "Exit"};
    int k = sizeof(options) / sizeof(options[0]);
    bool running = true;
    while(running)
    {
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
                cout<< "\n\n Test Finished\n\n" << endl;
                break;
            case 2:
                run_BST();
                cout<< "\n\n Test Finished\n\n" << endl;
                break;
            case 3:
                run_Graph();
                cout<< "\n\n Test Finished\n\n" << endl;
                break;
            case 4:
                running = false;;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;

}