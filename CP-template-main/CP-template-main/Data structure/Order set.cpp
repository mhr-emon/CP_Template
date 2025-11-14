#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Ordered set of integers
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ordered_set s;

    // --- INSERT ---
    s.insert(5);
    s.insert(1);
    s.insert(10);
    s.insert(7);
    cout << "After insertions: ";
    for (int x : s) cout << x << " "; // 1 5 7 10
    cout << "\n";

    // --- SIZE / EMPTY ---
    cout << "Size: " << s.size() << "\n";       // 4
    cout << "Empty? " << (s.empty() ? "Yes" : "No") << "\n"; // No

    // --- FIND ---
    if (s.find(7) != s.end())
        cout << "7 found in set\n";
    else
        cout << "7 not found\n";

    // --- ERASE ---
    s.erase(5);
    cout << "After erasing 5: ";
    for (int x : s) cout << x << " "; // 1 7 10
    cout << "\n";

    // --- ORDER-STATISTICS ---
    cout << "0-th smallest element: " << *s.find_by_order(0) << "\n"; // 1
    cout << "1-th smallest element: " << *s.find_by_order(1) << "\n"; // 7
    cout << "Number of elements < 7: " << s.order_of_key(7) << "\n";  // 1
    cout << "Number of elements < 8: " << s.order_of_key(8) << "\n";  // 2

    // --- LOWER / UPPER BOUND ---
    cout << "Lower bound of 7: " << *s.lower_bound(7) << "\n"; // 7
    cout << "Upper bound of 7: " << *s.upper_bound(7) << "\n"; // 10

    // --- ITERATION ---
    cout << "All elements (forward): ";
    for (auto it = s.begin(); it != s.end(); ++it) cout << *it << " ";
    cout << "\n";

    cout << "All elements (reverse): ";
    for (auto it = s.rbegin(); it != s.rend(); ++it) cout << *it << " ";
    cout << "\n";

    // --- SIMULATING MULTISET ---
    typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
    ordered_multiset ms;
    int idx = 0;
    ms.insert({5, idx++});
    ms.insert({5, idx++}); // duplicate allowed
    ms.insert({3, idx++});

    cout << "Ordered multiset elements: ";
    for (auto p : ms) cout << p.first << " "; // 3 5 5
    cout << "\n";

    cout << "Number of elements < 5: " << ms.order_of_key({5,0}) << "\n"; // 1

  int cnt_less_x = s.order_of_key(x);
int cnt_greater_c = s.size() - s.order_of_key(c + 1);


    return 0;
}
