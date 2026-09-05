#include <iostream>
using namespace std;

int squareRoot(int n) {
    int low = 0;
    int high = n;
    int answer = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mid <= n / mid) {
            answer = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return answer;
}

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    int result = squareRoot(n);

    cout << "Square root = " << result << endl;

    return 0;
}