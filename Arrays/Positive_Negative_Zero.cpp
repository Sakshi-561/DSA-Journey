#include <iostream>
using namespace std;

int main() {
    int n;
    int positive = 0, negative = 0, zero = 0;

    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (arr[i] > 0)
            positive++;
        else if (arr[i] < 0)
            negative++;
        else
            zero++;
    }

    cout << "Positive numbers = " << positive << endl;
    cout << "Negative numbers = " << negative << endl;
    cout << "Zeros = " << zero << endl;

    return 0;
}