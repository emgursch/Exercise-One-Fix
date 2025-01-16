#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    struct stat st; 

    // Check if the file exists
    if (stat(argv[1], &st) == -1) {
        fprintf(stderr, "Error: File '%s' does not exist.\n", argv[1]);
        return -1;
    }

    // Print the file size in bytes
    printf("File size of '%s': %lld bytes\n", argv[1], (long long)st.st_size); 

    return 0;
}
