// All operation on Singly Circular Linked List
/*
  1. Insertion at the beginning
  2. Insertion at end
  3. Insertion before given node
  4. Insertion after given node
  5. Deletion at beginning
  6. Deletion at the end
  7. Deletion at the specific position
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *head = NULL;

// Insertion at the beginning
void insert_begin()
{
  printf("\nInsertion at the beginning started !\n");
  struct node *new1;
  struct node *ptr1 = head;

  new1 = (struct node *)malloc(sizeof(struct node));

  if (head == NULL)
  {
    printf("\nList is Empty.\nLet's make first node.");
    printf("\nEnter the value : ");
    scanf("%d", &new1->data);
    printf("%d", new1->data);
    new1->next = new1;
    head = new1;
    printf("\nFirst node inserted successfully !\n");
    return;
  }

  printf("\nEnter the value : ");
  scanf("%d", &new1->data);
  while (ptr1 != NULL && ptr1->next != head)
  {
    ptr1 = ptr1->next;
  }
  new1->next = ptr1->next;
  head = new1;
  ptr1->next = head;
  printf("%d, ", head->data);
}

// Displaying List nodes
void Display()
{

  printf("\nDisplay process started !\n");
  printf("%d", head->data);
  struct node *ptr = head;

  if (head == NULL)
  {
    printf("Linked list is empty.\n");
    return;
  }

  printf("\nLinked list : ");
  while (ptr != NULL && ptr->next != head)
  {
    printf("%d, ", ptr->data);
    ptr = ptr->next;
  }
  printf("%d", ptr->data);
  printf("\n");
}

int main()
{
  insert_begin();
  insert_begin();
  insert_begin();
  insert_begin();
  insert_begin();
  insert_begin();

  Display();

  return 0;
}