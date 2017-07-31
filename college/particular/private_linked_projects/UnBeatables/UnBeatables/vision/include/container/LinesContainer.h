#ifndef _LINESCONTAINER_H_
#define _LINESCONTAINER_H_

#include "../namespace/common.h"
#include "../namespace/image.h"
#include "../namespace/lines.h"

class LinesContainer
{

private: 
	//singletone constructor
	explicit LinesContainer();
	static LinesContainer* instance;

protected:
	std::vector<cv::Vec2f> lines_;

public:
	virtual ~LinesContainer();
	static LinesContainer* getInstance();

	inline void setLines(std::vector<cv::Vec2f>& lines){this->lines_ = lines;}
	inline std::vector<cv::Vec2f>& getLines(){ return this->lines_;}
};

#endif //_LINESCONTAINER_H_