#include "InFieldDetection.h"

InFieldDetection::InFieldDetection()
: is_running_(true), fe_(ENTITIES_SIZE), persistence()/*, lines_container_(LinesContainer::getInstance())*/
{
    
    // lines_container_ = LinesContainer::getInstance();
    fe_[0]= new Post();    //outfield           imagem crua
    fe_[1]= new Goal();    //outfield           imagem crua
    fe_[2]= new Enemie();  //outfield           imagem multiplicada
    fe_[3]= new Center();  //infield e imgBot   imagem crua
    fe_[4]= new Ball();    //infield e imgBot   imagem multiplicada
    fe_[5]= new Corner();  
    fe_[6]= new InLine();

	tupleSetter();

    #ifdef OBJECT
        std::cout<<"InFieldDetection object created." << std::endl;
    #endif
}

InFieldDetection* InFieldDetection::instance = NULL;

InFieldDetection* InFieldDetection::getInstance() 
{
    if(!instance) {
        instance = new InFieldDetection();
        // calculateBaseHistogram(image);
    }
    return instance;
}

InFieldDetection::~InFieldDetection()
{
    
    for(size_t i=0; i<ENTITIES_SIZE; i++)
        delete fe_[i];
    fe_.clear();

    // delete lines_container_;
    #ifdef OBJECT
        std::cout<<"InFieldDetection object destroyed." << std::endl;
    #endif
}


//private
void InFieldDetection::tupleSetter()
{
    this->tpl_min_hsv_field_ = boost::make_tuple(37, 92, 0);
    this->tpl_max_hsv_field_ = boost::make_tuple(86, 224, 255);

    //this->tpl_min_hsv_field_ = boost::make_tuple(54, 15, 38);
    //this->tpl_max_hsv_field_ = boost::make_tuple(90, 72, 61);

}

void InFieldDetection::imagesSetter(cv::Mat image)
{
    this->img_original_ = image;
    image::convert(image,this->img_gray_, CV_BGR2GRAY);
    image::convert(image,this->img_hsv_, CV_BGR2HSV);
    image::hsv(this->img_hsv_, this->img_hsv_field_in_, this->tpl_min_hsv_field_, this->tpl_max_hsv_field_);
    image::whiteRegion(this->img_gray_, this->img_lines_);

    //img_hsv_field_in_ and img_hsv_field_out_
    image::morphClosing(this->img_hsv_field_in_, image::ELLIPSE, 10);
    image::morphOpening(this->img_hsv_field_in_, image::ELLIPSE, 10);
    // image::negate(this->img_hsv_field_in_, this->img_hsv_field_out_);
    
    //this->img_infield_ and this->img_outfield_
    image::intersection(this->img_hsv_field_in_, this->img_lines_, this->img_infield_);
    // image::intersection(this->img_hsv_field_out_, this->img_lines_, this->img_outfield_);
}

// void InFieldDetection::calculateBaseHistogram(cv::Mat& image)
// {
//     cv::image_hsv;
//     cv::cvtColor( image, image_hsv, CV_BGR2HSV );

//     /// Using 50 bins for hue and 60 for saturation
//     int h_bins = 50; int s_bins = 60;
//     int histSize[] = { h_bins, s_bins };

//     // hue varies from 0 to 179, saturation from 0 to 255
//     float h_ranges[] = { 0, 180 };
//     float s_ranges[] = { 0, 256 };

//     calcHist( &hsv_base, 1, channels, Mat(), hist_base, 2, histSize, ranges, true, false );
    
    
//     cvtColor( Frame, hsv_base, CV_BGR2HSV );
//     int h_bins = 50; 
//     int s_bins = 60;
//     int v_bins = 10;
//     int histSize[] = { h_bins, s_bins, v_bins };

//     float h_ranges[] = { 0, 180 };
//     float s_ranges[] = { 0, 256 };
//     float v_ranges[] = { 0, 256 };

//     const float* ranges[] = { h_ranges, s_ranges, v_ranges };
//     int channels[] = { 0, 1, 2};
//     calcHist( &hsv_base, 1, channels, Mat(), hist_base, 3, histSize, ranges, true, false );
//     normalize( hist_base, hist_base, 0, 1, NORM_MINMAX, -1, Mat() );
// }

//public
bool InFieldDetection::isRunning()
{
    char key = cv::waitKey(33);
    if(key==27) this->is_running_=false;
    return this->is_running_;
}


void InFieldDetection::run(cv::Mat imageTop)
{
    //a separação de em cima do campo ou abaixo so vale pra imgTop
    //imgBot tá sempre abaixo do campo..
    //obtendo separação imgTop = {infield, outfield}

    //1.certifique que videos de teste e camera estão em 320x240
    //2.não por menor E igual nas restrições de linhas
    //3.limpar todas as variaveis de linhas usadas

    imagesSetter(imageTop);

    image::debug(this->img_original_,"Original");
}

void InFieldDetection::detectAll(bool cam_flag, float angle) {
    detectPost();
    detectBall();
    detectCorner();
    detectCenter();
    detectEnemy();
    detectGoal();
    detectInline();
}

void InFieldDetection::updatePersistence(bool cam_flag) {
    this->persistence.ball_distance_x = this->fe_[BALL]->getPosition().x;
    this->persistence.ball_distance_y = this->fe_[BALL]->getPosition().y;
    this->persistence.cam_flag =  cam_flag;
    //STILL MISSING INFORMATION
}
