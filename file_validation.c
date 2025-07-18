#include"inverted_search.h" 

void file_validation_n_file_list(Flist **f_head, char *argv[])
{

    int i = 1 , empty;

    while(argv[i] != NULL)
    {
	empty = isFileEmpty(argv[i]);
	if(empty == FILE_NOTAVAILABLE)
	{
	    printf("File : %s is not available\n" , argv[i]);
	    printf("Hence we are not adding that file into file linked list\n");
	    i++;
	    continue;
	}
	else if(empty == FILE_EMPTY)
	{
	    printf("File : %s is not having contents in it\n" , argv[i]);
	    printf("Hence we are not adding that file into file linked list\n");
	    i++;
	    continue;
	}
	else
	{
	    int ret = to_create_list_of_files(f_head , argv[i]);

	    if(ret == SUCCESS)
	    {
		printf("Successfule : Inserting the file %s into file linked list\n" , argv[i]);
	    }
	    else if(ret == REPEATATION)
	    {
		printf("This file is not added to file linked list as it is repeated\n");
	    }
	    else
	    {
		printf("failure\n");
	    }

	    i++;
	    continue;        

	}
    }

}


//fun() is used to check for file availability and check for file contents

int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename , "r" );
    if(fptr == NULL)
    {
	if(errno == ENOENT)
	{
	    return FILE_NOTAVAILABLE;
	}
    }

    //Check for content

    fseek(fptr , 0 , SEEK_END);

    if(ftell(fptr) == 0)
    {
		fclose(fptr) ;
		return FILE_EMPTY;
    }

}

int to_create_list_of_files(Flist **f_head, char *name)
{
    //........TODO..........
    //check for duplicancy ..TODO ......insert_last()

	if( *f_head == NULL)
	{
		Flist *new_node = malloc( sizeof(Flist)) ;
		if (new_node == NULL)
		{
			return FAILURE ;
		}

		strcpy(new_node->file_name, name) ;
		new_node->link = NULL ;
		*f_head = new_node ;
		return SUCCESS ;
	}


	Flist *ptr = *f_head ;	
	while( ptr != NULL)
	{
		if( strcmp( ptr->file_name, name) == 0)
		{
			return REPEATATION ;
		}

		if( ptr->link == NULL)
		{
			Flist *new_node = malloc( sizeof(Flist)) ;
			if (new_node == NULL)
			{
				return FAILURE ;
			}
			
			strcpy(new_node->file_name, name) ;
			new_node->link = NULL ;
			ptr->link = new_node ;

			return SUCCESS ;			
		}
		ptr = ptr->link ;
	}
}
