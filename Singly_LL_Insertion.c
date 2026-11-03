// All the operatio for the singly linked list

// Insertion at the beginning
#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *head = NULL;

void insert_beginning()
{
  struct node *new1;

  new1 = (struct node *)malloc(sizeof(struct node));

  if (new1 == NULL)
  {
    printf("Memory Overflow !");
    return;
  }

  printf("\nEnter the data : ");
  scanf("%d", &new1->data);

  new1->next = head;
  head = new1;
}

// inserting node at the end
void insert_end()
{
  struct node *new2;

  if (head == NULL)
  {
    insert_beginning();
    return;
  }

  new2 = (struct node *)malloc(sizeof(struct node));

  if (new2 == NULL)
  {
    printf("Memory Overflow!");
    return;
  }

  printf("\nEnter the data: ");
  scanf("%d", &new2->data);

  new2->next = NULL;

  struct node *ptr2 = head;

  while (ptr2->next != NULL)
  {
    ptr2 = ptr2->next;
  }

  ptr2->next = new2;
}

void before_node()
{
  struct node *new3;
  struct node *prev = NULL;
  struct node *ptr3 = head;

  int item;

  if (head == NULL)
  {
    printf("List is empty!");
    return;
  }

  new3 = (struct node *)malloc(sizeof(struct node));

  if (new3 == NULL)
  {
    printf("Memory Overflow!");
    return;
  }

  printf("\nEnter data before which insertion is required: ");
  scanf("%d", &item);

  printf("Enter value to insert: ");
  scanf("%d", &new3->data);

  while (ptr3 != NULL && ptr3->data != item)
  {
    prev = ptr3;
    ptr3 = ptr3->next;
  }

  if (ptr3 == NULL)
  {
    printf("Item not found!");
    free(new3);
    return;
  }

  new3->next = ptr3;

  if (prev == NULL)
  {
    head = new3;
  }
  else
  {
    prev->next = new3;
  }
}

// displaying the whole linked list
void Display()
{
  struct node *ptr = head;

  if (head == NULL)
  {
    printf("List is empty !");
    return;
  }

  printf("\nLinked list : ");
  while (ptr != NULL)
  {
    printf("%d, ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

int main()
{
  insert_end();
  insert_end();
  insert_end();
  insert_end();
  insert_end();

  before_node();

  Display();
  return 0;
}
