#include "inverted.h"

int update_database(M_node *HT[], F_node **head)
{
    char filename[25];
    printf("Enter the filename you want to update : ");
    scanf("%s",filename);
    char *res=strstr(filename,".");
    if(res)
    {
        if(strcmp(res,".txt")==0)
        {
            FILE *fptr=fopen(filename,"r");
            if(fptr)
            {
                fseek(fptr,0,SEEK_END);
                unsigned long int f_tell=ftell(fptr);
                rewind(fptr);
                if(f_tell)
                {
                    if(check_duplicates(*head,filename)==FAILURE)
                    {
                        if(insert_first(head,filename)==SUCCESS)
                            printf("INFO : Successful : Inserting file name %s into file linked list\n\n",filename);
    
                    }
                    else
                        printf("INFO : %s => This file is repeated, so it will not store into the sll\n\n",filename);
                }
                else
                    printf("INFO : %s => This file is empty\n\n",filename);
                fclose(fptr);
            }
            else
                printf("INFO : %s => This file does not exist in the current directory\n\n",filename);
        }
        else
            printf("INFO : %s => This file is not .txt\n\n",filename);
    }
    else
        printf("INFO : %s => This file has without extension\n\n",filename);
    create_database(HT,*head);
    print_filenames(*head);
}
int insert_first(F_node **head,char * filename)
{
	F_node *new_node=malloc(sizeof(F_node));
    if(new_node==NULL)
        return FAILURE;
    strcpy(new_node->f_name,filename);
    new_node->link=NULL;
    new_node->link=*head;
    *head=new_node;
    return SUCCESS;
}