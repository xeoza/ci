
#include "list_func.h"

int main()
{
	FILE * f;
	FILE * f2;
	stud_t *head = NULL;
	double min = 0;

	setbuf(stdout, NULL);

	f = fopen("test.txt","r");
	if (!f)
		return -1;
	else
	{
		f2 = fopen("out.txt","w");
		fscan_list(f, &head);
		print_list(head);
		min = find_min_array(head);
		head = rm_stud(head, min);
		printf("RM OK\n");
		fprint_list(f2, head);
		printf("RESULT:\n");
		print_list(head);
		head =  sort(head);
		printf("SORT:\n");
		print_list(head);
		fclose(f);
		fclose(f2);
	}
}
