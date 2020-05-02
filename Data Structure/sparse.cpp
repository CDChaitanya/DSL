#include<iostream>
using namespace std;
class sparse
{
    int s[10][10];
    int row , col ,terms;
    int i,j;
    public:
    void getdata()
    {
        cout<<"ENTER NUMBER OF ROW "<<endl;
        cin>>s[0][0];
        cout<<"ENTER NUMBER OF COLUMN "<<endl;
        cin>>s[0][1];
        cout<<"ENTER NUMBER OF NON_ZERO TERMS "<<endl;
        cin>>s[0][2];
        row=s[0][0];
        col=s[0][1];
        terms=s[0][2];
        cout<<"ENTER NON_ZERO TERMS"<<endl;
        for(i=1;i<=terms;i++)
        {
            cin>>s[i][0]>>s[i][1]>>s[i][2];
        }
    }
    sparse add(sparse t)
    {
        sparse temp;
        int i,j,k;
        i=j=k=0;
        if(s[0][0]==t.s[0][0] && s[0][1]==t.s[0][1])
        {
            temp.s[0][0]=s[0][0];
            temp.s[0][1]=s[0][1];
            while(i<=s[0][2] && j<=t.s[0][2])
            {
                if(s[i][0]<t.s[j][0])
                {
                    temp.s[k][0]=s[i][0];
                    temp.s[k][1]=s[i][1];
                    temp.s[k][2]=s[i][2];
                    i++;
                }
                else if(s[i][0]>t.s[j][0])
                {
                    temp.s[k][0]=t.s[j][0];
                    temp.s[k][1]=t.s[j][1];
                    temp.s[k][2]=t.s[j][2];
                    j++;
                }
                else if(s[i][0]==t.s[j][0])
                {
                    if(s[i][1]<t.s[j][1])
                    {
                        temp.s[k][0]=s[i][0];
                        temp.s[k][1]=s[i][1];
                        temp.s[k][2]=s[i][2];
                        i++;
                    }
                    else if(s[i][1]>t.s[j][1])
                    {
                        temp.s[k][0]=t.s[j][0];
                        temp.s[k][1]=t.s[j][1];
                        temp.s[k][2]=t.s[j][2];
                        j++;
                    }  
                    else if(s[i][1]==t.s[j][1])
                    {
                        temp.s[k][0]=t.s[j][0];
                        temp.s[k][1]=t.s[j][1];
                        temp.s[k][2]=s[i][2]+t.s[j][2];
                        j++;
                        i++;
                    } 
                }
                k++;
            }
            temp.s[0][2]=k-1;
            cout<<"THE ADDITION IS "<<endl;
            return temp;
        }
        else
        {
            cout<<"INVALID DIMENTIONS OF 2 SPARSE MATRIX"<<endl;
        }
    }
    void display()
    {
        int k;
        k=s[0][2];
        cout<<"THE SPARSE MATRIX IS "<<endl;
        for(i=0;i<=k;i++)
        {
            cout<<s[i][0]<<"\t"<<s[i][1]<<"\t"<<s[i][2]<<endl;        
        }
    }
};
int main()
{
    sparse s1,s2,s3;
    s1.getdata();
    s1.display();
    s2.getdata();
    s2.display();
    s3=s1.add(s2);
    s3.display();
    return 0;
}