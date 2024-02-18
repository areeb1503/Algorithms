#include<iostream>
using namespace std;
void merge(int *arr,int s,int e){
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int *first=new int[len1];
    int *second=new int[len2];
    int k=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[k++];
    }
    for(int i=0;i<len2;i++){
        second[i]=arr[k++];
    }
    int i=0,j=0;
    k=s;
    while(i<len1&&j<len2){
        if(first[i]<second[j]){
            arr[k++]=first[i++];

        }
        else{
            arr[k++]=second[j++];
        }
    }
    while(i<len1){
        arr[k++]=first[i++];
    }
    while(j<len2){
        arr[k++]=second[j++];
    }
    delete [] first;
    delete [] second;


}
void mergeSort(int *arr,int s,int e){
    // base case 
    if(s>=e)
      return;
      int mid = (s+e)/2;
    //   left part
      mergeSort(arr,s,mid);
    //   right part
    mergeSort(arr,mid+1,e);
    //   merging the two parts
    merge(arr,s,e);

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

    mergeSort(arr,0,size);
    cout<<" Array after merge Sort"<<endl;
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
        
    }    cout<<endl;
    
return 0;
}