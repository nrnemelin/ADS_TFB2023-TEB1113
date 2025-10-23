#include <iostream>
#include <string>
#include <stdexcept> 

struct Node {
  std::string data;
  Node* next;
};

class Stack {
private:
  Node* top; // Always points to the top item

public:
  Stack() {
    top = nullptr;
  }

  // Destructor (cleans up memory)
  ~Stack() {
    while (!isEmpty()) {
      pop();
    }
  }

  // push(): Add an element to the TOP of stack
  void push(std::string value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top; // New node points to previous top
    top = newNode;       // Top is updated to the new node
    std::cout << "Pushed: " << value << std::endl;
  }

  // pop(): Remove an element from the TOP of stack
  std::string pop() {
    if (isEmpty()) {
      throw std::runtime_error("Stack is empty");
    }
    std::string valueToReturn = top->data;
    Node* oldTop = top;
    top = top->next; // Move top downwards
    delete oldTop;   // Free memory
    return valueToReturn;
  }

  bool isEmpty() {
    return top == nullptr;
  }
};

int main() {
  Stack myStack;

  std::cout << "--- Pushing items ---" << std::endl;
  myStack.push("test1"); // Added first (bottom)
  myStack.push("test2"); // Added second (middle)
  myStack.push("test3"); // Added last (top)

  std::cout << "\n--- Popping items ---" << std::endl;
  // It will pop in LIFO (Last-In, First-Out) order
  while (!myStack.isEmpty()) {
    std::cout << myStack.pop() << std::endl;
  }
  
  return 0;
}

