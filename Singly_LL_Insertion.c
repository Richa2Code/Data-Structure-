// All the operatio for the singly linked list

// Insertion at the beginning
#include <stdio.h>
#include <stdliB.h>
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

  new2 = (struct node *)malloc(sizeof(struct node));

  if (head == NULL)
  {
    insert_beginning();
  }

  struct node *ptr2 = head;
  while (ptr2->next != NULL)
  {
    ptr2 = ptr2->next;
  }

  printf("\nEnter the data : ");
  scanf("%d", &new2->data);

  ptr2->next = new2;
  new2->next = NULL;
}

void before_node()
{
  struct node *new3;

  new3 = (struct node *)malloc(sizeof(struct node));

  struct node *prev = NULL;
  struct node *ptr3 = head;

  int item;
  printf("\nEnter data value before which you want to perform insertion : ");
  scanf("%d", &item);

  int value;
  printf("Enter value to insert : ");
  scanf("%d", &new3->data);

  while (ptr3->data != item)
  {
    prev = ptr3;
    ptr3 = ptr3->next;
  }

  new3->next = ptr3;
  prev->next = new3;
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
    printf("\n");
  }
}

int main()
{
  insert_beginning(); // 1
  insert_beginning(); // 2
  insert_beginning(); // 3
  insert_beginning(); // 4
  insert_end();       // 5

  before_node();

  Display();
  return 0;
}
