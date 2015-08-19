/*
	compile:
	gcc -o r1 record.c -lm `pkg-config --cflags --libs opencv` 

*/
#include <opencv/cv.h>
#include <opencv/highgui.h>
//#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    CvCapture *capture, *capture1;
    IplImage *frame;

    cvNamedWindow("Webcam",0);

    CvVideoWriter *writer = NULL, *writer1 = NULL;
    char AviFileName[]="Output.avi";
    int AviForamt = 1;
    int FPS = 20;
    CvSize AviSize = cvSize(640,480);
    int AviColor = 1;

    int i=0;

	capture = cvCaptureFromCAM(0);
	capture1 = cvCaptureFromCAM(1);

    while(true)
    {
        frame = cvQueryFrame(capture1);
        cvWriteFrame(writer1,frame);

        cvShowImage("Webcam",frame);
        printf("%d\n",i);

        if(cvWaitKey(20)>0)     break;
        i++;
    }

    cvReleaseCapture(&capture);
    cvReleaseVideoWriter(&writer);
    cvDestroyWindow("Webcam");
}
