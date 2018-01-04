
/* 
File name is linked_list.c
 Purpose: file contains functions for manipulating singly linked list
 
 Created By
 Doron Nussbaum 2016
 
 Modifications:
 November 2017 - minor modifications
 
 
 Copyright 2017
 
 */

/******************************************************************/
// INCLUDE 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list.h"




/************************************************************************/
// Define 



/************************************************************************/

/*
Purpose: insert a new node into the list as the first element
input
id - id of person
firstName - first name of person
familyName - family name of person

input/output
head - head of linked list

return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/

PersonalInfo *insertToList(PersonalInfo **head, unsigned int id, 
        char *firstName, char *familyName)
{
	PersonalInfo *p = malloc(sizeof(PersonalInfo));
   	if (p!=NULL){
        	strcpy(p->firstName,firstName);
        	strcpy(p->familyName,familyName);
       		p->id = id;
       	 	p->next = *head;
        	*head=p;
    	}
    	return p;    
}


/************************************************************************/
/*
Purpose: insert a new node into the list after the given node  

Input
node - the node after which the new node must be added to the list
id - id of person
firstName - first name of person
familyName - family name of person


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/


PersonalInfo *insertAfter(PersonalInfo *node, unsigned int id, char *firstName, char *familyName)
{
	PersonalInfo *newStruct = malloc(sizeof(PersonalInfo));
		if (node==NULL){
			return NULL;
		}
    	if (newStruct!=NULL){
        	strcpy(newStruct->firstName,firstName);
        	strcpy(newStruct->familyName,familyName);
        	newStruct->id = id;
		newStruct->next = node->next;    		
		node->next = newStruct;
	}
	return newStruct;


}

/************************************************************************/
/*
Purpose: create a new node and insert it into the end of the list
Input
head - the head of the list
id - id of person
firstName - first name of person
familyName - family name of person


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/


PersonalInfo *insertLast(PersonalInfo **head, unsigned int id, char *firstName, char *familyName)
{
	PersonalInfo *temp = *head;
	if(temp==NULL) {
		return (insertToList(head,id,firstName,familyName));
	}
    
		while (temp->next!=NULL){
			temp = temp->next;
		}
		return (insertAfter(temp,id,firstName,familyName));
}


/************************************************************************/
/*
Purpose: search for the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

return
a pointer to the node that was found.
NULL - if no node was found or list empty

*/


PersonalInfo *searchByName(PersonalInfo *head, char *firstName)
{
	if(head==NULL){
		return NULL;
	}else{
		PersonalInfo *p=NULL;
		int foundNode= 0;
		p=head;
		if(p->id==NULL) return NULL;
		while(foundNode==0){
			if(strcmp(p->firstName,firstName)==0){
				foundNode=1;
				return p;
			}else if(p->next==NULL){
				foundNode=10;
			}else{
				p=p->next;
			}
		}
		return NULL;
	}

}

/************************************************************************/
/*
Purpose: search for the first node with the matching id
Input
head - the head of the list
id - id of person person

return
a pointer to the node that was allocated.  

NULL - if no node was found or list empty 

*/


PersonalInfo *searchById(PersonalInfo *head, unsigned int id)
{
	if (head == NULL){
		return NULL;
	}else{
		PersonalInfo *p = NULL;
		int foundNode = 0;	
		p = head;
		if(p->id == NULL) return NULL;		
		while (foundNode == 0) {			
			if(p->id == id){				
				foundNode = 1;
				return p;
			}else if(p->next == NULL){				
				foundNode = 10;
			}else{				
				p = p->next;
			}
			
		}		
		return NULL;
	}


    
}

/***************************************************************/

/*
Purpose: delete the first node from the list
Input
head - the head of the list

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return

0 if node was deleted
1 if node was not deleted or list is empty

*/


int deleteFromList(PersonalInfo **head, unsigned int *id,
	char *firstName, char *familyName)

{
	PersonalInfo *temp = *head;
	if(temp!=NULL){
		*head = temp->next;
		*id=temp->id;
		strcpy(firstName,temp->firstName);
		strcpy(familyName,temp->familyName);
		free(temp);		
		return(0);	
	}
	return(1);   

}


/***************************************************************/

/*
Purpose: delete the last node from the list
Input
head - the head of the list

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return

0 if node was deleted  
1 if node was not deleted or list is empty 

*/


int deleteLast(PersonalInfo **head, unsigned int *id,
                char *firstName, char *familyName)

{

	PersonalInfo *temp=*head;
	if(temp==NULL){
		return 1;
	}
	if(temp->next==NULL){
		return(deleteFromList(head,id,firstName,familyName));
	}
	while((temp->next)->next!=NULL){
		temp=temp->next;
	}
	return(deleteAfter(temp,id,firstName,familyName));	

}



