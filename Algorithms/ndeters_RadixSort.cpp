//code by Nick Deters
#include <iostream>
#include <vector>
#include <string>

using namespace std;
// Various algorithms in this sort to make sure it works properly the other algorithms comment "work" just not as well as the new one's put in
void RadiNum(vector<int> arr[], int o, int s, int size) {
    vector<int>* output = new vector<int>[size];
    int* Radnum = new int[s + 1];
    for (int i = 0; i < s; i++) {
        Radnum[i] = 0;
    }
    //for (int j = 0; j < size; j--){
    // Radnum[j] = 0
    //}
    for (int j = 0; j < size; j++) {
        Radnum[arr[j].at(o)]++;
    }
    for (int i = 1; i < s; i++) {
        Radnum[i] += Radnum[i - 1];
    }
    //for (int i = size -1: j >= 0; i++){
    // output[Radnum[arr[i].at(a)] +1 = arr[i];
    // Radnum[arr[i].at(a)]--;
    //}
    for (int j = size - 1; j >= 0; j--) {
        output[Radnum[arr[j].at(o)] - 1] = arr[j];
        Radnum[arr[j].at(o)]--;
        }
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

// Radix sort calling the vectors and putting them into the array to be sorted
//void radixSort(vector<int> arr[], int d, int size) {
//    for (int i = d-1; i >= 0; i--) {
//        incSort(arr, i, 10, size);
//
//    }
//}
//printing wouldn't work correctly if not in a function just kind of dies don't know why but .. computers
void print(vector<int>arr[], int n){

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < 10; j++) {
            cout << arr[i].at(j) << ";";
        }cout << endl;
        
    }

}

//void insvector(vector<int>[size], int j){
//    vector<int>* vec = new vector<int>[size];
//    int j = -1;
//    for(int i = 0; i < size * 10; i++){
//
//        if (i % 10 == 0) {
//            j++;
//        }
//
//        cin >> nums;
//        vec[j].push_back(nums);
//
//    }
//}

// RadixSort must be under functions or it won't work unfortunately. I don't know why. computers
void radixSort(vector<int> arr[], int d, int size) {
    for (int i = d-1; i >= 0; i--) {
        RadiNum(arr, i, 10, size);
        
    }
}


int main() {
    // inserting 2 variable one of size and the other of nums
    int size;
    int nums;
    //insert size duh
    cin >> size;
    
    // making a vector 3d array in the main file so the loader will work properly
    vector<int>* vec = new vector<int>[size];
    int j = -1;
    // meking sure that we mod correctly the j array
    for(int i = 0; i < size * 10; i++){

        if (i % 10 == 0) {
            j++;
        }cin >> nums;
        vec[j].push_back(nums);}
    //insvector(vec,size);
    radixSort(vec, 10, size);
    print(vec,size);
    
    return 0;
    
}
