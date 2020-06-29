#include <iostream>
#include <array>
#include <cmath>
#include <limits>
using namespace std;
// Algorithm to actually merge the lists together with one another
void merge(int array[], int left, int mid, int right){



  int *newarray = new int[right-left+1];
  int i = left;
  int j = mid+1;
  int k = 0;
  while ((i <= mid) && (j <= right)) {
    if (array[i] <= array[j]) {
      newarray[k] = array[i];
      i++;
      k++;
    }
    else {
      newarray[k] = array[j];
      j++;
      k++;
    }
  }

  while (i <= mid) {
    newarray[k] = array[i];
    i++;
    k++;
  }
  while (j <= right) {
    newarray[k] = array[j];
    j++;
    k++;
  }


    k = 0;
    for (i = left; i <= right; ++i) {
      array[i] = newarray[k];
      k++;
    }
    delete []newarray;
}



// Merging the lists with everything
void mergesort(int array[], int left, int right) {
  if (left < right) {
    int mid = floor((left+right)/2);

    mergesort(array, left, mid);
    mergesort(array, mid+1, right);
    merge(array, left, mid, right);
  }
    
}

//First call to and splits the list up by it's arrays
void mergeinitial(int array[], int length) {
  int left = 0;
  int right = length-1;
  mergesort(array, left, right);
}

// code starts
int main() {
// initializing the Length of the list being put in from the test files and creating the array
  int length;
  cin >> length;
  int array[length];
//check for that array has integers in it or breaking it
  if (length > 0) {
    for (int i = 0; i < length; i++)
      cin >> array[i];
  }

  else
    return 0;
// making the the integers begin where they need and split apart the list
  int left = 0;
  int right = length;
    
// callng Merge
  mergeinitial(array, length);
//Printing the statements out
    for (int i = 0; i < length; i++) {
    cout << array[i];
    cout << ";";
  }
return 0;
}
