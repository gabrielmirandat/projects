#ifndef _STATICINFIELDENTITY_H_
#define _STATICINFIELDENTITY_H_

#include "FieldEntity.h"
// #include "container/LinesContainer.h"
// #include <boost/shared_ptr.hpp>

class StaticInFieldEntity : public FieldEntity
{

protected:
   /*boost::shared_ptr<LinesContainer> lines_container_;*/
   // LinesContainer* lines_container_;
	std::vector<cv::Vec2f> lines_;

public:
	explicit StaticInFieldEntity();
	virtual ~StaticInFieldEntity();

};

#endif //_STATICINFIELDENTITY_H_