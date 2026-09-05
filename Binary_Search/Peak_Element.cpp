#include <iostream>
using namespace std;

int findPeak(int arr[], int n) {
    int low = 0;
    int high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[mid + 1]) {
            // Peak right side me hai
            low = mid + 1;
        }
        else {
            // Peak mid ya left side me hai
            high = mid;
        }
    }

    return low;
}

int main() {
    int n;

    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int peakIndex = findPeak(arr, n);

    cout << "Peak element = " << arr[peakIndex] << endl;
    cout << "Peak element index = " << peakIndex << endl;

    return 0;
}