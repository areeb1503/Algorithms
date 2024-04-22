#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

void countSort(vector<int> &A,int pos)
{
    
    vector<int> count(10, 0); //Creating an array with 'size'=max+1 and initializing all values with 0.

    // Store the count of each element in 'count' array.
    for (int i=0; i<A.size();i++){
        count[(A[i]/pos)%10]++; // Dividing the number by 'pos' and incrementing the count at that index.
    }

    // Modify the count array to store the actual position of each element in the sorted array.
    for (int i = 1; i<10; i++)
    {   
        count[i] = count[i] + count[i-1];
    }

    // Create a temporary 'output' array to store the sorted output.
    vector<int> output(A.size());

    // Building the 'output' array.
    for (int i = A.size()-1;i>=0;--i){
        output[count[(A[i] / pos) % 10] - 1] = A[i];
        -- count[(A[i]/pos)%10];
    }

    // Copy sorted element from 'output' array back into orignal 'A' array.
    for (int i=0; i<A.size();i++){
        A[i]=output[i];
    }
    output.clear(); // Free the memory by clearing the 'output' array.
}
void radixSort(vector<int>&v){
     int m=*max_element(v.begin(),v.end()) ;
     // Perform counting sort for every digit. Process is repeated until there are no more digits.
     for(int pos=1;pos<m/pos;pos=pos*10){
        countSort(v,pos);
     }
}

void display(vector<int> &arr)
{
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
  
    
     int size;
    cout<<"Enter the number of elements: ";
    cin>>size;
    cout<<endl;
    
   vector<int> arr(size);

    cout<<"Enter array elements : "<<endl;
    for (int i = 0; i < size; ++i)
    {
        /* code */
        cin>>arr[i];    
    }
    

    cout<<" Original array:"<<endl;
    for(int i = 0; i < size; ++i){
        cout<<arr[i]<<" ";
        
    }    cout<<endl;

    radixSort(arr);
    cout<<" Array after Radix Sort:"<<endl;
    for(int i = 0; i < size; ++i){
        cout<<arr[i]<<" ";
        
    }    cout<<endl;
    return 0;
}