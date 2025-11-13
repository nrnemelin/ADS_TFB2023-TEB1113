#include <iostream>
#include <string>

// --- Part 1: The Node for a Tree ---
struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int value) {
    data = value;
    left = nullptr;
    right = nullptr;
  }
};

// --- Part 2: The Binary Search Tree (BST) Class ---
class BinarySearchTree {
private:
  Node* root;
  Node* insertRecursive(Node* currentNode, int value) {
    // 1. Base Case: If the spot is empty, create the new node here
    if (currentNode == nullptr) {
      return new Node(value);
    }

    // 2. Recursive Step: Go left or right
    if (value < currentNode->data) {
      currentNode->left = insertRecursive(currentNode->left, value);
    } else {
      currentNode->right = insertRecursive(currentNode->right, value);
    }
    
    return currentNode;
  }

  // Recursive helper for printing "In-Order"
  // (Left, Root, Right) - This prints a sorted list!
  void inOrderRecursive(Node* currentNode) {
    if (currentNode == nullptr) {
      return;
    }
    
    inOrderRecursive(currentNode->left);  // 1. Go Left
    std::cout << currentNode->data << " "; // 2. Print Root
    inOrderRecursive(currentNode->right); // 3. Go Right
  }

  // Recursive helper for "Pre-Order"
  // (Root, Left, Right) - Useful for copying a tree
  void preOrderRecursive(Node* currentNode) {
    if (currentNode == nullptr) {
      return;
    }

    std::cout << currentNode->data << " "; // 1. Print Root
    preOrderRecursive(currentNode->left);  // 2. Go Left
    preOrderRecursive(currentNode->right); // 3. Go Right
  }

  // Recursive helper for "Post-Order"
  // (Left, Right, Root) - Useful for deleting a tree
  void postOrderRecursive(Node* currentNode) {
    if (currentNode == nullptr) {
      return;
    }

    postOrderRecursive(currentNode->left);  // 1. Go Left
    postOrderRecursive(currentNode->right); // 2. Go Right
    std::cout << currentNode->data << " "; // 3. Print Root
  }

  void destroyRecursive(Node* currentNode) {
    if (currentNode == nullptr) {
      return;
    }
    
    destroyRecursive(currentNode->left);  // Delete left
    destroyRecursive(currentNode->right); // Delete right side
    delete currentNode;                 // Delete this node
  }


public:

  BinarySearchTree() {
    root = nullptr;
  }

  ~BinarySearchTree() {
    std::cout << "\n(Cleaning up the tree...)" << std::endl;
    destroyRecursive(root);
  }

  void insert(int value) {
    std::cout << "Inserting: " << value << std::endl;
    root = insertRecursive(root, value);
  }

  // Public "In-Order" traversal
  void printInOrder() {
    std::cout << "In-Order (Sorted): ";
    inOrderRecursive(root);
    std::cout << std::endl;
  }

  // Public "Pre-Order" traversal
  void printPreOrder() {
    std::cout << "Pre-Order (Root-L-R): ";
    preOrderRecursive(root);
    std::cout << std::endl;
  }

  // Public "Post-Order" traversal
  void printPostOrder() {
    std::cout << "Post-Order (L-R-Root): ";
    postOrderRecursive(root);
    std::cout << std::endl;
  }
};


// --- Part 3: Main Execution ---
int main() {
  BinarySearchTree myTree;

  myTree.insert(50);
  myTree.insert(30);
  myTree.insert(70);
  myTree.insert(20);
  myTree.insert(40);
  myTree.insert(60);
  myTree.insert(80);

  /*
   The tree will look like this:
          50
         /  \
        30    70
       / \   / \
      20 40 60 80
  */

  std::cout << "\n--- Printing Tree Traversals ---" << std::endl;
  
  // 1. In-Order will print the numbers sorted
  myTree.printInOrder();

  // 2. Pre-Order prints the root first
  myTree.printPreOrder();

  // 3. Post-Order prints the root last
  myTree.printPostOrder();

  return 0;
}
