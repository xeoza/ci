#include "func.h"

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);

    FILE *f_in = fopen(argv[1], "r");
    FILE *f_out = fopen(argv[2], "w");

    list_t *head = NULL;

    readListF(f_in, &head);

    workWords(f_out, head);

    freeList(head);


    fclose(f_in);
    fclose(f_out);
    return 0;
}
