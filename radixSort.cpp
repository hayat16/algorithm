#include<iostream>
using namespace std;
int getmax(int A[],int n)
{
    int mx=A[0];
    for(int i=1;i<n;i++)
    {
        if(A[i]>mx)
        {
            mx=A[i];
        }
    }
    return mx;
}
void cs(int A[],int n,int exp)
{
    int B[n];
    int i;
    int c[10]={0};
    for(i=0;i<n;i++)
    {
        c[(A[i]/exp)%10]++;
    }
    for(i=1;i<10;i++)
    {
        c[i]=c[i]+c[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        B[c[(A[i]/exp)%10]-1]=A[i];
        c[(A[i]/exp)%10]--;
    }
for(i=0;i<n;i++)
{
    A[i]=B[i];
}
}
void radixSort(int A[],int n)
{
    int m=getmax(A,n);
    for(int exp=1;m/exp>0;exp*=10)
    {
        cs(A,n,exp);
    }
}
int main()
{
    int A[]={170,45,75,90,802,24,2,66};

        int n=sizeof(A)/sizeof(A[0]);

        radixSort(A,n);
        for(int i=0;i<n;i++)
        {
            cout<<A[i]<<"\t";
        }
        return 0;

}
