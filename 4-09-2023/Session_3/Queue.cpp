#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
	int a[10];
	//int* a;
	int front, back, total_size, current_size;
} queue;

void Intialise(queue* q) {
	//(*q).front = -1;
	// q->a = (int*)calloc(10, sizeof(int));
	q->front = q->back = -1;
	q->total_size = 10;
	q->current_size = 0;
}

void push(queue* q, int data) {
	if (q->total_size == q->current_size) {
		return;
	}
	if (q->current_size == 0) {
		q->front = 0;
	}
	q->back = (q->back + 1) % q->total_size;
	q->a[q->back] = data;
	q->current_size++;
}

void pop(queue*q) {
	if (q->current_size == 0) {
		return;
	}
	if (q->current_size == 1) {
		q->front = q->back = -1;
	} else {
		q->front = (q->front + 1) % q->total_size;
	}
	q->current_size--;
}

int size(queue* q) {
	return q->current_size;
}

int front(queue* q) {
	if (q->current_size == 0) {
		return -1;
	} else {
		return q->a[q->front];
	}
}

bool empty(queue* q) {
	if (q->current_size == 0) {
		return true;
	} else {
		return false;
	}
}


int main() {
	int n;
	scanf("%d", &n);
	queue q;
	Intialise(&q);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		push(&q, x);
	}

	while (!empty(&q)) {
		printf("%d ", front(&q));
		pop(&q);
	}

}





