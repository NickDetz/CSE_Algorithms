#include<iostream>
#include <stdlib.h>


using namespace std;
// randomized partitions in the code for quick sort
int randomizedPartition(int[], int , int);
void randomizedQuicksort(int[], int, int);
// had to add a partition function becasuse random partision doesnt work that way
int partition(int[], int, int);

// randomize the Quicksort
void randomizedQuicksort(int A[], int p, int r) {
  if (p<r) {
    int q = randomizedPartition(A, p, r);
    //randomizedQuicksort(A, p +1, 1-1);
    randomizedQuicksort(A, p, q - 1);
    randomizedQuicksort(A, q + 1, r);
  }
}
// randomize the partition
int randomizedPartition(int A[], int p, int r) {
  srand (time(NULL));
  int i = rand() %r + p;
    // partition mistake
  //int temp = A[r];
    //A[i] = temp;
  return partition(A,p,r);
}
// Partision so ttaht it is really simple to partition
int partition(int A[], int p, int r) {
  int x = A[r];
  int i = p - 1;
  for (size_t j = p; j <= r - 1; j++) {
      
      // first loop
    if (A[j] <= x) {
      i = i + 1;
      int temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }

  }
    //second encompasing loop
  int temp = A[i + 1];
  A[i + 1] = A[r];
  A[r] = temp;
  return (i + 1);
}
// start of the code
int main(int argc, char const *argv[]) {
    int arrSize;
    cin >> arrSize;
    int arr[arrSize];
    for (int i = 1; i <= arrSize; i++) {
        cin >> arr[i];
    }
    randomizedQuicksort(arr, 1, arrSize);
    for (int i = 1; i <= arrSize; i++) {
        cout << arr[i] << ";";
    }
    return 0;
}
