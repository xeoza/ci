#include "func.h"

int main(int argc, char **argv)
{
	int rc = OK;
	FILE *in = fopen(argv[1], "r");//, *out = fopen(argv[2], "w");
	if (in)
	{
		node *list = NULL;
		if (read_data(in, &list) == OK)
		{
			puts("OK");
			reverse(&list);
			printf_list(list);
			if (replace_min_max(&list) == 0)
			{
				puts("OK");
				printf_list(list);
				puts("OK");
			}
			delete_list(&list);
			puts("OK");
		}
		fclose(in);
	}
	else
		rc = ERR_NO_FILE;
	return rc;
}