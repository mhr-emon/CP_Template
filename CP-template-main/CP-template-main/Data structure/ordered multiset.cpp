#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// ordered_multiset: stores pairs (value, unique index)
typedef tree<
    pair<int,int>,              // key type: pair (value, unique_index)
    null_type,                  // mapped type: none (like set)
    less<pair<int,int>>,        // comparator
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_multiset;

int main() {
    ordered_multiset ms;
    int idx = 0; // unique index for duplicates

    // --- insert elements ---
    ms.insert({5, idx++});
    ms.insert({3, idx++});
    ms.insert({5, idx++}); // duplicate allowed
    ms.insert({7, idx++});
    ms.insert({5, idx++}); // duplicate allowed

    // --- iteration ---
    cout << "Elements in ordered_multiset: ";
    for (auto p : ms) cout << p.first << " ";
    cout << "\n"; // 3 5 5 5 7

    // --- order-statistics ---
    cout << "0-th smallest element: " << ms.find_by_order(0)->first << "\n"; // 3
    cout << "2-nd smallest element: " << ms.find_by_order(2)->first << "\n"; // 5

    // number of elements < 5
    cout << "Number of elements < 5: " << ms.order_of_key({5, 0}) << "\n"; // 1

    // number of elements <= 5
    cout << "Number of elements <= 5: " << ms.order_of_key({5, INT_MAX}) << "\n"; // 4

    // --- erase one occurrence of 5 ---
    auto it = ms.lower_bound({5, 0});
    if (it != ms.end()) ms.erase(it);

    cout << "After erasing one 5: ";
    for (auto p : ms) cout << p.first << " ";
    cout << "\n"; // 3 5 5 7

    return 0;
}
