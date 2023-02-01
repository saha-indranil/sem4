% Write a prolog program to reverse a list

reverse_list(List, Reversed) :-
    reverse_list(List, [], Reversed).

reverse_list([], Acc, Acc).
reverse_list([H|T], Acc, Reversed) :-
    reverse_list(T, [H|Acc], Reversed).

/*
OUTPUT

?- reverse_list([a,b,c,d],Reversed).
Reversed = [d, c, b, a].

?- reverse_list([1],Reversed).
Reversed = [1].

?- reverse_list([],Reversed).
Reversed = [].

*/