#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;    // Pointer to next node
    Node* prev;    // Pointer to previous node
};

int main() {
    // Create nodes
    Node node1, node2, node3;
    
    // Initialize node1 (head)
    node1.data = "test1";
    node1.prev = NULL;      // First node, no previous
    node1.next = &node2;    // Points to node2
    
    // Initialize node2
    node2.data = "test2";
    node2.prev = &node1;    // Points back to node1
    node2.next = &node3;    // Points to node3
    
    // Initialize node3 (tail)
    node3.data = "test3";
    node3.prev = &node2;    // Points back to node2
    node3.next = NULL;      // Last node, no next
    
    // Forward traversal
    cout << "Forward traversal: ";
    Node* current = &node1;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    
    // Backward traversal
    cout << "Backward traversal: ";
    current = &node3;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
    
    return 0;
}
