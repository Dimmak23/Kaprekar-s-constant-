# Kaprekar-s-constant

The number 6174 is known as Kaprekar's constant. It is the ultimate
convergence point of the Kaprekar's routine, an algorithm thought
up by Indian mathematician D.R. Kaprekar in 1949. 

The routine is as follows: 

1. Take any four-digit number (at least two different digits must
be used, zeroes allowed). 
2. Arrange the digits in descending and then in ascending order
to get two four-digit numbers. 
3. Subtract the smaller number from the larger and get the result. 
4. Repeat steps 2-4 with the new number. 

After a few iterations, the algorithm converges to a fixed point
and starts to result in the same number  - 6174 - the so-called
Kaprekar's constant. 

For Example: 
n = 5324 

5432 - 2345 = 3087 
8730 - 0378 = 8352 
8532 - 2358 = 6174 
7641 - 1467 = 6174 

Challenge - level: Hard 

Write a code that universally finds Kaprekar's constants and/or loop
for any K-digit number. If a sequence is found, all the numbers
comprising it have to be returned. 

So, this program work under integer rates, for now.

When you will try to compile this program with GNU gcc
compiler on the PC from comand line you should also enter code:
"-std=c++11"

Text me if find any bugs.

Good luck!
