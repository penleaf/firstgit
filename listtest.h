#ifndef LISTTEST_H
#define LISTTEST_H


struct node{

int value;
struct node *next;

};
typedef struct node Lnode;

void Scope(Lnode *head);
void Freelist(Lnode *head);
int Getlength(Lnode *head);
Lnode* Deletenode(Lnode *head,int k);
Lnode* DeleteKey(Lnode *head,int key);

void Scope(Lnode *head)
{
    printf("\nSearching.......\n");
    int i=0;
    Lnode *ptr_s = head;

    while(NULL != ptr_s)
    {
        printf("List [ %d ] = %d\n",i,ptr_s->value);
        ptr_s = ptr_s->next;
        i++;
    }

}

void Freelist(Lnode *head)
{
    Lnode *tmp;//point to next node
/*
    while(NULL!=head->next)
    {
      tmp = head->next;//next node location
      free(head);
      head = tmp;//new head
    }

    free(head);//the last node
*/

    while(NULL!=head)
    {
        tmp = head;//tmp is responsible for elimination
        head = head->next;//new head
        free(tmp);
    }

}

int Getlength(Lnode *head)
{
    int i=0;
    Lnode *tmp = head;
    while(NULL != tmp)
    {
        i++;
        tmp = tmp->next;
    }

    return i;
}

Lnode *Deletenode(Lnode *head,int k)
{
    Lnode *tmp,*newhead;
    newhead = head;

    if(k > Getlength(head)-1 || k < 0)
    {
        printf("delete out of range\n");

    }
    else
    {
        if(k==0)
        {

           newhead = head->next;
           free(head);
           printf("debug");

        }
        else
        {
            int i=0;
            while(i != k) // searching
            {
                tmp = head;//previous node
                head = head->next;
                i++;
            }
            tmp->next = head->next;
            free(head);//free the node;

        }

    }

    return(newhead);//update head address
}

Lnode *DeleteKey(Lnode *head,int key)
{
    Lnode *tmp, *previous, *newhead;
    newhead = head;
    int i=0, length=Getlength(head);

    while(i < length)
    {


        if(head->value == key)
        {
           tmp = head;
           if(i==0)
           {
               head = head->next;//move
               newhead = head;
               free(tmp);//free

           }
           else
           {
               previous->next = head->next;//connect
               head = head->next;//move
               free(tmp);//free

           }

        }

        else
        {
           previous = head;//record previous
           head = head->next;//move
        }

        i++;
    }

    return(newhead);

}


#endif // LISTTEST_H
