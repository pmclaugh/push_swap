# push_swap
42 project about sorting a stack. you have auxiliary stack and a limited instruction set.

 The threshold to pass is sorting 500 elements in 5300 operations, most students achieve 4900-5100, none below 4700. 
 Mine uses a novel method and sorts in 3800-3850.

A quick rundown of the problem:
Performance is measured by how many instructions you use. You are free to do any extra computation between instructions.
At the start, you are presented with an unsorted stack of integers, which are guaranteed unique. This is Stack A.
You also have an empty stack, Stack B.
Your instructions are:

-Top of A becomes top of B ("Push")

-Bottom of A to top of A ("Rotate")

-Top of A to bottom of A ("Reverse Rotate")

-Top and 2nd from top of A swapped ("Swap")

and the equivalents for B->A

There are also double-operations, ie if you want to rotate both stacks in the same direction, that can be one operation.

 The solution is a little... intricate. I'm working on making some sort of animation. 
 You can run "make demo" and then "./demo inputs/64" for a colorful demo to accompany this basic explanation:
 
 Let's define an operator, split(S), where S is an ordered set that defines the stack. For now we will consider sets whose size are powers of 2.
 
 I can define 4 sets A, B, C, D that equally partition S. As long as they are the same size (each 1/4 of S), I can move the stack from A to B in 2 * |S| operations such that stack B is now A followed by B followed by C followed by D. This is accomplished as follows:
 
 If the top of A is in set A or D, rotate past it (1 operation).
 
 If it's in B, push it to the top of stack B. (1)
 
 if it's in C, push it to B and rotate it under. (2)

This will take 5/4 * |S| operations, and will result in stack A just containing A and D mixed, and stack B contains B entirely separate from C.

Then repeat the process, pushing elements of A to the top in 1 operation and elements of D to the bottom in 2. This will take 3/4 * |S| operations, for a total of 2 * |S| operations. This also results in the instruction stream containing a lot of "Rotate B" followed by "Rotate A", which can be condensed to a single operation. In practice this means it takes 1.875 * |S| operations.

It is possible to design an ordering of a stack and an accompanying set of definitions of A, B, C, D such that this operation will result in a sorted list. It is then possible to design backwards, resulting in log4(|s|) transformations that take ANY list of |s| elements and sort them in 2 * |s|log4(|s|) operations. This gets us to less than 4500 operations for 500 elements.

Further optimizations using optimized patterns allow us to save steps on the final transform, pushing down to ~3820.


If this description is a bit confounding, come back soon and there will be an animation or video!
