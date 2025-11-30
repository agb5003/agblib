#define __STDC_WANT_LIB_EXT1__ 1

#include <agbfile.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE* fileA;
    FILE* fileB;

    if (argc == 3) {
        if (fopen_s(&fileA, argv[1], "rb")) {
            perror("Error opening file for copy");
            return 1;
        }
        if (fopen_s(&fileB, argv[2], "wb")) {
            perror("Error opening destination file for copy");
            return 1;
        }
        if (filebcopy(fileA, fileB)) {
            perror("Error copying file");
            fclose(fileA);
            fclose(fileB);
            return 1;
        }
        fclose(fileA);
        fclose(fileB);
    } else {
        printf("Usage: ./main <input-file> <output-file>\n");
        return 1;
    }
    return 0;
}
