#include <iostream>
#include <array>
#include <cmath>

using namespace std;

int SENTINEL = 2147483647;
// actual algorithm
void extendedBottomUpCutRod(int arr[], int rev[], int size[], int length) {

	int q;
	rev[0] = 0;

	for (int j = 1; j <= length; j++) {
		q = -SENTINEL;

		for (int i = 1; i <= j; i++) {
			if (q < (arr[i] + rev[j-i])) {
				q = arr[i] + rev[j-i];
				size[j] = i;
			}
		}

		rev[j] = q;
}

	return;
}
// print function
void printCutRodSolution(int arr[], int rev[], int size[], int length) {
	extendedBottomUpCutRod(arr, rev, size, length);
	cout << rev[length] << "\n";
	while (length > 0) {
		cout << size[length] << " ";
		length = length - size[length];
	}
	cout << "-1";
}
// start code here
int main() {
  int length;
  cin >> length;
// 3 arrayss are used for this this
  int arr[length+1];
	int size[length+1];
    int rev[length+1];
    // int revChagne[length+1]
  for (int i = 1; i <= length; i++) {
    cin >> arr[i];
  }

  printCutRodSolution(arr, rev, size, length);

  endl(cout);

  return 0;
}
//References
//		 https://en.cppreference.com/w/Main_Page
