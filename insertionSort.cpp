#include<iostream>
using namespace std;
void insertion(int A[],int n)
{
    int i,j,key;
    for(j=1; j<n; j++)
    {
        key=A[j];
        i=j-1;
        while(i>=0 && A[i]>key)
        {
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
    }
}
int main()
{
    int A[]= {5,3,9,8,10,1,0,6};
    int i,n=8;
    cout<<"before insertion\n";
    for(i=0; i<n; i++)
    {

        cout<<A[i]<<"\t";
    }
    insertion(A,n);
    cout<<"\nAfter insertion\n";
    for(i=0; i<n; i++)
    {
        cout<<A[i]<<"\t";
    }
}
