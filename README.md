# C - Stacks, Queues / LIFO, FIFO

This is "Monty", a minimal, stack-based programming language. With very few operations, the language is capable of virtually any output in the same manner as other minimal languages like Brainfuck (the "bf" folder contains some code in that language as an exercise).

## Searching for Commands

![Diagram of a trie](https://i.imgur.com/wQZ5RGf.png)

The Monty language has only a small number of operations, but it still uses a very efficient algorithm to search through them to match with ones found in scripts. Each valid operation is stored in a trie, which is structured like a tree where each branch has up to 26 sub-branches, one for each letter in the alphabet. Compared to searching through a list, searching through a trie is faster because each letter of the operation in the script only needs to be compared to one letter in all the valid operation names put together, rather than comparing it to each entire name among all valid names in order. Since the list of valid operations doesn't change after the program starts, the entire trie can be constructed at compile-time.

## A Note about Sequencing

When working with multiple values off of a stack in C, it becomes important to consider the order of evaluation in a line of code. Multiple operations in Monty involve removing the top two values from a stack, performing some mathematical operation on them, then putting the result back onto the stack. When the order of these operands matter (when using subtraction and division), extra code must be written.

It might seem like Monty's subtraction operation could be written simply as `stack_push(stack_pop() - stack_pop())`, but this isn't the case. Although both of the pop functions are guaranteed to execute before the push function, the pop functions aren't guaranteed to execute in any particular order. Therefore, there's no way to know whether the value on the top of the stack will be on the left side of the subtraction or the right.

## Author

Sam Hermes [GitHub](https://github.com/HermesBoots/) [LinkedIn](https://www.linkedin.com/in/samuel-hermes/) [Twitter](https://twitter.com/SamHermesBoots)
