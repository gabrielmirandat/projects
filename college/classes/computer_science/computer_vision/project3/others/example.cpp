Mat img_1 = imread( "images/imgl.jpg", CV_LOAD_IMAGE_GRAYSCALE );
Mat img_2 = imread( "images/imgr.jpg", CV_LOAD_IMAGE_GRAYSCALE );


if( !img_1.data || !img_2.data )
{ return -1; }

//-- Step 1: Detect the keypoints using SURF Detector
int minHessian = 430;
SurfFeatureDetector detector( minHessian );
std::vector<keypoint> keypoints_1, keypoints_2;
detector.detect( img_1, keypoints_1 );
detector.detect( img_2, keypoints_2 );

//-- Step 2: Calculate descriptors (feature vectors)
SurfDescriptorExtractor extractor;
Mat descriptors_1, descriptors_2;
extractor.compute( img_1, keypoints_1, descriptors_1 );
extractor.compute( img_2, keypoints_2, descriptors_2 );




//-- Step 3: Matching descriptor vectors with a brute force matcher
BFMatcher matcher(NORM_L1, true);
std::vector< DMatch > matches;
matcher.match( descriptors_1, descriptors_2, matches );

//-- Draw matches
Mat img_matches;
drawMatches( img_1, keypoints_1, img_2, keypoints_2, matches, img_matches );
//-- Show detected matches
namedWindow( "Matches", CV_WINDOW_NORMAL );
imshow("Matches", img_matches );
waitKey(0);


//-- Step 4: calculate Fundamental Matrix
vector<point2f>imgpts1,imgpts2;
for( unsigned int i = 0; i<matches.size(); i++="" )="" {="" queryidx="" is="" the="" "left"="" image="" imgpts1.push_back(keypoints_1[matches[i].queryidx].pt);="" trainidx="" is="" the="" "right"="" image="" imgpts2.push_back(keypoints_2[matches[i].trainidx].pt);="" }="" mat="" f="findFundamentalMat" (imgpts1,="" imgpts2,="" fm_ransac,="" 0.1,="" 0.99);="" --="" step="" 5:="" calculate="" essential="" matrix="" double="" data[]="{1189.46" ,="" 0.0,="" 805.49,="" 0.0,="" 1191.78,="" 597.44,="" 0.0,="" 0.0,="" 1.0};="" camera="" matrix="" mat="" k(3,="" 3,="" cv_64f,="" data);="" mat_<double=""> E = K.t() * F * K; 

//-- Step 6: calculate Rotation Matrix and Translation Vector
Matx34d P;
//decompose E 
SVD svd(E,SVD::MODIFY_A);
Mat svd_u = svd.u;
Mat svd_vt = svd.vt;
Mat svd_w = svd.w;
Matx33d W(0,-1,0,1,0,0,0,0,1);//HZ 9.13
Mat_<double> R = svd_u * Mat(W) * svd_vt; //
Mat_<double> T = svd_u.col(2); //u3

if (!CheckCoherentRotation (R)) {
std::cout<<"resulting rotation is not coherent\n";
return 0;
}


//-- Step 7: Reprojection Matrix and rectification data
Mat R1, R2, P1_, P2_, Q;
Rect validRoi[2];
double dist[] = { -0.03432, 0.05332, -0.00347, 0.00106, 0.00000};
Mat D(1, 5, CV_64F, dist);

stereoRectify(K, D, K, D, img_1.size(), R, T, R1, R2, P1_, P2_, Q, CV_CALIB_ZERO_DISPARITY, 1, img_1.size(),  &validRoi[0], &validRoi[1] );