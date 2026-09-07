#include <iostream>
using namespace std;

bool isPossible(int arr[], int n, int students, int maxPages) {
    int studentCount = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {

        if (pages + arr[i] <= maxPages) {
            pages += arr[i];
        }
        else {
            studentCount++;
            pages = arr[i];

            if (studentCount > students) {
                return false;
            }
        }
    }

    return true;
}

int main() {

    int n, students;

    cout << "Enter number of books: ";
    cin >> n;

    int arr[n];

    cout << "Enter pages in each book: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of students: ";
    cin >> students;

    if (students > n) {
        cout << "Allocation not possible";
        return 0;
    }

    int low = 0;
    int high = 0;

    for (int i = 0; i < n; i++) {
        high += arr[i];

        if (arr[i] > low) {
            low = arr[i];
        }
    }

    int answer = high;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, students, mid)) {
            answer = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << "Minimum maximum pages = " << answer << endl;

    return 0;
}