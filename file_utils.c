    //
// Created by allison on 10/09/18.
//

#include <sys/stat.h>
#include <stdlib.h>
#include <bits/types/FILE.h>
#include <stdio.h>
#include "file_utils.h"


/**********************************************************************
 * reads a text file and stores it in memory
 * @param filename the name/path of the file to read
 * @param buffer pointer to a pointer to store "string" of text
 * @return the amount of read bytes
 *********************************************************************/
int read_file(char* filename, char **buffer) {

    FILE *in = fopen(filename, "r");
    //make sure things don't go wrong
    if (in == NULL) {
        fprintf(stderr, "Could not load file");
        exit (1);
    }

    //getting size of file
    struct stat st;
    stat(filename, &st);
    int size = st.st_size;

    //allocate enough memory for all chars in file
    *buffer = (char*) malloc(size * sizeof(char));

    //read file and store the amount read
    int read = fread(*buffer, sizeof(char), size, in);

    fclose(in);
    return read;
}

/**********************************************************************
 * writes a file from stored memory into an output file
 *
 * @param filename the name/path of the file to write into
 * @param buffer the pointer that stores the location of the string to
 *          be written
 * @param size the size of the file to read
 * @return the amount of bytes that were written
 **********************************************************************/
int write_file(char* filename, char *buffer, int size) {
    FILE *out = fopen(filename, "w");

    //error handling just in case
    if (out == NULL) {
        fprintf(stderr, "Could not load file");
        exit(1);
    }

    //write the file
    int written = fwrite(buffer, sizeof(char), size, out);


    fclose(out);
    return written;
}

