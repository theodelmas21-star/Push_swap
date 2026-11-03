# push_swap

> An algorithmic sorting project at 42 School that sorts data on a stack with a limited set of instructions using the lowest possible number of actions.

## Overview

**push_swap** is a highly efficient algorithmic project designed to sort data with a limited set of instructions, using two stacks (`a` and `b`) and a restricted set of operations. The challenge is to find the most optimized sequence of actions to sort any given stack of integers in ascending order.

## Features

- **Algorithm Optimization**: Implements advanced sorting strategies to minimize operation counts.
- **Error Handling**: Validates input arguments, catching non-integer values, integers out of bounds, and duplicates.
- **Stack Operations**: Full implementation of swap, push, rotate, and reverse-rotate operations.

## Compilation & Usage

### Compilation

Compile the project using the provided `Makefile`:

```bash
git clone git@github.com:your-username/push_swap.git
cd push_swap
make
```

### Usage

Run the program by passing a list of integers as arguments:

```bash
./push_swap 4 67 3 87 23
```

You can combine it with the checker program to verify that the stack is correctly sorted:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

## Operations Reference

| Operation | Description |
| :--- | :--- |
| `sa` / `sb` / `ss` | Swap the first two elements at the top of stack a / b / both. |
| `pa` / `pb` | Take the first element at the top of b/a and put it at the top of a/b. |
| `ra` / `rb` / `rr` | Shift up all elements of stack a / b / both by 1. |
| `rra` / `rrb` / `rrr` | Shift down all elements of stack a / b / both by 1. |