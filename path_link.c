#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main(void)
{
	struct node
	{
		char *file;
		struct node *next;
	};
	struct node *head, *newnode, *temp;
	struct dirent *de;
	DIR *dr;
	char *tempfile;

	newnode = malloc(sizeof(struct node));

	dr = opendir(".");

	if (dr == NULL)
	{
		printf("Could not open current directory");
		return 0;
	}
	head = 0;
	while ((de = readdir(dr)) != NULL)
	{
		tempfile = de->d_name;
		newnode->file = tempfile;
		newnode->next = 0;
		if (head == 0)
		{
			head = temp = newnode;
		}
		else
		{
			temp->next = newnode;
			temp = newnode;
		}
		if (head == 0)
			temp = head;
		
		
		printf("%s\n", temp->file);
		
		
	}
	closedir(dr);
	return 0;
}
