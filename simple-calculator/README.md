# Simple Calculator

A simple calculator program written in C.
It displays a menu and lets the user choose an operation.

## Operations

1. Add
2. Subtract
3. Multiply
4. Divide
0. Quit

## Number type

The calculator uses decimal numbers (`double`) for all operations.
Results are printed with `%g`, so whole numbers print without a decimal
part (10 + 25 = 35) and fractions print naturally (10 / 4 = 2.5).

## Errors

- A choice not in the menu prints `Invalid choice`.
- Dividing by zero prints `Error: division by zero`.
