  #include <iostream>
  using namespace std;
  
  void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    if (largest != i) {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }
  
  
 
  
  int main() {
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

    heapSort(arr,size);
    cout<<" Array after Heap Sort:"<<endl;
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
        
    }    cout<<endl;
    return 0;
  }