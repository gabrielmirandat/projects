#include "Communicator.hpp"

Communicator::Communicator(int width, int height)
{
    this->servo_comm_ = new CommunicateServo(width, height);

    // connect to host
    this->client_socket_ = new ClientSocket(LOCALHOST, PORT_FRAME);

    // begins server
    this->server_socket_ = new ServerSocket(PORT_STATE);

#if defined (OUTPUT_TEXT) || defined (OUTPUT_TEXT_COMM)
        std::cout<<"[COMM] Communicator object created." << std::endl;
#endif
}

Communicator::~Communicator()
{
    delete this->servo_comm_;
    delete this->client_socket_;
    delete this->server_socket_;

#if defined (OUTPUT_TEXT) || defined (OUTPUT_TEXT_COMM)
    std::cout<<"[COMM] Communicator object destroyed." << std::endl;
#endif
}

void Communicator::sendMatToGui(cv::Mat image)
{
    // std::string reply;
    // write to socket
     this->client_socket_->operator <<(image);
    // read from socket
    // this->client_socket_->operator >>(reply);

#if defined (OUTPUT_TEXT) || defined (OUTPUT_TEXT_COMM)
    // std::cout << "[COMM] We received this response from the server:\n\"" << reply << "\"\n";
#endif
}

void Communicator::sendPosToServo(int x, int y)
{
    this->servo_comm_->sendPosToServo(x,y);
}

char Communicator::rcvStateFromGui()
{
    ServerSocket handler_socket;
    this->server_socket_->accept(handler_socket);
    char state;

    // read from socket
    handler_socket >> state;
#if defined (OUTPUT_TEXT) || defined (OUTPUT_TEXT_COMM)
    std::cout << "[COMM] Server received state from client: " << state << std::endl;
#endif

    return state;

}


