#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int arr[], int n, int cows, int minDistance) {

    int cowCount = 1;
    int lastPosition = arr[0];

    for (int i = 1; i < n; i++) {

        if (arr[i] - lastPosition >= minDistance) {
            cowCount++;
            lastPosition = arr[i];
        }

        if (cowCount == cows) {
            return true;
        }
    }

    return false;
}

int main() {

    int n, cows;

    cout << "Enter number of stalls: ";
    cin >> n;

    int arr[n];

    cout << "Enter stall positions: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of cows: ";
    cin >> cows;

    // Sort stall positions
    sort(arr, arr + n);

    int low = 1;
    int high = arr[n - 1] - arr[0];

    int answer = 0;

    // Binary Search on Answer
    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, cows, mid)) {
            answer = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << "Maximum minimum distance = " << answer << endl;

    return 0;
}