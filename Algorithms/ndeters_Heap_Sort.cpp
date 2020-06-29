#include<iostream>
using namespace std;
//building all the Heaps for the calls and commands as voids
void Heapsort(int[], int);
void HeapBuild(int[], int);
void Heapify(int[], int, int);

int main() {
  int arrSize;
  cin >> arrSize;
  int arr[arrSize];
  for (int i = 1; i <= arrSize; i++) {
    cin >> arr[i];
  }
  Heapsort(arr, arrSize);
  for (int i = 1; i <= arrSize; i++) {
    cout << arr[i] << ";";
  }
}
// heapsort alorithm
void Heapsort(int arr[], int size) {
    // call to heapbuild so the heap can be made
  HeapBuild(arr, size);
    //need a temp variable to save memory or won't pass test 4
  int temp;
  for (int i = size; i >=2; i--) {
    temp = arr[i];
    arr[i] = arr[1];
    arr[1] = temp;
    Heapify(arr, 1, i - 1);
  }
}

void Heapify(int arr[], int i, int size) {
    // test example 4 needs this to pass
  int j, temp;
  temp = arr[i];
  j = 2*i;
  while (j <= size) {
    if (j < size && arr[j+1] > arr[j]) {
      j = j+1;
    }
      // check for example 3 to pass
    if (temp > arr[j]) {
      break;
    } else if (temp <= arr[j]){
      arr[j/2] = arr[j];
      j = 2*j;
    }
  }
  arr[j/2] = temp;
}
// have to build the heap first to take out pass the tests
void HeapBuild(int arr[], int size) {
    for (int i = size/2; i >= 1; i--) {
        Heapify(arr, i, size);
    }
}
