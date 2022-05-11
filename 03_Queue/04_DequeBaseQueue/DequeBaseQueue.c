#include "DequeBaseQueue.h"

void QueueInit(Queue * pq)
{
	DequeInit(pq);
}

int QIsEmpty(Queue * pq)
{
	return DQIsEmpty(pq);
}

void Enqueue(Queue * pq, Data data)
{
	DQAddLast(pq, data);
}

Data Dequeue(Queue * pq)
{
	return DQRemoveFirst(pq);
}

Data QPeek(Queue * pq)
{
	return DQGetFirst(pq);
}

/*
#include <stdio.h>
#include "DequeBaseQueue.h"

int main(void)
{
	Queue q;
	QueueInit(&q);

	Enqueue(&q, 1);  
	Enqueue(&q, 2);
	Enqueue(&q, 3);  
	Enqueue(&q, 4);
	Enqueue(&q, 5);

	while(!QIsEmpty(&q))
		printf("%d ", Dequeue(&q)); 

	return 0;
}
*/