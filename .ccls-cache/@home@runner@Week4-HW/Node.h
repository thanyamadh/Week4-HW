struct Node {                                      
   int id;
   int score;
   struct Node *nextPtr;
   struct Node *pPtr;
};
typedef struct Node LLnode;
typedef LLnode* LLPtr;

//funtion
void instructions( void );
int isEmpty( LLPtr sPtr );
void insert( LLPtr *sPtr, int id ,int score);
int deletes( LLPtr *sPtr, int value );
void printList( LLPtr currentPtr );
void printReverse( LLPtr currentPtr );

void instructions( void )
{ 
   puts( "Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end." );      
}

int isEmpty( LLPtr sPtr )
{ 
   return sPtr == NULL;
}

void insert( LLPtr *sPtr, int id , int score)
{ 
   LLPtr newPtr;
   LLPtr previousPtr;
   LLPtr currentPtr;

   newPtr =(LLPtr) malloc( sizeof( LLnode ) );

   if ( newPtr != NULL ) 
   {
      newPtr->id = id; //กำหนดค่าให้idของNewPtr=id
      newPtr->score = score; //กำหนดค่าให้idของNewPtr=id
      newPtr->nextPtr = NULL; //กำหนดให้node(ไป)ชี้ไปที่NULLก่อน
      newPtr->pPtr = NULL; //กำหนดให้node(กลับ)ชี้ไปที่NULLก่อน

      previousPtr = NULL;
      currentPtr = *sPtr;

      //หาตำแหน่งที่จะแทรก
      while ( currentPtr != NULL && id > currentPtr->id ) 
      {
         previousPtr = currentPtr;              
         currentPtr = currentPtr->nextPtr;
      }                                        
      if ( previousPtr == NULL ) //แทรกเป็นตัวแรก
      { 
         newPtr->nextPtr = *sPtr;
         if(*sPtr)
         (*sPtr)->pPtr=newPtr;
         *sPtr = newPtr;
      }
      else //แทรกระหว่างPreกับCur
      {
         previousPtr->nextPtr = newPtr; //ต่อจากpreเป็นNew
         newPtr->pPtr=previousPtr; //ให้node(กลับ)ของNewชี้ที่pre
         if(currentPtr!=NULL) //เช็คว่าตัวต่อไปไม่ใช่NULLถึงจะให้nodeชี้
         {
           newPtr->nextPtr = currentPtr; //ต่อจากnewคือCur
           currentPtr->pPtr=newPtr; //ให้node(กลับ)ของCurชี้ที่New
         }    
      }
   }
   else 
   {
      printf( "%d not inserted. No memory available.\n", id );
   }
}

int deletes( LLPtr *sPtr, int value )
{ 
   LLPtr previousPtr; 
   LLPtr currentPtr;
   LLPtr tempPtr;

   if ( value == ( *sPtr )->id ) //กรณีลบตัวแรก
   { 
      tempPtr = *sPtr;
      if(( *sPtr )->nextPtr != NULL) //เช็คกรณีไปตัวสุดท้ายไม่NULL(กรณีแบบเวรี่เฟิร์ส)
      {
        *sPtr = ( *sPtr )->nextPtr;
        ( *sPtr )->pPtr=NULL;
      }
      else
          *sPtr=NULL;
      free( tempPtr );
      return value;
   }
   else //กรณีลบระหว่าง
   { 
      previousPtr = *sPtr;
      currentPtr = ( *sPtr )->nextPtr;

      //หาตำแหน่งที่จะลบ
      while ( currentPtr != NULL && currentPtr->id != value ) 
      { 
         previousPtr = currentPtr;  
         currentPtr = currentPtr->nextPtr; 
      }
      if ( currentPtr != NULL ) 
      { 
        tempPtr = currentPtr; //ให้ค่านั้นเป็นTemp
        if(currentPtr->nextPtr != NULL) //เช็คกรณีกลับตัวแรกNULL
        {
          previousPtr->nextPtr = currentPtr->nextPtr;
          currentPtr->nextPtr->pPtr=previousPtr;
        }
        else
        {
          previousPtr->nextPtr = NULL;
        }
         free( tempPtr );
         return value;
      }
   }

   return '\0';
}


void printList( LLPtr currentPtr )
{ 
   if ( isEmpty( currentPtr ) ) 
   {
      puts( "List is empty.\n" );
   }
   else 
   { 
      puts( "The list is:" );
      while ( currentPtr != NULL ) 
      { 
         printf( "ID %d - ", currentPtr->id );
         printf( "Score %d\n", currentPtr->score );
         currentPtr = currentPtr->nextPtr;   
      }
      puts( "---NULL---\n" );
   }
}

void printReverse( LLPtr currentPtr )
{ 
   if ( isEmpty( currentPtr ) ) 
   {
      puts( "List is empty.\n" );
   }
   else 
   { 
      puts( "The Reverse list is:" );
      while ( currentPtr->nextPtr != NULL )
      {
        currentPtr = currentPtr->nextPtr;
      }
      while ( currentPtr != NULL ) 
      { 
         printf( "ID %d - ", currentPtr->id );
         printf( "Score %d\n", currentPtr->score );
         currentPtr = currentPtr->pPtr;   
      }
      puts( "---NULL---\n" );
   }
}