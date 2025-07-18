#include "inverted_search.h"

char *fname;

void create_database(Flist *f_head, Wlist *head[])
{
    // Traverse through the file linked list
    while (f_head)
    {
        read_datafile(f_head, head, f_head->file_name);
        f_head = f_head->link;
    }
}

// Read content of the file 
Wlist *read_datafile(Flist *file, Wlist *head[], char *filename)
{
    int flag;
    fname = filename; 
    // Open the file in read mode
    FILE *fptr = fopen(filename, "r");

    // Declare an array to store words
    char word[WORD_SIZE];

    while (fscanf(fptr, "%s", word) != EOF)
    {
        flag = 1;  // Reset flag for each new word

        // Index
        int index = tolower(word[0]) % 97;

        // Other than alphabet 
        if (!(index >= 0 && index <= 25))
            index = 26;

        if (head[index] != NULL)
        {
            Wlist *temp = head[index];

            // Compare the new word with each node's words
            while (temp)
            {
                if (!strcmp(temp->word, word))
                {
                    update_word_count(&temp, filename);
                    flag = 0;
                    break;
                }
                temp = temp->link;
            }
        }

        if (flag == 1)
        {
            // If words are not repeating    
            insert_at_last(&head[index], word);
        }
    }

    fclose(fptr);  // Close the file after reading
    return NULL;   // Or return an appropriate value if needed
}

int update_word_count(Wlist **head, char *file_name)
{
    // Check if filenames are the same
    Ltable *ptr = (*head)->Tlink;
    while (ptr)
    {
        if (strcmp(ptr->file_name, file_name) == 0)
        {
            // When filenames are the same -> increment word_count
            ptr->word_count++;
            return SUCCESS;
        }
        ptr = ptr->table_link;
    }

    // If the filename is not found, create a new Ltable node
    Ltable *new_node = malloc(sizeof(Ltable));
    if (new_node == NULL)
        return FAILURE;

    // Update fields
    new_node->word_count = 1;
    strcpy(new_node->file_name, file_name);
    new_node->table_link = (*head)->Tlink; // Attach at the beginning
    (*head)->Tlink = new_node;

    // Increment file_count
    (*head)->file_count++;
    return SUCCESS;
}
