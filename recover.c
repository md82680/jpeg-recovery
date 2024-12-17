#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int image_number = 0;
int main(int argc, char *argv[])
{
 if (argc != 2)
 {
    printf("Usage: ./recover image\n");
    return 1;
 }

 FILE *file = fopen(argv[1], "r");
 if (file == NULL)
 {
    printf("Could not open file.\n");
    return 1;
 }
 uint8_t buffer[512];
 FILE *img = NULL;
 while (fread(buffer, sizeof(uint8_t), 512, file) == 512)
 {
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        if (img != NULL)
        {
            fclose(img);
        }
        char filename[8];
        sprintf(filename, "%03i.jpg", image_number);
        img = fopen(filename, "w");
        image_number++;
    }
    if (img != NULL)
    {
        fwrite(buffer, sizeof(uint8_t), 512, img);
    }
 }
 if (img != NULL)
 {
    fclose(img);
 }
 printf("Total JPEG files created: %i\n", image_number);
 fclose(file);
 return 0;
}



