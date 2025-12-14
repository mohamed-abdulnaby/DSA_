#include <iostream>
#include "Node.h"
#include "BST.h"

using namespace std;

int main() {
    employee empTree;

    // Insert nodes
    empTree.Insert(50);
    empTree.Insert(30);
    empTree.Insert(70);
    empTree.Insert(20);
    empTree.Insert(40);
    empTree.Insert(60);
    empTree.Insert(80);

    cout << "Inserted nodes: 20, 30, 40, 50, 60, 70, 80" << endl;

    // Search for a node
    Node* searchNode = empTree.Search(40);
    if (searchNode)
        cout << "Found node with ID 40" << endl;
    else
        cout << "Node with ID 40 not found" << endl;

    // Get Min and Max
    Node* minNode = empTree.GetMin();
    Node* maxNode = empTree.GetMax();
    if (minNode) cout << "Min ID: " << minNode->ID << endl;
    if (maxNode) cout << "Max ID: " << maxNode->ID << endl;

    // Delete a node
    cout << "Deleting node with ID 30" << endl;
    empTree.Delete(30);

    // Search for deleted node
    searchNode = empTree.Search(30);
    if (!searchNode)
        cout << "Node with ID 30 successfully deleted" << endl;
    else
        cout << "Node with ID 30 still exists" << endl;

    // Check min and max after deletion
    minNode = empTree.GetMin();
    maxNode = empTree.GetMax();
    if (minNode) cout << "Min ID after deletion: " << minNode->ID << endl;
    if (maxNode) cout << "Max ID after deletion: " << maxNode->ID << endl;

    return 0;
}
