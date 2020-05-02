#include<iostream>
using namespace std;
class stack
{
    int MAX;
    int top;
    int data[100];
    public:
    stack()
    {
        MAX=100;
        top=-1;
    }
    int isempty()
    {
        if(top==-1)
        {
            return 1;
        }
        return 0;
    }
    int isfull()
    {
        if(top==MAX-1)
        {
            return 1;
        }
        return 0;
    }
    void push(int x)
    {
        if(isfull())
        {
            cout<<"STACK OVERFLOW"<<endl;
        }
        else
        {
            top++;
            data[top]=x;
        }
    }
    int pop()
    {
        int x=-1;
        if(isempty())
        {
            cout<<"STACK UNDERFLOW"<<endl;
        }
        else
        {
            x=data[top];
            top--;
        }
        return x;       
    }
    void TOP()
    {
        if(isempty())
        {
            cout<<"STACK IS EMPTY"<<endl;
        }
        else
        {
            cout<<"THE TOP ELEMENT IS "<<data[top]<<endl;
        }
    }
    void peek(int pos)
    {
        if(top-pos+1<0)
        {
            cout<<"INVALID POSITION"<<endl;
        }
        else
        {
            cout<<"THE ELEMENT AT "<<pos<<" IS "<<data[top-pos+1]<<endl;
        }
    }
    void display()
    {
        if(isempty())
        {
            cout<<"EMPTY"<<endl;
        }
        else
        {
            int i=top;
            for(i=top;i>=0;i--)
            {
                cout<<data[i]<<endl;
            }
        }
    }
};
int main()
{
    stack s;
    int choice,x,pos;
    do
    {
        cout<<"1. PUSH"<<endl;
        cout<<"2. POP"<<endl;
        cout<<"3. TOP"<<endl;
        cout<<"4. peek"<<endl;
        cout<<"5. DISPLAY"<<endl;
        cout<<"ENTER YOUR CHOICE"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
        {
            cout<<"NUMBER ....?"<<endl;
            cin>>x;
            s.push(x);
            break;
        }
        case 2:
        {
            x=s.pop();
            cout<<"THE POPED ELEMENT IS "<<x<<endl;
            break;
        }
        case 3:
        {
            s.TOP();
            break;
        }
        case 4:
        {
            cout<<"POSITION .....?"<<endl;
            cin>>pos;
            s.peek(pos);
            break;
        }
        case 5:
        {
            cout<<"THE STACK IS ===>"<<endl;
            s.display();
            break;
        }
        case 6:
        {
            exit(1);
            break;
        }
        default:
        {
            cout<<"INVALID INPUT"<<endl;
        }
        }
    } while(1);
}