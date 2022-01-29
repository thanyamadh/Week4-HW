#include <stdio.h>
#include <stdlib.h>
#include "Node.h"


int main( void )
{ 
  LLPtr startPtr = NULL;
   unsigned int choice;
   int id,score;

   instructions();
   printf( "%s", "? " );
   if(scanf("%u",&choice)){}; //scanf( "%u", &choice );

   while ( choice != 3 ) 
   { 
      switch ( choice ) 
      { 
         case 1:
            printf( "%s", "Enter ID: " );
            if(scanf("%d",&id)){}; //scanf( "%d", &id );
            printf( "%s", "Enter score: " );
            if(scanf("%d",&score)){}; //scanf( "%d", &score );
            insert( &startPtr, id , score );
            printList( startPtr );
            printReverse( startPtr );
            break;
         case 2:
            if ( !isEmpty( startPtr ) ) 
            { 
               printf( "%s", "Enter ID to be deleted: " );
               if(scanf("%d",&id)){}; //scanf( "%d", &id );
               if ( deletes( &startPtr, id )==id) 
               {
                  printf( "%d deleted.\n", id );
                  printList( startPtr );
                  printReverse( startPtr );
               }
               else 
               {
                  printf( "%d not found.\n\n", id );
               }
            }
            else 
            {
               puts( "List is empty.\n" );
            }
            break;
         default:
            puts( "Invalid choice.\n" );
            instructions();
            break;
      }
      printf( "%s", "? " );
      if(scanf("%u",&choice)){}; //scanf( "%u", &choice );
   }

   puts( "End of run." );
}