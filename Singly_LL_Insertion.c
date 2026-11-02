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
    printf("Overflow !");
    return;
  }

  printf("\nEnter the data : ");
  scanf("%d", &new1->data);

  new1->next = head;
  head = new1;
}

// inserting node at the end
insert_end()
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

  Display(); // 4,3,2,1,5
  return 0;
}
