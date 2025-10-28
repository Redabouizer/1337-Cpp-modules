# PmergeMe Algorithm Architecture

## System Overview

```
┌─────────────────────────────────────────────────────────────┐
│                     Input: Array of Integers                │
└──────────────────────┬──────────────────────────────────────┘
                       │
                       ▼
            ┌──────────────────────┐
            │  Parse & Validate    │
            │  Input Arguments     │
            └──────────┬───────────┘
                       │
         ┌─────────────┴─────────────┐
         │                           │
         ▼                           ▼
    ┌──────────┐              ┌──────────┐
    │  Vector  │              │  Deque   │
    │  Data    │              │  Data    │
    └────┬─────┘              └────┬─────┘
         │                         │
         ▼                         ▼
    ┌──────────────────────┐  ┌──────────────────────┐
    │ fordJohnsonVector()  │  │ fordJohnsonDeque()   │
    │                      │  │                      │
    │ Time & Sort          │  │ Time & Sort          │
    └────┬─────────────────┘  └────┬─────────────────┘
         │                         │
         ▼                         ▼
    ┌──────────────────────┐  ┌──────────────────────┐
    │   Sorted Vector      │  │    Sorted Deque      │
    │   + Time Metrics     │  │    + Time Metrics    │
    └─────────┬────────────┘  └─────────┬────────────┘
              │                         │
              └──────────┬──────────────┘
                         │
                         ▼
            ┌──────────────────────────┐
            │   Display Results        │
            │ Before | After | Timing  │
            └──────────────────────────┘
```

---

## Sorting Algorithm Flow: Divide & Conquer with Binary Insertion

### Phase 1: Input Array (Example: 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1)

```
Level 0 (Original):
┌─────────────────────────────────────────────────────────────────────────┐
│ 22│21│20│19│18│17│16│15│14│13│12│11│10│ 9│ 8│ 7│ 6│ 5│ 4│ 3│ 2│ 1 │
└─────────────────────────────────────────────────────────────────────────┘
Size: 22 elements → Threshold > 20 → RECURSIVE SORT
```

### Phase 2: Divide into Left & Right Halves

```
Level 1 - First Recursion:
├─ Left Half (11 elements)
│  ┌──────────────────────────────────────┐
│  │ 22│21│20│19│18│17│16│15│14│13│12│
│  └──────────────────────────────────────┘
│  Size: 11 ≤ 20 → INSERTION SORT
│
└─ Right Half (11 elements)
   ┌──────────────────────────────────────┐
   │ 10│ 9│ 8│ 7│ 6│ 5│ 4│ 3│ 2│ 1 │
   └──────────────────────────────────────┘
   Size: 11 ≤ 20 → INSERTION SORT
```

### Phase 3: Insertion Sort on Left Half (22 21 20 19 18 17 16 15 14 13 12)

```
Step 1: [22 | 21 20 19 18 17 16 15 14 13 12]
Step 2: [21 22 | 20 19 18 17 16 15 14 13 12]
Step 3: [20 21 22 | 19 18 17 16 15 14 13 12]
Step 4: [19 20 21 22 | 18 17 16 15 14 13 12]
...
Final:  [12 13 14 15 16 17 18 19 20 21 22]
         ▲  ▲  ▲  ▲  ▲  ▲  ▲  ▲  ▲  ▲  ▲
         Sorted Left Half (ascending)
```

### Phase 4: Insertion Sort on Right Half (10 9 8 7 6 5 4 3 2 1)

```
Step 1: [10 | 9 8 7 6 5 4 3 2 1]
Step 2: [9 10 | 8 7 6 5 4 3 2 1]
Step 3: [8 9 10 | 7 6 5 4 3 2 1]
Step 4: [7 8 9 10 | 6 5 4 3 2 1]
...
Final:  [1 2 3 4 5 6 7 8 9 10]
        ▲ ▲ ▲ ▲ ▲ ▲ ▲ ▲ ▲ ▲
        Sorted Right Half (ascending)
```

### Phase 5: Merge with Comparison Counting

```
Two Sorted Arrays:
Left:  [12 13 14 15 16 17 18 19 20 21 22]
Right: [ 1  2  3  4  5  6  7  8  9 10]

Merge Process (with comparisons):

i=0, j=0: Compare 12 vs 1  → 1 < 12 → Output: [ 1 ]
i=0, j=1: Compare 12 vs 2  → 2 < 12 → Output: [ 1  2 ]
i=0, j=2: Compare 12 vs 3  → 3 < 12 → Output: [ 1  2  3 ]
i=0, j=3: Compare 12 vs 4  → 4 < 12 → Output: [ 1  2  3  4 ]
i=0, j=4: Compare 12 vs 5  → 5 < 12 → Output: [ 1  2  3  4  5 ]
i=0, j=5: Compare 12 vs 6  → 6 < 12 → Output: [ 1  2  3  4  5  6 ]
i=0, j=6: Compare 12 vs 7  → 7 < 12 → Output: [ 1  2  3  4  5  6  7 ]
i=0, j=7: Compare 12 vs 8  → 8 < 12 → Output: [ 1  2  3  4  5  6  7  8 ]
i=0, j=8: Compare 12 vs 9  → 9 < 12 → Output: [ 1  2  3  4  5  6  7  8  9 ]
i=0, j=9: Compare 12 vs 10 → 10< 12 → Output: [ 1  2  3  4  5  6  7  8  9 10]
(Right exhausted, copy remaining Left)
Output: [1 2 3 4 5 6 7 8 9 10 12 13 14 15 16 17 18 19 20 21 22]

✓ FINAL SORTED ARRAY
```

