#include<iostream>
using namespace std; 
class node
{
    int roll;
    node* next;
    public:
    node(int x)
    {
        roll=x;
        next=NULL;
    }
    friend class sll;
};
class sll 
{
    node* head;
    public:
    sll()
    {
        head=NULL;
    }
    void create()
    {
        int i,n,x;
        node *p;
        cout<<"ENTER TOTAL NUMBER OF STUDENTS"<<endl;
        cin>>n;
        cout<<"ENTER ROLL NUMBER OF FIRST STUDENT "<<endl;
        cin>>x;
        head=new node(x);
        p=head;
        for(i=1;i<n;i++)
        {
            cout<<"ENTER DATA OF NEXT STUDENT"<<endl;
            cin>>x;
            p->next=new node(x);
            p=p->next;
        }
    }
    void show()
    {
        node *p;
        p=head;
        while(p!=NULL)
        {
            cout<<p->roll<<endl;
            p=p->next;
        }
    }
    int count()
    {
        node *p;
        int cnt;
        p=head;
        while(p!=NULL)
        {
            cnt++;
            p=p->next;
        }
        return cnt;
    }
    void search(int key)
    {
        node *p;
        p=head;
        while(p!=0)
        {
            if(p->roll==key)
            {
                cout<<"FOUND"<<endl;
                return;
            }
            else
            {
                p=p->next;
            }
        }
    }
    void insert_beg(int x)
    {
        node *p;
        p=new node(x);
        if(head==NULL)
        {
            head=p;
        }
        else
        {
            p->next=head;
            head=p;
        }
    }
    void insert_end(int x)
    {
        node *p,*q;
        p=new node(x);
        if(head==NULL)
        {
            head=p;
        }
        else
        {
            q=head;
            while(q->next!=NULL)
            {
                q=q->next;
            }
            q->next=p;
        }
    }
    void insert_pos(int pos , int x)
    {
        node *p,*q;
        int c=count();
        q=new node(x);
        if(pos<1 || pos>c)
        {
            cout<<"INVALID POSITION"<<endl;
            return;
        }
        if(pos==1)
        {
            insert_beg(x);
        }
        else
        {
            p=head;
            for(int i=1;i<pos-1;i++)                       // POSITION -1 IS ESSENTIAL 
            {
                p=p->next;
            }
            q->next=p->next;
            p->next=q;
        }
        
    }
    void delete_beg()
    {
        node *p;
        if(head==NULL)
        {
            cout<<"LIST IS EMPTY"<<endl;
        }
        if(head->next ==NULL)
        {
            delete head;
            head=NULL;
        }
        else
        {
            p=head;
            head=head->next;
            delete p;
        }
    }
    void delete_end()
    {
        node *p;
        if(head==NULL)
        {
            cout<<"LIST IS EMPTY "<<endl;
        }
        if(head->next ==NULL)
        {
            delete head;
            head=NULL;
        }
        else
        {
            p=head;
            while(p->next->next!=NULL)
            {
                p=p->next;
            }
            delete(p->next);
            p->next=NULL;
        }  
    }
    void delete_pos(int pos)
    {
        node *p,*q;
        int c=count();
        if(pos<1 || pos>c)
        {
            cout<<"INVALID POSITION"<<endl;
            return;
        }
        if(pos==1)
        {
            delete_beg();
        }
        else
        {
            p=head;
            for(int i=1;i<pos;i++)
            {
                p=p->next;
            }
            q=p->next;
            p->next=q->next;
            delete q;
        }
    }
};
int main()
{
    int choice;
    int value,position,cnt,p,n,c;
    sll s;
    while(1)
    {
     cout<<"=========================="<<endl;
     cout<<"OPERATION PERFORMED ON SLL"<<endl;
     cout<<"=========================="<<endl;
     cout<<"1.CREATE"<<endl;
     cout<<"2.INSERT AT BEGINING"<<endl;
     cout<<"3.INSERT AT END"<<endl;
     cout<<"4.COUNT"<<endl;
     cout<<"5.SEARCH"<<endl;
     cout<<"6.SHOW"<<endl;
     cout<<"7.DELETE AT BEGINING"<<endl;
     cout<<"8.DELETE AT END"<<endl;
     cout<<"9. EXIT"<<endl;
     cout<<"10.DELETE AT POSITION"<<endl;
     cout<<"11.INSERT AT POSITION"<<endl;
     cout<<"ENTER YOUR CHOICE";
     cin>>choice;
    
     switch(choice)
     {
        case 1:
        s.create();
        break;
        
        case 2:
        cout<<"ENTER ELEMENT TO BE ADDED AT BEGINING"<<endl;
        cin>>value;
        s.insert_beg(value);
        break;

        case 3:
        cout<<"ENTER ELEMENT TO BE ADDED AT END"<<endl;
        cin>>value;
        s.insert_end(value);
        break;

        case 11:
        cout<<"ENTER ELEMENT TO BE ADDED AT ANY POSITION"<<endl;
        cin>>value;
        cout<<"POSITION ?"<<endl;
        cin>>position;
        s.insert_pos(position,value);
        break;

        case 4:
        cnt=s.count();
        cout<<"THE COUNT IS"<<cnt<<endl;
        break;

        case 5:
        cout<<"ENTER THE ELEMENT TO BE SEARCH"<<endl;
        cin>>n;
        s.search(n);
        break;

        case 6:
        s.show();
        break;

        case 7:
        s.delete_beg();
        break;

        case 10:
        cout<<"ENTER POSITION TO BE DELETED"<<endl;
        cin>>p;
        s.delete_pos(p);
        break;

        case 8:
        s.delete_end();
        break;

        case 9:
        exit(1);
        break;

        default:
        cout<<"INVALID INPUT"<<endl;
     }
    }
}