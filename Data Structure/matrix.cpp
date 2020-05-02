#include<iostream>
using namespace std;
class matrix
{
    public:
    int a[3][3],b[3][3];
    int i,j;
    void scan()
    {
        cout<<"ENTER FIRST MATRIX"<<endl;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"ENTER SECOND MATRIX"<<endl;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>b[i][j];
            }
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void add()
    {
        int c[3][3];
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                c[i][j]=a[i][j]+b[i][j];
            }
        } 
        cout<<"THE ADDITION IS "<<endl;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }  
    }
    void sub()
    {
        int c[3][3];
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                c[i][j]=a[i][j]-b[i][j];
            }
        } 
        cout<<"THE SUBSTRACTION IS "<<endl;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }  
    }
    void mul()                                         
    {
        int c[3][3];
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)                     // INITIALIZE TO ZERO 
            {
                c[i][j]=0;
            }
        }  
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    c[i][j]=c[i][j]+a[i][k]*b[k][j];
                }
            }
        } 
        cout<<"THE MULTIPLICATION IS "<<endl;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }  
    }
    void transpose()
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<a[j][i]<<" ";
            }
            cout<<endl;
        }  
    }
    void diagonal()
    {
        int sum=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(i==j)
                {
                    sum=sum+a[i][j];
                }
            }
        } 
        cout<<"THE SUM OF DIAGONAL ELEMENT IS "<<sum<<endl;    
    }
    int upper()
    {
        for(int i=1;i<3;i++)                     // STARTS WITH 1
        {
            for(int j=0;j<i;j++)                 // TILL I
            {
                if(a[i][j]!=0)
                {
                    return 0;                    // FALSE
                }
                return 1;                        //TRUE
            }
        }      
    }
    void saddle()                 // minor problem
    {
        int i,j,k=0;
        int max=0,flag=0;
        int min=0,colind=0;
        for(int i=0;i<3;i++)
        {
            min=a[i][0];
            for(int j=0;j<3;j++)
            {
                if(min>a[i][j])
                {
                    min=a[i][j];
                    colind=j;
                }
            }
            max=a[i][colind];
            for(k=0;k<3;k++)
            {
                if(max<a[k][colind])
                {
                    max=a[k][colind];
                    flag=1;
                }
            }
            if(min==max)
            {
                cout<<"THE SADDLE POINT IS"<<max<<endl;
            }
        }
        if(!flag)
        {
            cout<<"NO SADDLE POINT"<<endl;
        }
};
int main()
{
    matrix m;
    int choice;
    m.scan();
    do
    {
        cout<<"1. ADDITION"<<endl;
        cout<<"2. SUBSTRACTION"<<endl;
        cout<<"3. MULTIPLICATION"<<endl;
        cout<<"4. TRANSPOSE "<<endl;
        cout<<"5. SUM OF DIAGONAL "<<endl;
        cout<<"6. UPPPER TRINGULAR "<<endl;
        cout<<"7. SADDLE POINT"<<endl;
        cout<<"ENTER CHOICE"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: 
            {
                m.add();
                break;
            }
            case 2: 
            {
                m.sub();
                break;
            }
            case 3: 
            {
                m.mul();
                break;
            }
            case 4:
            {
                m.transpose();
                break;
            }
            case 5:
            {
                m.diagonal();
                break;
            }
            case 6: 
            {
                if(m.upper())
                {
                    cout<<"YES"<<endl;
                }
                else
                {
                    cout<<"NO"<<endl;
                }
                break;  
            }
            case 7:
            {
                m.saddle();
                break;
            }
            default:
            {
                cout<<"INVALID INPUT"<<endl;
            }
        }
    }while(1);
    return 0;
}