#include<iostream>
#include<string.h>
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
    void push(char x)
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
    char pop()
    {
        char x=-1;
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
};
int main()
{
    char str[100];
    stack s;
    int flag=1;
    cout<<"ENTER EXPRESSION"<<endl;
    cin.getline(str,99);
    char k;
    for(int i=0;i<strlen(str);i++)
    {
        k=str[i];
        switch (k)
        {
        case '(':
        {
            s.push('(');
            break;
        }
        case '[':
        {
            s.push('[');
            break;
        }   
        case '{':
        {
            s.push('{');
            break;
        }    
        case ')':
        {
            if(s.pop()!='(')
            {
                flag=0;
            }
            break;
        }
        case ']':
        {
            if(s.pop()!='[')
            {
                flag=0;
            }
            break;
        } 
        case '}':
        {
            if(s.pop()!='{')
            {
                flag=0;
            }
            break;
        }    
        }     
    }
    if(!s.isempty())
    {
        cout<<"NOT PARENTHESISED"<<endl;
    }
    else
    {
        if(flag)
        {
            cout<<"PARENTHESIZED"<<endl;
        }
        else
        {
            cout<<"NOT PARENTHESIZED"<<endl;
        }
    }
    return 0;
}