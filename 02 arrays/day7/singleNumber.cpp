#include <bits/stdc++.h>
using namespace std;

//
// Approach 1: Hashing using a frequency vector
//
// GOAL:
//
// ⏱ TIME COMPLEXITY ANALYSIS:
//   - Let `n` be the size of the array.
//   - Let `m` be the maximum element in the array.
//   - Step 1: max_element() → O(n) comparisons.
//   - Step 2: Loop to count frequencies → O(n) time.
//   - Step 3: Loop to find element with freq = 1 → O(n) time.
//   → Total: O(n) + O(n) + O(n) = **O(n)**
//
// 🧠 SPACE COMPLEXITY ANALYSIS:
//   - We allocate a vector of size (m + 1) to store frequency.
//   - If all values in arr are ≤ m, then space = O(m + 1) = **O(m)**
//   - Additional: No other major space used.
//
//   - Vector initialization: vector<int> hash(m+1, 0) is O(m+1) memory
//   - Accessing vector: O(1) per operation due to contiguous memory layout
int findSingleUsingHash(const vector<int> &arr)
{
    int maxVal = *max_element(arr.begin(), arr.end()); // O(n)
    vector<int> hash(maxVal + 1, 0);                   // O(m+1) space

    for (int num : arr) // O(n)
    {
        hash[num]++;
    }

    for (int num : arr) // O(n)
    {
        if (hash[num] == 1)
            return num;
    }

    return -1; // If no unique element is found
}

//
// Approach 2: XOR Method (Optimal for this problem)
//
// GOAL:
//   XOR all elements. Since a^a = 0 and a^0 = a,
//   all duplicate elements cancel out, leaving the unique one.
//
// ⏱ TIME COMPLEXITY ANALYSIS:
//   - Single pass through array → O(n)
//   - XOR operation is O(1) per element
//   - Total operations = n * O(1) = **O(n)**
//
// 🧠 SPACE COMPLEXITY ANALYSIS:
//   - Only one integer variable used (result) → **O(1)**
//
//   - XOR is a simple bitwise op (very fast, constant time)
//   - No additional memory or structures involved
int findSingleUsingXOR(const vector<int> &arr)
{
    int result = 0;
    for (int num : arr) // O(n)
    {
        result ^= num; // O(1) per XOR
    }
    return result;
}

//
// Approach 3: Using unordered_map to count frequencies
//
// GOAL:
//   Use a hash map to count frequencies, then find the element with count 1.
//
// ⏱ TIME COMPLEXITY ANALYSIS:
//   - Let `n` be size of array, `k` be number of distinct elements.
//   - Step 1: Insert all n elements into unordered_map → average O(1) per insert → O(n)
//             (Worst-case: O(n²) if many hash collisions, but unlikely.)
//   - Step 2: Iterate through map of size k → O(k)
//   - Total: **O(n + k)** → For most arrays where k ≈ n → **O(n)**
//
// 🧠 SPACE COMPLEXITY ANALYSIS:
//   - unordered_map<int, int> stores up to k key-value pairs.
//   - Max space: O(k) keys + values → **O(k)**
//   - Worst-case: when all n elements are distinct → O(n)
//
//   - Hash map overhead is higher than vector (due to hashing logic).
//   - Memory used = hash table size + load factor buffer.
//   - Lookup/insert is amortized O(1), not strict O(1).
int findSingleUsingMap(const vector<int> &arr)
{
    unordered_map<int, int> freq;

    for (int num : arr) // O(n)
    {
        freq[num]++;
    }

    for (auto &p : freq) // O(k)
    {
        if (p.second == 1)
            return p.first;
    }

    return -1; // If no unique element is found
}

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};

    cout << "Approach 1 (Hash Vector): " << findSingleUsingHash(arr) << endl;
    cout << "Approach 2 (XOR): " << findSingleUsingXOR(arr) << endl;
    cout << "Approach 3 (Unordered Map): " << findSingleUsingMap(arr) << endl;

    return 0;
}