/************************************************************************/

/*
Purpose: delete the record after the given node 
Input
node - a node in the list

output
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return
0 if node was deleted 
1 if node was not deleted (either input node is NULL or input node was the lastnode in the list)

*/



int deleteAfter(PersonalInfo *node, unsigned int *id,
                char *firstName, char *familyName)

{
	if(node==NULL){
		return 1;
	}
	else if(node->next==NULL){
		return 1;
	}
	else{
		PersonalInfo *p=node->next;
		node->next=p->next;
		*id=p->id;
		strcpy(firstName,p->firstName);
		strcpy(familyName,p->familyName);
		free(p);
		return(0);		
	}

}

/************************************************************************/

/*
Purpose: delete the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return
0  if node was deleted
1 if node was not found (e.g., list is empty, no such node exists)

*/


int deleteNodeByName(PersonalInfo **head, char *firstName,
	char *familyName, unsigned int *id)
{
	if(head==NULL){
		return 0;
	}else{
		if ((*head)->firstName==NULL) return NULL;
		PersonalInfo *p=NULL;
		PersonalInfo *last=NULL;
		int foundLast=0;
		p=*head;

		while(foundLast==0){
			if(p->id==id){
				foundLast=1;
				if(last!=NULL){
					last->next=p->next;
					free(p);
				}else{
					if(p->next==NULL){
						*head=NULL;
						free(p);
					}else{
						*head=p->next;
						free(p);
					}
					
				}
				return 1;
			}else if(p->next==NULL){
				foundLast=1;
			}else{
				last=p;
				p=p->next;
			}
		} 
		return 0;

	}
}	
/************************************************************************/
/*
Purpose: deletes all nodes from the list
input/output
head - the head of the list


*/


void deleteList(PersonalInfo **head)
{
	if (head == NULL){
		return;
	}else{
		if((*head)->firstName == NULL){
			*head = NULL;
			return;
		}

		PersonalInfo *p = NULL;
		PersonalInfo *next = NULL;
		int foundLast = 0;	
		p = *head;
		while (foundLast == 0) {
			if(p->next == NULL){				
				foundLast = 1;
				free(p);
			}else{
				next = p->next;
				free(p);
				p = next;
			}
		}
	}

	*head = NULL;


}



/************************************************************************/
/*
Purpose: prints the fields of a node
input:
node - a pointer to a given node

*/


void printNode(PersonalInfo *node)
{
	printf("%-20s %-20s %7d \n",node->firstName, node->familyName, node->id);

}


/************************************************************************/
/*
Purpose: prints all the records in the list

input
head - the head of the list
*/


void printList(PersonalInfo *head)
{
	if(head == NULL){		
		return;
	}else{
		PersonalInfo *p = NULL;
		int foundNode = 0;		
		p = head;
		while (foundNode == 0) {
			
			printNode(p);
			if(p->next == NULL){				
				foundNode = 1;
			}else{				
				p = p->next;
			}
		}
	} 



}

/************************************************************************/
/*
Purpose: counts the number of nodes in the list
input
head - the head of the list

return 
the number of nodes in the list

*/


int listSize(PersonalInfo *head)
{
	int num = 0;
	
	// add code 
	if(head == NULL || head->firstName == NULL){
		return 0;
	}else{
		PersonalInfo *p = NULL;
		int foundNode = 0;		
		p = head;
		while (foundNode == 0) {
			num++;
			if(p->next == NULL){				
				foundNode = 1;
			}else{				
				p = p->next;
			}
		}

		return num;
	}



}

/************************************************************************/
/*
Purpose: counts the number of nodes in the list with a matching firstName
input
head - the head of the list

return 
the number of nodes in the list that match the firstName


*/


int countRecords(PersonalInfo *head, char *firstName)
{
	int num = 0;
	
	
	if(head == NULL || head->firstName == NULL){
		return 0;
	}else{
		PersonalInfo *p = NULL;
		int foundNode = 0;		
		p = head;
		while (foundNode == 0) {
			if(strcmp(p->firstName,firstName) == 0) num++;
			if(p->next == NULL){				
				foundNode = 1;
			}else{				
				p = p->next;
			}
		}

		return num;
	}


}




/************************************************************************/
/*

Purpose: removes all duplicates records from the list.  Duplicate records are determined by their first name. 
You can assume that the listed is sorted by first name.

input
head - the head of the  list



*/




void removeDuplicates(PersonalInfo *head)
{

	if(head==NULL){
		return;
	}
	while(head->next!=NULL){
		if(strcmp(head->firstName,head->next->firstName)==0){
			deleteAfter(head, &head->id,head->firstName, head->familyName);
		}
		else{
			head=head->next;
		}
	}
}
	













