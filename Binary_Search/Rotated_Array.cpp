#include <iostream>
using namespace std;

int searchInRotatedArray(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Target mil gaya
        if (arr[mid] == target) {
            return mid;
        }

        // Left half sorted hai
        if (arr[low] <= arr[mid]) {

            // Target left sorted half me hai
            if (arr[low] <= target && target < arr[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        // Right half sorted hai
        else {

            // Target right sorted half me hai
            if (arr[mid] < target && target <= arr[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    int n, target;

    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout << "Enter rotated sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> target;

    int result = searchInRotatedArray(arr, n, target);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    }
    else {
        cout << "Element not found" << endl;
    }

    return 0;
}