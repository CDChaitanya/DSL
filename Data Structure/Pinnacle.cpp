#include<iostream>
#include<string.h>
using namespace std;
class node
{
    int prn;
    char name[20];
    node *next;
    public:
    node(int x, char *s)
    {
        prn=x;
        strcpy(name,s);
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
    void create()
    {
        int i,n,x;
        char s[20];
        cout<<"ENTER TOTAL NUMBER OF MEMBER IN CLUBE"<<endl;
        cin>>n;
        cout<<"ENTER DETAILS OF PRESIDENT"<<endl;
        cout<<"PRN ..?"<<endl;
        cin>>x;
        cout<<"NAME...?"<<endl;
        cin.ignore(1);
        cin.getline(s,19);
        head=new node(x,s);
        cout<<"ENTER DETAILS OF MEMBER"<<endl;
        node *p;
        p=head;
        for(i=0;i<n-1;i++)
        {
            cout<<"PRN ..?"<<endl;
            cin>>x;
            cout<<"NAME...?"<<endl;
            cin.ignore(1);
            cin.getline(s,19);
            p->next=new node(x,s);
            p=p->next;
        }
        cout<<"ENTER DETAILS OF SECRATRY"<<endl;
        cout<<"PRN ..?"<<endl;
        cin>>x;
        cout<<"NAME...?"<<endl;
        cin.ignore(1);
        cin.getline(s,19);
        p->next=new node(x,s);
    }
    void insert_beg(int x,char*s)
    {
        node*p;
        p=new node(x,s);
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
    void insert_end(int x,char *s)
    {
        node*p,*q;
        p=new node(x,s);
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
    int count()
    {
        node *p;
        p=head;
        int cnt;
        while(p!=NULL)
        {
            cnt++;
            p=p->next;
        }
        return cnt;
    }
    void show()
    {
        node *p;
        p=head;
        while(p!=NULL)
        {
            cout<<p->prn<<" "<<p->name<<endl;
            p=p->next;
        }
    }
    void insert_pos(int x,char *s,int pos)
    {
        int c;
        node *p,*q;
        c=count();
        if(pos<1||pos>c)
        {
            cout<<"INVALID POSTION"<<endl;
        }
        if(pos==1)
        {
            insert_beg(x,s);
        }
        else
        {
            p=new node(x,s);
            q=head;
            for(int i=0;i<pos-1;i++)
            {
                q=q->next;
            }
            p->next=q->next;
            q->next=p;
        }
    }
    void delete_beg()
    {
        node *p;
        if(head==NULL)
        {
            cout<<"CLUB IS EMPTY"<<endl;
        }
        if(head->next==NULL)
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
            cout<<"LIST IS EMPTY"<<endl;
        }
        if(head->next==NULL)
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
            delete (p->next);
            p->next=NULL;
        }
    }
    void delete_pos(int pos)
    {
        node *p,*q;
        if(head==NULL)
        {
            cout<<"LIST IS EMPTY"<<endl;
        }
        if(pos==1)
        {
            delete_beg();
        }
        else
        {
            p=head;
            for(int i=0;i<pos-1;i++)
            {
                p=p->next;
            }
            q=p->next;
            p->next=q->next;
            delete q;
        }
    }
    void displayR()                                 //PROBLEM
    {
        display_R(head);
    }
    void display_R(node *p)
    {
        if(p!=NULL)
        {
            display_R(p->next);
            cout<<p->prn<<" "<<p->name<<endl;
        }
    }
    void concat(sll a, sll b)
    {
        node *p,*q;
        p=a.head;
        q=b.head;
        while(p!=NULL)
        {
            insert_end(p->prn,p->name);
            p=p->next;
        }
        while(q!=NULL)
        {
            insert_end(q->prn,q->name);
            q=q->next;
        }
    }
    void sort(sll a)                               // PROBLEM
    {
        node *p,*q;
        int temp;
        p=q=a.head;
        while(p->next!=NULL)
        {
            temp=p->prn;
            while(q!=NULL)
            {
                if (q->prn < temp)
                {
                    insert_end(q->prn,q->name);
                }
                else
                {
                    break;
                }
                q=q->next;                
            }
            insert_end(p->prn,p->name);
            p=p->next;
        }
    }
};
int main()
{
    int choice;
    char s[20];
    int value,position,cnt,p,n,c;
    sll s1,s2,s3,s4;
    while(1)
    {
     cout<<"=========================="<<endl;
     cout<<"      PINNACLE CLUB       "<<endl;
     cout<<"=========================="<<endl;
     cout<<"1.CREATE ClUB"<<endl;
     cout<<"2.CHANGE PRESIDENT"<<endl;
     cout<<"3.CHANGE SECRATRY"<<endl;
     cout<<"4.ADD MEMBER"<<endl;
     cout<<"5.REMOVE MEMBER"<<endl;
     cout<<"6.COUNT"<<endl;
     cout<<"7.SHOW"<<endl;
     cout<<"8.SHOW REVERSE"<<endl;
     cout<<"9.CONCAT"<<endl;
     cout<<"10.SORT"<<endl;
     cout<<"11.EXIT"<<endl;
     cout<<"ENTER YOUR CHOICE";
     cin>>choice;
     switch(choice)
     {
        case 1:
        s1.create();
        break;
        
        case 2:
        s1.delete_beg();
        cout<<"PRN"<<endl;
        cin>>value;
        cout<<"NAME"<<endl;
        cin.ignore(1);
        cin.getline(s,19);
        s1.insert_beg(value,s);
        break;

        case 3:
        s1.delete_end();
        cout<<"PRN"<<endl;
        cin>>value;
        cout<<"NAME"<<endl;
        cin.ignore(1);
        cin.getline(s,19);
        s1.insert_end(value,s);
        break;

        case 4:
        cout<<"PRN"<<endl;
        cin>>value;
        cout<<"NAME"<<endl;
        cin.getline(s,19);
        cin.ignore(1);  
        cout<<"POSITION ?"<<endl;
        cin>>position;
        s1.insert_pos(value,s,position);
        break;

        case 5:
        cout<<"ENTER POSITION TO BE DELETED"<<endl;
        cin>>p;
        s1.delete_pos(p);
        break;

        case 6:
        cnt=s1.count();
        cout<<"THE COUNT IS"<<cnt<<endl;
        break;

        case 7:
        s1.show();
        break;

        case 8:
        s1.displayR();
        break;

        case 9:
        cout<<"FIRST CREATE SECOND CLUB"<<endl;
        s2.create();
        s3.concat(s1,s2);
        s3.show();
        break;

        case 10:
        s4.sort(s3);
        s4.show();
        break;

        case 11:
        exit(1);
        break;

        default:
        cout<<"INVALID INPUT"<<endl;
     }
    }
}