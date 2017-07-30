/// @file
/// @brief Class representing the servo communicator
/// @attention Laboratório de Automação e Robótica (LARA)\n
/// Research laboratory from the University of Brasilia.
/// @attention CLARA project

#ifndef _CS_H_
#define _CS_H_

#include "iostream"
#include "tlayer.hpp"
#include "ClientSocket.hpp"

#define INNER_PROP 20       ///< Default inner proportion to consider a quadrant change
#define OUTER_PROP 10       ///< Default outer proportion to consider a quadrant change

/// @brief This Class realizes the interface between the instrument's tip pose estimation and the commands for the servo motors
/// @details Class designed to process position values acquired by CLARA computer vision systems and convert it to commands for the servo motors.
class CommunicateServo
{
private:
	int x_pos_;            ///< Integer value to store the x position of the tip
	int y_pos_;            ///< Integer value to store the y position of the tip
	int outerProp_;        ///< Inner proportion to consider a quadrant change
    int innerProp_;        ///< Outer proportion to consider a quadrant change
	char oldCmd_X_;        ///< Retains the old command character on the horizontal axis
	char oldCmd_Y_;        ///< Retains the old command character on the vertical axis

    // commands
    char commandX_;        ///< The actual command character on the horizontal axis
    char commandY_;        ///< The actual command character on the vertical axis

    int frame_width_;      ///< Stores the frame width as an integer value
    int frame_height_;     ///< Stores the frame height as an integer value

    ClientSocket* client_socket_;       ///< Socket client to communicate the servo motors

    ///
    /// @brief Check for changes of quadrants.
    /// @details Check for changes on the position of the instruments tip in the image. Only when a position chenges, we need to notify the servo motors.
    /// @return True when the quadrants remain the same, False otherwise.
    ///
    bool checkForChanges();
    ///
    /// @brief Based on the last command (oldCmd) returns the outerProp_ value, or the innerProp_.
    /// @details This decision is relevant, once the inner proportion is more restrained when compared to the outer proportion.
    ///          This dynamic is designed to allow an eaasy descentralization, and a more precise centralization process.
    /// @param Receives a character value corresponding to the old command sent.
    /// @return Returns the outerProp_ value when the last command was centralized ('Z'), or the innerProp_ otherwise.
    ///
    int setProportion( char );
    ///
    /// @brief According to the acquired x_pos_, this function decides which command to send to servo.
    /// @details Changes are made oon private variables of the class.
    ///
    void setCommandX();
    ///
    /// @brief According to the acquired y_pos_, this function decides which command to send to servo.
    /// @details Changes are made oon private variables of the class.
    ///
    void setCommandY();

public:
    ///
    /// @brief CommunicateServo class constructor.
    /// @details This constructor recives both image's width and height in order to set it's private variables frame_width_ and frame_height_.
    ///          The last two parameters correspond to the outerProp_ and innerProp_ values to consider a quadrant change on servo commands.
    ///          Their default values are the #define OUTER_PROP and INNER_PROP respectively.
    ///
    explicit CommunicateServo(int width, int height, int lowVal=OUTER_PROP, int highVal=INNER_PROP );
    ///
    /// @brief CommunicateServo class destructor.
    /// @details No operations are realized when destroying CommunicateServo object.
    ///
    virtual ~CommunicateServo();
    ///
    /// @brief Funtion designed to update class's private variables values x_pos_ and y_pos_.
    /// @param x, integer value to update class x_pos_.
    /// @param y, integer value to update class y_pos_.
    ///
	void setPosition( int x, int y );
    ///
    /// @brief Funtion called to generate commands based on stored values of x_pos_ and y_pos_.
    /// @details It calls private functions setCommandX and setCommandY to update the internal values of commandX_ and commandY_.
    ///
    void generateCommands();
    ///
    /// @brief Publish commands to the socket connection woth motors.
    /// @details This operation is only necessary when a command has changed. So, checkForChanges() is called before publishing.
    ///
	bool showCommands();
    ///
    /// @brief Atualizes oldCmd_X_ and oldCmd_Y_ according to stored values of commandX_ and commandY_.
    ///
	void atualize();
    ///
    /// @brief Main interface of class CommunicateServo. Realizes every necessary steps to recive intruments tip position and communicate it to the servo motors.
    /// @details Performs the function calls of setPosition(), generateCommands(), showCommands() and atualize().
    /// @param prediction_x, integer value for instruments tip's estimated X position.
    /// @param prediction_y, integer value for instruments tip's estimated Y position.
    ///
    void sendPosToServo(int prediction_x, int prediction_y);
};

#endif //_CS_H_
