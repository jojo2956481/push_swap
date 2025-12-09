This project has been created as part of the 42 curriculum by pgougne and lebeyssa

# push_swap

## 📘 Merged Comparison Table of Sorting Algorithms

```
| Algorithm                | Best Case                                           | Average Case    | Worst Case              | Space Complexity (aux.) | Stable?                               |
| ------------------------ | --------------------------------------------------- | --------------- | ----------------------- | ----------------------- | ------------------------------------- |
| **Merge Sort**           | O(n log n)                                          | O(n log n)      | O(n log n)              | O(n)                    | ✔️ Yes                                |
| **Heap Sort**            | O(n log n)                                          | O(n log n)      | O(n log n)              | O(1)                    | ❌ No                                  |
| **Quick Sort**           | O(n log n)                                          | O(n log n)      | O(n²)                   | O(log n) recursion      | ❌ No                                  |
| **Insertion Sort**       | O(n)                                                | O(n²)           | O(n²)                   | O(1)                    | ✔️ Yes                                |
| **Bubble Sort**          | O(n)                                                | O(n²)           | O(n²)                   | O(1)                    | ✔️ Yes                                |
| **Cocktail Shaker Sort** | O(n)                                                | O(n²)           | O(n²)                   | O(1)                    | ✔️ Yes                                |
| **Timsort**              | O(n)                                                | O(n log n)      | O(n log n)              | O(n)                    | ✔️ Yes                                |
| **Selection Sort**       | O(n²)                                               | O(n²)           | O(n²)                   | O(1)                    | ❌ No                                  |
| **Shell Sort**           | Depends on gap sequence (≈ O(n log² n) to O(n¹·²⁵)) | Depends on gaps | O(n²) typically         | O(1)                    | ❌ No                                  |
| **Comb Sort**            | O(n log n)                                          | O(n²)           | O(n²)                   | O(1)                    | ❌ No                                  |
| **Odd–Even Sort**        | O(n)                                                | O(n²)           | O(n²)                   | O(1)                    | ✔️ Yes                                |
| **Tree Sort (BST Sort)** | O(n log n)                                          | O(n log n)      | O(n²) (unbalanced tree) | O(n)                    | ❌ No                                  |
| **Smoothsort**           | O(n)                                                | O(n log n)      | O(n log n)              | O(1)                    | ❌ No                                  |
| **Introsort**            | O(n log n)                                          | O(n log n)      | O(n log n)              | O(1)                    | ❌ No                                  |
| **Counting Sort**        | O(n + k)                                            | O(n + k)        | O(n + k)                | O(n + k)                | ✔️ Yes                                |
| **Radix Sort (LSD/MSD)** | O(n·k)                                              | O(n·k)          | O(n·k)                  | O(n + k)                | ✔️ LSD / ❌ MSD (sometimes)            |
| **Bucket Sort**          | O(n) (uniform distribution)                         | O(n)            | O(n²)                   | O(n)                    | ✔️ Yes (if per-bucket sort is stable) |

```

## Resources

- https://fr.wikipedia.org/wiki/Algorithme_de_tri

- http://lwh.free.fr/pages/algo/tri/tri.htm
