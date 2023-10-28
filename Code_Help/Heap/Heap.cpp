#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = size / 2;
            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
                return;
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Heap is empty!!" << endl;
        }
        arr[1] = arr[size];
        size--;
        int index = 1;

        while (index < size)
        {
            int left = index * 2;
            int right = index * 2 + 1;

            if (left < size && arr[index] < arr[left])
            {
                swap(arr[left], arr[index]);
                index = left;
            }
            else if (right < size && arr[index] < arr[right])
            {
                swap(arr[right], arr[index]);
                index = right;
            }
            else
                return;
        }

        return;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = i * 2;
    int right = i * 2 + 1;

    if (left <= n && arr[left] > arr[largest])
        largest = left;

    if (right <= n && arr[right] > arr[largest])
        largest = right;

    if (i != largest)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[1], arr[size]);
        size--;

        heapify(arr, size, 1);
    }
}

int main()
{
    // Top value will always be at correct position
    //  Heap h;
    //  h.insert(100);
    //  h.insert(50);
    //  h.insert(55);
    //  h.insert(67);
    //  h.deleteFromHeap();

    // h.print();
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, n);
    cout << "Heap Sort: " << endl;
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
}