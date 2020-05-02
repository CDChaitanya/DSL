#include<iostream>
using namespace std;
class queue
{
    int rear,front;
    int MAX;
    int *data;
    public:
    queue()
    {
        MAX=20;
        rear=front=-1;
        data=new int[MAX];
    }
    int empty()
    {
        if(front==-1)
        {
            return 1;
        }
        return 0;
    }
    int full()
    {
        if(rear==MAX-1)
        {
            return 1;
        }
        return 0;
    }
    int fullfront()
    {
        if(front==0)
        {
            return 1;
        }
        return 0;
    }
    void enqueueF(int x)
    {
        if(!fullfront())
        {
            if(empty())
            {
                front++;
                rear++;
                data[front]=x;
            }
            else
            {
                front--;
                data[front]=x;
            }   
        }
        else
        {
            cout<<"QUEUE IS FULL"<<endl;
        }
    }
    void enqueueR(int x)
    {
        if(!full())
        {
            if(empty())
            {
                front++;
            }
            rear++;
            data[rear]=x;
        }
        else
        {
            cout<<"LIST IS FULL"<<endl;
        }
    }
    int dequeueF()
    {
        if(!empty())
        {
            int x;
            x=data[front];
            if(front==rear)
            {
                front=rear=-1;
            }
            else
            {
                front++;     
            }
            return x;
        }
        else
        {
            cout<<"LIST IS EMPTY"<<endl;
        }
    }
    int dequeueR()
    {
        if(!empty())
        {
            int x=data[rear];
            if(front==rear)
            {
                front=rear=-1;
            }
            else
            {
                rear--;
            }
            return x;
        }
        else
        {
            cout<<"LIST IS EMPTY"<<endl;
        } 
    }
    void display()
    {
        for(int i=front;i<rear;i++)
        {
            cout<<data[i]<<endl;
        }
    }
};
int main()
{
	queue q;
	int x,j;
	while(1)
	{
	cout<<"1.Insert job at front"<<endl;
	cout<<"2.Insert job at back"<<endl;
	cout<<"3.Delete job at front"<<endl;
	cout<<"4.Delete job at back"<<endl;
	cout<<"5.Display queue"<<endl;
	cout<<"6.exit"<<endl;
	cin>>x;
	switch(x)
	{
		case 1:
		{
			cout<<"Enter job "<<endl;
			cin>>j;
			q.enqueueF(j);
			break;
		}
		case 2:
		{
			cout<<"Enter job "<<endl;
			cin>>j;
			q.enqueueR(j);
			break;
		}
		case 3:
		{
			cout<<"Deleted job is "<<q.dequeueF()<<endl;
			break;
		}
		case 4:
		{
			cout<<"Deleted job is "<<q.dequeueR()<<endl;
			break;
		}
		case 5:
		{
			q.display();
			break;
		}
		case 6:
		{
			exit(1);
		}
		default:
		cout<<"Enter valid choice"<<endl;
	}
	}
}