#include <QCoreApplication>
#include"listtest.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Lnode *head, *current, *previous;

   int num=0;
   printf("type num of nodes = ");
   scanf("%d",&num);

   int i;
   for(i=0;i<num;i++)
   {
       current = (Lnode*)malloc(sizeof(Lnode));
       printf("\ninitial node [ %d ] =",i);
       scanf("%d",&(current->value));
       //printf("value of node i = %d\n", current->value);

       if(i==0)
       {
          head = current;

       }

       else
       {
           previous->next = current;

       }


       //current->value = i;
       current->next = NULL;

       previous = current;

   }

   Scope(head);

   int k=0;
/*
   printf("\nchoose node number to kill:");
   scanf("%d",&k);
   printf("h = %p\n",head);
   head = Deletenode(head,k);//update head
    printf("newh = %p\n",head);
   Scope(head);
*/
/*
   printf("\nchoose value to kill:");
   scanf("%d",&k);
   head=DeleteKey(head,k);
   Scope(head);
*/
   printf("PushFront #1 -----\n");
   head = PushFront(head,3);
   Scope(head);
   printf("PushFront #2 -----\n");
   head = PushFront(head,2);
   Scope(head);
   printf("PushFront #3 -----\n");
   head = PushFront(head,1);
   Scope(head);

   printf("PushBack #1----\n");
   PushBack(head,9);
   Scope(head);
   printf("PushBack #2----\n");
   PushBack(head,10);
   Scope(head);
   printf("PushBack #3----\n");
   PushBack(head,11);
   Scope(head);


   head = Reverse(head);
   Scope(head);

   Freelist(head);


    return a.exec();
}
