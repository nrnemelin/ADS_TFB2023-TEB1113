#include <iostream>
#include <string>
#include <stdexcept>

// --- Part 1: The Node (The Person in Line) ---
struct Node {
  std::string data;
  Node* next; 
};

// --- Part 2: The Queue Class (The Line Manager) ---
class Queue {
private:
  Node* front;
  Node* rear;

public:
  Queue() {
    front = nullptr;
    rear = nullptr;
  }

  ~Queue() {
    while (!isEmpty()) {
      dequeue();
    }
  }

  // ENQUEUE: Add to the BACK (Rear)
  void enqueue(std::string value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (isEmpty()) {
      front = newNode;
      rear = newNode;
    } else {
      // 1. Link the old rear to the new node
      rear->next = newNode;
      // 2. Update rear to point to the new node
      rear = newNode;
    }
    std::cout << "Enqueued (Joined Line): " << value << std::endl;
  }

  // DEQUEUE: Remove from the FRONT
  std::string dequeue() {
    if (isEmpty()) {
      throw std::runtime_error("Queue is empty!");
    }

    // 1. Get data from front
    std::string valueToReturn = front->data;

    // 2. Remember the old front node
    Node* oldFront = front;

    // 3. Move front to the next person
    front = front->next;

    // 4. Special case: If line is now empty, make sure rear is null too
    if (front == nullptr) {
      rear = nullptr;
    }

    // 5. Delete the old front node
    delete oldFront;

    return valueToReturn;
  }

  bool isEmpty() {
    return front == nullptr;
  }
};

// --- Part 3: Main Execution ---
int main() {
  Queue myQueue;

  std::cout << "--- Enqueueing (Joining the line) ---" << std::endl;
  myQueue.enqueue("test1");
  myQueue.enqueue("test2");
  myQueue.enqueue("test3"); 

  std::cout << "\n--- Dequeueing (Leaving the line) ---" << std::endl;
  
  while (!myQueue.isEmpty()) {
    std::cout << myQueue.dequeue() << std::endl;
  }

  return 0;
}
