// All operations done with Doubly Circular Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *prev;
  int data;
  struct node *next;
};

struct node *head = NULL;

// Insertion at the beginning
void insert_begin()
{
  printf("Insertion at the beginning started !\n");
  struct node *new1;
  new1 = (struct node *)malloc(sizeof(struct node));

  // struct node *ptr1 = head;
  if (head == NULL)
  {
    printf("List is Empty.\nLet's enter the first node.\n");
    printf("Enter the data :");
    scanf("%d", &new1->data);
    new1->prev = new1;
    new1->next = new1;
    head = new1;
    return;
  }
  else
  {
    printf("Enter the data :");
    scanf("%d", &new1->data);

    // main logic
    new1->prev = head->prev;
    head->prev->next = new1;
    head->prev = new1;
    new1->next = head;
    head = new1;
  }
  printf("\n");
}

// Displaying node data
void display()
{
  printf("Display process started !\n");
  struct node *ptr = head;

  if (head == NULL)
  {
    printf("List is Empty.\n");
    return;
  }

  do
  {
    printf("%d, ", ptr->data);
    ptr = ptr->next;
  } while (ptr != head);

  printf("\n");
}

int main()
{

  insert_begin();
  insert_begin();
  insert_begin();
  insert_begin();
  insert_begin();
  display();

  return 0;
}