#ifndef _FRAME_H_
#define _FRAME_H_

#include <iostream>
#include "namespace/userdefined"

class Frame
{
private:
   //variables
   std::string info_std_;
   int slast_;

   //functions
   void gen_random();

public:
	explicit Frame();
	virtual ~Frame();

	inline int const getInfo(){return this->info_;}
	inline int const getSlast(){return this->slast_;}
	inline void setSlast(int slast){this->slast = slast;}
};

#endif //_FRAME_H_