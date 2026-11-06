// // All operations done with Doubly Circular Linked List

// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//   struct node *prev;
//   int data;
//   struct node *next;
// };

// struct node *head = NULL;

// // Insertion at the beginning
// void insert_begin()
// {
//   printf("Insertion at the beginning started !\n");
//   struct node *new1;
//   new1 = (struct node *)malloc(sizeof(struct node));

//   // struct node *ptr1 = head;
//   if (head == NULL)
//   {
//     printf("List is Empty.\nLet's enter the first node.\n");
//     printf("Enter the data :");
//     scanf("%d", &new1->data);
//     new1->prev = new1;
//     new1->next = new1;
//     head = new1;
//     return;
//   }
//   else
//   {
//     printf("Enter the data :");
//     scanf("%d", &new1->data);

//     // main logic
//     new1->prev = head->prev;
//     head->prev->next = new1;
//     head->prev = new1;
//     new1->next = head;
//     head = new1;
//   }
//   printf("\n");
// }

// // Insertion at the end
// void insert_end()
// {
//   printf("");
// }

// // Displaying node data
// void display()
// {
//   printf("Display process started !\n");
//   struct node *ptr = head;

//   if (head == NULL)
//   {
//     printf("List is Empty.\n");
//     return;
//   }

//   do
//   {
//     printf("%d, ", ptr->data);
//     ptr = ptr->next;
//   } while (ptr != head);

//   printf("\n");
// }

// int main()
// {

//   insert_begin();
//   insert_begin();
//   insert_begin();
//   insert_begin();
//   insert_begin();
//   display();

//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// All operations done with Doubly Circular Linked List

struct node
{
  struct node *prev;
  int data;
  struct node *next;
};

struct node *head = NULL;

// Insertion at Beginning
void insert_begin()
{
  printf("\nInsertion at beginning started.\n");

  struct node *new1;
  new1 = (struct node *)malloc(sizeof(struct node));

  if (new1 == NULL)
  {
    printf("Memory allocation failed.");
    return;
  }

  printf("Enter data : ");
  scanf("%d", &new1->data);

  if (head == NULL)
  {
    new1->prev = new1;
    new1->next = new1;
    head = new1;
  }
  else
  {
    struct node *last = head->prev;

    new1->prev = last;
    new1->next = head;

    last->next = new1;
    head->prev = new1;

    head = new1;
  }
}

// Insertion at End
void insert_end()
{
  printf("\nInsertion at end started.\n");

  struct node *new2;
  new2 = (struct node *)malloc(sizeof(struct node));

  if (new2 == NULL)
  {
    printf("Memory allocation failed.");
    return;
  }

  printf("Enter data : ");
  scanf("%d", &new2->data);

  if (head == NULL)
  {
    new2->prev = new2;
    new2->next = new2;
    head = new2;
  }
  else
  {
    struct node *last = head->prev;

    new2->next = head;
    new2->prev = last;

    last->next = new2;
    head->prev = new2;
  }
}

// Insertion Before Given Node
void insert_before()
{
  printf("\nInsertion before given node started.\n");

  struct node *new3;
  struct node *ptr3 = head;
  int item1;

  if (head == NULL)
  {
    printf("List is empty. Let's make first node.\n");
    insert_begin();
    return;
  }

  printf("Enter node data before which insertion is required : ");
  scanf("%d", &item1);

  while (ptr3->data != item1 && ptr3->next != head)
    ptr3 = ptr3->next;

  if (ptr3->data != item1)
  {
    printf("Desired node data %d is not present.\n", item1);
    return;
  }

  new3 = (struct node *)malloc(sizeof(struct node));

  if (new3 == NULL)
  {
    printf("Memory allocation failed.");
    return;
  }

  printf("Enter data : ");
  scanf("%d", &new3->data);

  new3->next = ptr3;
  new3->prev = ptr3->prev;

  ptr3->prev->next = new3;
  ptr3->prev = new3;

  if (ptr3 == head)
    head = new3;
}

// Insertion After Given Node
void insert_after()
{
  printf("\nInsertion after given node started.\n");

  struct node *new4;
  int item2;
  struct node *ptr4 = head;

  if (head == NULL)
  {
    printf("List is empty. Let's make first node.\n");
    insert_begin();
    return;
  }

  printf("Enter data after which insertion is required : ");
  scanf("%d", &item2);

  while (ptr4->data != item2 && ptr4->next != head)
    ptr4 = ptr4->next;

  if (ptr4->data != item2)
  {
    printf("Node data %d is not present.\n", item2);
    return;
  }

  new4 = (struct node *)malloc(sizeof(struct node));

  if (new4 == NULL)
  {
    printf("Memory allocation failed.");
    return;
  }

  printf("Enter data : ");
  scanf("%d", &new4->data);

  new4->next = ptr4->next;
  new4->prev = ptr4;

  ptr4->next->prev = new4;
  ptr4->next = new4;
}

// Deletion at Beginning
void del_begin()
{
  printf("\nDeletion at beginning started.\n");

  if (head == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  struct node *ptr5 = head;

  if (head->next == head)
  {
    head = NULL;
  }
  else
  {
    struct node *last = head->prev;

    head = head->next;
    head->prev = last;
    last->next = head;
  }

  free(ptr5);
}

// Deletion at End
void del_end()
{
  printf("\nDeletion at end started.\n");

  if (head == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  struct node *ptr6 = head->prev;

  if (ptr6 == head)
  {
    head = NULL;
  }
  else
  {
    ptr6->prev->next = head;
    head->prev = ptr6->prev;
  }

  free(ptr6);
}

// Deletion of Specific Node
void del_specific()
{
  struct node *ptr7 = head;
  int item3;

  if (head == NULL)
  {
    printf("List is empty.\n");
    return;
  }

  printf("Enter data value which you want to delete : ");
  scanf("%d", &item3);

  while (ptr7->data != item3 && ptr7->next != head)
    ptr7 = ptr7->next;

  if (ptr7->data != item3)
  {
    printf("Node data %d is not present.\n", item3);
    return;
  }

  if (ptr7->next == ptr7)
  {
    head = NULL;
  }
  else
  {
    ptr7->prev->next = ptr7->next;
    ptr7->next->prev = ptr7->prev;

    if (ptr7 == head)
      head = ptr7->next;
  }

  free(ptr7);
}

// Display Process
void Display()
{
  printf("\nDisplaying started.\n");

  struct node *ptr = head;

  if (head == NULL)
  {
    printf("List is empty!\n");
    return;
  }

  printf("Doubly Circular Linked List : ");

  do
  {
    printf("%d, ", ptr->data);
    ptr = ptr->next;
  } while (ptr != head);

  printf("(back to head)\n");
}

// Forward Traversal
void forw_tra()
{
  struct node *ptrf = head;

  if (head == NULL)
  {
    printf("List is empty!\n");
    return;
  }

  printf("\nForward Direction Traversal : ");

  do
  {
    printf("%d, ", ptrf->data);
    ptrf = ptrf->next;
  } while (ptrf != head);

  printf("(back to head)\n");
}

// Backward Traversal
void backw_tra()
{
  struct node *ptrb = head;

  if (head == NULL)
  {
    printf("List is empty!\n");
    return;
  }

  ptrb = head->prev;

  printf("\nBackward Direction Traversal : ");

  do
  {
    printf("%d, ", ptrb->data);
    ptrb = ptrb->prev;
  } while (ptrb != head->prev);

  printf("(back to last node)\n");
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

  del_specific();
  Display();

  return 0;
}
