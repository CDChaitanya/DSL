#include<iostream>
using namespace std;
void BubbleSort(int a[],int n)
{
    int flag;
    for(int i=0;i<n-1;i++)
    {
        flag=0;
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
        {
            return;
        }
    }
}
void InsertionSort(int a[],int n)
{
    int i,j;
    int temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0;j--)        // ADHICHE SAGALE COMPARE KARTA
        {
            if(a[j]>temp)
            {
                a[j+1]=a[j];
            }
            else
            {
                break;
            }
        }
    }
    a[j+1]=temp;
}
void SelectionSort(int a[],int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(a[k]>a[j])
            {
                k=j;
            }
        }
        int temp;
        temp=a[i];
        a[i]=a[k];
        a[k]=temp;
    }
}
int partition(int a[],int l,int h)
{
    int pivot=a[l];
    int i=l,j=h;
    do
    {
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);
        if(i<j)
        {
            int t;
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }while(i<j);
    int temp;
    temp=a[j];
    a[j]=a[l];
    a[l]=temp;

    return j;
}
void QuickSort(int a[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(a,l,h);
        QuickSort(a,l,j);
        QuickSort(a,j+1,h);
    }
}
void ShellSort(int a[],int n)
{
    int step;
    int temp;
    int i,j;
    for(step=n/2;step>0;step=step/2)
    {
        for(i=step;i<n;i++)                         // HERE  1  IS  REPLACED BY   "STEP" 
        {
            temp=a[i];
            for(j=i-step;j>=0;j=j-step)
            {
                if(a[j]>temp)
                {
                    a[j+step]=a[j];
                }
                else
                {
                    break;
                }
            }
         a[j+step]=temp;
        }
    }
}
int main()
{
    int a[100];
    int n;
    cout<<"ENTER TOTAL NUMBER OF ELEMENTS"<<endl;
    cin>>n;
    cout<<"NOW ENTER THE NUMBERS"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //int h=n+1;
    //a[h]=INT32_MAX;
    //QuickSort(a,0,h);
    ShellSort(a,n);
    cout<<"THE SORTED LIST IS ===>"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
}