---

## Complete Recursion Tree Example: Array of 9 Elements

### Input: [3, 5, 9, 7, 4, 2, 8, 1, 6]

```
                    [3 5 9 7 4 2 8 1 6]
                            │
                Size 9 > 20? NO → Use Insertion Sort
                            │
        ────────────────────┼────────────────────
        │                                       │
    Level 1            Mid = 4              Level 1
    (Size 4 ≤ 20)                         (Size 5 ≤ 20)
        │                                       │
    [3 5 9 7]                             [4 2 8 1 6]
        │                                       │
        │ Insertion Sort                        │ Insertion Sort
        ▼                                       ▼
    [3 5 7 9]                             [1 2 4 6 8]
        │                                       │
        └─────────────────┬─────────────────────┘
                          │
                    MERGE Operation
                          │
         Compare & Output Elements
              (Count Comparisons)
                          │
                          ▼
        ┌────────────────────────────────┐
        │  [1 2 3 4 5 6 7 8 9]           │
        │                                │
        │  SORTED FINAL ARRAY ✓          │
        └────────────────────────────────┘

Comparisons Counted: ~10-12
Recursive Depth: 2
Merge Operations: 1
```

---

## Detailed Merge Process: Step-by-Step

### Merging [3, 5, 7, 9] + [1, 2, 4, 6, 8]

```
Pointers:  i=0(Left)  j=0(Right)
Left:      [3 5 7 9]
Right:     [1 2 4 6 8]
Output:    []

Step 1:  Compare 3 vs 1 → 1 < 3 ✓  Output: [1],          j++
         i=0, j=1
         
Step 2:  Compare 3 vs 2 → 2 < 3 ✓  Output: [1 2],        j++
         i=0, j=2
         
Step 3:  Compare 3 vs 4 → 3 < 4 ✓  Output: [1 2 3],      i++
         i=1, j=2
         
Step 4:  Compare 5 vs 4 → 4 < 5 ✓  Output: [1 2 3 4],    j++
         i=1, j=3
         
Step 5:  Compare 5 vs 6 → 5 < 6 ✓  Output: [1 2 3 4 5],  i++
         i=2, j=3
         
Step 6:  Compare 7 vs 6 → 6 < 7 ✓  Output: [1 2 3 4 5 6],  j++
         i=2, j=4
         
Step 7:  Compare 7 vs 8 → 7 < 8 ✓  Output: [1 2 3 4 5 6 7],  i++
         i=3, j=4
         
Step 8:  Compare 9 vs 8 → 8 < 9 ✓  Output: [1 2 3 4 5 6 7 8],  j++
         i=3, j=5
         
Step 9:  j exhausted, copy remaining: Output: [1 2 3 4 5 6 7 8 9]
         ✓ MERGE COMPLETE
```

---

## Comparison Counting Mechanism

```
┌──────────────────────────────────┐
│   _comp(a, b) Function           │
├──────────────────────────────────┤
│                                  │
│  _comparisonCount++;             │
│  return (a < b);                 │
│                                  │
│  Counts every comparison         │
│  in the entire algorithm         │
│                                  │
└──────────────────────────────────┘
                │
                ▼
        ┌──────────────────┐
        │ Used in:         │
        ├──────────────────┤
        │ • Insertion Sort │
        │ • Merge Process  │
        │ • Binary Search  │
        └──────────────────┘
                │
                ▼
        ┌────────────────────────────┐
        │ Result: Total Comparisons  │
        │ = Measure of Efficiency    │
        └────────────────────────────┘
```

---

## Data Structure: Vector vs Deque

### Vector Implementation (Random Access)

```
Memory Layout (Contiguous):
┌─────────────────────────────────┐
│ [12] [13] [14] [15] [16] [17]   │  Fast Access: O(1)
└─────────────────────────────────┘
 Idx:0   1   2   3   4   5

Operations:
• Access arr[i]: O(1) - Direct index
• Insert: O(n) - May require reallocation
• Merge: O(n) - Sequential access
• Time: Typically faster ⚡
```

### Deque Implementation (Chunked)

