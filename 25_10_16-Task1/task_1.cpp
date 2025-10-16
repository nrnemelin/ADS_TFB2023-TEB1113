#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

int main() {
    Node node1, node2, node3;
    
    node1.data = "test1";
    node2.data = "test2";
    node3.data = "test3";
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node1;
    
    cout << "Cyclic Linked List:" << endl;
    
    Node* current = &node1;
    for (int i = 0; i < 6; i++) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    
    return 0;
}
