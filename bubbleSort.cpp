#include<iostream>
using namespace std;
int bubbleSort(int *arr,int n){
    int count=0;
    for(int i=1;i<n;i++){
        //for rounds 1 to n-1
        for (int j= 0; j <n-i; j++)
        {
            //process element till n-i th index
            if (arr[j] > arr[j+1]){
            swap(arr[j],arr[j+1]);
            count++;
            }
        }
        
    }
    return count;
}
void printArray(int *arr, int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
        
    }    cout<<endl;
}

int main(){
    int arr[6]={14,6,9,7,10,8,};
    cout<<" Original array:"<<endl;
    printArray(arr,6);

   int count= bubbleSort(arr,6);
   cout << "Number of comparisons are "<<count<<endl;
    cout<<" Array after bubble Sort"<<endl;
     printArray(arr,6);


    
    
return 0;
}