```
Memory Layout (Chunks):
┌──────────┬──────────┬──────────┐
│Chunk 0   │Chunk 1   │Chunk 2   │
│[1][2][3] │[4][5][6] │[7][8][9] │
└──────────┴──────────┴──────────┘
↑         ↑          ↑
Indexed map keeps references

Operations:
• Access arr[i]: O(1) - Index mapping
• Insert: O(n) - Still sequential
• Merge: O(n) - Iterates through chunks
• Time: Slightly slower due to indirection 🐢
```

---

## Algorithm Complexity Analysis

### Time Complexity

```
fordJohnsonVector(arr):

if arr.size ≤ 20:
    ├─ Time: O(n²)           Insertion Sort
    └─ Best case: O(n)       Already sorted

else:
    ├─ Split:        O(n)    Create left/right
    ├─ Sort left:    T(n/2)  Recursive call
    ├─ Sort right:   T(n/2)  Recursive call
    └─ Merge:        O(n)    Combine sorted arrays

Total Recurrence: T(n) = 2·T(n/2) + O(n)
Solution: T(n) = O(n log n)
```

### Comparison Counting

```
Maximum Comparisons:

For n = 22:
├─ Left Sort (11 elements):   ~55 comparisons (insertion sort)
├─ Right Sort (11 elements):  ~55 comparisons (insertion sort)
└─ Merge (22 elements):       ~20 comparisons (binary merge)

Total: ~130 comparisons (worst case)
Typical: ~100-120 comparisons

Formula: F(n) ≈ n log₂(n) - n + 1
For n=22: F(22) ≈ 22·4.46 - 22 + 1 ≈ 77 comparisons
```

---

## Execution Flow Diagram

```
START
  │
  ├─ parseInput()
  │  └─ Read command line arguments
  │
  ├─ Create Vector & Deque copies
  │
  ├─ Display "Before: [input array]"
  │
  ├──────────────────────────────────┐
  │ VECTOR SORT                       │
  ├──────────────────────────────────┤
  │ Timer START                       │
  │ fordJohnsonVector(vector)         │
  │ │                                 │
  │ ├─ if size ≤ 20: Insertion Sort  │
  │ │                                 │
  │ └─ else:                          │
  │    ├─ Split in half              │
  │    ├─ fordJohnsonVector(left)    │
  │    ├─ fordJohnsonVector(right)   │
  │    └─ Merge with comparisons     │
  │ Timer END                         │
  │ comparisonCount_vec = count      │
  │
  ├──────────────────────────────────┐
  │ DEQUE SORT                        │
  ├──────────────────────────────────┤
  │ Timer START                       │
  │ fordJohnsonDeque(deque)           │
  │ │ [Same algorithm as vector]      │
  │ Timer END                         │
  │ comparisonCount_deq = count      │
  │
  ├─ Display "After: [sorted array]"
  │
  ├─ Display "Time to process (vector): X.XXXXX us"
  │
  ├─ Display "Time to process (deque): Y.YYYYY us"
  │
  END
```

---

## Key Functions Architecture

### Function Call Hierarchy

```
main(argc, argv)
    │
    ├─ PmergeMe instance created
    │
    ├─ run(argc, argv)
    │   │
    │   ├─ parseInput()
    │   │
    │   ├─ displaySequence("Before: ", vector)
    │   │
    │   ├─ fordJohnsonVector(vector)
    │   │   │
    │   │   ├─ Check size
    │   │   ├─ if size ≤ 20: [insertion loop with _comp]
    │   │   └─ else:
    │   │       ├─ Create left & right
    │   │       ├─ fordJohnsonVector(left)    [RECURSIVE]
    │   │       ├─ fordJohnsonVector(right)   [RECURSIVE]
    │   │       └─ Merge process [_comp counting]
    │   │
    │   ├─ fordJohnsonDeque(deque)
    │   │   [Same structure as Vector]
    │   │
    │   ├─ displaySequence("After: ", vector)
    │   │
    │   └─ Display timing metrics
    │
    └─ Return success/failure
```

---

## Summary Table

| Aspect | Details |
|--------|---------|
| **Algorithm** | Merge Sort + Binary Insertion (Ford-Johnson inspired) |
| **Time Complexity** | O(n log n) average & worst case |
| **Space Complexity** | O(n) - For merge temporary arrays |
| **Stability** | Stable (equal elements maintain order) |
| **Best Case** | O(n) - Already sorted (insertion sort) |
| **Worst Case** | O(n log n) - Requires recursion |
| **Comparisons** | ~n log₂(n) (counted & tracked) |
| **Adaptive** | Yes - Fast when partially sorted |
| **In-place** | No - Requires extra space for merge |

---

## Example: Complete Execution

```
Input Command: ./PmergeMe 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

Before: 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

[SORTING HAPPENS]
├─ Vector Sort:
│  ├─ Split: [22...16] | [15...1]
│  ├─ Sort each half via insertion
│  └─ Merge both sorted halves
│
└─ Deque Sort: [Same process]

After:  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22

Time to process a range of 22 elements with std::vector : 7.00000 us
Time to process a range of 22 elements with std::deque  : 33.00000 us
```

