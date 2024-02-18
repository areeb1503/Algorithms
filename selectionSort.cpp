#include<iostream>
using namespace std;

void selection_sort(int arr[],int n){
    int least;
    int comp = 0;
    for (int i = 0; i < n-1; i++)
    {
        least=i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]<arr[least]){
                least=j;
            }
              comp++;
            
        }
        if (i!=least){
                swap(arr[i],arr[least]);
        }
       
        
    }
    cout<<"Number of comparisons made: " <<comp<<endl;
    
}

void display(int arr[],int size){
    cout<<":"<<endl;
    
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
    cout<<"Orignal Array is :"<<endl;
    for (int i = 0; i < s; i++)
    {
        cout<<A[i]<<" ";
    }cout<<endl;
    
    cout<<"After sorting:"<<endl;
    selection_sort(A,s);
    for (int i = 0; i < s; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    
    return 0;        
}