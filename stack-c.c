typedef struct Node{
    struct Node *next;
    int data;
}Node;

Node* createNode(int data){
    Node * temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void push(Node ** top,int data){
    Node * temp = createNode(data);
    temp->next = *top;
    *top = temp;
}

void pop(Node** top){
    if(*top == NULL) return;
    Node * temp = *top;
    *top = (*top)->next;
    free(temp);
}

void Top(Node * top){
    if(top == NULL) {printf("Empty!\n");return;}
    printf("%d",top->data);
}

void isEmpty(Node * top){
    if(top == NULL) printf("Empty Stack\n");
    else printf("NOT EMPTY\n");
} 
