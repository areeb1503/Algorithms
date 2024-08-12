#include <iostream>
#include <vector>
int count = 0;
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        count++;
        if (arr[j] < pivot)
        {

            i++;

            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
int randomPart(vector<int> &arr, int low, int high)
{
    int pivotIndex = low + rand() % (high - low );
    swap(arr[high], arr[pivotIndex]);
    return partition(arr, low, high);
}

void rQS(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        // int pivotIndex = randomPart(arr, low, high);
        int pivotNewIndex = partition(arr, low, high);
        rQS(arr, low, pivotNewIndex - 1);
        rQS(arr, pivotNewIndex + 1, high);
    }
}

int main()
{
    int n;
    cout << "Enter the no of elements" << endl;
    cin >> n;
    vector<int> arr = {3, 6, 8, 10, 1, 2, 5};

    cout<<"Enter the elements :"<<endl;
    for (int i=0; i<n; i++){
        cin>> arr[i];
    }

    rQS(arr, 0, n - 1);

    for (int i = 0; i <n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    cout<<"No of comparisons "<<count;

    return 0;
}