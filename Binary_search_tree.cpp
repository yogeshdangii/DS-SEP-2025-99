#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* left;
    Node* right;
    bool isEmpty; 

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
        if (target < data && left->search(target))
        return true; 
        return right->search(target);
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

    cout << "Pre-order Traversal: ";
    tree.preorder(); cout << endl;

    cout << "Post-order Traversal: ";
    tree.postorder(); cout << endl;


    return 0;
}
