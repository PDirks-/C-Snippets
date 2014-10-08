/*
 *  Simple demo of stack concepts in C
 *
 *	Create new sentence Struct as building block of stack: user enters phrase;
 *	to do:
 *		- program sometimes bugs out when only numbers are given for sentence input
 *		- prompt for input sometimes repeats itself when input with spaces is given
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word{		// create sentence 
	char word[20];
	struct word * next;
} Sentence;

Sentence *link(Sentence *Main, char word[]);
Sentence *undo(Sentence *Main, Sentence **Redo);
Sentence *redo(Sentence *Redo, Sentence **Main);
Sentence *create_Sentence(char word[]);
void printSentence(Sentence *Main);
void clean_up(Sentence *Main, Sentence *Redo);
void freeList(Sentence *nodes);

int main( void ){
	int choice = -1;
	char input[20];
	Sentence *head = NULL;		//MAIN list
	Sentence *Redo = NULL;		//stack
	do{
		printf("What would you like to do? 1 push, 2 undo, 3 redo, 4 print, 5 exit\n");
		printf("choice: ");
		scanf("%d", &choice);
		printf("input: ");
		switch(choice){
			case 1:
				scanf("%s", input);
				head = link(head, input);
				break;
			case 2:
				if(head != NULL)
					head = undo(head, &Redo);
				break;
			case 3:
				if(Redo != NULL)
					Redo = redo(Redo, &head);
				break;
			case 4:
				if(head != NULL)
					printSentence(head);
				break;
			case 5:
				printf("Exiting now...\n");
				choice = 0;
				break;
			default:
				choice = 0;
				break;
		}// end switch
	} while(choice != 0);
	
	clean_up(head, Redo);
	return 0;
}

// append word into main sentence struct chain
// input: head of sentence chain, word to append (array of chars)
// output: head of sentence chain
Sentence *link(Sentence *Main, char word[]){
	Sentence *new = create_Sentence(word);//assign inputted word to new sentence struct
	Sentence *current;
	if( Main == NULL)		// if first node, return first node has head of list
		return new;
	else{					// else, it is not the first node, need to run down list; then append phrase to chain
		current = Main;
		while(current->next != NULL)
			current = current->next;//move down node untill NULL
		current->next = new;//last node assigned to new
	}
	return Main;//return starting position
}

// undo- revert most recent addition
// input: head pointer of main sentence struct, redo pointer to hold broken off word
// output: returns head pointer of main sentence struct
Sentence *undo(Sentence *Main, Sentence **Redo){
	Sentence *temp = Main;
	Sentence *temp2 = Main;
	while(temp->next != NULL){		// use temp to find full last node
		temp = temp->next;
	}
	if(Main == temp){				// in case only 1 node in list
		*Redo = link(*Redo, temp->word);
		free(temp);
		return NULL;
	}
	while(temp2->next != temp){		// use temp2 to find second to last node
		temp2 = temp2->next;
	}
	*Redo = link(*Redo, temp->word);	// address redo pointer to last word in chain
	temp2->next = NULL;					// break off last word
	free(temp);							// free temp pointer
	return Main;
}

// redo- reverse the affects of the redo
// input: pointer leading to head of phrase
// output: pointer leading to head of phrase
Sentence *redo(Sentence *Redo, Sentence **Main){
	Sentence *temp = Redo;
	Sentence *temp2 = Redo;
	while(temp->next != NULL){//find full last node
		temp = temp->next;
	}
	if(Redo == temp){//if only 1 node in list
		*Main = link(*Main, temp->word);
		free(temp);
		return NULL;
	}
	while(temp2->next != temp){//find second to last node
		temp2 = temp2->next;
	}
	*Main = link(*Main, temp->word);
	temp2->next = NULL;
	free(temp);
	return Redo;
}

// creates sentence
// input: phrase to put into sentence struct
// output: pointer to sentence struct
Sentence *create_Sentence(char word[]){
	Sentence *temp = malloc(sizeof(Sentence));
	strcpy(temp->word,word);//
	temp->next = NULL;
	return temp;
}

// print working sentence
// input: lead pointer of sentence struct
void printSentence(Sentence *Main){
	Sentence * temp= Main ;
	while(temp != NULL ){
		printf("%s ", temp->word);//use arrows when the name is a pointer
		temp = temp->next;
	}
	printf("\n");
}
void clean_up(Sentence *Main, Sentence *Redo){
	freeList(Main);
	freeList(Redo);
}

// free all memory related to sentence
void freeList(Sentence *nodes){
	Sentence *temp = nodes;
	if(nodes != NULL){
		temp = nodes->next;
		free(nodes);//free current head
		freeList(temp);//recursive to next node
		}
}
