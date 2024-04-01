#include<iostream>
using namespace std;

int insertion_sort(int arr[],int n){
      int counter = 0; //keeps track of number of comparisons

    for (int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1; //Will Store index of previous element.
        while (j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j]; //Shifting elements.
            j--; //Will check previous indices.
                        counter++;

        }
        arr[j+1]=key;
    }
    return counter;
}

void display(int arr[],int size){
    cout<<"Array is :"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
                    
int main(){
    int s;
    cout<<"Enter size of your Array :";cin>>s;
    int A[s];
    cout<<"Enter Array elements :"<<endl;
    for (int i = 0; i < s; i++)
    {
        cin>>A[i];
    }
    cout<<"Orignal"<<endl;
    display(A,s);
    cout<<"After sorting"<<endl;
    int count=insertion_sort(A,s);
    cout<<"Number of Comparisions made are "<<count<<endl;
    display(A,s);
    return 0;
}
