/*#include "inverted_search.h"

void update_database( Wlist *head[], Flist **f_head)
{
    //promopt the user for new file 

    char file_name[FNAME_SIZE];

    printf("Enter the file name\n");
    scanf("%s" , file_name);


    //validation ........TODO...........

    while(*f_head)
    {
	if(!strcmp(*f_head->file_name , file_name))
	{
	    create_database(*f_head,head);
	}

	*f_head = (*f_head)->link;*/
   /* }
}
*/

#include "inverted_search.h"

void update_database(Wlist *head[], Flist **f_head)
{
    // Prompt the user for a new file 
    char file_name[FNAME_SIZE];

    printf("Enter the file name: ");
    scanf("%s", file_name);

    // Validation to check if the file exists
    if (isFileEmpty(file_name) == FILE_NOTAVAILABLE) {
        printf("File: %s is not available.\n", file_name);
        return; // Exit the function if the file is not available
    }

    // Traverse through the file linked list
    Flist *temp = *f_head;  // Use a temporary pointer to traverse

    while (temp)
    {
        if (!strcmp(temp->file_name, file_name))
        {
            create_database(temp, head); // Pass the correct pointer
            return; // Exit after updating
        }
        temp = temp->link; // Move to the next file in the list
    }

    printf("File: %s not found in the file list.\n", file_name); // Indicate if the file was not found
}
