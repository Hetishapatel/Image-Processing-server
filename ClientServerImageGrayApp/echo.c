/*
 * echo - read and echo text lines until client closes connection
 */
/* $begin echo */
#include "csapp.h"
#include "opencv2/opencv.hpp"
#define BUFSIZEMAX 15*1024

using namespace cv;

void echo(int connfd) 
{
    char imageName[] = "godzillagrayjpg.jpg";
    size_t n; 
    FILE *fw;
    fw = fopen(imageName , "wb+" );
    char buf[BUFSIZEMAX]; 
    rio_t rio;

    Rio_readinitb(&rio, connfd);
    Rio_readnb(&rio, buf, BUFSIZEMAX);
    fwrite(buf , 1 , BUFSIZEMAX, fw);
    fclose(fw);

    Mat image;
    image = imread( imageName, 1 );
    
    if(!image.data )
    {
        printf( " No image data \n " );
        // return -1;
    }

    Mat gray_image;
    cvtColor( image, gray_image, COLOR_BGR2GRAY );

    imwrite( "Gray_Image.jpg", gray_image );

    namedWindow( imageName, WINDOW_AUTOSIZE );
    namedWindow( "Gray image", WINDOW_AUTOSIZE );

    imshow( imageName, image );
    imshow( "Gray image", gray_image );

    waitKey(0);
}
/* $end echo */