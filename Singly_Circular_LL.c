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
}

// Insertion at the end
void insert_end()
{
  printf("\nInsertion at the end started.\n");
  struct node *new2;
  struct node *ptr2 = head;
  // struct node *temp;

  new2 = (struct node *)malloc(sizeof(struct node));
  printf("Enter the value : ");
  scanf("%d", &new2->data);

  if (head == NULL)
  {
    printf("List is empty!\nNow, Performing Insertion at the beginning.\n");
    insert_begin();
    return;
  }

  while (ptr2->next != head)
  {
    ptr2 = ptr2->next;
  }
  // temp = ptr2->next;
  ptr2->next = new2;
  new2->next = head;
}

// Insertion before given node
void insert_before()
{
  printf("Insertion before given node started !\n");
  struct node *new3;
  struct node *ptr3 = head;
  struct node *prev1;
  int item1;

  new3 = (struct node *)malloc(sizeof(struct node));

  if (head == NULL)
  {
    printf("\nList is empty.\nLet's make first node.");
    insert_begin();
    return;
  }

  printf("Enter the value before which you want insertion to be happened : ");
  scanf("%d", &item1);

  printf("\nEnter the value : ");
  scanf("%d", &new3->data);

  while (ptr3->data != item1)
  {
    printf("%d", item1);
    prev1 = ptr3;
    ptr3 = ptr3->next;
  }
  if (ptr3 == NULL)
  {
    printf("\nSorry, %d is not present in linked list.", item1);
  }

  new3->next = prev1->next;
  prev1->next = new3;
}

// Insertion after given node
void insert_after()
{
  printf("\nInsertion after the given node started .\n");
  struct node *new4;
  struct node *ptr4 = head;

  int item2;

  new4 = (struct node *)malloc(sizeof(struct node));

  if (head == NULL)
  {
    printf("\nList is empty!\nLets make first node.");
    insert_begin();
    return;
  }

  printf("\nEnter the value after which you want to insertion to be happened : ");
  scanf("%d", &item2);
  printf("\nEnter the value : ");
  scanf("%d", &new4->data);

  while (ptr4->data != item2)
  {
    ptr4 = ptr4->next;
  }

  new4->next = ptr4->next;
  ptr4->next = new4;
}

// Displaying List nodes
void Display()
{

  printf("\nDisplay process started !\n");
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
  printf("%d", ptr->data); // It will print last inserted node.So compulsory require.
  printf("\n");
}

int main()
{
  insert_begin();
  insert_begin();
  insert_begin();
  insert_end();
  insert_end();
  insert_end();

  Display();
  insert_before();
  Display();
  insert_after();
  Display();
  return 0;
}