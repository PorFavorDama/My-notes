#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int x;
	struct n* next;
}node;

void addElement(node* r,int x){
	while(r->next != NULL){
		r = r->next;
	}
		r->next = (node*)malloc(sizeof(node));
		r->next->x=x;
		r->next->next=NULL;
}


void printList(node* r){
	while( r != NULL){
		printf("%d\n",r->x);
		r = r->next;
	}
}

void delete(node** r,int x){
	node* toBeDeleted;
	node* newRoot = *r;
	int endOfList = 0;
	while(endOfList !=1){
		if( (*r)->x == x){ 			//If the element you want to delete is the root of the list...
			toBeDeleted = (*r);		//...we are going to delete it and change the pointer to root with the new one.
			*r = (*r)->next;		//Then you have to check the list again with "continue" to see
			newRoot = *(r);			//...whether the data you want to delete is again in the root of your list or not.
			free(toBeDeleted);		//We also have to update the newRoot to be able to delete other elements if asked.
			continue;
		} 
		if(newRoot->next->x == x){ 					//If the element you want to delete is amongst the other elements...
			toBeDeleted = newRoot->next;			//...this will run to check whether your next element is the one...
			newRoot->next = toBeDeleted->next;		//...you want to delete. If so, the next element of the element...
			free(toBeDeleted);						//...you want to delete will be assigned to the current element's next not to...
			if(newRoot->next == NULL){ 				//...lose the rest of the list. If the newRoot's next element is NULL
				endOfList = 1;		   				//...that means we are at the end of the list so atTheEnd must be assigned 1.
				continue;
			}
			else
				continue;
		}
		
		newRoot = newRoot->next;
		if(newRoot->next == NULL){
			endOfList =1;
		}
	}
}

void addInOrder(node** r,int x){
	node* root = *r;
	if(root == NULL){								//If our root is NULL then we will allocate memory for it...
		root = (node*) malloc(sizeof(node));		//...and then assign x to root->x and Null to root->next.
		root ->next = NULL;						//Then we will have to change the pointer of the root...
		root ->x = x;								
		*r = root;								//...like so.
		//return;
	}
	if( root->x > x){												//If the root's x is greater than the x we want to add...
		node* currentRoot = root;									//... then we will have to prepend it to the root.
		node* toBePrepended =(node*) malloc(sizeof(node));			//Allocating memory for our element to be prepended.
		toBePrepended-> x = x;										
		toBePrepended->next = root;
		(*r) = toBePrepended;										//Changing our pointer's first element to be "toBePrepended"
		return;
	}
	
	node* iter = *r;
	
	while( iter->next != NULL && iter->next->x < x){	//while iter->next is not null and iter->next's x is less than our X... 
		iter = iter-> next;								
	}
	node* temp = (node*) malloc(sizeof(node));			//Allocate memory for our new element.
	temp->next = iter->next;							//Then assign the iter's null to our new element's next item.
	temp->x = x;										//Assign the x value.
	iter->next = temp;									//Now our current element's next should point to our new element...
}														//...which is greater than the 	current element.
		

int main(){
	node* root;
	root = (node*)malloc(sizeof(node));
	root->next = NULL;
	root->x = 13;
	addInOrder(&root,5);
	addInOrder(&root,7);
	addInOrder(&root,6);
	addInOrder(&root,1);
	addInOrder(&root,3);
	addInOrder(&root,21);
	addInOrder(&root,19);
	//addElement(root,13);
	//addElement(root,500);
	//addElement(root,13);
	//addElement(root,500);
	//addElement(root,82);
	//addElement(root,18);
	//addElement(root,13);
	//addElement(root,500);
	
	for(int i = 0; i < 5;i++){
		addInOrder(&root,i*5);
	}
	//addElement(root,13);
	printList(root);
	delete(&root,3);
	printf("\n");
	printList(root);
	return 0;
}
								
		
	