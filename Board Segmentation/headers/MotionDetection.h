//
// Created by charles on 2016/07/20.
//

#ifndef TRACK4K_MOTIONDETECTION_H
#define TRACK4K_MOTIONDETECTION_H

//opencv
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include "../../FileReader.h"

#include "../../MetaFrame.h"

//C
#include <stdio.h>
//C++
#include <iostream>
#include <sstream>

class MotionDetection {
public:
    // Global variables
    cv::Mat fgMaskMOG2; //fg mask fg mask generated by MOG2 method
    cv::Ptr<cv::BackgroundSubtractor> pMOG2; //MOG2 Background subtractor
    int keyboard; //input from keyboard

    void processVideo(MetaFrame &frame);
    std::vector<cv::Rect> boundMotion(cv::Mat threshold_output);

    int subtract(std::vector<cv::Mat> &frames, PersistentData &pD);
};

#endif //TRACK4K_MOTIONDETECTION_H