/*
#include "inverted_search.h" 
void search( Wlist *head, char *word)
{
    //check empty or not

    if(head == NULL)
    {
	printf("List is empty , search not possible\n");
	return 0;
    }

    //traverse 

    while(head)
    {
	//compare new word with each node word

	if(!strcmp(head->word , word))
	{
	    printf("Word %s is present in %d file/s \n" , word , head->file_count);

	    Ltable *Thead = head->Tlink;

	    while(Thead)
	    {
		printf("In file : %s    %d time/s " , Thead->file_name , Thead->word_count);

		Thead = Thead->table_link;
	    }
	    printf("\n");
	    return 0;
	}

	head = head->link;
    }

    printf("Search word not present\n");
}
*/

#include "inverted_search.h" 

void search(Wlist *head, char *word)
{
    // Check if the list is empty
    if (head == NULL)
    {
        printf("List is empty, search not possible\n");
        return;  // Just return; no value to return
    }

    // Traverse the list
    while (head)
    {
        // Compare the new word with each node's word
        if (!strcmp(head->word, word))
        {
            printf("Word %s is present in %d file/s \n", word, head->file_count);

            Ltable *Thead = head->Tlink;

            while (Thead)
            {
                printf("In file: %s    %d time/s ", Thead->file_name, Thead->word_count);
                Thead = Thead->table_link;
            }
            printf("\n");
            return;  // Just return; no value to return
        }

        head = head->link;  // Move to the next node
    }

    printf("Search word not present\n");
}