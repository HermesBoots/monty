# C - Stacks, Queues / LIFO, FIFO

This is "Monty", a minimal, stack-based programming language. With very few operations, the language is capable of virtually any output in the same manner as other minimal languages like Brainfuck (the "bf" folder contains some code in that language as an exercise).

## A Note about Sequencing

When working with multiple values off of a stack in C, it becomes important to consider the order of evaluation in a line of code. Multiple operations in Monty involve removing the top two values from a stack, performing some mathematical operation on them, then putting the result back onto the stack. When the order of these operands matter (when using subtraction and division), extra code must be written.

It might seem like Monty's subtraction operation could be written simply as `stack_push(stack_pop() - stack_pop())`, but this isn't the case. Although both of the pop functions are guaranteed to execute before the push function, the pop functions aren't guaranteed to execute in any particular order. Therefore, there's no way to know whether the value on the top of the stack will be on the left side of the subtraction or the right.
