#include <iostream>

// --- 1. Tree Representation ---
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

// --- 2. Binary Tree Implementation ---
class BinarySearchTree {
private:
    Node* root;

    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }
        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = insertRecursive(current->right, value);
        }
        return current;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteRecursive(Node* current, int value) {
        if (current == nullptr) return current;

        // Step 1: Find the node to delete
        if (value < current->data) {
            current->left = deleteRecursive(current->left, value);
        } else if (value > current->data) {
            current->right = deleteRecursive(current->right, value);
        } else {
            // Step 2: We found the node! Now delete it.
            
            // Case 1: No child (Leaf node) or One child
            if (current->left == nullptr) {
                Node* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == nullptr) {
                Node* temp = current->left;
                delete current;
                return temp;
            }

            // Case 2: Two children
            // Find smallest value in the right subtree
            Node* temp = findMin(current->right);
            
            current->data = temp->data;
            
            current->right = deleteRecursive(current->right, temp->data);
        }
        return current;
    }

    bool searchRecursive(Node* current, int value) {
        if (current == nullptr) return false;
        if (current->data == value) return true;

        if (value < current->data) {
            return searchRecursive(current->left, value);
        } else {
            return searchRecursive(current->right, value);
        }
    }

    // --- 3. Tree Traversal Algorithms ---
    void inOrderRecursive(Node* current) {
        if (current == nullptr) return;
        inOrderRecursive(current->left);
        std::cout << current->data << " ";
        inOrderRecursive(current->right);
    }

    void preOrderRecursive(Node* current) {
        if (current == nullptr) return;
        std::cout << current->data << " ";
        preOrderRecursive(current->left);
        preOrderRecursive(current->right);
    }

    void postOrderRecursive(Node* current) {
        if (current == nullptr) return;
        postOrderRecursive(current->left);
        postOrderRecursive(current->right);
        std::cout << current->data << " ";
    }

public:
    BinarySearchTree() { root = nullptr; }

    // --- 4. Insert, Delete, Update Operations ---
    
    void insert(int value) {
        root = insertRecursive(root, value);
        std::cout << "Inserted: " << value << std::endl;
    }

    void deleteNode(int value) {
        root = deleteRecursive(root, value);
        std::cout << "Deleted: " << value << std::endl;
    }

    void update(int oldValue, int newValue) {
        if (searchRecursive(root, oldValue)) {
            std::cout << "Updating " << oldValue << " to " << newValue << "..." << std::endl;
            deleteNode(oldValue);
            insert(newValue);
        } else {
            std::cout << "Error: Value " << oldValue << " not found in tree." << std::endl;
        }
    }

    // Traversals
    void displayInOrder() {
        std::cout << "In-Order: ";
        inOrderRecursive(root);
        std::cout << std::endl;
    }
    
    void displayPreOrder() {
        std::cout << "Pre-Order: ";
        preOrderRecursive(root);
        std::cout << std::endl;
    }

    void displayPostOrder() {
        std::cout << "Post-Order: ";
        postOrderRecursive(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree tree;

    // 1. Inserting Elements
    std::cout << "--- 1. Inserting Elements ---" << std::endl;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // 2. Traversals
    std::cout << "\n--- 2. Tree Traversals ---" << std::endl;
    tree.displayInOrder();
    tree.displayPreOrder();
    tree.displayPostOrder();

    // 3. Updating Elements
    std::cout << "\n--- 3. Updating Element (30 -> 35) ---" << std::endl;
    tree.update(30, 35);
    tree.displayInOrder();

    // 4. Deleting Elements
    std::cout << "\n--- 4. Deleting Element (20) ---" << std::endl;
    tree.deleteNode(20);
    tree.displayInOrder();

    return 0;
}
