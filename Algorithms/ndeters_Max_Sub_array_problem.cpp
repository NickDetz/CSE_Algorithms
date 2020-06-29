#include<iostream>

using namespace std;
int length;

// Merging the arrays
void merge(int array[], int mid, int left, int right) {
    int LeftArr[mid - left + 1];
    int RightArr[right - mid];
    
    for (int i = 0; i < mid - left + 1; i++)
            LeftArr[i] = array[left + i];
                for (int i = 0; i < right - mid; i++)
                    RightArr[i] = array[mid + 1 + i];
   //adding 3 new integers so that the for loops can be used sufficiantly put the
    int s = 0;
    int j = 0;
    int k = left;
   
    
    //for (int i = 0; i< left - (mid - right) i++)
    // array[k++] = LeftArr[s++]
    
    //for (int i = 0; i< right - (mid - left + 1) i++)
    //array[k++] = LeftArr[s++];
    
    while (s < mid - left + 1 && j < right - mid)
    {
        if (LeftArr[s] <= RightArr[j])
            array[k++] = LeftArr[s++];
        else
            array[k++] = RightArr[j++];
    }
    
    
    // Need to stabalize the value's from the loop that are odd
    while (s < mid - left + 1)
        array[k++] = LeftArr[s++];
    
    while (j < right - mid)
        array[k++] = RightArr[j++];
}


        // making the merg calls so it can pass the Merge's on each side properly
void mergeSort(int array[], int left = 0, int right = length - 1) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, mid, left, right);
    }
}

int main(){
    // getting the length and putting it into the array
    cin >> length;
    int *array = new int [length];
    
    //Putting the values into the array
    for(int i = 0; i < length; i++){
        cin >> array[i];
    }
    
    // Begin the Call to mergeSort
    mergeSort(array);
    
    // Putting the ; in  for the tests to be happy
    for (int i = 0; i < length; i++){
        cout << array[i] << ";";
    }
    // Zero everything out for the next algorithm
    delete[] array;
    return 0;
}
