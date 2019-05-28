#include <iostream>
#include <string>
#include "Image.hpp"

using namespace std;
int main(int agvc, const char *argv[]) {
    picture bmp;
    const char *file = argv[1];
    const char *result = argv[2];
    const char *buff = argv[3];
    int qwe = stoi(buff);
    bmp.readPicture(file);
    return 0;
}
