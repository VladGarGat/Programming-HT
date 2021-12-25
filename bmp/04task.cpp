#include "BmpStructures.h"
#include "ImgFunctions.h"
#include <iostream>
int main()
{
    size_t const kern2 = 5;
    size_t const kern1 = 3;
    double** kernel = new double* [kern1];
    kernel[0] = new double[kern1] {0, -1, 0};
    kernel[1] = new double[kern1] {-1, 5, -1};
    kernel[2] = new double[kern1] {0, -1, 0};

    RgbImg img = readRgbImg("kidsnoise.bmp");
    RgbImg filtered = convolution(img, kern2);
    RgbImg sharpened = convolution(filtered, kern1, kernel);
    writeRgbImg("filtered.bmp", filtered);
    writeRgbImg("sharpen.bmp", sharpened);
    deleteRgbImg(img);
    deleteRgbImg(filtered);
    deleteRgbImg(sharpened);
}
