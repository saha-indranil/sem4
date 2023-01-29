% Write a PROLOG program to print the fibonacci series upto n terms, where n is given as input.

fib(0,0).
fib(1,1).
fib(N,F) :-
    N > 1,
    N1 is N - 1,
    N2 is N - 2,
    fib(N1, F1),
    fib(N2, F2),
    F is F1 + F2.

print_fib(N, Max) :-
    N >= 0, N < Max,
    fib(N, F),
    write(F), nl,
    N1 is N + 1,
    print_fib(N1, Max).

/*
OUTPUT

?- print_fib(0,10).
0
1
1
2
3
5
8
13
21
34
false.

*/