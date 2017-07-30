#include "CommunicateServo.hpp"


CommunicateServo::CommunicateServo(int width, int height, int lowVal, int highVal )
{

    //connect to host
    // this->socket_comm_.conn(LOCALHOST , PORT_SERVO);
    this->client_socket_ = new ClientSocket(LOCALHOST , PORT_SERVO);

    this->frame_width_ = width;
    this->frame_height_ = height;

    // Default commands
    this->commandX_ = 'Z';
    this->commandY_ = 'Z';
    this->oldCmd_X_ = 0; //null
    this->oldCmd_Y_ = 0; //null

    this->outerProp_ = lowVal;
    this->innerProp_ = highVal;

// cond
#if defined (OUTPUT_TEXT) || defined (OUTPUT_TEXT_COMM)
    std::cout<<"[COMM] CommunicateServo object created." << std::endl;
#endif
}

CommunicateServo::~CommunicateServo()
{
    delete client_socket_;

#if defined (OUTPUT_TEXT) || defined (OUTPUT_TEXT_COMM)
    std::cout << "[COMM] CommunicateServo object deleted." << std::endl;
#endif
}

void CommunicateServo::setPosition( int x, int y )
{
    this->x_pos_ = x;
    this->y_pos_ = y;
}

bool CommunicateServo::checkForChanges()
{
    if( (this->commandX_ != this->oldCmd_X_) || (this->commandY_ != this->oldCmd_Y_) )
        return true;
    else
        return false;
}

int CommunicateServo::setProportion( char oldCmd )
{
    if( oldCmd == 'Z' )
        return (this->outerProp_);
    
    return (this->innerProp_);
}

void CommunicateServo::setCommandX()
{
    int proportion;
    proportion = setProportion( this->oldCmd_X_ );

    int tolerance_x = this->x_pos_ - this->frame_width_/2;
    if( abs( tolerance_x ) > this->frame_width_/proportion )
        this->commandX_ = tolerance_x > 0 ? 'R' : 'L';
}

void CommunicateServo::setCommandY()
{
    int proportion;
    proportion = setProportion( this->oldCmd_Y_ );

    int tolerance_y = this->y_pos_ - this->frame_height_/2;
    if( abs( tolerance_y ) > this->frame_height_/proportion )
        this->commandY_ = tolerance_y > 0 ? 'D' : 'U';
}

void CommunicateServo::generateCommands()
{
    // Default commands
    this->commandX_ = 'Z';
    this->commandY_ = 'Z';
    setCommandX();
    setCommandY();
}

bool CommunicateServo::showCommands()
{
    if( checkForChanges() )
    {
#if defined (OUTPUT_TEXT) || defined (OUTPUT_TEXT_COMM)
        cout << "[COMM] go to! " << commandX_ << " " << commandY_ << "\n" << endl;
#endif

        char char_buffer[3];
        char_buffer[0] = this->commandX_;
        char_buffer[1] = this->commandY_;
        char_buffer[2] = '\0';

        // std::string reply;

        // Write to socket
         this->client_socket_->operator <<(char_buffer);
        // Read from socket
        // this->client_socket_->operator >>(reply);

#if defined (OUTPUT_TEXT) || defined (OUTPUT_TEXT_COMM)
        // std::cout << "[COMM] We received this response from the server:\n\"" << reply << "\"\n";
#endif

        return 0;
    }
    else
        return 1;
}

void CommunicateServo::atualize()
{
    this->oldCmd_X_ = this->commandX_;
    this->oldCmd_Y_ = this->commandY_;
}

void CommunicateServo::sendPosToServo(int prediction_x, int prediction_y)
{
    /* Comunicate it to servo motors */
    setPosition( prediction_x, prediction_y);
    generateCommands();
    showCommands();
    atualize();
}
