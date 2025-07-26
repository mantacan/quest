#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* create_node(char data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node* build_list() {
    Node* head = create_node('A');
    Node* current = head;
    
    for(char c = 'B'; c <= 'Z'; c++) {
        current->next = create_node(c);
        current = current->next;
    }
    
    return head;
}

Node* get_nth_node(Node* head, int n) {
    Node* current = head;
    for(int i = 1; i < n && current != NULL; i++) {
        current = current->next;
    }
    return current;
}

void free_list(Node* head) {
    Node* current = head;
    while(current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main(void){
    Node* head = build_list();
    Node* tenth = get_nth_node(head, 10);
    
    printf("%c%c", tenth->data, tenth->data);
    
    free_list(head);
    return 0;
}