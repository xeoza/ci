#include "functions.h"
//app.exe in.txt out.txt –s search –r replace 
int main(int argc, char **argv)
{
    int rc = SUCCESS;
    if (argc != 7)
    {
        return IOERROR;
    }
    FILE * in, * out;
    in = fopen(argv[1], "r");
    if (!in)
        return IOERROR;
    fseek(in, 0, MY_SEEK_END);
    if (ftell(in) == 0)
        return IOERROR;
    rewind(in);
    out = fopen(argv[2], "w");
    if (out)
    {
        char *line = NULL, *result_string;
        ssize_t read;
        size_t len;

        while ((read = my_getdelim(&line, &len, '\n', in)) != -1)
        {
            result_string = str_replace(line, argv[4], argv[6]);
            printf("%s", line);
            fprintf(out, "%s", result_string);
            free(result_string);
        }
        free(line);
        fclose(out);
    }
    else
    {
        rc = IOERROR;
    }
    fclose(in);
    
    return rc;
}