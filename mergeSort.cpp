#include<iostream>
using namespace std;
int merge(int A[],int left,int middle,int right)
{
    int length1=middle-left+1;
    int length2=right-middle;
    int subarray1[length1];
    int subarray2[length2];
    int i;
    for(i=0;i<length1;i++)
    {
        subarray1[i]=A[left+i];

    }
    for(int j=0;j<length2;j++)
    {
        subarray2[j]=A[middle+1+j];
    }
    subarray1[length1]=100;//infinity
    subarray2[length2]=100;//infinity

    int j=0;
    i=0;
    for(int k=left;k<=right;k++)
    {
        if(subarray1[i]<=subarray2[j])
        {
            A[k]=subarray1[i];
            i++;
        }
        else if(subarray1[i]>subarray2[j])
        {
             A[k]=subarray2[j];
            j++;
        }
    }
    return 0;


}

int merge_sort(int A[],int startp,int endr)
{
    if(startp<endr)
    {
        int midq=(startp+endr)/2;
        merge_sort(A,startp,midq);
        merge_sort(A,midq+1,endr);
        merge(A,startp,midq,endr);
    }
    return 0;
}
int main()
{
    int A[]={5,9,10,67,51,0,25};
    int i;
    cout<<"Before sorting\n";
    for(i=0;i<=6;i++)
    {
        cout<<A[i]<<"\t";
    }
    merge_sort(A,0,6);
    cout<<"\nAfter sorting\n";
    for(i=0;i<=6;i++)
    {
        cout<<A[i]<<"\t";
    }
    return 0;

}
