#include<iostream>
#include<vector>

using namespace std;

// implementing a stack using an array 

class stack{

    int arr[10000];
    int pointer;
    public:
    stack(){
        pointer = -1;
    }

    bool Push(int x)
    {
        pointer++;
        if(pointer == 10000)
        {
            cout << "Stack overflow" << endl;
            return false;
        }
        arr[pointer] = x;
        return true; 
    }

    bool Pop(){
        if(pointer == -1)
        {
            cout << "Stack Underflow" << endl;
            return false;
        }
        pointer--;
        return true;
    }

    int Peek(){
        if(pointer == -1 )
        return -1;
        if(pointer == 10000 )
         pointer--;
        return arr[pointer];
    }

    bool IsEmpty(){
        if(pointer == -1)
        return true;
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