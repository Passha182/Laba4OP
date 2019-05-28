#include "Image.hpp"
#include <iostream>
#include <fstream>
#include <string>

void picture::readPicture(const char *FileName){
    
    FILE *image = fopen(FileName, "rb");
    if (!image) {
        cout << "File could not be open\n";
        exit(1);
    }
    
    fread(&header.id, sizeof(header.id), 1, image);
    fread(&header.filesize, sizeof(header.filesize), 1, image);
    fread(&header.reserved, sizeof(header.reserved), 1, image);
    fread(&header.headersize, sizeof(header.headersize), 1, image);
    fread(&header.infoSize, sizeof(header.infoSize), 1, image);
    fread(&header.width, sizeof(header.width), 1, image);
    fread(&header.depth, sizeof(header.depth), 1, image);
    fread(&header.biPlanes, sizeof(header.biPlanes), 1, image);
    fread(&header.bits, sizeof(header.bits), 1, image);
    fread(&header.biCompression, sizeof(header.biCompression), 1, image);
    fread(&header.biSizeImage, sizeof(header.biSizeImage), 1, image);
    fread(&header.biXPelsPerMeter, sizeof(header.biXPelsPerMeter), 1, image);
    fread(&header.biYPelsPerMeter, sizeof(header.biYPelsPerMeter), 1, image);
    fread(&header.biClrUsed, sizeof(header.biClrUsed), 1, image);
    fread(&header.biClrImportant, sizeof(header.biClrImportant), 1, image);
    
    int check = (header.width * 3) % 4;
    int stride = 0;
    if (check) {
        stride = 4 - check;
    }
    
    array = new RGBQUAD*[header.depth];
    for (int i = 0; i < header.depth; i++) {
        array[i] = new RGBQUAD[header.width];
    }
    
    for (int i = 0; i < header.depth; i++) {
        for (int j = 0; j < header.width; j++) {
            fread(&array[i][j].blueComponent, 1, 1, image);
            fread(&array[i][j].greenComponent, 1, 1, image);
            fread(&array[i][j].redComponent, 1, 1, image);
        }
        if (stride != 0) {
            RGBQUAD empty;
            fread(&empty, 1, stride, image);
        }
    }
    fclose(image);

}

