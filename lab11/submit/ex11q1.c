#include "ex11q1.h"
//https://www.w3schools.com/c/c_structs.php

// ############################################################################
// Vector
// ############################################################################
//define the vec_create function from the header file
Vec* vec_create(void) {
    Vec* new_vector = malloc(sizeof(Vec));
   
    new_vector->length = 0;
    new_vector->capacity = 5;
    new_vector->storage = malloc(sizeof(int) * new_vector->capacity);
   
    return new_vector;
}

void vec_insert_at(Vec* vec, int at, int item){
   
    if(vec->length == vec->capacity){ //if the vector is full, reallocate space
        vec->capacity += 1;
        vec->storage = realloc(vec->storage, sizeof(int) * vec->capacity);
    }
    //shifting elements to the right after the index to be inserted
    for(int i = vec->length; i > at; i--){
        vec->storage[i] = vec->storage[i-1];
    }
    vec->storage[at] = item;
    vec->length++;
}

void vec_print(Vec* vec){
    printf("[");
    for(int i = 0; i < vec->length; i++){
        printf("%d", vec->storage[i]);
        if(i != vec->length - 1){
            printf(", ");
        }
    }

    printf("]\n");
}

void vec_free(Vec* vec){
    free(vec->storage);
    free(vec);
}

// ############################################################################
// Linked List
// ############################################################################

LinkedListNode* list_node_create(int item){
    LinkedListNode* new_node = malloc(sizeof(LinkedListNode));
   
    new_node->item = item;
    new_node->next = NULL; //set the next node to NULL
    return new_node;
}
LinkedList* list_create(void){
    LinkedList* new_list = malloc(sizeof(LinkedList));
   
    new_list->length = 0;
    new_list->start = NULL; //empty list
    return new_list;
}
void list_insert_at(LinkedList* list, int at, int item){
   
    LinkedListNode* new_node = list_node_create(item);
    if(at == 0){ //if inserting at the start of the list
        new_node->next = list->start;
        list->start = new_node;
    }else{
        LinkedListNode* current = list->start;
        int i =0;
        while(i < at - 1){ //traverse current to the point of insertion of the new node
            current = current->next;
            i++;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    list->length += 1;
}
void list_print(LinkedList* list){
    printf("[");
    LinkedListNode* current = list->start;
    while(current != NULL){
        printf("%d", current->item);
        if(current->next != NULL){
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");
}
void list_free(LinkedList* list){
    LinkedListNode* node = list->start;
    while(node != NULL){
        LinkedListNode* temp = node->next;
        free(node);
        node = temp;
    }
    free(list);
}

// ############################################################################
// Doubly Linked List
// ############################################################################
DoublyLinkedListNode* dlist_node_create(int item){
    DoublyLinkedListNode* new_node = malloc(sizeof(DoublyLinkedListNode));
    
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->item = item;
    return new_node;
}

DoublyLinkedList* dlist_create(void){
    DoublyLinkedList* new_list = malloc(sizeof(DoublyLinkedList));
   
    new_list->length = 0;
    new_list->end = NULL;
    new_list->start = NULL;
    return new_list;
}
void dlist_insert_at(DoublyLinkedList* l, int at, int item){
   
    DoublyLinkedListNode* newNode = dlist_node_create(item);

    if (l->length == 0) {
        l->end = newNode;
        l->start = newNode;
    }
    else if (at == 0) {
        newNode->next = l->start;
        l->start->prev = newNode;
        l->start = newNode;
    } 
    else if (at == l->length) {
        newNode->prev = l->end;
        l->end->next = newNode;
        l->end = newNode;
    } 
    else if (at <= l->length / 2) {
        // If insertion index is closer to the start, iterate from the start
        DoublyLinkedListNode* current = l->start;
        int i = 0;
        while(i < at) {
            current = current->next;
            i++;
        }

        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
    } 
    else {
        // If the insertion index is closer to the end, iterate from the end
        DoublyLinkedListNode* current = l->end;
        int i = l->length - 1;
        while (i > at) {
            current = current->prev;
            i--;
        }

        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }

    l->length += 1;
}
void dlist_print(DoublyLinkedList* l){
    printf("[");
    DoublyLinkedListNode* current = l->start;
    while(current != NULL){
        printf("%d", current->item);
        if(current->next != NULL){
            printf(", ");
        }
        current = current->next;
    }
    printf("]\n");
}
void dlist_free(DoublyLinkedList* l){
    DoublyLinkedListNode* node = l->start;
    while(node != NULL){
        DoublyLinkedListNode* temp = node->next; //to keep track of the next node before freeing the current one
        free(node);
        node = temp;
    }
    free(l);
}


// ############################################################################
// Main
// ############################################################################
int main(void) {
    char line[1000];
 
    // Uncomment each for loop as you implement that part

    clock_t begin_vec = clock();
    Vec* v = vec_create();

    for (int i = 0; i < 100000; i++) {
       int a, b;
       if (getchar() == 'i') {
           scanf("%s %d %s %d\n", line, &a, line, &b);
           vec_insert_at(v, b, a);
       } else {
           scanf("%s\n", line);
           vec_print(v);
       }
    }

    vec_free(v);
    clock_t end_vec = clock();

    clock_t begin_list = clock();
    LinkedList* l = list_create();

    for (int i = 0; i < 100000; i++) {
       int a, b;
       if (getchar() == 'i') {
           scanf("%s %d %s %d\n", line, &a, line, &b);
           list_insert_at(l, b, a);
       } else {
           scanf("%s\n", line);
           list_print(l);
       }
    }

    list_free(l);
    clock_t end_list = clock();

    clock_t begin_dlist = clock();
    DoublyLinkedList* dlist = dlist_create();

    for (int i = 0; i < 100000; i++) {
       int a, b;
       if (getchar() == 'i') {
           scanf("%s %d %s %d\n", line, &a, line, &b);
           dlist_insert_at(dlist, b, a);
       } else {
           scanf("%s\n", line);
           dlist_print(dlist);
       }
    }

    dlist_free(dlist);
    clock_t end_dlist = clock();

    fprintf(stderr, "Vector: %gs\n", (double)(end_vec - begin_vec) / CLOCKS_PER_SEC);
    fprintf(stderr, "Linked List: %gs\n", (double)(end_list - begin_list) / CLOCKS_PER_SEC);
    fprintf(stderr, "Doubly Linked List: %gs\n", (double)(end_dlist - begin_dlist) / CLOCKS_PER_SEC);
}
