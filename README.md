*This project has been created as part of the 42 curriculum by pgougne [, lebeyssa]*
___
# **Description**

This project is about sorting numbers in ascending order with only two stacks and restricted actions.
We have got stack a and stack b, and the actions was :
- Swap (sa, sb, ss): Swap the first two elements at the top of the stack.
- Push (pa, pb): Take the first element at the top of one stack and put it at the top of the other.
- Rotate (ra, rb, rr): Shift up all elements by one. The first element becomes the last.
- Reverse Rotate (rra, rrb, rrr): Shift down all elements by one. The last element becomes the first.

With only these eleven actions, we are able to sort a stacks full of arguments.

## Algorithmic Strategy

To handle different input sizes efficiently, the project implements sorting algorithms from three distinct complexity classes. Each class represents a trade-off between simplicity of implementation and performance.

---

### 1. Simple Algorithms (O(n²))

Simple algorithms are based on repeated comparisons and local rearrangements of elements.  
They are easy to implement and understand but become inefficient as the number of elements increases.

**Typical behavior:**
- Elements are compared one by one.
- Multiple passes are required to reach a sorted state.
- The number of operations grows quadratically with input size.

### 1. Insertion Sort (Non-Optimized) — O(n²)

**Adaptation to push_swap:**
- The algorithm operates exclusively on stack A.
- Sorting is performed using only swap (`sa`) and rotation (`ra`, `rra`) operations.
- No elements are pushed to stack B.

**Why it is not optimized:**
- The algorithm does not take advantage of stack B.
- Many redundant rotations and swaps are required.
- The number of operations increases rapidly with input size.

**Use case:**
This version of insertion sort is used only as a baseline algorithm for very small datasets and to illustrate the limitations of simple O(n²) approaches under push_swap constraints

---

### 2. Medium Algorithms (O(n√n))

Medium-complexity algorithms improve performance by reducing the number of comparisons through data partitioning.  
They divide the input into several smaller groups, allowing partial ordering before final recombination.

**Typical behavior:**
- The dataset is split into √n blocks or ranges.
- Each block is processed independently.
- The partial results are merged into a fully sorted sequence.

### 2. Chunk Sort Adaptation — O(n√n)

**Adaptation to push_swap:**
- Each value is assigned an index representing its position in the sorted order.
- The index range is divided into √n chunks.
- Elements belonging to the current chunk are pushed from stack A to stack B using `pb`.
- Stack B is organized so that larger values are retrieved first using `pa`.

**Why it fits the rules:**
- Chunk partitioning works naturally with push and rotate operations.
- No direct access to elements is required.
- Reduces the number of unnecessary rotations compared to O(n²) approaches.

**Advantages under push_swap constraints:**
- Significantly fewer instructions for medium-sized datasets.
- Good balance between simplicity and efficiency.

---

### 3. Complex Algorithms (O(n log n))

Complex algorithms rely on advanced partitioning or non-comparison-based techniques to achieve optimal performance.  
They significantly reduce the number of required operations and scale efficiently with large datasets.

**Typical behavior:**
- The dataset is recursively divided or processed bit by bit.
- Sorting progresses through structured passes rather than simple comparisons.
- The total number of operations grows logarithmically with input size.

### 3. Radix Sort Adaptation — O(n log n)

**Adaptation to push_swap:**
- Each element is first replaced by its index in the sorted sequence.
- Sorting is performed bit by bit on these indices.
- For each bit:
  - Elements with a `0` bit are pushed to stack B (`pb`).
  - Elements with a `1` bit are rotated in stack A (`ra`).
- After each pass, all elements in stack B are pushed back to stack A (`pa`).

**Why it fits the rules:**
- Uses only allowed stack operations.
- Does not rely on comparisons between arbitrary elements.
- Fully compatible with the two-stack limitation.

**Advantages under push_swap constraints:**
- Predictable and efficient number of operations.
- Excellent scalability for large inputs (100+ elements).

---


### Conclusion

Within the constraints of *push_swap*, different algorithmic strategies are required depending on input size.  
Insertion sort serves as a simple baseline for small datasets.  
Chunk sort provides an efficient intermediate solution using value partitioning.  
Radix sort offers the best performance for large datasets while strictly respecting the project rules.
___
# **Instructions**

Compilation is directed by a Makefile with this commands :
- make (make all) : compile the executable file push_swap
- make bonus : compile the executable of the checker (bonus)
- make clean : remove every .o files
- make fclean : remove every .o files in addition of executable files (push_swap & checker) 
- make re : remove like make fclean & recompile like make all

Run the program by passing a list of integers as arguments:

>./push_swap 5 6 3 2 1 4 7 8 9

Example of output: 
>ra\
>pb\
>rra\
>sa\
>pa

Options :\
Multiple options can be added in the command :\
--simple / --medium / --complex / --adaptive : choosing the algorithm\
--bench : display informations

Example :
>./push_swap --simple --bench 5 6 2 4 7 8 9

___
# **Resources**
For this project, we used many tutorials, to understand the difference between algorithms and algorithms itself.\
For example, Geekforgeeks for algorithms demonstrations, stackoverflow/stackexchange for technical challenge.\
AI was use to discover the project, find response that is very specific, and rarely debugging edge cases.

___
# **Technical choices**
We decided to choose these three algorithms :\
--simple : Insertion sort\
--medium : chunk sort\
--complex : radix sort\
--adaptive : choosing between the previous algorithms depending of the disorder
___