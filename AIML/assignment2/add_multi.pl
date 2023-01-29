% Write a PROLOG program for addition and multiplication of two numbers.

add(A, B, C) :- C is A + B.
multiply(A, B, C) :- C is A * B.

/*

OUTPUT
?- add(10,15,X).
X = 25.

?- multiply(10,15,X).
X = 150

*/