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
    CvCapture *capture;
    IplImage *frame;

    capture=cvCreateCameraCapture(0);
    cvNamedWindow("Webcam",0);

    CvVideoWriter *writer = NULL;
    char AviFileName[]="Output.avi";
    int AviForamt = 1;
    int FPS = 20;
    CvSize AviSize = cvSize(640,480);
    int AviColor = 1;
    writer=cvCreateVideoWriter(AviFileName, CV_FOURCC('P','I','M','1'), FPS,AviSize,AviColor);
	if(writer == NULL)
		printf("writer null..\n");

    int i=0;
    while(true)
    {
        frame = cvQueryFrame(capture);
        cvWriteFrame(writer,frame);

        cvShowImage("Webcam",frame);
        printf("%d\n",i);

        if(cvWaitKey(20)>0)     break;
        i++;
    }

    cvReleaseCapture(&capture);
    cvReleaseVideoWriter(&writer);
    cvDestroyWindow("Webcam");
}
