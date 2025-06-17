#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

int isEmpty(node *head);
int insertFirst(node **head,int value);
int insertLast(node **head,int value);
int insertAt(node **head,int value,int index);
int deleteFirst(node **head);
int deleteLast(node **head);
int deleteAt(node **head,int index);
int search(node *head,int value);
void display(node *head);

int main()
{
    node *head = NULL;

    insertLast(&head,10);
    insertLast(&head,20);
    insertLast(&head,30);
    insertLast(&head,40);
    insertLast(&head,50);
    display(head);

    insertAt(&head,35,3);
    display(head);

    deleteAt(&head,3);
    display(head);

    deleteFirst(&head);
    deleteLast(&head);
    display(head);

    search(head,45);

    return 0;
}

int isEmpty(node *head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return 1;
    }
    return 0;
}

int insertFirst(node **head,int value)
{
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }
    newNode->number = value;
    newNode->next = NULL;
    if(isEmpty(*head))
    {
        *head = newNode;
        return 1;
    }

    newNode->next = *head;
    *head = newNode;

    return 1;
}

int insertLast(node **head,int value)
{
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }
    newNode->number = value;
    newNode->next = NULL;
    if(isEmpty(*head))
    {
        *head = newNode;
        return 1;
    } 

    for(node *ptr = *head;ptr!=NULL;ptr=ptr->next)
    {
        if(ptr->next==NULL)
        {
            ptr->next = newNode;
            break;
        }
    }

    return 1;

}

int insertAt(node **head,int value,int index)
{
    node *newNode = malloc(sizeof(node));

    newNode->number = value;
    newNode->next = NULL;

    if(isEmpty(*head))
    {
        *head = newNode;
        printf("Node attached succesfully\n");
        return 1;
    }

    if(index == 0)
    {
        insertFirst(head,value);
        free(newNode);
        return 1;
    }
    node *prev = *head;
    for(int i =0;i<index-1;i++)
    {
        if(prev==NULL)
        {
            printf("Out of bounds\n");
            free(newNode);
            return 0;
        }else{
            if(prev->next==NULL)
            {
                insertLast(head,value);
                free(newNode);
                return 1;
            }
        }
         prev = prev->next;
    }

    newNode->next = prev->next;
    prev->next = newNode;
    printf("Node attached succesfully at index %d\n",index);
    return 1;
}

int search(node *head,int value)
{
    if(isEmpty(head))
    {
        return 1;
    }
    
    for(node *ptr = head;ptr!=NULL;ptr=ptr->next)
    {
        if(ptr->number==value)
        {
            printf("Element found in the list\n");
            return 1;
        }
    }
     printf("Element %d was not found in the list\n",value);

    return 0;
}

int deleteFirst(node **head)
{
    if(isEmpty(*head))
    {
        return 1;
    }

    node *ptr = *head;
    *head = (*head)->next;
    free(ptr);

    printf("First node deleted succesfully\n");
    return 1;
}

int deleteLast(node **head)
{

    if(isEmpty(*head))
    {
        return 0;
    }

    if((*head)->next==NULL)
    {
        free(*head);
        *head = NULL;
        return 1;
    }
    node *ptr=*head;
    for(;ptr->next->next!=NULL;ptr=ptr->next)
    {
        ///
    }
    
    free(ptr->next);
    ptr->next =NULL;
    printf("Last node deleted successfully\n");
    return 0;
}

int deleteAt(node **head,int index)
{
      if(isEmpty(*head))
    {
        return 0;
    }

    if(index==0)
    {
        node *ptr = *head;
        *head = (*head)->next;
        free(ptr);
        printf("Node at index 0 deleted succesfully\n");
        return 1;
    }

    node *prev = *head;
    for(int i=0;i<index-1;i++)
    {
        if(prev==NULL || prev->next==NULL)
        {
            printf("Index out of bounds\n");
            return 0;
        }
        prev = prev->next;
    }

    node *toDelete=prev->next;

    if (toDelete == NULL)
    {
    return 0;  // index was too large
    }
    prev->next = toDelete->next;
    free(toDelete);
    printf("Node at index %d deleted succesfully\n",index);
    return 1;
}

void display(node *head)
{
    if(isEmpty(head))
    {
        return;
    }

    printf("List:\n");
    for(node *ptr = head;ptr!=NULL;ptr=ptr->next)
    {
        printf("%d\n",ptr->number);
       
    }
}
