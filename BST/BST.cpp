#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if(root == nullptr){
    return;
  } else {
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
  }

}

// Insert a node
struct node *insertNode(struct node *root, int key) {
  if(root == nullptr) {
    root = new node;
    root->key = key;
    root->left = nullptr;
    root->right = nullptr;
  } else if(root->key > key) {
    root->left = insertNode(root->left, key);
  } else if(root->key < key) {
    root->right = insertNode(root->right, key);
  }
  return root;
}

//find max
int findMax(node *root) {
  while(root->right != nullptr) {
    root = root->right;
  }
  return root->key;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if(root == nullptr) {
    return root;
  } else if(root->key == key) {
    if(root->left == nullptr && root->right == nullptr) {
      delete root;
      root = nullptr;
    } else if(root->left == nullptr) {
      node *temp = root;
      root = root->right;
      delete temp;
    } else if(root->left == nullptr) {
      node *temp = root;
      root = root->left;
      delete temp;
    } else {
      int maxValue = findMax(root->left);
      root->key = maxValue;
      root->left = deleteNode(root->left, maxValue);
    }
  } else if(root->key > key) {
    root->left = deleteNode(root->left, key);
  } else if(root->key < key) {
    root->right = deleteNode(root->right, key);
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}