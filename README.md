# push_swap

> This project was created in compliance with the 42 norm, which means no ternary operators, no switches, no for loops, no in function comments, ... -> https://github.com/FreddyMSchubert/42_cursus/blob/main/en.norm.pdf

### Subject

```
[2] [ ]
[1] [ ]
[3] [ ]
[6] [ ]
[5] [ ]
[8] [ ]
 a -- b
```

Given 2 stacks a and b where b is emtpy and a is filled with a random amount of non-duplicated integers, sort numbers in ascending order into stack a with the following operations:

- sa (swap a) -> Swap the first two elements at the top of stack a
- sb (swap b) -> Swap the first two elements at the top of stack b
- ss (swap 2) -> Swap the first two elements at the top of both stacks
- pa (push a) -> Take the first element at the top of b and put it at the top of a.
- pb (push b) -> Take the first element at the top of a and put it at the top of b.
- ra (rotate a) -> Shift up all elements of stack a by 1. The first becomes the last.
- rb (rotate b) -> Shift up all elements of stack b by 1. The first becomes the last.
- rr (rotate 2) -> Shift up all elements of both stacks by 1. The first becomes the last.
- rra (reverse rotate a) -> Shift down all elements of stack a by 1. The last becomes the first.
- rrb (reverse rotate b) -> Shift down all elements of stack b by 1. The last becomes the first.
- rrr (reverse rotate 2) -> Shift down all elements of both stacks by 1. The last becomes the first.

Allowed external functions:
- read, write, malloc, free, exit
