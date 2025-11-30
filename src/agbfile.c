#include <stdio.h>
#include <agbfile.h>

#define CHUNK_SIZE 4096

int filecopy(FILE* in, FILE* out)
{
    if (in == NULL && out == NULL) {
        perror ("Error copying file");
        return 1;
    }

    char c;
    while ((c = fgetc(in)) != EOF)
        putc(c, out);

    return 0;
}

int filebcopy(FILE* in, FILE* out)
{
    if (in == NULL && out == NULL) {
        perror ("Error copying file");
        return 1;
    }

    char buffer[CHUNK_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, CHUNK_SIZE, in)) > 0) {
        if (fwrite(buffer, 1, bytes_read, out) != bytes_read) {
            perror("Error copying file");
            return 1;
        }
    }
    return 0;
}
