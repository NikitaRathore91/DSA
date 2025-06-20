#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> binary_decimals;

// Function to precompute binary decimals up to 10^5
void precomputeBinaryDecimals() {
    for (int i = 0; i < 20; ++i) {  // 2^20 is approximately 10^6
        binary_decimals.insert(1 << i);
    }
}

// Function to check if n can be represented as a product of binary decimals
bool isProductOfBinaryDecimals(int n) {
    if (n == 1) return true;
    for (int bd : binary_decimals) {
        if (n % bd == 0 && isProductOfBinaryDecimals(n / bd)) {
            return true;
        }
    }
    return false;
}

int main() {
    // Precompute binary decimals
    precomputeBinaryDecimals();

    // Input number of test cases
    int t;
    cin >> t;

    // Iterate through each test case
    while (t--) {
        int n;
        cin >> n;
        if (n == 1 || isProductOfBinaryDecimals(n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}