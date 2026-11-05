// All operations done with Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *prev;
  int data;
  struct node *next;
};

struct node *head = NULL;

// Insertion at the Beginning
void insert_begin()
{
  printf("\nInsertion at the beginning started.\n");
  struct node *new1;

  new1 = (struct node *)malloc(sizeof(struct node));

  if (head == NULL)
  {
    printf("List is Empty.\nLet's enter the first node.\n");
    printf("Enter the data :");
    scanf("%d", &new1->data);
    new1->prev = NULL;
    new1->next = NULL;
    head = new1;
  }
  else
  {
    printf("Enter the data :");
    scanf("%d", &new1->data);

    new1->prev = NULL;
    new1->next = head;
    head->prev = new1;
    head = head->prev;
  }
}

// Insertion at the end
void insert_end()
{
  printf("Insertion at te end started!.\n");
  struct node *new2;
  struct node *ptr1 = head;

  new2 = (struct node *)malloc(sizeof(struct node));

  if (head == NULL)
  {
    printf("List is empty.\n");
  }

  printf("Enter the data : ");
  scanf("%d", &new2->data);

  while (ptr1->next != NULL)
  {
    ptr1 = ptr1->next;
  }

  ptr1->next = new2;
  new2->prev = ptr1;
  new2->next = NULL;
}
// Display Process
void Display()
{
  printf("\nDisplaying started.\n");
  struct node *ptr = head;

  if (head == NULL)
  {
    printf("List is empty !");
    return;
  }

  printf("Doubly Linked List : ");
  while (ptr != NULL)
  {
    printf("%d, ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

int main()
{
  insert_begin();
  insert_begin();
  insert_begin();
  insert_begin();
  Display();

  insert_end();
  Display();
  return 0;
}