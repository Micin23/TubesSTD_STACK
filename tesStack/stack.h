#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<iostream>

using namespace std;

#define Top(S) ((S).Top)
#define info(S) ((S).info)

typedef string infotype;
const int nMax = 10;

struct Stack{
    infotype info[nMax];
    int Top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void show(Stack S);
bool isOperand(char c);
infotype postfixToInfix(infotype postfix, Stack &S);
bool Validasi(string Teks);

#endif // STACK&QUEUE_H_INCLUDED*/
