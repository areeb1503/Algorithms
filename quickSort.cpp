#include<iostream>
using namespace std;
int partition(int *arr,int s , int e){
    int pivot=arr[s];
    int i=s;
    int j=e;
while(i<j){
    while(arr[i]<=pivot && i<=e-1)  {
    i++;
    }  
    while(arr[j]>pivot && j>=s+1){
        j--;
    }
    if(i<j)swap(arr[i],arr[j]);
  
}
swap(arr[s],arr[j]);

    return j;
}
void quickSort(int *arr,int s, int e){
    // base case
    if(s>=e)
      return;
    //  select pivot element and place it at the start of the array.......
    int p=partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);


}

int main(){
    int size;
    cout<<"Enter the number of elements: ";
    cin>>size;
    cout<<endl;

    int arr[size];
    cout<<"Enter array elements : "<<endl;
    for (int i = 0; i < size; i++)
    {
        /* code */
        cin>>arr[i];    
    }
    

    cout<<" Original array:"<<endl;
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
        
    }    cout<<endl;

    quickSort(arr,0,size-1);
    cout<<" Array after Quick Sort"<<endl;
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
        
    }    cout<<endl;
return 0;
}