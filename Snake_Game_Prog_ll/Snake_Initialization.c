#include "Snake_Initalization.h"

SNAKEBODY createBody(int x, int y) {
	SNAKEBODY S;
	S.x = x;
	S.y = y;
	return S;
}

void addNode(PSNAKENODE* list, SNAKEBODY s) {
	PSNAKENODE newNode = (PSNAKENODE)malloc(sizeof(SNAKENODE));

	if (!newNode) {
		fprintf(stderr, "Error creating snake node");
		exit(EXIT_FAILURE);
	}

	else {
		newNode->data = copyBody(s);
		newNode->next = *list;
		*list = newNode;
	}
}

SNAKEBODY copyBody(SNAKEBODY s) {
	return createBody(s.x, s.y);
}

PSNAKENODE initialSize(int startX, int startY, int length) { // startX and Y will be passed based on the given size of the snake area, however, length with be hard coded
	PSNAKENODE head = NULL;

	for (int i = 0; i < length; i++) { 
		SNAKEBODY body = createBody(startX - i, startY); // creates body parts down vertically (for a given length)
		addNode(&head, body);
	}

	return head;
}

void freeSnake(PSNAKENODE head) {
	PSNAKENODE temp;

	while (head != NULL) {    // until all nodes are gone
		temp = head;	     // temp is head
		head = head->next;  // move head to the next node
		free(temp);        // free temp
	}
}