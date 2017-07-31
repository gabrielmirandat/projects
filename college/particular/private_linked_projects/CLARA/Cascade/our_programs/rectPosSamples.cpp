#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <iostream>
#include <fstream>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

void help() {
	cout << "This is the program designed to help creating our cascade training dataset\n"
			"Usage:\n"
			"\t./haarFitInstrument <LOCAL/path/to/an/image/file>\n\n"

			"Obs: note that is highly recomended to use a local path from your working dir to the img file\n"
			"For our work, the recomendation is highly important\n\n"

			"The program shall stop on each image from the directory, waiting for the --> spacebar\n"
			"In the meanwhile, select the rectangle you want by dragging the mouse around it.\n\n"

			"When you`re done whith the frame, press the spacebar to call another one\n"
			"If you`re done whith the work, press 'esc' to quit the program\n\n"
	<< endl;
}
//---------- Functions

void onMouse( int, int, int, int, void * );

// 	Files
void createNewFile		( string );
void writeTxtFile 		( string, Rect );
vector<string> openDir 	( string );

// 	Strings
string getImageName		( string );
string getImagePrefix	( string );
string getPathName		( string );
string getTxtName		( string );
vector<string> listImages( string, string* );

//--------------------

//----Global Variables

Mat image;
string windowName;
size_t i;

// 	Selecting the rectangle
bool selectObject = false;
Rect selection;
Point origin;

// 	Write to file
string imgPath;
string txtName;

//--------------------

int main(int argc, char* argv[]) {
	help();

	string fullPath = argv[1];
	string PathName;
	
	char key;
	vector<string> ImageList;
	ImageList = listImages( fullPath, &PathName );

	//  File
    txtName = getTxtName( fullPath );
	txtName = PathName + txtName;
	createNewFile( txtName );
	
	for( i = 0; i < ImageList.size(); i++ )
	{
		imgPath = PathName + ImageList[i];

		cout << "Image Path: " << imgPath << endl;

		image = imread( imgPath );

		if( !image.data )
        	cout <<  "Could not open or find the image" << endl;
        else
        {
    		windowName = ImageList[i];

			imshow( windowName, image );

			setMouseCallback( windowName, onMouse, 0 );

			key = waitKey( 0 );
			if( key == 27 )
				break;
			else
				destroyWindow( windowName );
		}
	}

	return 0;
}

void onMouse(int event, int x, int y, int, void *){
    if (selectObject) 
    {
        selection.x = MIN( x, origin.x );
        selection.y = MIN( y, origin.y );
        selection.width = std::abs( x - origin.x );
        selection.height = std::abs( y - origin.y );
        selection &= Rect( 0, 0, 650, 500 );
    }

    switch (event) 
    {
    case CV_EVENT_LBUTTONDOWN:
        selectObject = true;
        origin = Point( x, y );
        selection = Rect( x, y, 0, 0 );
        break;
    case CV_EVENT_LBUTTONUP:
    	rectangle( image, selection, Scalar( 0, 0, 255 ), 1, 8, 0);
    	imshow( windowName, image );
        cout << selection << endl;
        writeTxtFile( txtName, selection );
        selectObject = false;
        break;
    }
}

void writeTxtFile ( string filename, Rect selected )
{
	ofstream dataFile;
	dataFile.open( filename.c_str(), ios::app );
    size_t quantity = 1;

	dataFile 	<< imgPath 							<< " \t" 
                << quantity                         << "\t"
				<< selected.x 						<< "\t" 
        		<< selected.y   					<< "\t" 
       			<< selected.x + selected.width   	<< "\t" 
        		<< selected.y + selected.width   	<< "\t" 
        		<< endl;
}

vector<string> openDir( string path = "." )
{

    DIR*    dir;
    dirent* pdir;
    std::vector<std::string> files;

    dir = opendir(path.c_str());

    while ( (pdir = readdir(dir) ) != NULL )
    {
        files.push_back(pdir->d_name);
    }
    
    return files;
}

void createNewFile( string filename )
{
    ofstream dataFile;
    dataFile.open ( filename.c_str(), ios::out );
    dataFile.close ();
}

string getImageName( string videoName )
{
    string imageName;
    imageName = videoName;

    size_t barra = imageName.find_last_of("/")+1;
    
    //cut off the path
    imageName.erase( imageName.begin(), imageName.begin() + barra );

    cout << "Image Name: " <<  imageName << endl;

    return( imageName );
}

string getImagePrefix( string videoName )
{
    string imageName;
    imageName = videoName;

    size_t barra = imageName.find_last_of( "/" ) + 1;
    
    //cut off the path
    imageName.erase( imageName.begin(), imageName.begin() + barra );

    size_t under_ = imageName.find_last_of( "_" );

    //cut off postfix
    imageName.erase( imageName.begin() + under_, imageName.end() );

    cout << "Image Name Prefix: " <<  imageName << endl;

    return( imageName );
}

string getPathName( string arg1 )
{
    string pathName;
    pathName = arg1;

    size_t barra = pathName.find_last_of( "/" ) + 1;
    
    //just the path
    pathName.erase( pathName.begin() + barra, pathName.end() );

    cout << "Path Name: " <<  pathName << endl;

    return( pathName );
}

string getTxtName( string arg1 )
{
	string txtFileName;

	txtFileName = getImagePrefix( arg1 );
	txtFileName += ".txt";
	//result: myfile.txt

	return txtFileName;
}

vector<string> listImages( string arg1, string *pathName )
{
	*pathName 	= getPathName( arg1 );
	string imagePrefix 	= getImagePrefix( arg1 );

	vector<string> fileNames = openDir( *pathName );
	vector<string> imgNames;

	for( int i = 0; i < fileNames.size(); i++ )
	{
		//Compare prefixes from cadidates to imgFile
		if( !( fileNames[i].compare( 0, imagePrefix.size(), imagePrefix ) ) )
		{
			imgNames.push_back( fileNames[i] ); 
		}
	}
	return imgNames;
}

