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
  struct node *ptr2 = head;

  new2 = (struct node *)malloc(sizeof(struct node));

  if (head == NULL)
  {
    printf("List is empty.\n");
  }

  printf("Enter the data : ");
  scanf("%d", &new2->data);

  while (ptr2->next != NULL)
  {
    ptr2 = ptr2->next;
  }

  ptr2->next = new2;
  new2->prev = ptr2;
  new2->next = NULL;
}

// Insertion before given node
void insert_before()
{
  printf("Insertion before the given node started \n");
  struct node *new3;
  struct node *ptr3 = head;

  int item1;

  new3 = (struct node *)malloc(sizeof(struct node));

  if (head == NULL)
  {
    printf("List is empty.Lets make first node.\n");
    insert_begin();
    return;
  }
  else
  {
    printf("Enter node data before which you want insertion : ");
    scanf("%d", &item1);

    printf("Enter the data : ");
    scanf("%d", &new3->data);

    while (ptr3->data != item1)
    {
      ptr3 = ptr3->next;
    }
    if (ptr3 == NULL)
    {
      printf("Desired node data %d is not present in linked list.", item1);
      return;
    }
    new3->prev = ptr3->prev;
    ptr3->prev->next = new3;
    new3->next = ptr3;
    ptr3->prev = new3;
  }
}

// Insertion after given node
void insert_after()
{
  printf("Insertion after given node started.\n");
  struct node *new4;
  int item2;
  struct node *ptr4 = head;
  new4 = (struct node *)malloc(sizeof(struct node));

  if (head == NULL)
  {
    insert_begin();
    return;
  }

  printf("Enter the data value after which you want insertion : ");
  scanf("%d", &item2);

  printf("Enter the data : ");
  scanf("%d", &new4->data);

  while (ptr4->data != item2)
  {
    ptr4 = ptr4->next;
  }

  if (ptr4 == NULL)
  {
    printf("node data %d is not present in list.", item2);
    return;
  }

  new4->next = ptr4->next;
  ptr4->next->prev = new4;
  ptr4->next = new4;
  new4->prev = ptr4;
}

// Deletion from beginning
void del_begin()
{
  printf("Deletion at the beginning started.\n");
  struct node *ptr5 = head;

  if (head == NULL)
  {
    printf("List is empty.");
    return;
  }

  ptr5->next->prev = NULL;
  head = head->next;
  free(ptr5);
}

// Deletion of end
void del_end()
{
  printf("\nDeletion at the end started \n");
  struct node *ptr6 = head;

  if (head == NULL)
  {
    printf("List is empty.");
    return;
  }

  while (ptr6->next != NULL)
  {
    ptr6 = ptr6->next;
  }

  ptr6->prev->next = NULL;
  free(ptr6);
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
  while (ptr->next != NULL)
  {
    printf("%d, ", ptr->data);
    ptr = ptr->next;
  }
  printf("%d", ptr->data);
  printf("\n");
}

// Forward Traversal
void forw_tra()
{
  struct node *ptrf = head;

  if (head == NULL)
  {
    printf("List is empty!");
    return;
  }

  printf("\nForward Direction Traversal : \n");
  while (ptrf != NULL)
  {
    printf("%d, ", ptrf->data);
    ptrf = ptrf->next;
  }
  printf("\n");
}

// Backward Traversal
void backw_tra()
{

  struct node *ptrb = head;

  if (head == NULL)
  {
    printf("List is empty!");
    return;
  }

  printf("\nBackward Direct ion Traversal : \n");
  while (ptrb->next != NULL)
  {
    ptrb = ptrb->next;
  }

  while (ptrb != NULL)
  {
    printf("%d, ", ptrb->data);
    ptrb = ptrb->prev;
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
  insert_end();
  Display();

  forw_tra();
  backw_tra();
  insert_before();
  Display();

  insert_after();
  Display();

  del_begin();
  Display();

  del_end();
  Display();

  return 0;
}