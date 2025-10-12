#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;
};

int main() {

    Node node1, node2, node3;
    
    node1.data = "test1";
    node1.prev = NULL;
    node1.next = &node2;
    
    node2.data = "test2";
    node2.prev = &node1;
    node2.next = &node3;
    
    node3.data = "test3";
    node3.prev = &node2;
    node3.next = NULL;
    
    cout << "Forward: ";
    Node* current = &node1;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    
    cout << "Backwards: ";
    current = &node3;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
    
    return 0;
}
