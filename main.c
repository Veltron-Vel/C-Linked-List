#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;


int main()
{
    int size;
    printf("How many elements do you want in your array ?:\n");
    scanf("%d",&size);
    node *list = NULL;
    for(int i=0;i<size;i++)
    {
        node *n = malloc(sizeof(node));

            if(n==NULL)
        {
            return 1;
        }

        printf("Type the number:\n");
        scanf("%d",&n->number);
        n->next = NULL;

        if(list==NULL)
        {
            list = n;
        } else
        {
            for(node *ptr=list;ptr!=NULL;ptr=ptr->next)
            {
                if(ptr->next==NULL)
                {
                    ptr->next = n;
                    break;
                }

            }
        }
    }

    printf("The array is :\n");

    for(node *ptr=list;ptr!=NULL;ptr=ptr->next)
    {
        printf("%i\n",ptr->number);
    }

    return 0;
}
