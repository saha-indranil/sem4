% Write a prolog program to find minimum and maximum from a list

min_list([X], X).
min_list([H|T], Min) :-
    min_list(T, TailMin),
    Min is min(H, TailMin).

max_list([X], X).
max_list([H|T], Max) :-
    max_list(T, TailMax),
    Max is max(H, TailMax).

min_max(List, Min, Max) :-
    min_list(List, Min),
    max_list(List, Max).

/*
OUTPUT

?- min_max([3,8,2,1,5],Min,Max).
Min = 1,
Max = 8 .

?- min_max([5],Min,Max).
Min = Max, Max = 5 .

?- min_max([],Min,Max).
false.

*/