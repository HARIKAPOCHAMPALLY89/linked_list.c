#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node* next;
};

struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
return newNode;
}

void append(struct Node** head_ref, int data) {
struct Node* newNode = createNode(data);
if (*head_ref == NULL) {
*head_ref = newNode;
return;
}
struct Node* last = *head_ref;
while (last->next != NULL)
last = last->next;
last->next = newNode;
}

void prepend(struct Node** head_ref, int data) {
struct Node* newNode = createNode(data);
newNode->next = *head_ref;
*head_ref = newNode;
}

void deleteNode(struct Node** head_ref, int key) {
struct Node* temp = *head_ref;
struct Node* prev = NULL;

if (temp != NULL && temp->data == key) {
*head_ref = temp->next;
free(temp);
return;
}

while (temp != NULL && temp->data != key) {
prev = temp;
temp = temp->next;
}

if (temp == NULL) return;

prev->next = temp->next;
free(temp);
}

int search(struct Node* head, int key) {
struct Node* current = head;
while (current != NULL) {
if (current->data == key)
return 1;
current = current->next;
}
return 0;
}

void display(struct Node* head) {
struct Node* current = head;
while (current != NULL) {
printf("%d -> ", current->data);
current = current->next;
}
printf("NULL\n");
}

int main() {
struct Node* head = NULL;

append(&head, 10);
append(&head, 20);
prepend(&head, 5);
display(head);

deleteNode(&head, 10);
display(head);

printf("Search 20: %s\n", search(head, 20) ? "Found" : "Not Found");
printf("Search 10: %s\n", search(head, 10) ? "Found" : "Not Found");

return 0;
}
