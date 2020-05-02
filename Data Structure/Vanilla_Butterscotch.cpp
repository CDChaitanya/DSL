#include<iostream>
#include<string.h>
using namespace std;
class node
{
    int roll;
    char name[20];
    node *next;
    public:
    node(int x, char *p)
    {
        roll=x;
        strcpy(name,p);
        next=NULL;
    }
    friend class sll;
};
class sll
{
    node *head;
    public:
    sll()
    {
        head=NULL;
    }
    void Add_end(int x,char* a)
    {
        node *p,*q;
        q=new node(x,a);
        if(head==NULL)
        {
            head=q;
        }
        else
        {
            p=head;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=q;
        }
    }
    void show()
    {
        node *p;
        p=head;
        while(p!=NULL)
        {
            cout<<p->roll<<" "<<p->name<<endl;
            p=p->next;
        }
    }
    void uni(sll a,sll b)
    {
        node *p,*q;
        p=a.head;
        q=b.head;
        while(p!=NULL)
        {
            Add_end(p->roll,p->name);
            p=p->next;
        }
        while(q!=NULL)
        {
            int flag=1;
            p=a.head;
            while(p!=NULL)
            {
                if(p->roll==q->roll)
                {
                    flag=0;
                    break;
                }
                p=p->next;
            }
            if(flag)
            {
                Add_end(q->roll,q->name);
            }
            q=q->next;
        }
    }
    void inter(sll a, sll b)
    {
        node *p,*q;
        q=b.head;
        while(q!=NULL)
        {
            int flag=1;
            p=a.head;
            while(p!=NULL)
            {
                if(p->roll==q->roll)
                {
                    flag=0;
                    break;
                }
                p=p->next;
            }
            if(!flag)
            {
                Add_end(q->roll,q->name);
            }
            q=q->next;
        }
    }
    void van(sll a, sll b)
    {
        node *p,*q;
        p=a.head;
        while(p!=NULL)
        {
            int flag=1;
            q=b.head;
            while(q!=NULL)
            {
                if(q->roll==p->roll)
                {
                    flag=0;
                    break;
                }
                q=q->next;
            }
            if(flag)
            {
                Add_end(p->roll,p->name);
            }
            p=p->next;
        }
    }
    void butter(sll a, sll b)
    {
        node *p,*q;
        q=b.head;
        while(q!=NULL)
        {
            int flag=1;
            p=a.head;
            while(p!=NULL)
            {
                if(p->roll==q->roll)
                {
                    flag=0;
                    break;
                }
                p=p->next;
            }
            if(flag)
            {
                Add_end(q->roll,q->name);
            }
            q=q->next;
        }
    }
    int count()                                  //??? MINOR PROBLEM
    {
        node *p;
        int cnt;
        p=head;
        while(p->next!=NULL)
        {
            cnt++;
            p=p->next;
        }
        return cnt;
    }
};
int main()
{
    sll s1,s2,s3,s4,s5,s6;
    int ch;
    int x;
    char str[20];
    while(1)
    {
        cout<<"ENTER ROLL NUMBER OR TO STOP ENTER -1"<<endl;
        cin>>x;
        if(x==-1)
        {
            break;
        }
        cin.ignore(1);
        cout<<"ENTER THE NAME "<<endl;
        cin.getline(str,19);
        cout<<"1. VANILLLA"<<endl;
        cout<<"2. BUTTERSCOTCH"<<endl;
        cout<<"3. BOTH"<<endl;
        cout<<"4. NEITHER"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                s1.Add_end(x,str);
                break;
            }
            case 2:
            {
                s2.Add_end(x,str);
                break;
            }
            case 3:
            {
                s1.Add_end(x,str);
                s2.Add_end(x,str);
                break;
            }
            case 4:
            {
                s3.Add_end(x,str);
                break;
            }
        }
    }
    cout<<"WHO LIKES VANILLA"<<endl;
    s1.show();
    cout<<"WHO LIKES BUTTERSCOTCH"<<endl;
    s2.show();
    cout<<"WHO LIKES ONLY VANILLA"<<endl;
    s4.van(s1,s2);
    s4.show();
    cout<<"WHO LIKES ONLY BUTTERSCOTCH"<<endl;
    s5.butter(s1,s2);
    s5.show();
    cout<<"WHO LIKES VANILLA OR BUTTERSCOTCH"<<endl;
    s6.uni(s1,s2);
    s6.show();
    cout<<"WHO LIKES NEITHER "<<endl;
    s3.show();
    int y;
    y=s3.count();
    cout<<"THE NUMBER OF STUDENTS WHO LIKE NEITHER ICECREAM"<<y<<endl;
}