#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sys/stat.h>
#include "file_utils.h"

/**********************************************************************
 * Reads a file using file_utils.h into a string, reverses it byte
 * by byte, and  outputs it using write_file from file_utils.h
 *
 * @author Allison Bickford
 * @param argc the amount of arguments
 * @param argv pointer to an array of characters that represent the
 *          arguments
 * @return 0 if successful
 *********************************************************************/
int main(int argc, char** argv) {

    //to store the char array from the file
    char* file_contents;

    //if there isn't the correct amount of arguments
    if(argc != 3) {
        printf("Incorrect amount of arguments. Usage:PROG_NAME INPUT_FILENAME OUTPUT_FILENAME\n");
    }

    //store the amount of bytes read_file read
    int readBytes = read_file(argv[1], &file_contents);

    //reversing the file
    //https://stackoverflow.com/questions/15717735/reversing-string-using-pointers-in-c
    char *start = file_contents;
    //pointer to the end of the string
    char *end = start + strlen(start) - 1;
    while (end > start)
    {
        //store the end character
        char temp = *end;
        //move from end towards beginning
        *end-- = *start;
        //set the original contents to the temp character
        *start++ = temp;
    }

    write_file(argv[2], file_contents, readBytes);

    //memory allocated in read_file
    free(file_contents);

    return 0;
}