#include<iostream>

using namespace std;

class queue{
    int arr[10000];
    int size;
    int front;
    int back;
    public:
    queue(){
        front = -1;
        back = -1;
        size = 10000;
    }

    bool Enqueue(int x){
      if( (back+1)%size == front )
      return false;
      if(front == -1)
       front++;
      back++;
      back %= size;
      arr[back] = x;
      return true;
    }

    bool Dequeue(){
        if(front == -1)
        return false;
        if( front == back )
        {
          front = -1;
          back = -1;
          return true;
        }
        front++;
        front %= size;
        return true;
    }
    int Front(){
        if(front == -1 )
        return -1;
        return arr[front];
    }

    bool IsEmpty(){
        if(front == -1 && back == -1)
        return true;
    return false;
    }

};

int main(){
    // Enqueue
    // Dequeue
    // Front
    // IsEmpty

    queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
     
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    cout << q.IsEmpty();
    cout << q.Front();

}