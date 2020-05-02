#include<iostream>
using namespace std;
class queue
{
    int *data;
    int rear;
    int front;
    int max;
    public:
    queue()
    {
        max=20;
        front=rear=-1;
        data=new int[max];
    }
    int empty()
    {
        if(front==rear)
        {
            return 1;
        }
        return 0;
    }
    int full()
    {
        if(((rear+1)%max)==front)
        {
            return 1;
        }
        return 0;
    }
    void enqueue(int x)
    {
        if(full())
        {
            cout<<"LIST IS FULL"<<endl;
        }
        else
        {
            rear=(rear+1)%max;
            data[rear]=x;
        }
    }
    int dequeue()
    {
        int x=-1;
        if(empty())
        {
            cout<<"LIST IS EMPTY"<<endl;
        }
        else
        {
            front=(front+1)%max;
            x=data[front];
        }
        return x;
    }
    void display()
    {
        if(empty())
        {
            cout<<"LIST IS EMPTY"<<endl;
        }
        else
        {
            cout<<"THE LIST IS "<<endl;
            for(int i=front+1;i<=rear;i++)
            {
                cout<<data[i]<<endl;
            }
        }
    }
};
int main()
{
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50); 
    q.display();
    cout<<"THE DELETED ELEMENT IS "<<q.dequeue()<<endl;
    cout<<"THE DELETED ELEMENT IS "<<q.dequeue()<<endl;
    q.display();
    return 0;
}