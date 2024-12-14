# Push_swap

## Overview
The `push_swap` project involves sorting integers using two stacks (`a` and `b`) and a set of operations. The goal is to compute and output the minimal sequence of instructions required to sort the stack `a` in ascending order.

Additionally, the `checker` program validates the correctness of the sorting process by applying a series of instructions and checking if stack `a` is sorted and stack `b` is empty.

## Operations
- `sa`: Swap the top two elements of stack `a`.
- `sb`: Swap the top two elements of stack `b`.
- `ss`: Swap both stack `a` and stack `b`.
- `pa`: Push the top element of stack `b` to stack `a`.
- `pb`: Push the top element of stack `a` to stack `b`.
- `ra`: Rotate stack `a` (move the top element to the bottom).
- `rb`: Rotate stack `b` (move the top element to the bottom).
- `rr`: Rotate both stack `a` and stack `b`.
- `rra`: Reverse rotate stack `a` (move the bottom element to the top).
- `rrb`: Reverse rotate stack `b` (move the bottom element to the top).
- `rrr`: Reverse rotate both stack `a` and stack `b`.

## Video Demonstration
For a visual demonstration of how the `push_swap` program works, you can watch the video below:

![](https://github.com/rh-oussama/push_swap-42/blob/main/demo-pushswap.gif)


## Requirements
- **Push_swap Program**: Sort the integers with the minimum number of operations.
- **Checker Program**: Validate if the instructions sort the stack correctly, outputting `OK` if correct, or `KO` if not.

## Approach
1. Implement an efficient sorting algorithm (Insertion Sort for small inputs, Merge Sort or Radix Sort for larger ones) using the given operations.
2. The `checker` program will execute the operations on the stacks and check if stack `a` is sorted and stack `b` is empty.

## Compilation
To compile the project, run:
```bash
make
