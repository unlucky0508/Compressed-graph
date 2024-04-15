#include "stack.h"
// Creates functions in order to use the stack structure

stack CreateStack()
{
	stack p;
	p.top = -1;
	return p;
}

int isEmptyStack(stack p)
{
	return (p.top == -1);
}

int isFullStack(stack p)
{
	return (p.top == N-1);
}

int Push(stack *p, element e)
{
	if (isFullStack(*p)) return 0;
	p->data[++p->top] = e;
	return 1;
}

int Pop(stack *p)
{
	if (isEmptyStack(*p)) return 0;
	p->top--;
	return 1;
}

int Top(stack p, element *e)
{
	if (isEmptyStack(p)) return 0;
	*e = p.data[p.top];
	return 1;
}