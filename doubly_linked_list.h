typedef struct node_tag{
	struct node_tag *prev;
	struct node_tag *next;
	char string[50];
} NODE;

void printMenu(){
	printf("==== MENU ====\n");
	printf("[1] Edit String\n");
	printf("[2] Undo\n");
	printf("[3] Redo\n");
	printf("[4] Exit\n");
	printf("=============\n");
	printf("Choice: ");
}

void printSubMenu(){
	printf("[1] Replace string\n");
	printf("[2] Change char at\n");
	printf("[3] Append a string\n");
	printf("[4] Back to main menu\n");
	printf("Choice: ");
}

void createNewNode(NODE **myString){
	// initializing a new node to be inserted into the linked list
	(*myString)=(NODE*)malloc(sizeof(NODE));
	(*myString)->next=NULL;
	(*myString)->prev=NULL;
}

void insertNode(NODE **head,NODE **tail,NODE **currentPtr,NODE **myString){
	// insert newly created node into the linked list
	(*myString)->prev=(*currentPtr);
	(*currentPtr)->next=(*myString);
	(*myString)->next=(*tail);
	(*tail)->prev=(*myString);
	(*currentPtr)=(*currentPtr)->next;
	(*myString)=NULL;
}

void deleteAll(NODE **head,NODE **tail){
	NODE *del=NULL;
	del=(*head);
	// delete all nodes other than the dummy node at the tail
	while(del->next!=NULL){
		(*head)=del->next;
		del->next->prev=NULL;
		del->prev=NULL;
		del->next=NULL;
		free(del);
		del=(*head);
		//printf("Node deleted.\n");
	}
	// delete the remaining dummy node at the tail
	(*tail)->prev=NULL;
	free(*tail);
	del=(*head)=(*tail)=NULL;
}