#include "inverted_search.h" 

int main(int argc , char *argv[])
{
    system("clear");

    Wlist *head[27] = { NULL} ; 
    char word[WORD_SIZE];
    //validate CLA

    if(argc <= 1)
    {
	printf("Enter the valid no. CLA\n");
	printf("./Flist.exe  file1.txt   file2.txt.....\n");
	return 0;
    }


    //create file linked list

    //declare head pointer

   Flist *f_head = NULL;


   //validate the files

   file_validation_n_file_list(&f_head, argv);


   if(f_head == NULL)
   {
       printf("no files added to file linked list\n");
       printf("Hence the process got terminated\n");
       return 1;
   }

    int choice ;
   while(1)
   {
     printf("Select your choice among following options :\n") ;
    printf("1. Create DataBase\n2. Display DataBase\n3. Update DataBase\n4.Search\n5. Save DataBase\n6. Exit\n") ;
    printf("Enter your choice: ") ;
    scanf("%d", &choice) ;

    switch (choice)
    {
    case 1:   create_database(f_head , head) ;
        break;
    case 2:
        display_database(head);
        break;
    case 3:
         update_database(head , &f_head);
         break;
    case 4:
   	    printf("Enter the word to search\n"); 
	    scanf("%s"  , word);
	    int index = tolower(word[0]) % 97 ;
   	    search(head[index] , word);
        break;
    case 5 :
         save_database(head);
         break ;
    case 6 :
        exit(0) ;
    default:
        printf("Invalid : Enter the valid choice") ;
    }

   }
}