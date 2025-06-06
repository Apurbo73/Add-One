 🔢 Problem:

You can't use regular integers (`int`, `long long`) because `N` can be up to **200,000 digits** long. So you treat the number as a **string of digits**, and simulate addition just like how we do it by hand.

---

### ✅ Code Breakdown:

```cpp
int T;
cin >> T;
```

* Read the number of test cases.

```cpp
while (T--) {
    string N;
    cin >> N;
```

* For each test case, read the big number `N` as a string.

```cpp
    int carry = 1; // We are adding 1
```

* Initialize a `carry` variable to `1` because we are computing `N + 1`.

---

### 🔁 Simulate Addition from Right to Left:

```cpp
    for (int i = N.length() - 1; i >= 0; i--) {
        int digit = N[i] - '0';        // Convert char to int
        int sum = digit + carry;       // Add the carry
        N[i] = (sum % 10) + '0';       // Update digit (mod 10), convert back to char
        carry = sum / 10;              // Compute new carry
        if (carry == 0) break;         // No need to continue if carry is 0
    }
```

**Example:**
Let's say `N = "999"`:

* Start from right: 9 + 1 = 10 → write `0`, carry `1`
* Next: 9 + 1 = 10 → write `0`, carry `1`
* Next: 9 + 1 = 10 → write `0`, carry `1`
* Now carry is still `1`, so we handle that in the next step:

---

### 🆕 Handle Leftover Carry:

```cpp
    if (carry == 1) {
        N.insert(N.begin(), '1');  // Add '1' at the start of the string
    }
```

* If there’s still carry left after processing all digits, you need to add a `'1'` at the front (e.g., "999" → "1000").

---

### 🖨️ Print the Result:

```cpp
    cout << N << endl;
}
```

* Print the final result string for that test case.

---






This C++ code reads a large number N as a string to handle very large inputs (up to 200,000 digits), and simulates adding 1 to it. For each test case, it starts from the rightmost digit and adds 1, handling carry just like manual addition. If the sum of a digit and carry exceeds 9, it sets that digit to 0 and carries over 1 to the next digit to the left.

If there's still a carry left after the loop (like when adding 1 to "999"), it inserts a '1' at the beginning of the string, resulting in "1000". This way, the program avoids using large number libraries or data types, and directly works with strings to perform accurate big number arithmetic
