//I collaborated with Tristan Fong
#include<iostream>
#include<vector>
#include <algorithm>
#include <array>
using namespace std;

int length = 0;
// added the sentiniel for checking because int can only go up to 2147483647
int sentinel = 2147483647;

//page 377 has the algorithm
void printOptPar(int (*array)[20], int i, int j) {
    if (j == 1) {
        cout << "A0";
        return;
    }
    if(i == j) {
        cout << "A" << i-1;
    }
    else {
        cout << "(";
        printOptPar(array, i, array[i][j]);
        printOptPar(array, (array[i][j] + 1), j);
        cout << ")";
    }
}
// page 375 has the algorith
int matrixchainorder(int p[], int n, int (*array)[20]) {
    int m[n][n];
    int j,q;
    
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }
    
    for (int l = 2; l < n; l++) {
        for (int i = 1; i <= n-l + 1; i++) {
            j = i+l-1;
            //needs a check right here or will go out of bounds
            //added a sentinel check because the others check didnt work
            m[i][j] = sentinel;
            
            for (int k = i; k <= j-1; k++) {
                q = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
                if (q < m[i][j]) {
                    m[i][j] = q;
                    array[i][j] = k;
                }}}}
    
    return m[1][n-1];
    
}
//book uses p so use p with the length
int main() {
    cin >> length;
    int p[length];
    
    int array[20][20];
    
    for(int i = 0; i <= length; i++) {
        cin >> p[i];
    }
    
    cout << matrixchainorder(p, length+1, array) << "\n";
    printOptPar(array, 1, length);
    cout << "\n";
    
    return 0;
}
