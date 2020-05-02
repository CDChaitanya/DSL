#include<iostream>
#include<string.h>
using namespace std;
class stack
{
    int top;
    int MAX;
    char data[100];
    public:
    stack()
    {
        top=-1;
        MAX=100;
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
        top++;
        data[top]=x;
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
    char TOP()
    {
        char x=data[top];
        return x;
    }
};
int isoprand(char x)
{
    if(x=='+'||x=='-'||x=='/'||x=='*')
    {
        return 0;
    }
    return 1;
}
int precedence(char x)
{
    if(x=='+'||x=='-')
    {
        return 1;
    }
    if(x=='*'||x=='/')
    {
        return 2;
    }
    return 0;
}
char* conert(char infix[])
{
    stack s;
    char *postfix=new char[strlen(infix)+1];
    int i=0,j=0;
    while(infix[i]!='\0')
    {
        if(isoprand(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else
        {
            if(precedence(infix[i])>precedence(s.TOP()))
            {
                s.push(infix[i++]);
            }
            else
            {
                postfix[j++]=s.pop();
            }
        }
    }
    while(!s.isempty())
    {
        postfix[j++]=s.pop();
    }    
    postfix[j]='\0';
    return postfix;
}
int evaluate(char postfix[])
{
    stack s;
    int x1,x2,r;
    for(int i=0;postfix[i]!='\0';i++)
    {
        if(isoprand(postfix[i]))
        {
            s.push(postfix[i]-'0');   // ####IMPORTANT#####
        }
        else
        {
            x2=s.pop();
            x1=s.pop();
            switch(postfix[i])
            {
                case '+':
                {
                    r=x1+x2;
                    s.push(r);
                    break;
                }
                case '-':
                {
                    r=x1-x2;
                    s.push(r);
                    break;
                }
                case '*':
                {
                    r=x1*x2;
                    s.push(r);
                    break;
                }
                case '/':
                {
                    r=x1/x2;
                    s.push(r);
                    break;
                }
            }
        }
    }
    return (s.pop());
}
int main()
{
    char infix[50];
    int value;
    cout<<"ENTER INFIX EXPRESSION"<<endl;
    cin.getline(infix,49);
    char *post=conert(infix);
    cout<<"THE POSTFIX EXPRESSION IS"<<endl;
    for(int i=0;i<=strlen(post);i++)
    {
        cout<<post[i];
    }
    value=evaluate(post);
    cout<<"\nTHE POSTFIX EVALUATION IS "<<value<<endl;
    return 0;
}