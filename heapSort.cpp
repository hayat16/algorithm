#include<iostream>
using namespace std;

#define length 8
int heapsize;
int Max_heapify(int A[],int i)
{
    int largest;
    int l=2*i+1;
    int r=2*i+2;
    if(l<=heapsize && A[l]>A[i])
    {
         largest=l;
    }
    else
    {
        largest=i;
    }
   if(r<=heapsize && A[r]>A[largest])
   {
       largest=r;
   }
   if(largest!=i)
   {
       swap(A[i],A[largest]);
        Max_heapify(A,largest);
   }

    return 0;
}
int Build_max_heap(int A[])
{
    heapsize=length-1;
    for(int i=(length-1)/2;i>=0;i--)
    {
      Max_heapify(A,i);
    }
    return 0;
}
int Heapsort(int A[])
{
    Build_max_heap(A);
    for(int i=length-1;i>=1;i--)
    {
        swap(A[0],A[i]);
       heapsize=heapsize-1;
       Max_heapify(A,0);
    }

    return 0;
}

int main()
{
    int A[length]={5,10,0,2,66,14,15,30};
    int i;

    cout<<"Before sorting\n";
    for(i=0;i<length;i++)
    {
        cout<<A[i]<<"\t";
    }
     Heapsort(A);
    cout<<"\nAfter sorting\n";
    for(i=0;i<length;i++)
    {
        cout<<A[i]<<"\t";
    }
    return 0;
}
