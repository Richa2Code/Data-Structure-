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

// Insertion at the beginning
void insert_beginning()
{
  printf("Insertion at the beginning strted\n ");
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
  printf("\nInsertion at the end started.");
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
  printf("\nInsertion before the given node started");
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

// Insertion after a given node
void after_node()
{
  printf("\nInsertion after the given node stated from here !");
  struct node *new4;
  struct node *ptr4 = head;
  struct node *temp;

  int item2;

  if (head == NULL)
  {
    printf("List is empty !");
    return;
  }

  new4 = (struct node *)malloc(sizeof(struct node));

  printf("\n Enter the data value after ehich you want insertion : ");
  scanf("%d", &item2);

  printf("\nEnter the data : ");
  scanf("%d", &new4->data);

  while (ptr4->data != item2)
  {
    ptr4 = ptr4->next;
  }

  if (ptr4 == NULL)
  {
    printf("Given node %d is not exist in list.", item2);
  }
  else
  {
    temp = ptr4->next;
    ptr4->next = new4;
    new4->next = temp;
  }
}

// Deletion at the beginning
void del_begin()
{
  struct node *ptr5 = head;
  if (head == NULL)
  {
    printf("List is empty. Nothing to delete.");
    return;
  }
  else
  {
    printf("\nDeletion done at the beginning.\nDeleted data : %d", head->data);
    ptr5 = head->next;
    free(head);
    head = ptr5;
  }
}

// Deletion at the end
void del_end()
{
  printf("\nDeletion done at the end.");
  struct node *ptr5 = head;
  struct node *prev2;

  if (head == NULL)
  {
    printf("\nList is empty!\nNothing to delete.\n");
    return;
  }

  while (ptr5->next != NULL)
  {
    prev2 = ptr5;
    ptr5 = ptr5->next;
  }
  printf("\nDeleted item : %d", ptr5);
  prev2->next = NULL;
  free(ptr5);
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

  after_node();
  before_node();
  del_begin();
  del_end();
  Display();
  return 0;
}
