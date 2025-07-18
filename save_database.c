/*
#include "inverted_Search.h" 

void save_database( Wlist *head[])
{
    //prompt the user for new file 

    char file_name[FNAME_SIZE];
    printf("Enter the file name\n");
    scanf("%s" , file_name);

    //open file

    FILE *fptr = fopen(file_name , "w" );

    for(int i = 0; i <27; i++)
    {
	if(head[i] != NULL)
	{
	    write_databasefile(head[i] , fptr);
	}
    }

    printf("Database saved\n");
}

 void write_databasefile(Wlist *head, FILE* databasefile)
{

    //......TODO........
 //    # [index]  word is [  word  ] : file count is [  file_count ] :  file_name  is [  file_name  ]  : word count is [ word_count  ]
}
*/

#include "inverted_search.h" 

void save_database(Wlist *head[])
{
    // Prompt the user for a new file 
    char file_name[FNAME_SIZE];
    printf("Enter the file name: ");
    scanf("%s", file_name);

    // Open file
    FILE *fptr = fopen(file_name, "w");
    if (fptr == NULL)
    {
        printf("Error opening file: %s\n", file_name);
        return; // Exit the function if the file cannot be opened
    }

    // Write data to the file
    for (int i = 0; i < 27; i++)
    {
        if (head[i] != NULL)
        {
            write_databasefile(head[i], fptr);
        }
    }

    fclose(fptr); // Close the file
    printf("Database saved successfully to %s\n", file_name);
}

void write_databasefile(Wlist *head, FILE *databasefile)
{
    // Traverse through the Wlist to write to the file
    while (head != NULL)
    {
        fprintf(databasefile, "[%d] word is [%s]: file count is [%d]: ", 
                tolower(head->word[0]) % 97, 
                head->word, 
                head->file_count);
        
        Ltable *Thead = head->Tlink;

        // Traverse through the Ltable to write file names and counts
        while (Thead)
        {
            fprintf(databasefile, "file_name is [%s]: word count is [%d]  ", 
                    Thead->file_name, 
                    Thead->word_count);
            Thead = Thead->table_link;
        }
        fprintf(databasefile, "\n"); // New line for the next word entry
        head = head->link; // Move to the next word node
    }
}
