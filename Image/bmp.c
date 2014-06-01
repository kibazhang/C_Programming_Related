#include <stdlib.h>
#include <stdio.h>

#include "bmp.h"
#define BMP_HEADER_TYPE 0x4d42
#define BMP_HEADER_BITS 24
#define BMP_HEADER_PLANE 1

BMP_Image *BMP_create(BMP_Header *header)
{
    // allocate memory for the image structure
    BMP_Image *input_image = malloc(sizeof(BMP_Image));
    if(input_image == NULL)//check if the data has been written
    {
      return NULL;
    }

    // copy the header information 
    input_image -> header = *header;//since the input_image is a pointer, use -> instead
    input_image -> width = header -> width;//copy width
    input_image -> height = header -> height;//copy height
    input_image -> bytes_per_pixel = header -> bits/8;//copy bytes per pixel

    // image size is file size minus the size of the header
    input_image -> data_size = header -> size - sizeof(BMP_Header); 

    // allocate memory for the data
    input_image -> data = malloc(sizeof(char) * input_image -> data_size);
    if(input_image -> data == NULL)//check if the memory has been reserved or not
    {
      return NULL;
    }

    // return the image structure
    return input_image;
}

void BMP_destroy(BMP_Image *image)
{
    // deallocate the allocated memory
    free(image -> data);//free the pointed memory by the poiinters
    free(image);
}

BMP_Image *BMP_load(const char *filename)
{
    // read the header from the file
    FILE *input_file = fopen(filename,"rb");//use rb to read binary file
    if (input_file == NULL)//check if it's opened
    {
      return NULL;
    }
    BMP_Header input_header;//input header file
    if (fread(&input_header, sizeof(BMP_Header), 1, input_file) != 1)//check if the input file has been successfully read or not
    {
      fclose(input_file);
      return NULL;
    }
    // print the header information (use BMP_printHeader)
    BMP_printHeader(&input_header);//print the header information to the screen

    // make sure the header is valid before proceeding (use BMP_checkValid)
    if(BMP_checkValid(&input_header) != 1)//check if the header information is valid or not
    {
      return NULL;
    }
    // create the image structure (BMP_create)
    BMP_Image *input_image = BMP_create(&input_header);//use BMP_create to create a output_image structure

    // read all of the image data
    if(fread(input_image -> data, sizeof(char), input_image -> data_size, input_file) != input_image -> data_size)//use fread to read all the image data
    {
      fclose(input_file);//if not successful, close the file
      return NULL;
    }

    // return the image
    fclose(input_file);
    return input_image;
}

void BMP_invert(BMP_Image *image)
{
    // loop through each byte in the image data
    int lcv;//loop control variable of the for loop
    for(lcv = 0; lcv < image -> data_size; lcv++)
    {
      image -> data[lcv] = 255 - image -> data[lcv];//to reverse the color, use data = 255 - data
    }
}

int BMP_save(BMP_Image *image, const char *filename)
{
    // write the BMP header
    FILE * output_file = fopen(filename, "wb");//open the output file
    if(output_file == NULL)//check if has been opened
    {
      return 0;
    }

    if(fwrite(&(image -> header), sizeof(BMP_Header), 1, output_file) != 1)//check if it's been correctly written to the output file
    {
      fclose(output_file);
      return 0;
    }
    // write the image data
    if(fwrite(image -> data, sizeof(char), image -> data_size, output_file) != image -> data_size)//check if the output file has been correctly written
    {
      fclose(output_file);
      return 0;
    }

    fclose(output_file);//close files
    return 1;//1 means EXIT_SUCCESSFUL
}

// == DO NOT MODIFY ANYTHING BELOW THIS POINT ==============

int BMP_checkValid(BMP_Header *header)
{
    // Make sure this is a BMP file
    if (header->type != BMP_HEADER_TYPE) return 0;

    // Make sure we are getting 24 bits per pixel
    if (header->bits != BMP_HEADER_BITS) return 0;

    // Make sure there is only one image plane
    if (header->planes != BMP_HEADER_PLANE) return 0;

    // Make sure there is no compression
    if (header->compression != 0) return 0;

    return 1;
}

void BMP_printHeader(BMP_Header *header)
{
    printf("file type (should be %x): %x\n", BMP_HEADER_TYPE, header->type);
    printf("file size: %d\n", header->size);
    printf("offset to image data: %d\n", header->offset);
    printf("header size: %d\n", header->header_size);
    printf("width: %d\n", header->width);
    printf("height: %d\n", header->height);
    printf("planes: %d\n", header->planes);
    printf("bits: %d\n", header->bits);
}
