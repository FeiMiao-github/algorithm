// tmp test

#include <iostream>

int arr1[10];
int arr2[20];

int main() {
    *(arr1 + 9) = 1;

    std::cout << arr1[0] << ", " << arr2[0] << "\n";
    return 0;
}