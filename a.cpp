#include <iostream>

#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string N;
        cin >> N;

        int carry = 1;
        for (int i = N.length() - 1; i >= 0; i--) {
            int digit = N[i] - '0';
            int sum = digit + carry;
            N[i] = (sum % 10) + '0';
            carry = sum / 10;
            if (carry == 0) break;
        }

        if (carry == 1) {
            N.insert(N.begin(), '1');
        }

        cout << N << endl;
    }
    return 0;
}