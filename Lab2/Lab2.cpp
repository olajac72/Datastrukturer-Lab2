// C++ program for insertion sort  
#include <iostream> 
#include <chrono>

using namespace std;

// First draft
//https://www.geeksforgeeks.org/insertion-sort/
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// A utility function to print an array of size n  
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// https://www.tutorialspoint.com/binary-insertion-sort-in-cplusplus

int binarySearch(int arr[], int item, int low, int high) {
    if (high <= low)
        return (item > arr[low]) ? (low + 1) : low;
    int mid = (low + high) / 2;
    if (item == arr[mid])
        return mid + 1;
    if (item > arr[mid])
        return binarySearch(arr, item, mid + 1, high);
    return binarySearch(arr, item, low, mid - 1);
}

void BinaryInsertionSort(int arr[], int n) {
    int i, loc, j, k, selected;
    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = arr[i];
        loc = binarySearch(arr, selected, 0, j);
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}

/* Driver code */
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    auto start = chrono::high_resolution_clock::now();

    insertionSort(arr, n);

    auto t2 = std::chrono::high_resolution_clock::now();

    auto int_ms = std::chrono::duration_cast<std::chrono::microseconds>(t2 - start);
   
    std::chrono::duration<unsigned int, std::micro> int_usec = int_ms;
    printArray(arr, n);
    cout << "Linear insertion sort took :" << int_usec.count() << endl;

    int arr2[] = { 12, 56, 1, 67, 45, 8, 82, 16, 63, 23 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]), i;
    
    start = chrono::high_resolution_clock::now();

    BinaryInsertionSort(arr2, n2);

    t2 = std::chrono::high_resolution_clock::now();
    int_ms = std::chrono::duration_cast<std::chrono::microseconds>(t2 - start);
    
    int_usec = int_ms;
    
    cout << "Sorted array is : \n";
    for (i = 0; i < n2; i++)
        cout << arr2[i] << "\t";

    cout << endl;
    cout << "Binary insertion sort took :" << int_usec.count() << endl;
    return 0;
}