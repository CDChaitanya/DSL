#include<iostream>
using namespace std;
class node
{
    bool data;
    node *next,*prev;
    public:
    node(bool b)
    {
        data=b;
        next=prev=NULL;
    }
    friend class dll;
};
class dll
{
    public:
    node *head;
    node *tail;
    bool sum;
    bool carray;
    dll()
    {
        head=NULL;
        tail=NULL;
    }
    void insert_beg(bool b)
    {
        node *p;
        p=new node(b);
        if(head==NULL && tail==NULL)
        {
            head=p;
            tail=p;
        }
        else
        {
            p->next=head;
            head->prev=p;
            head=p;
        }
    }
    void Binary(int n)
    {
        while(n!=1)
        {
            if(n%2==0)                    //EVEN
            {
                insert_beg(0);
            }
            else                          //ODD
            {
                insert_beg(1);
            }
            n=n/2;
        }
        insert_beg(1);                    // ALWAYS AT END
    }
    void display()
    {
        node *p;
        p=head;
        while(p!=NULL)
        {
            cout<<p->data<<" "<<endl;
            p=p->next;
        }
        cout<<endl;
    }
    void one(node *end)
    {
        while(end!=NULL)
        {
        if(end->data==0)
        {
            insert_beg(1);
        }
        else
        {
            insert_beg(0);
        }
        end=end->prev;
        }
    }
    void two(node *end)
    {
        sum=0;
        carray=0;
        if(end->data==1)                // IT IS FOR THE FIRST TERM ONLY
        {
            carray=1;
            insert_beg(0);
        }
        else
        {
            carray=0;
            insert_beg(1);
        }
        end=end->prev;
        while(end!=NULL)                // THIS IS FOR REMAINING PART
        {
            if(carray==1)
            {
                if(end->data==1)
                {
                    carray=1;
                    insert_beg(0);
                }
                else
                {
                    carray=0;
                    insert_beg(1);
                }
            }
            else
            {
                insert_beg(end->data);
            }
            end=end->prev;
        }
        while(carray==1)
        {
            insert_beg(1);
        }
    }
    void add(node *end1 , node *end2)
    {
        sum=0;
        carray=0;
        while(end1!=NULL && end2!=NULL)
        {
            sum=(end1->data ^ end2->data ^ carray);
            carray=(end1->data & end2->data) | (end1->data & carray) | (end2->data & carray );
            insert_beg(sum);
            end1=end1->prev;
            end2=end2->prev;
        }
        if(carray==1)
        {
            insert_beg(1);
        }
    }
    int count()
    {
        int cnt=0;
        node *p ;
        p=head;
        while(p!=NULL)
        {
            cnt++;
            p=p->next;
        }
        return cnt;
    }
};
int main()
{
    int n1,n2;
    dll d1,d2,d3,d4,d5;
    cout<<"ENTER INTEGER"<<endl;
    cin>>n1;
    d1.Binary(n1);
    cout<<"IN BINARY"<<endl;
    d1.display();
    d2.one(d1.tail);
    cout<<"ONE'S COMPLEMENT IS"<<endl;
    d2.display();
    d3.two(d2.tail);
    cout<<"TWO'S COMPLEMENT IS"<<endl;
    d3.display();
    cout<<"ENTER ANOTHER INTEGER"<<endl;
    cin>>n2;
    d4.Binary(n2);
    cout<<"IN BINARY"<<endl;
    d4.display();

    int c1=d1.count();
    int c2=d4.count();
    cout << c1<<" "<<c2<<endl;

    if(c1>c2)
    {
        for(int i=0;i<(c1-c2);i++)
        {
            d4.insert_beg(0);
        }
    }
    else
    {
        for(int i=0;i<(c2-c1);i++)
        {
            d1.insert_beg(0);
        }
    }
    
    d5.add(d1.tail , d4.tail);
    cout<<"THE ADDITION IS"<<endl;
    d5.display();
    return 0;
}