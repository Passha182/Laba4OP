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
    
}

