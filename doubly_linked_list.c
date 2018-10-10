#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubly_linked_list.h"

int main(){
	NODE *head=NULL,*tail=NULL,*myString=NULL,*currentPtr=NULL;
	int choice=-1,subchoice=-1,changeCharAt,stringLength;
	char newChar,appendString[50];
	
	// initialize dummy nodes at the head and tail
	head=(NODE*)malloc(sizeof(NODE));
	tail=(NODE*)malloc(sizeof(NODE));
	head->next=NULL;
	head->prev=NULL;
	tail->next=NULL;
	tail->prev=NULL;
	
	// initialize node for storing new strings
	myString=(NODE*)malloc(sizeof(NODE));
	myString->next=NULL;
	myString->prev=NULL;
	
	printf("Current string: ");
	fgets(myString->string,50,stdin);
	// insert node of input string to the middle of the LL
	head->next=myString;
	myString->prev=head;
	myString->next=tail;
	tail->prev=myString;
	// initialize a pointer that always points to the current string
	currentPtr=myString;
	myString=NULL;
	
	do{
		printMenu();
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printSubMenu();
				scanf("%d",&subchoice);
				switch(subchoice){
					case 1:
						createNewNode(&myString);
						printf("Enter new string: ");
						// catch the "Enter" button
						getchar();
						// store new string into a new node
						fgets(myString->string,50,stdin);
						// insert newly created node into the linked list
						insertNode(&head,&tail,&currentPtr,&myString);
						printf("Current string: %s",currentPtr->string);
						break;
					case 2:
						stringLength=strlen(currentPtr->string)-2;
						printf("Enter index (0-%d): ",stringLength);
						scanf("%d",&changeCharAt);
						getchar();
						// check if the input is within the range
						if(changeCharAt<0 || changeCharAt>stringLength){
							printf("Input is out of bounds.\n");
						}
						else{
							createNewNode(&myString);
							// copy the current string into the newly created node
							strcpy(myString->string,currentPtr->string);
							printf("Enter character: ");
							scanf("%c",&newChar);
							// replace the character at the chosen index
							myString->string[changeCharAt]=newChar;
							// insert newly created node into the linked list
							insertNode(&head,&tail,&currentPtr,&myString);
							printf("Current string: %s",currentPtr->string);
						}
						break;
					case 3:
						createNewNode(&myString);
						// copy the current string into the newly created node
						strcpy(myString->string,currentPtr->string);
						// remove any new line character from the existing string
						myString->string[strlen(currentPtr->string)-1]='\0';
						// store the string that the user wishes to append
						printf("Enter string: ");
						getchar();
						fgets(appendString,50,stdin);
						// use strcat string function to append to the existing string
						strcat(myString->string,appendString);
						// insert newly created node into the linked list
						insertNode(&head,&tail,&currentPtr,&myString);
						printf("Current string: %s",currentPtr->string);
						break;
					case 4:
						printf("Returning to main menu . . .\n");
						break;
					default:
						printf("Invalid input.");
						break;
				}
				
				break;
			case 2:
				// check if there is a node before the current string
				if(currentPtr->prev->prev==NULL){
					printf("No actions to undo.\n");
				}
				// move the current pointer to the previous node
				else{
					currentPtr=currentPtr->prev;
					printf("Current string: %s",currentPtr->string);
				}
				break;
			case 3:
				// check if there is a node after the current string
				if(currentPtr->next->next==NULL){
					printf("No actions to redo.\n");
				}
				// move the current pointer to the next node
				else{
					currentPtr=currentPtr->next;
					printf("Current string: %s",currentPtr->string);
				}
				break;
			case 4:
				// delete all nodes in the linked list
				deleteAll(&head,&tail);
				printf("All nodes successfully deleted.\n");
				printf("Thank you for using this program.\n");
				printf("Goodbye!\n");
				break;
			default:
				printf("Invalid input.\n");
				break;
		}
	}while(choice!=4);
	return 0;
}