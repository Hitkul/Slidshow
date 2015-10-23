#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv )
{
    

    char image_names[7][10]={"1.png\0","2.png\0","3.png\0","4.png\0","1.jpg\0","2.jpg\0","test.jpg\0"};
    int i,j;
    Mat imagesrc[7],imagedst[7],dst;
    
    Size size(800,800);

    for ( i = 0; i < 7; ++i){
        imagesrc[i] = imread( image_names[i], -1 );    
        
        if ( !imagesrc[i].data ){
            printf("No image data \n");
            return -1;
        }

        resize(imagesrc[i],imagedst[i],size);
    }
    
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    float alpha,beta;
    imshow("Display Image", imagedst[0]);
    waitKey(2500);

    for (i = 0; i < 7; ++i)
    {
        for (alpha = 1.0; alpha >=0; alpha-=0.01){
            beta=1.0-alpha;
            addWeighted( imagedst[i], alpha, imagedst[i+1], beta, 0.0, dst);
            imshow("Display Image", dst);
            waitKey(10);
        }

        imshow("Display Image", imagedst[i+1]);
        waitKey(2500);    
    }

    return 0;
}