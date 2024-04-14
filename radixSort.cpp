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
   vector<int> arr = {543,986,217,765,329};
    
    cout<<"Orignal Array :"<<endl;
    display(arr);

    radixSort(arr);

    cout<<"Sorted Array :"<<endl;
    display(arr); 
    
    return 0;
}