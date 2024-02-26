#include<iostream>
using namespace std;
int partition(int *arr,int s , int e){
    int count=0;
    int pivot=arr[s];
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    int pivotIndex=s+count;
    swap(arr[pivotIndex],arr[s]);
    int i=s,j=e;
    while(i<pivotIndex && j>pivotIndex){
        //         less than p<< [p] >>p greater than p
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
    if(i<pivotIndex && j>pivotIndex){
        swap(arr[i++],arr[j--]);
    }
    }
    return pivotIndex;
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

    quickSort(arr,0,size);
    cout<<" Array after Quick Sort"<<endl;
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
        
    }    cout<<endl;
return 0;
}