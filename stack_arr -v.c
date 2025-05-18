int arr[10];
top = -1;

void push(int data){
    arr[++top] = data;
}

void pop(){
    if(top == -1) printf("Empty Stack\n");
    else top--;
}

void Top(){
    if(top == -1) printf("Empty Stack\n");
    else printf("%d\n",arr[top]);
}

bool isEmpty(){
    if(top == -1) return false;
    else return true;
}
