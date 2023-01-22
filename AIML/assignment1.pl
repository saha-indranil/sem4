female(pam).
female(liz).
female(pat).
female(ann).
male(jim).
male(bob).
male(tom).
male(peter).
parent(pam,bob).
parent(tom,bob).
parent(tom,liz).
parent(bob,ann).
parent(bob,pat).
parent(pat,jim).
parent(bob,peter).
parent(peter,jim).
mother(X,Y):-parent(X,Y),female(X).
father(X,Y):-parent(X,Y),male(X).
haschild(X):-parent(X,_).
sister(X,Y):-parent(Z,X),parent(Z,Y),female(X),X\==Y.
brother(X,Y):-parent(Z,X),parent(Z,Y),male(X),X\==Y.
grandmother(X,Y):- parent(Z,Y),parent(X,Z),female(X).
uncle(X,Y):- parent(Z,Y),brother(X,Z),Z\==X.

/*
OUTPUT
?- grandmother(X,Y).
X = pam,
Y = ann ;
X = pam,
Y = pat ;
X = pam,
Y = peter ;
false.

?- uncle(X,Y).
X = peter,
Y = jim ;
false.
*/