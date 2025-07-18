#include "inverted_search.h"

extern char *fname; // Declare fname as an external variable

int insert_at_last(Wlist **head, data_t *data)
{
    // Create node
    Wlist *new = malloc(sizeof(Wlist));
    if (new == NULL)
        return FAILURE;

    new->file_count = 1;
    strcpy(new->word, data);
    new->Tlink = NULL;
    new->link = NULL;

    // Call function to update Ltable node
    update_link_table(&new);

    // Check if Wlist is empty or not
    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    // Non-empty case
    Wlist *temp = *head;

    // Traverse through the list
    while (temp->link)
    {
        temp = temp->link;
    }

    temp->link = new;
    return SUCCESS;
}

int update_link_table(Wlist **head)
{
    // Create node
    Ltable *new = malloc(sizeof(Ltable));
    if (new == NULL)
        return FAILURE;

    // Update fields
    new->word_count = 1;
    strcpy(new->file_name, fname);
    new->table_link = NULL;

    // Link new Ltable node
    if ((*head)->Tlink == NULL)
    {
        (*head)->Tlink = new; // Attach if there's no Tlink
    }
    else
    {
        new->table_link = (*head)->Tlink; // Attach to the existing link
        (*head)->Tlink = new; // Update the Tlink
    }

    return SUCCESS;
}