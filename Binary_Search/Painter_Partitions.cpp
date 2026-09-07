#include <iostream>
using namespace std;

bool isPossible(int arr[], int n, int painters, int maxWork) {
    int painterCount = 1;
    int work = 0;

    for (int i = 0; i < n; i++) {

        if (work + arr[i] <= maxWork) {
            work += arr[i];
        }
        else {
            painterCount++;
            work = arr[i];

            if (painterCount > painters) {
                return false;
            }
        }
    }

    return true;
}

int main() {

    int n, painters;

    cout << "Enter number of boards: ";
    cin >> n;

    int arr[n];

    cout << "Enter length of each board: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of painters: ";
    cin >> painters;

    if (painters > n) {
        cout << "Allocation not possible";
        return 0;
    }

    int low = 0;
    int high = 0;

    // Find maximum board and total length
    for (int i = 0; i < n; i++) {

        high += arr[i];

        if (arr[i] > low) {
            low = arr[i];
        }
    }

    int answer = high;

    // Binary Search on Answer
    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, painters, mid)) {
            answer = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << "Minimum maximum work = " << answer << endl;

    return 0;
}