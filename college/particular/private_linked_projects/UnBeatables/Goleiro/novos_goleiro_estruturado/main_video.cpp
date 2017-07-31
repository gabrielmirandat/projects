#include "vision_implementation.hpp"

int main(int argc, char** argv)
{
    VS vs;
    
    VideoCapture cap(argv[1]);

    if (!cap.isOpened())
    {
      std::cout << "!!! Failed to open file: " << argv[1] << std::endl;
      return -1;
    }

    int choice = 0;
    cout << "Choose what you want:" << endl;
    cout << "0 - post detection - goalkeeper" << endl;
    cout << "1 - goal detection" << endl;
    cout << "2 - base line detection - goalkeeper:" << endl;
    cout << "3 - ball detection:" << endl;
    cin >> choice;

    switch(choice)
    {
      case 0: //-- post detection test
          for(;;)
          {
            Mat frame;
            if (!cap.read(frame))             
              break;
    
            imshow("frame",frame);
            //imwrite("frame.jpg", frame);
      
            bool ok = vs.detectPost(frame);
            if(ok)
              cout << "diffPosts: " << vs.getDiffPosts() << endl; 
            waitKey(33);
          }   
          break; 
      case 1: //-- goal detection test
          for(;;) 
          {
            Mat frame;
            if (!cap.read(frame))             
              break;
    
            imshow("frame",frame);
            //imwrite("frame.jpg", frame);
      
            bool ok = vs.detectGoal(frame);
            if(ok)
            {
              cout << "goalSize: " << vs.getGoalSize() << endl; 
              cout << "post1x: " << vs.getPost1x() << endl; 
              cout << "post2x: " << vs.getPost2x() << endl; 
            } 
          waitKey(33);
          }
          break;
      case 2: //-- base detection test
          for(;;)
          {
            Mat frame;
            if (!cap.read(frame))             
              break;
    
            imshow("frame",frame);
            //imwrite("frame.jpg", frame);
      
            bool ok = vs.detectBase(frame);
            if(ok)
              cout << "thetaBase: " << vs.getThetaBase() << " degrees: " << vs.getThetaBase()*180/CV_PI << endl;   
          waitKey(33);
          }
          break;
      case 3:
          for(;;)
          {
            Mat frame;
            if (!cap.read(frame))             
              break;
    
            imshow("frame",frame);
            //imwrite("frame.jpg", frame);
      
            bool ok = vs.detectBall(frame, DOWN);
            if(ok)
            {
                cout << "ballSide: " << vs.getBallSide() << endl;
                cout << "ballDist: " << vs.getBallDist() << "\n" << endl;
            }
          waitKey(33);
          }
          break;
      default: ;
    }

	return 0;
}