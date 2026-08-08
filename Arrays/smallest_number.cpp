#include <iostream>
using namespace std;

int main() {
    int arr[] = {45, 12, 78, 5, 34};
    int n = 5;

    int smallest = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    cout << "Smallest number = " << smallest;

    return 0;
}