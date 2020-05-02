#include<iostream>
using namespace std;
class student
{
    public:
    int i,j,n;
    int roll[10];
    int marks[10];
    char present[10];
    void scan()
    {
        cout<<"ENTER TOTAL NUMBER OF STUDENTS"<<endl;
        cin>>n;
        cout<<"PRESS y / n FOR PRESENT"<<endl;
        for(i=0;i<n;i++)
        {
            cout<<"ROLL NUMBER"<<endl;
            cin>>roll[i];
            cout<<"PRESENT "<<endl;
            cin>>present[i];
            if(present[i]=='y')
            {
                cout<<"ENTER MARKS"<<endl;
                cin>>marks[i];
            }
            else
            {
                marks[i]=0;
            }
        }
    }
    void average()
    {
        int total=0;
        float avg;
        for(i=0;i<n;i++)
        {
            total=total + marks[i];
        }
        avg=total/n;
        cout<<"THE AVERAGE MARKS ARE "<<avg<<endl;
    }
    void high()
    {
        int max;
        max=marks[0];
        for(i=1;i<n;i++)
        {
            if(max<marks[i])
            {
                max=marks[i];
            }
        }
        cout<<"THE HIGHEST MARKS ARE  "<<max<<endl;
    }
    void low()
    {
        int min;
        min=marks[0];
        for(i=1;i<n;i++)
        {
            if(min>marks[i])
            {
                min=marks[i];
            }
        }
        cout<<"THE LOWEST MARKS ARE  "<<min<<endl;
    }
    void most()                                         //PROBLEM 
    {
        int b,freq[50];       // [ MAX MARKS ]
        int mod=0;
        for(int i=0;i<n;i++)
        {
            freq[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            b=marks[i];
            for(int j=0;j<n;j++)
            {
                if(marks[j]==b)
                {
                    freq[i]++;
                }
            }
        }
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(freq[i]>mod)
            {
                mod=freq[i];
                if(i>j)
                {
                    j=i;
                }
            }
        }
        cout<<"FREQUENCY IS "<<mod<<"FOR MARKS "<<marks[j]<<endl;
    }
	void absent()
	{
        int cnt;
		for(i=0;i<n;i++)
		{
			if(present[i]=='n')
		    {
			    cnt++;
		    }
		}
		cout<<"THE NUMBER OF STUDENTS WHO ARE ABSENT ARE "<<cnt<<endl;
		for(i=0;i<n;i++)
		{
			if(present[i]=='n')
		    {
			    cout<<roll[i]<<endl;
		    }
		}
	}
    void display()
    {
        cout<<"STATISTICS"<<endl;
        cout<<"R "<<"P "<<"M"<<endl;
        for(i=0;i<n;i++)
        {
            cout<<roll[i]<<"  "<<present[i]<<"  "<<marks[i]<<endl;
        }  
    }
};
int main()
{
    student s;
    int choice;
    s.scan();
    do
    {
        cout<<"1. AVERAGE SCORE OF CLASS"<<endl;
        cout<<"2. HIGHEST AND LOWEST MARKS"<<endl;   
        cout<<"3. MARKS SCORED BY MOST OF THE STUDENT"<<endl;
        cout<<"4. LIST OF ABSENT STUDENT "<<endl; 
        cout<<"5. DISPLAY"<<endl;
        cout<<"ENTER YOUR CHOICE"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                s.average();
                break;
            }
            case 2:
            {
                s.high();
                s.low();
                break;
            }
            case 3:
            {
                s.most();
                break;
            }
            case 4:
            {
                s.absent();
                break;
            }
            case 5:
            {
                s.display();
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