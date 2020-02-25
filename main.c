#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *ifile = stdin, *ofile = stdout;

    if (argc > 1 && strcmp(argv[1], "-"))
    {
        ifile = fopen(argv[1], "r");
        if (ifile == NULL)
        {
            fprintf(stderr, "Cannot open %s for reading.\n", argv[1]);
            return 1;
        }
    }

    if (argc > 2 && strcmp(argv[2], "-"))
    {
        ofile = fopen(argv[2], "w");
        if (ofile == NULL)
        {
            fprintf(stderr, "Cannot open %s for writing.\n", argv[2]);
            return 2;
        }
    }

    char bytes[16];
    int nread;
    unsigned offset = 0;

    while ((nread = fread(bytes, 1, sizeof(bytes), ifile)))
    {
        fprintf(ofile, "%08x\t", offset);

        for (int i = 0; i < nread; i++)
        {
            fprintf(ofile, "%02hhx", bytes[i]);
            fputc(i != nread - 1 ? ' ' : '\n', ofile);
        }
        offset += nread;
    }

    fclose(ifile);
    fclose(ofile);
    return 0;
}
