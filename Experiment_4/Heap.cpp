#include <iostream>
using namespace std;

const int SIZE = 100;

int arr[SIZE];
int currentSize = 0;

void addValue(int data) {

    if (currentSize >= SIZE) {
        cout << "Heap is Full\n";
        return;
    }

    arr[currentSize] = data;
    int index = currentSize;
    currentSize++;

    while (index > 0) {
        int parent = (index - 1) / 2;

        if (arr[parent] < arr[index]) {
            swap(arr[parent], arr[index]);
            index = parent;
        }
        else
            break;
    }
}

void heapify(int pos) {

    int maxIndex = pos;
    int lchild = 2 * pos + 1;
    int rchild = 2 * pos + 2;

    if (lchild < currentSize && arr[lchild] > arr[maxIndex])
        maxIndex = lchild;

    if (rchild < currentSize && arr[rchild] > arr[maxIndex])
        maxIndex = rchild;

    if (maxIndex != pos) {
        swap(arr[pos], arr[maxIndex]);
        heapify(maxIndex);
    }
}

int removeTop() {

    if (currentSize == 0) {
        cout << "Heap Empty\n";
        return -1;
    }

    int deletedValue = arr[0];

    arr[0] = arr[currentSize - 1];
    currentSize--;

    heapify(0);

    return deletedValue;
}

void displayHeap() {
    int i = 0;
    for (; i < currentSize; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {

    addValue(15);
    addValue(45);
    addValue(25);
    addValue(60);
    addValue(35);

    cout << "Heap after adding elements:\n";
    displayHeap();

    cout << "Removed Element: " << removeTop() << endl;

    cout << "Heap after removal:\n";
    displayHeap();

    return 0;
}