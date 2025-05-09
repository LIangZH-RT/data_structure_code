#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

typedef struct Node {
	int data;
	struct Node * next;
} Node;

Node * createNode(int data) {
	Node * temp = (Node *) malloc(sizeof(Node))	;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void insertHead(Node ** head,int data) {
	Node * temp = createNode(data);
	temp->next = *head;
	*head = temp;
}

void push_Back(Node ** head, int data) {
	Node * newNode = createNode(data);
	if(*head == NULL) {
		*head = newNode;
		return;
	}
	Node * temp = *head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}

void insert(Node ** head,int data,int pos) {
	Node * newNode = createNode(data);
	if(pos < 1) return;
	if(pos == 1) {
		newNode->next = *head;
		*head = newNode;
		return;
	}
	if(*head == NULL) return;
	Node * temp = *head;
	int i;
	for(i=0; i<pos-2; i++) {
		if(temp->next == NULL) return;
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}

void remove_list(Node **head,int pos){
	if(*head == NULL) return; // 检查空链表
	
	Node * temp1 = *head;
	//判断pos
	if(pos == 1){
		*head = temp1->next;
		free(temp1);
		return;
	}
	int i;
	//找到节点2 
	for(i = 0;i < pos-2;i++){
		temp1 = temp1->next; 
	}
	Node * temp2 = temp1->next; //temp2存储的节点3 节点2的下一节点为节点3的下一节点（节点4）
	//修改链接
	temp1->next = temp2->next;
	//清除释放节点3 
	free(temp2);  
}

// 迭代方式反转链表
void reverse_iterative(Node **head){
	Node *prev, *current, *next;
	prev = NULL;current = *head;
	while(current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

void reverse_recursive(Node **head ,Node * current){
	if(current->next == NULL){
		*head = current;
		return;
	}
	reverse_recursive(head, current->next);
	//反转操作
	Node * temp = current->next;
	temp->next = current;
	current->next = NULL;
}

// 打印链表函数
void printList(Node *head) {
	Node *temp = head;
	printf("链表内容: ");
	while(temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

// 释放整个链表的内存
void freeList(Node **head) {
	Node *current = *head;
	Node *next;
	
	while(current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	
	*head = NULL;
}



int main() {
	system("pause");
	return 0;
}
