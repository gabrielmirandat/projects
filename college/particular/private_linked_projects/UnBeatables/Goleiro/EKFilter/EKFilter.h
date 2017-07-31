////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author:      GU Zhaopeng <zpgu@nlpr.ia.ac.cn>
// Version:     0.0.1
// Date:        2009-12                                         
// Description:   A simple & clear OpenCV based Extended Kalman Filter abstract class implementation,
//                absolutely following standard EKF equations. Special thanks to the opensource project of
//                KFilter1.3. The code is still being tested£¬so I'll do the best to make sure the safety of them. 
//
//
// Copyright (C) 2009-2010 OpenPR 
// All rights reserved. 
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met: 
// 
//     * Redistributions of source code must retain the above copyright 
//       notice, this list of conditions and the following disclaimer. 
//     * Redistributions in binary form must reproduce the above copyright 
//       notice, this list of conditions and the following disclaimer in the 
//       documentation and/or other materials provided with the distribution. 
//     * Neither the name of OpenPR nor the names of its  
//       contributors may be used to endorse or promote products derived 
//       from this software without specific prior written permission. 
// 
// THIS SOFTWARE IS PROVIDED BY HOLDERS AND CONTRIBUTORS "AS IS" AND ANY 
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
// DISCLAIMED. IN NO EVENT SHALL HOLDER AND CONTRIBUTORS BE LIABLE FOR ANY 
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND 
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cv.h>
#include <cxcore.h>
#include <highgui.h>


/*!
 * \class EKFilter
 *
 * \brief
 *	This is the base abstract class of EKFilter, when using several functions should be overrided, pay attention to 
 *	the dimension of all the vectors, if never used make sure to set the dimension to at least 1.
 *
 * \author [GU Zhaopeng]
 * \date December 2009
 */
class EKFilter
{
public:
	EKFilter(void);
	~EKFilter(void);
public:
	////Dimensions
	//Dimension of State Vector
	int kalman_x_dimension;
	//Dimension of Measurement Vector
	int kalman_z_dimension;
	//Dimension of Control Vector
	int kalman_u_dimension;
	//Dimension of Process Noise Vector
	int kalman_w_dimension;
	//Dimension of Measurement Noise Vector
	int kalman_v_dimension;

	////Vectors
	//State Vector
	CvMat* kalman_x_last;
	CvMat* kalman_x_predicted;
	CvMat* kalman_x_updated;
	//Control Vector
	CvMat* kalman_u;
	//Measurement Vector
	CvMat* kalman_z;
	CvMat* kalman_z_predicted;
	////Matrices
	CvMat* kalman_P_last;
	CvMat* kalman_P_predicted;
	CvMat* kalman_P_updated;
	CvMat* kalman_A;						
	CvMat* kalman_W;
	CvMat* kalman_Q;
	CvMat* kalman_H;
	CvMat* kalman_V;
	CvMat* kalman_R;
	CvMat* kalman_S;
	CvMat* kalman_K;

public:
	
	////Auxiliary Functions
 	int CheckDimension(CvMat* M1,CvMat* M2);
	int GetSubMatrix(CvMat* M1,CvMat* M2,int start_row,int start_col);
	int SetSubMatrix(CvMat* M1,CvMat* M2,int start_row,int start_col);
	//Combine M1 M2 as [M1 M2]
	int RowCombineSubMatrix(CvMat* M1,CvMat* M2,CvMat* M3);
	//Combine M1 M2 as [M1;M2]
	int ColCombineSubMatrix(CvMat* M1,CvMat* M2,CvMat* M3);
	//Delete M1(:,col) from M1
	int DelCol(CvMat* M1,CvMat* M2,int col);
	//Delete M1(row,:) from M1
	int DelRow(CvMat* M1,CvMat* M2,int row);
	//Insert column V before col (0 based) 
	int InsertCol(CvMat* M1,CvMat* V,CvMat* M2,int col);
	//Insert column Vt before row (0 based) 
	int InsertRow(CvMat* M1,CvMat* Vt,CvMat* M2,int row);
	int OutputMat(CvMat* M,int order=0);
	
	////Output Matrices to Files
	int OutputMatFile(CvMat* M,char *filename,int num,int order=0);

	////Initialize Functions
	int SetDimensions(int x_dimension, 
		int u_dimension, 
		int z_dimension, 
		int w_dimension, 
		int v_dimension);
	int InitMatrices();
	int ClearMatrices();

	////EKF Working Functions
	
	//Set process noise Q & measurement noise R
	int Set_NoiseCovariance(CvMat *Q,CvMat* R);
	
	//f(x,u,0) 
	virtual int Get_x_predicted()=0;
	//A=df/dx 
	virtual int Get_A()=0;
	//W=df/dw
	virtual int Get_W()=0;
	
	//P-=A*P*At+W*Q*Wt
	int Get_P_predicted();
	
	//H=dz/dx
	virtual int Get_H()=0;
	//zk=h(xk-,0)
	virtual int Get_z_predicted()=0;
	
	//V=dh/dv
	virtual int Get_V()=0;
	//S=H*P-*Ht+V*R*Vt	V=I
	int Get_S();
	//K=P*Ht*S_inv
	int Get_K();
	
	//Set Measurement
	int Set_z(CvMat* z);

	//x_updated=x_predicted+K(z-z_predicted);
	int Get_x_updated();
	//P=(I-K*H)*P_predicted
	int Get_P_updated();

};
