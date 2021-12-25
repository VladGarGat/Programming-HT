void rotation(const char* inpic = "rainbow.bmp", const char* outpic = "rainbow_rotated.bmp", int angle = 90)
{
    RgbImg iimg = readRgbImg(inpic);
    size_t hei = iimg.height, wid = iimg.width;
    while (angle >= 360)
    {
            angle -= 360;
    }
    if (angle == 90)
    {
        RgbImg oimg = createRgbImg(hei, wid, { 0, 0, 0 });
        for (size_t x = 0; x < wid; x++)
        {
            for (size_t y = 0; y < hei; y++)
            {
                oimg.pixels[wid - 1 - x][y] = iimg.pixels[y][x];
            }
        }
        writeRgbImg(outpic, oimg);
        deleteRgbImg(iimg);
        deleteRgbImg(oimg);
    }
    else if (angle == 180) {
    RgbImg oimg = createRgbImg(wid, hei, { 0, 0, 0 });
    for (size_t x = 0; x < wid; x++)
    {
        for (size_t y = 0; y < hei; y++)
        {
            oimg.pixels[y][x] = iimg.pixels[hei - y - 1][wid - x - 1];
        }
    }
    writeRgbImg(outpic, oimg);
    deleteRgbImg(iimg);
    deleteRgbImg(oimg);
    }
    else if (angle == 270) {
        RgbImg oimg = createRgbImg(hei, wid, { 0, 0, 0 });
        for (size_t x = 0; x < wid; x++)
        {
            for (size_t y = 0; y < hei; y++)
            {
                oimg.pixels[x][hei - 1 - y] = iimg.pixels[y][x];
            }
        }
        writeRgbImg(outpic, oimg);
        deleteRgbImg(iimg);
        deleteRgbImg(oimg);
    }
}
