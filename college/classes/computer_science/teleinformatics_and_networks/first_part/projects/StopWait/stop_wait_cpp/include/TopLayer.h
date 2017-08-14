#ifndef _TOPLAYER_H_
#define _TOPLAYER_H_

#include <iostream>
#include "TopLayer.h"
#include "Frame.h"
#include "namespace/userdefined"

class TopLayer
{
private:
   bool permission_;
   std::vector<Frame*> frame_list_;

public:
	explicit TopLayer(size_t number_bits);
	virtual ~TopLayer();

	inline bool const getPermission(){return this->permission_;}
	inline void setPermission(bool permission){this->permission = permission;}
	inline size_t const getFrameListNumber(){return frame_list_.size();} 

	boost::shared_ptr<Frame> const popFrame();
	void insertFrame(boost::shared_ptr<Frame>);
};

#endif //_TOPLAYER_H_