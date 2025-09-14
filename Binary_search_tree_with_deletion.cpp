#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* left;
    Node* right;
    bool isEmpty; 
    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }
public:
    Node() {
        isEmpty = true;
        left = right = nullptr;
    }
    void insert(int val) {
        if (isEmpty) {
            data = val;
            isEmpty = false;
            return;
        }
        if (val < data) {
            if (!left) left = new Node();
            left->insert(val);
        } else if (val > data) {
            if (!right) right = new Node();
            right->insert(val);
        }
    }
    bool search(int target) {
        if (isEmpty) return false;
        if (target == data) return true;
        if (target < data) return left ? left->search(target) : false;
        return right ? right->search(target) : false;
    }
    Node* deleteNode(Node* root, int key) {
        if (!root || root->isEmpty) return root;

        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            } else if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* succ = findMin(root->right);
                root->data = succ->data;
                root->right = deleteNode(root->right, succ->data);
            }
        }
        return root;
    }
    void remove(int val) {
        if (!isEmpty) {
            Node* updated = deleteNode(this, val);
            if (!updated) { 
                isEmpty = true;
                left = right = nullptr;
            } else if (updated != this) {
                *this = *updated;
            }
        }
    }
    void inorder() {
        if (isEmpty) return;
        if (left) left->inorder();
        cout << data << " ";
        if (right) right->inorder();
    }
    void preorder() {
        if (isEmpty) return;
        cout << data << " ";
        if (left) left->preorder();
        if (right) right->preorder();
    }
    void postorder() {
        if (isEmpty) return;
        if (left) left->postorder();
        if (right) right->postorder();
        cout << data << " ";
    }
};

int main() {
    Node tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order Traversal: ";
    tree.inorder(); cout << endl;

    cout << "Deleting 20";
    tree.remove(20);
    tree.inorder(); cout << endl;

    cout << "Deleting 30";
    tree.remove(30);
    tree.inorder(); cout << endl;

    cout << "Deleting 50";
    tree.remove(50);
    tree.inorder(); cout << endl;

    return 0;
}
