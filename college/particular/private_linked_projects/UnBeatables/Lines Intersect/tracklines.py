import cv2
import cv2.cv
import cv
import numpy as np

#cap = cv2.VideoCapture(0)
while(1):
    
    line_threshold_theta_low = 0.03
    line_threshold_theta_high = 0.315
    houghLinesThreshold = 35
    close_threshold = 80
    
    # Take each frame
    size = 320,240
    #frame1 = np.zeros(size, dtype=np.uint8)
    #_, frame1 = cap.read()
    frame1 = cv2.imread('image1.jpeg')
    frame = cv2.cvtColor(frame1, cv2.COLOR_BGR2HSV)

    # Convert BGR to HSV
    #hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    img_gray = cv2.cvtColor(frame1, cv2.COLOR_RGB2GRAY)
    
    #edges = cv2.Canny(img_gray,50,150,apertureSize = 3)
    #lines = cv2.HoughLines(edges,1,np.pi/180,200)
        
    #Gaussian Blur
    #WHITETrackingFrames = cv2.blur(frame,(4,4))
    GREENTrackingFrames = cv2.blur(frame,(2,2))
    #GREENTrackingFrames = 255 - GREENTrackingFrames
    
    
    # define range of blue color in HSV
    #lower_white = np.array([5,0,30], dtype=np.uint8)
    #upper_white = np.array([75,35, 255], dtype=np.uint8)
    lower_green = np.array([35, 80, 0], dtype=np.uint8)
    upper_green = np.array([85, 210, 210], dtype=np.uint8)
    
    #Imagem
    #[70,110,0]
    #[85, 230, 255]
    #Camera nao iluminacao_low
    #[70,50,0]
    #[110, 175, 255]
    
    #Camera nao iluminacao_high
    #[70, 40, 0]
    #[110, 165, 255]
    
    # Threshold the HSV image to get only blue colors
    #WHITETrackingFrames = cv2.inRange(WHITETrackingFrames, lower_white, upper_white)
    GREENTrackingFrames = cv2.inRange(GREENTrackingFrames, lower_green, upper_green)
    GREENTrackingFrames = 255 - GREENTrackingFrames
    #def inverse(GREENTrackingFrames, GREENTrackingFramesInverse):
    #    GREENTrackingFrames = (255-GREENTrackingFrames)
    
    
    #Line Detection
    edges = cv2.Canny(GREENTrackingFrames,50,150,apertureSize = 3)
    lines = cv2.HoughLines(edges,1,np.pi/180,houghLinesThreshold)
    LINETrackingFrames = frame1.copy()
    
    x1 = []
    y1 = []
    x2 = []
    y2 = []
    
    k=0
    nLines=0
    param_list = []
    
    for rho,theta in lines[0]:
        flag = 0
        a = np.cos(theta)
        b = np.sin(theta)
        x0 = a*rho
        y0 = b*rho
        if k!=0:
            for n in range(0,k-1):
                if (abs(lines[0][n][1]-lines[0][k][1])/(np.pi) >= line_threshold_theta_high):
                    flag = 1
                    break
                if (abs(lines[0][n][1]-lines[0][k][1])/(np.pi) <= line_threshold_theta_low):
                    flag = 1
                    break
        if not flag:
            param_list.append([lines[0][k][0],lines[0][k][1]])
            x1.append(int(x0 + 400*(-b)))
            y1.append(int(y0 + 400*(a)))
            x2.append(int(x0 - 400*(-b)))
            y2.append(int(y0 - 400*(a)))
            cv2.line(LINETrackingFrames,(x1[nLines],y1[nLines]),(x2[nLines],y2[nLines]),(0,0,255),2)
            nLines+=1
        flag = 0 
        k+=1
    
    #Verify if the line is close
    line_is_close = 0
    
    for i in range(nLines):
        if (abs(param_list[i][1]) <= np.pi/2.5 and (np.tan(param_list[i][1])*(160-x1[i]))+y1[i]>=close_threshold):
            line_is_close = 1
            break
    
    #Find the lines intersections
    line_intersection = []
    k=0
    point_is_close = 0
    
    for i in range(nLines):
        for j in range(i+1,nLines):
            m1 = np.tan(param_list[j][1])
            n1 = param_list[j][0]/np.cos(param_list[j][1])
            m2 = np.tan(param_list[i][1])
            n2 = param_list[i][0]/np.cos(param_list[i][1])
            if param_list[i][1] != param_list[j][1]: #retas nao sao paralelas
                x_int = (m1*n2-n1*m2)/(m1-m2)
                y_int = (n1-n2)/(m1-m2)
                if(x_int>=0 and (x_int)<=360 and y_int>=0 and (y_int)<=240):
                    line_intersection.append([int(x_int),int(y_int)])
                    cv2.circle(LINETrackingFrames,(line_intersection[k][0],line_intersection[k][1]),3,(255,0,0),-1)
                    k+=1
                    if (y_int>=close_threshold):
                        point_is_close = 1

    print line_is_close,point_is_close

    cv2.imshow("frame",frame1)
    cv2.imshow("mask",LINETrackingFrames)
    cv2.imshow("mask1",GREENTrackingFrames)
    #cv2.imshow('res',res)
    k = cv2.waitKey(5) & 0xFF
    if k == 27:
        break

cv2.destroyAllWindows()
