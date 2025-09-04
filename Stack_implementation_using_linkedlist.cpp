#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
    int data;
    Node * prev;
    Node * next;
    Node(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

// implementing a stack using doubly Linked list 

class stack{

    Node* pointer;
    public:
    stack(){
        pointer = nullptr;
    }

    bool Push(int x)
    {
        Node * nextptr = new Node(x);
        if(!pointer)
        {
            pointer = nextptr;
            return true;
        }
        pointer->next = nextptr;
        nextptr->prev = pointer;
        pointer = nextptr;
        return true;
    }

  bool Pop(){
    if(!pointer)
        return false;
    Node * temp = pointer;
    Node * pre = temp->prev;
    if(pre) 
     pre->next = nullptr;
    
    pointer = pre;
    delete temp;
    return true;
}


    int Peek(){
        if(!pointer)
        return -1;

        return pointer->data;
    }

    bool IsEmpty(){
     if(!pointer)return true;
     return false;
    }
};


int main()
{
    stack stk;
    stk.Push(1);
    stk.Push(2);
    stk.Push(3);
    stk.Push(4);
    stk.Push(5);
    stk.Push(6);
    stk.Push(7);

    while(!stk.IsEmpty())
    {
        cout << stk.Peek() << " ";
        stk.Pop();
    }
    

}