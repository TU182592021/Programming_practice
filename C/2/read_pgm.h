#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

#define DONE 3

/**
 * @fn
 * read pgm file
 * @brief read pgm file, both ASCII and binary formats are supported
 * @param (name) file name of input .pgm
 * @param (width) address of a variable to store the width of the input
 * @param (height) address of a variable to store theheight of the input
 * @param (maxval) address of a variable to store themax pixel value of the
 * input
 * @return returns an address of buffer allocated inside this function. free()
 * shall be called in the user code.
 * @author Osamu Watanabe
 */
unsigned char *read_pgm(char *name, int *width, int *height, int *maxval)
{
    FILE *fp = fopen(name, "rb");
    if (fp == NULL)
    {
        printf("File %s is not found.\n", name);
        exit(EXIT_FAILURE);
    }
    int status = 0; // status, = 3 is DONE
    char c;
    int val = 0;
    char comment[256]; // temporal buffer to eat comments
    c = fgetc(fp);
    if (c != 'P')
    {
        printf("This image is not in PNM format.\n");
        exit(EXIT_FAILURE);
    }
    c = fgetc(fp);
    int isASCII = false;
    if (c != '5' && c != '2')
    {
        printf("This image is not in PGM format.\n");
        exit(EXIT_FAILURE);
    }
    if (c == '2')
    {
        isASCII = true;
    }
    while (status < DONE)
    {
        c = fgetc(fp);
        // eat spaces, LF or CR, or comments
        while (c == ' ' || c == '\n' || c == 0xd)
        {
            c = fgetc(fp);
            if (c == '#')
            {
                fgets(comment, sizeof(comment), fp);
                c = fgetc(fp);
            }
        }
        // get values
        while (c != ' ' && c != '\n' && c != 0xd)
        {
            val *= 10;
            val += c - '0';
            c = fgetc(fp);
        }

        // update status
        switch (status)
        {
        case 0:
            *width = val;
            val = 0;
            status++;
            break;
        case 1:
            *height = val;
            val = 0;
            status++;
            break;
        case 2:
            *maxval = val;
            val = 0;
            status++;
            break;
        default:
            break;
        }
    }

    if (*maxval > 255)
    {
        printf("Maximum value greater than 255 is not supported\n");
        exit(EXIT_FAILURE);
    }

    int numpixels = *width * *height;
    unsigned char *buf =
        (unsigned char *)malloc(numpixels * sizeof(unsigned char));
    if (buf == NULL)
    {
        printf("malloc() error\n");
        exit(EXIT_FAILURE);
    }

    // read pixel values into buffer
    if (isASCII == false)
    {
        fread(buf, sizeof(unsigned char), numpixels, fp);
    }
    else
    {
        for (int i = 0; i < numpixels; ++i)
        {
            val = 0;
            c = fgetc(fp);
            while (c != ' ' && c != '\n' && c != EOF)
            {
                val *= 10;
                val += c - '0';
                c = fgetc(fp);
            }
            buf[i] = val;
        }
    }
    fclose(fp);
    return buf;
}