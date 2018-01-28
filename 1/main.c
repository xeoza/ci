#include "func.h"

int main(int argc, char **argv)
{
	int rc = OK;
	if (argc == 2)
	{
		FILE *in = fopen(argv[1], "r");
		if (in)
		{
			node *first_struct = NULL, *second_struct = NULL;
			if(read_data(in, &first_struct, &second_struct) == OK)
			{
				print_node(first_struct);
				puts("");
				print_node(second_struct);
				puts("");
				node *result = NULL;
				if (sum_node(first_struct, second_struct, &result) == 0)
				{
					if (round_up_number(&result) == 0)
					{
						puts("RESULT:");
						reverse(&result);
						print_node(result);
						printf("Answer = %d\n", translate_to_int(result));

					}
					else
					{
						rc = IOERROR;
					}
					delete_node(&result);
				}
				else
				{
					rc = IOERROR;
				}
				delete_node(&first_struct);
				delete_node(&second_struct);

			}
		}
		else
			rc = ERR_OPEN_FILE;
	}
	else
		rc = IOERROR;
	
	return rc;
}