#define N 20

typedef int element;

typedef struct  {
	element data[N]; 
	int top;
} stack;

stack CreateStack();
int isEmptyStack(stack p);
int isFullStack(stack p);
int Push(stack *p, element e);
int Pop(stack *p);
int Top(stack p, element *e);