#include <stdlib.h>

typedef struct Node{
    struct Node *prev;
    struct Node *next;
    int data;
}Node;

Node * createNode(int data){
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->prev = NULL;
    temp->next = NULL;
    temp->data = data;
    return temp;
}


void insertAtHead(Node **head, int data){

    Node * newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void push_Back(Node ** head, int data) {
	Node * newNode = createNode(data);
	Node * temp = *head;
	//添加判断头部情况
	if(*head == NULL) {
		*head = newNode;
		return;
	}
	while(temp->next != NULL){
		temp = temp->next;	
	}
	newNode->prev = temp;
	temp->next = newNode;
}

void insert(Node ** head,int data,int pos){
	Node * newNode = createNode(data);
	if(pos < 1) return;
	if(pos == 1) {
		newNode->next = *head;
		if(*head != NULL) {
			(*head)->prev = newNode;
		}
		*head = newNode;
		return;
	}
	Node * temp = *head;
	for(int i=0; i<pos-2; i++){
	//超出链表判断
		if(temp->next == NULL) return;  
		temp = temp->next;
	}
	newNode->next = temp->next;
	newNode->prev = temp;
	temp->next = newNode;
} 

void remove(Node **head, int pos){
    Node * temp1 = *head;
    if(pos == 1){
        *head = temp1->next;
        if(*head != NULL) { 
            (*head)->prev = NULL; 
        }
        free(temp1);
        return;
    }
    int i;
    for(i = 0;i < pos-2;i++){
        temp1 = temp1->next; 
    }
    Node * temp2 = temp1->next; 
    //这里修改 要删除的节点的下一节点的prev指向 
    //begin
    if(temp2->next != NULL) 
    temp2->next->prev = temp1;
    //end
    temp1->next = temp2->next;
    free(temp2);  
}


int main(){

    return 0;
    
}