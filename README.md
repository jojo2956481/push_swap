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