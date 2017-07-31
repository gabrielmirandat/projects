////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author:      GU Zhaopeng <zpgu@nlpr.ia.ac.cn>
// Version:     0.0.1
// Date:        2009-12                                         
// Description:   A simple & clear OpenCV based Extended Kalman Filter abstract class implementation,
//                absolutely following standard EKF equations. Special thanks to the opensource project of
//                KFilter1.3. The code is still being tested，so I'll do the best to make sure the safety of them. 
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

#include "EKFilter.h"
#include <iostream>
#include <fstream>
using namespace std;

EKFilter::EKFilter(void)
{
	////Dimensions
	//Dimension of State Vector
	kalman_x_dimension=0;
	//Dimension of Measurement Vector
	kalman_z_dimension=0;
	//Dimension of Control Vector
	kalman_u_dimension=0;
	//Dimension of Process Noise Vector
	kalman_w_dimension=0;
	//Dimension of Measurement Noise Vector
	kalman_v_dimension=0;

	////Vectors
	//State Vector
	kalman_x_last=NULL;
	kalman_x_predicted=NULL;
	kalman_x_updated=NULL;
	//Control Vector
	kalman_u=NULL;
	//Measurement Vector
	kalman_z=NULL;
	kalman_z_predicted=NULL;

	////Matrices
	kalman_P_last=NULL;
	kalman_P_predicted=NULL;
	kalman_P_updated=NULL;
	kalman_A=NULL;
	kalman_W=NULL;
	kalman_Q=NULL;
	kalman_H=NULL;
	kalman_V=NULL;
	kalman_R=NULL;
	kalman_S=NULL;
	kalman_K=NULL;

}

EKFilter::~EKFilter(void)
{
	ClearMatrices();
}

int EKFilter::ClearMatrices()
{
	//if (!=NULL)
	//	cvReleaseMat(&);
	if (kalman_x_last!=NULL)
		cvReleaseMat(&kalman_x_last);
	if (kalman_x_predicted!=NULL)
		cvReleaseMat(&kalman_x_predicted);
	if (kalman_x_updated!=NULL)
		cvReleaseMat(&kalman_x_updated);
	if (kalman_u!=NULL)
		cvReleaseMat(&kalman_u);
	if (kalman_z!=NULL)
		cvReleaseMat(&kalman_z);
	if (kalman_z_predicted!=NULL)
		cvReleaseMat(&kalman_z_predicted);
	if (kalman_P_last!=NULL)
		cvReleaseMat(&kalman_P_last);
	if (kalman_P_predicted!=NULL)
		cvReleaseMat(&kalman_P_predicted);
	if (kalman_P_updated!=NULL)
		cvReleaseMat(&kalman_P_updated);
	if (kalman_A!=NULL)
		cvReleaseMat(&kalman_A);
	if (kalman_W!=NULL)
		cvReleaseMat(&kalman_W);
	if (kalman_Q!=NULL)
		cvReleaseMat(&kalman_Q);
	if (kalman_H!=NULL)
		cvReleaseMat(&kalman_H);
	if (kalman_V!=NULL)
		cvReleaseMat(&kalman_V);
	if (kalman_R!=NULL)
		cvReleaseMat(&kalman_R);
	if (kalman_S!=NULL)
		cvReleaseMat(&kalman_S);
	if (kalman_K!=NULL)
		cvReleaseMat(&kalman_K);

	return 0;
}

int EKFilter::SetDimensions(int x_dimension, int u_dimension, int z_dimension, int w_dimension, int v_dimension)
{
	kalman_x_dimension=x_dimension;
	kalman_u_dimension=u_dimension;
	kalman_z_dimension=z_dimension;
	kalman_w_dimension=w_dimension;
	kalman_v_dimension=v_dimension;

	return 0;
}

int EKFilter::CheckDimension(CvMat *M1,CvMat* M2)
{
	if (M1==NULL || M2==NULL)
		return -1;
	if (M1->cols!=M2->cols ||M1->rows!=M2->rows)
		return -1;

	return 0;
}

int EKFilter::InitMatrices()
{
	ClearMatrices();

	////Vectors
	//State Vector
	kalman_x_last=cvCreateMat(kalman_x_dimension,1,CV_32F);
	cvSetZero(kalman_x_last);
	kalman_x_predicted=cvCreateMat(kalman_x_dimension,1,CV_32F);
	cvSetZero(kalman_x_predicted);
	kalman_x_updated=cvCreateMat(kalman_x_dimension,1,CV_32F);
	cvSetZero(kalman_x_updated);
	//Control Vector
	kalman_u=cvCreateMat(kalman_u_dimension,1,CV_32F);
	cvSetZero(kalman_u);
	//Measurement Vector
	kalman_z=cvCreateMat(kalman_z_dimension,1,CV_32F);
	cvSetZero(kalman_z);
	kalman_z_predicted=cvCreateMat(kalman_z_dimension,1,CV_32F);
	cvSetZero(kalman_z_predicted);

	////Matrices
	kalman_P_last=cvCreateMat(kalman_x_dimension,kalman_x_dimension,CV_32F);
	cvSetZero(kalman_P_last);
	kalman_P_predicted=cvCreateMat(kalman_x_dimension,kalman_x_dimension,CV_32F);
	cvSetZero(kalman_P_predicted);
	kalman_P_updated=cvCreateMat(kalman_x_dimension,kalman_x_dimension,CV_32F);
	cvSetZero(kalman_P_updated);
	kalman_A=cvCreateMat(kalman_x_dimension,kalman_x_dimension,CV_32F);
	cvSetZero(kalman_A);
	kalman_W=cvCreateMat(kalman_x_dimension,kalman_w_dimension,CV_32F);
	cvSetZero(kalman_W);
	kalman_Q=cvCreateMat(kalman_w_dimension,kalman_w_dimension,CV_32F);
	cvSetZero(kalman_Q);
	kalman_H=cvCreateMat(kalman_z_dimension,kalman_x_dimension,CV_32F);
	cvSetZero(kalman_H);
	kalman_V=cvCreateMat(kalman_z_dimension,kalman_v_dimension,CV_32F);
	cvSetZero(kalman_V);
	kalman_R=cvCreateMat(kalman_v_dimension,kalman_v_dimension,CV_32F);
	cvSetZero(kalman_R);
	kalman_S=cvCreateMat(kalman_z_dimension,kalman_z_dimension,CV_32F);
	cvSetZero(kalman_S);
	kalman_K=cvCreateMat(kalman_x_dimension,kalman_z_dimension,CV_32F);
	cvSetZero(kalman_K);

	return 0;
}

int EKFilter::Set_NoiseCovariance(CvMat *Q,CvMat* R)
{
	if (NULL==Q || NULL==R)
		return -1;
	if (CheckDimension(Q,kalman_Q)!=0 || CheckDimension(R,kalman_R)!=0)
		return -1;
	cvCopy(R,kalman_R);
	cvCopy(Q,kalman_Q);
	return 0;
}

//int EKFilter::Get_x_predicted()
//{
//	cvCopy(kalman_x_last,kalman_x_predicted);
//	return 0;
//}

//int EKFilter::Get_A()
//{
//	cvSetIdentity(kalman_A);
//	return 0;
//}

//int EKFilter::Get_W()
//{
//	cvSetZero(kalman_W);
//	return 0;
//}

int EKFilter::Get_P_predicted()
{
	CvMat* kalman_At=cvCreateMat(kalman_A->cols,kalman_A->rows,CV_32F);
	CvMat* kalman_Wt=cvCreateMat(kalman_W->cols,kalman_W->rows,CV_32F);
	CvMat* kalman_A_x_P=cvCreateMat(kalman_A->rows,kalman_P_last->cols,CV_32F);
	CvMat* kalman_A_x_P_x_At=cvCreateMat(kalman_A->rows,kalman_A->rows,CV_32F);
	CvMat* kalman_W_x_Q=cvCreateMat(kalman_W->rows,kalman_Q->cols,CV_32F);
	CvMat* kalman_W_x_Q_x_Wt=cvCreateMat(kalman_W->rows,kalman_W->rows,CV_32F);

	cvTranspose(kalman_A,kalman_At);
	cvTranspose(kalman_W,kalman_Wt);
	cvMatMul(kalman_A,kalman_P_last,kalman_A_x_P);
	cvMatMul(kalman_A_x_P,kalman_At,kalman_A_x_P_x_At);
	cvMatMul(kalman_W,kalman_Q,kalman_W_x_Q);
	cvMatMul(kalman_W_x_Q,kalman_Wt,kalman_W_x_Q_x_Wt);

	cvAdd(kalman_A_x_P_x_At,kalman_W_x_Q_x_Wt,kalman_P_predicted);

	cvReleaseMat(&kalman_At);
	cvReleaseMat(&kalman_Wt);
	cvReleaseMat(&kalman_A_x_P);
	cvReleaseMat(&kalman_A_x_P_x_At);
	cvReleaseMat(&kalman_W_x_Q);
	cvReleaseMat(&kalman_W_x_Q_x_Wt);

	return 0;
}

int EKFilter::Set_z(CvMat* z)
{
	if (CheckDimension(z,kalman_z)!=0)
		return -1;
	//cvmCopy(z,kalman_z);
	cvReleaseMat(&kalman_z);
	kalman_z=cvCloneMat(z);
	return 0;
}

//int EKFilter::Get_z_predicted()
//{
//	return 0;
//}

//int EKFilter::Get_H()
//{
//	cvSetZero(kalman_H);
//	return 0;
//}

int EKFilter::Get_S()
{
	////Debug 
	//OutputMat(kalman_V);

	CvMat* kalman_Ht=cvCreateMat(kalman_H->cols,kalman_H->rows,CV_32F);
	CvMat* kalman_Vt=cvCreateMat(kalman_V->cols,kalman_V->rows,CV_32F);
	CvMat* kalman_H_x_P=cvCreateMat(kalman_H->rows,kalman_P_predicted->cols,CV_32F);
	CvMat* kalman_H_x_P_x_Ht=cvCreateMat(kalman_H->rows,kalman_H->rows,CV_32F);
	CvMat* kalman_V_x_R=cvCreateMat(kalman_V->rows,kalman_R->cols,CV_32F);
	CvMat* kalman_V_x_R_x_Vt=cvCreateMat(kalman_V->rows,kalman_V->rows,CV_32F);

	cvTranspose(kalman_H,kalman_Ht);
	cvTranspose(kalman_V,kalman_Vt);
	cvMatMul(kalman_H,kalman_P_predicted,kalman_H_x_P);
	cvMatMul(kalman_H_x_P,kalman_Ht,kalman_H_x_P_x_Ht);
	cvMatMul(kalman_V,kalman_R,kalman_V_x_R);
	cvMatMul(kalman_V_x_R,kalman_Vt,kalman_V_x_R_x_Vt);

	cvAdd(kalman_H_x_P_x_Ht,kalman_V_x_R_x_Vt,kalman_S);


	////Debug 
	//OutputMat(kalman_P_predicted);
	//OutputMat(kalman_H);
	//OutputMat(kalman_Ht);
	//OutputMat(kalman_V);
	//OutputMat(kalman_R);
	//OutputMat(kalman_Vt);
	//OutputMat(kalman_S);

	cvReleaseMat(&kalman_Ht);
	cvReleaseMat(&kalman_Vt);
	cvReleaseMat(&kalman_H_x_P);
	cvReleaseMat(&kalman_H_x_P_x_Ht);
	cvReleaseMat(&kalman_V_x_R);
	cvReleaseMat(&kalman_V_x_R_x_Vt);

	return 0;
}

int EKFilter::Get_K()
{



	CvMat* kalman_Ht=cvCreateMat(kalman_H->cols,kalman_H->rows,CV_32F);
	CvMat* kalman_Sinv=cvCreateMat(kalman_S->cols,kalman_S->rows,CV_32F);
	CvMat* kalman_P_x_Ht=cvCreateMat(kalman_P_predicted->rows,kalman_Ht->cols,CV_32F);

	cvTranspose(kalman_H,kalman_Ht);
	cvInvert(kalman_S,kalman_Sinv);
	cvMatMul(kalman_P_predicted,kalman_Ht,kalman_P_x_Ht);
	cvMatMul(kalman_P_x_Ht,kalman_Sinv,kalman_K);

	////Debug
	//cout<<"kalman_P_predicted"<<endl;
	//OutputMat(kalman_P_predicted);
	//cout<<"kalman_H"<<endl;
	//OutputMat(kalman_H);
	//cout<<"kalman_S"<<endl;
	//OutputMat(kalman_S);
	//cout<<"kalman_Ht"<<endl;
	//OutputMat(kalman_Ht);
	//cout<<"kalman_K"<<endl;
	//OutputMat(kalman_K);

	cvReleaseMat(&kalman_Sinv);
	cvReleaseMat(&kalman_Ht);
	cvReleaseMat(&kalman_P_x_Ht);

	return 0;
}

int EKFilter::Get_x_updated()
{
	CvMat* kalman_z_minus_z_predicted=cvCreateMat(kalman_z_dimension,1,CV_32F);
	CvMat* kalman_K_x_z_minus_z_predicted=cvCreateMat(kalman_K->rows,1,CV_32F);

	cvmSub(kalman_z,kalman_z_predicted,kalman_z_minus_z_predicted);
	cvMatMul(kalman_K,kalman_z_minus_z_predicted,kalman_K_x_z_minus_z_predicted);
	cvmAdd(kalman_x_predicted,kalman_K_x_z_minus_z_predicted,kalman_x_updated);

	////Debug
	//cout<<"kalman_z_minus_z_predicted"<<endl;
	//OutputMat(kalman_z_minus_z_predicted);
	//cout<<"kalman_K_x_z_minus_z_predicted"<<endl;
	//OutputMat(kalman_K_x_z_minus_z_predicted);
	//cout<<"kalman_x_predicted"<<endl;
	//OutputMat(kalman_x_predicted);
	//cout<<"kalman_x_updated"<<endl;
	//OutputMat(kalman_x_updated);


	cvReleaseMat(&kalman_z_minus_z_predicted);
	cvReleaseMat(&kalman_K_x_z_minus_z_predicted);

	return 0;
}

int EKFilter::Get_P_updated()
{
	CvMat* kalman_I=cvCreateMat(kalman_P_predicted->rows,kalman_P_predicted->rows,CV_32F);
	CvMat* kalman_K_x_H=cvCreateMat(kalman_K->rows,kalman_H->cols,CV_32F);
	CvMat* kalman_I_minus_K_x_H=cvCreateMat(kalman_K_x_H->rows,kalman_K_x_H->cols,CV_32F);

	cvMatMul(kalman_K,kalman_H,kalman_K_x_H);
	cvSetIdentity(kalman_I);
	cvmSub(kalman_I,kalman_K_x_H,kalman_I_minus_K_x_H);
	cvMatMul(kalman_I_minus_K_x_H,kalman_P_predicted,kalman_P_updated);

	//Make sure kalman_P_updated is symmetric
	for (int row=0;row<kalman_P_updated->rows;row++)
	{
		for (int col=row;col<kalman_P_updated->cols;col++)
		{
			double tmp;
			tmp=cvmGet(kalman_P_updated,row,col)+cvmGet(kalman_P_updated,col,row);
			tmp=tmp/2;
			cvmSet(kalman_P_updated,row,col,tmp);
			cvmSet(kalman_P_updated,col,row,tmp);
		}
	}
	//CvMat* P_half=cvCreateMat(kalman_P_updated->rows,kalman_P_updated->cols,CV_32F);
	//CvMat* P_half_t=cvCreateMat(kalman_P_updated->cols,kalman_P_updated->rows,CV_32F);

	//for (int row=0;row<kalman_P_updated->rows;row++)
	//{
	//	for (int col=0;col<kalman_P_updated->cols;col++)
	//	{
	//		cvmSet(P_half,row,col,0.5*cvmGet(kalman_P_updated,row,col));
	//	}
	//}

	//cvTranspose(P_half,P_half_t);

	//cvAdd(P_half,P_half_t,kalman_P_updated);

	////Debug
	//OutputMat(kalman_K);cout<<endl;
	//OutputMat(kalman_H);cout<<endl;
	//OutputMat(kalman_I);cout<<endl;
	//OutputMat(kalman_I_minus_K_x_H);cout<<endl;
	//OutputMat(kalman_P_updated);cout<<endl;

	//cvReleaseMat(&P_half);
	//cvReleaseMat(&P_half_t);

	cvReleaseMat(&kalman_I);
	cvReleaseMat(&kalman_K_x_H);
	cvReleaseMat(&kalman_I_minus_K_x_H);

	return 0;
}

int EKFilter::OutputMat(CvMat* M,int order)
{
	if (order==0)
		for (int row=0;row<M->rows;row++)
		{
			for (int col=0;col<M->cols;col++)
			{
				cout<<cvmGet(M,row,col)<<" ";
			}
			cout<<endl;
		}
	else
		for (int col=0;col<M->cols;col++)
		{
			for (int row=0;row<M->rows;row++)
			{
				cout<<cvmGet(M,row,col)<<" ";
			}
			cout<<endl;
		}
	return 0;
}

int EKFilter::GetSubMatrix(CvMat* M1,CvMat* M2,int start_row,int start_col)
{
	assert(start_row+M2->rows<=M1->rows);
	assert(start_col+M2->cols<=M1->cols);
	//assert(M1->type==M2->type);
	CvMat *submatheader=cvCreateMatHeader(M2->rows,M2->cols,M2->type);
	cvGetSubRect(M1,submatheader,cvRect(start_col,start_row,submatheader->cols,submatheader->rows));
	cvCopy(submatheader,M2);
	cvReleaseMat(&submatheader);
	return 0;
}

int EKFilter::SetSubMatrix(CvMat* M1,CvMat* M2,int start_row,int start_col)
{
	assert(start_row+M2->rows<=M1->rows);
	assert(start_col+M2->cols<=M1->cols);
	//assert(M1->type==M2->type);
	CvMat *submatheader=cvCreateMatHeader(M2->rows,M2->cols,M2->type);
	cvGetSubRect(M1,submatheader,cvRect(start_col,start_row,submatheader->cols,submatheader->rows));
	cvCopy(M2,submatheader);
	cvReleaseMat(&submatheader);
	return 0;
}

//Combine M1 M2 as [M1 M2]
int EKFilter::RowCombineSubMatrix(CvMat* M1,CvMat* M2,CvMat* M3)
{
	if (M1->rows!=M2->rows)
		return -1;
	SetSubMatrix(M3,M1,0,0);
	SetSubMatrix(M3,M2,0,M1->cols);
	return 0;
}

//Combine M1 M2 as [M1;M2]
int EKFilter::ColCombineSubMatrix(CvMat* M1,CvMat* M2,CvMat* M3)
{
	if (M1->cols!=M2->cols)
		return -1;
	SetSubMatrix(M3,M1,0,0);
	SetSubMatrix(M3,M2,M1->rows,0);
	return 0;
}

int EKFilter::DelCol(CvMat* M1,CvMat* M2,int col)
{
	assert(col>=0 && col<M1->cols);
	assert(M1->cols>1);
	assert(M1->rows==M2->rows && M1->cols==M2->cols+1);
	if (col>0 && col<M1->cols-1)
	{
		//Submatrix header of M1
		CvMat* submatheader1_left=cvCreateMatHeader(M1->rows,col,M1->type);
		CvMat* submatheader1_right=cvCreateMatHeader(M1->rows,M1->cols-col-1,M1->type);
		//Submatrix header of M2	
		CvMat* submatheader2_left=cvCreateMatHeader(M2->rows,col,M1->type);
		CvMat* submatheader2_right=cvCreateMatHeader(M2->rows,M1->cols-col-1,M1->type);
		
		//Get them
		cvGetSubRect(M1,submatheader1_left,cvRect(0,0,col,M1->rows));
		cvGetSubRect(M1,submatheader1_right,cvRect(col+1,0,M1->cols-col-1,M1->rows));

		cvGetSubRect(M2,submatheader2_left,cvRect(0,0,col,M2->rows));
		cvGetSubRect(M2,submatheader2_right,cvRect(col,0,submatheader1_right->cols,M2->rows));

		cvCopy(submatheader1_left,submatheader2_left);
		cvCopy(submatheader1_right,submatheader2_right);

		cvReleaseMat(&submatheader1_left);
		cvReleaseMat(&submatheader1_right);
		cvReleaseMat(&submatheader2_left);
		cvReleaseMat(&submatheader2_right);
	}
	if (col==0)
	{
		//Submatrix header of M1
		CvMat* submatheader1_right=cvCreateMatHeader(M1->rows,M1->cols-1,M1->type);
		//Get them
		cvGetSubRect(M1,submatheader1_right,cvRect(1,0,M1->cols-1,M1->rows));
		cvCopy(submatheader1_right,M2);
		cvReleaseMat(&submatheader1_right);
	}
	if (col==M1->cols-1)
	{
		//Submatrix header of M1
		CvMat* submatheader1_left=cvCreateMatHeader(M1->rows,M1->cols-1,M1->type);
		//Get them
		cvGetSubRect(M1,submatheader1_left,cvRect(0,0,M1->cols-1,M1->rows));
		cvCopy(submatheader1_left,M2);
		cvReleaseMat(&submatheader1_left);
	}
	return 0;
}

int EKFilter::DelRow(CvMat* M1,CvMat* M2,int row)
{
	assert(row>=0 && row<M1->rows);
	assert(M1->rows>1);
	assert(M1->cols==M2->cols && M1->rows==M2->rows+1);

	if (row>0 && row<M1->rows-1)
	{
		//Submatrix header of M1
		CvMat* submatheader1_up=cvCreateMatHeader(row,M1->cols,M1->type);
		CvMat* submatheader1_down=cvCreateMatHeader(M1->rows-row-1,M1->cols,M1->type);
		//Submatrix header of M2	
		CvMat* submatheader2_up=cvCreateMatHeader(row,M1->cols,M1->type);
		CvMat* submatheader2_down=cvCreateMatHeader(M1->rows-row-1,M1->cols,M1->type);

		//Get them
		cvGetSubRect(M1,submatheader1_up,cvRect(0,0,M1->cols,row));
		cvGetSubRect(M1,submatheader1_down,cvRect(0,row+1,M1->cols,M1->rows-row-1));

		cvGetSubRect(M2,submatheader2_up,cvRect(0,0,M2->cols,row));
		cvGetSubRect(M2,submatheader2_down,cvRect(0,row,M2->cols,submatheader1_down->rows));

		cvCopy(submatheader1_up,submatheader2_up);
		cvCopy(submatheader1_down,submatheader2_down);

		cvReleaseMat(&submatheader1_up);
		cvReleaseMat(&submatheader1_down);
		cvReleaseMat(&submatheader2_up);
		cvReleaseMat(&submatheader2_down);
	}
	if (row==0)
	{
		//Submatrix header of M1
		CvMat* submatheader1_down=cvCreateMatHeader(M1->rows-1,M1->cols,M1->type);
		//Get them
		cvGetSubRect(M1,submatheader1_down,cvRect(0,1,M1->cols,M1->rows-1));
		cvCopy(submatheader1_down,M2);
		cvReleaseMat(&submatheader1_down);
	}
	if (row==M1->rows-1)
	{
		//Submatrix header of M1
		CvMat* submatheader1_up=cvCreateMatHeader(M1->rows-1,M1->cols,M1->type);
		//Get them
		cvGetSubRect(M1,submatheader1_up,cvRect(0,0,M1->cols,M1->rows-1));
		cvCopy(submatheader1_up,M2);
		cvReleaseMat(&submatheader1_up);
	}
	return 0;
}

int EKFilter::InsertCol(CvMat* M1,CvMat* V,CvMat* M2,int col)
{
	assert(col>=0 && col<=M1->cols);
	assert(M1->rows==M2->rows && M1->cols+1==M2->cols);
	assert(V->cols==1 && V->rows==M1->rows);

	if (col>0 && col<M1->cols)
	{
		//Submatrix header of M1
		CvMat* submatheader1_left=cvCreateMatHeader(M1->rows,col,M1->type);
		CvMat* submatheader1_right=cvCreateMatHeader(M1->rows,M1->cols-col,M1->type);
		//Get them
		cvGetSubRect(M1,submatheader1_left,cvRect(0,0,col,M1->rows));
		cvGetSubRect(M1,submatheader1_right,cvRect(col,0,M1->cols-col,M1->rows));

		SetSubMatrix(M2,submatheader1_left,0,0);
		SetSubMatrix(M2,submatheader1_right,0,col+1);
		SetSubMatrix(M2,V,0,col);

		cvReleaseMat(&submatheader1_left);
		cvReleaseMat(&submatheader1_right);
	}
	if (col==0)
	{
		RowCombineSubMatrix(V,M1,M2);
	}
	if (col==M1->cols)
	{
		RowCombineSubMatrix(M1,V,M2);
	}
	return 0;
}

int EKFilter::InsertRow(CvMat* M1,CvMat* Vt,CvMat* M2,int row)
{
	assert(row>=0 && row<=M1->rows);
	assert(M1->cols==M2->cols && M1->rows+1==M2->rows);
	assert(Vt->cols==M1->cols && Vt->rows==1);
	if (row>0 && row<M1->rows)
	{
		//Submatrix header of M1
		CvMat* submatheader1_up=cvCreateMatHeader(row,M1->cols,M1->type);
		CvMat* submatheader1_down=cvCreateMatHeader(M1->rows-row,M1->cols,M1->type);
		//Get them
		cvGetSubRect(M1,submatheader1_up,cvRect(0,0,M1->cols,row));
		cvGetSubRect(M1,submatheader1_down,cvRect(0,row,M1->cols,M1->rows-row));

		SetSubMatrix(M2,submatheader1_up,0,0);
		SetSubMatrix(M2,submatheader1_down,row+1,0);
		SetSubMatrix(M2,Vt,row,0);
		cvReleaseMat(&submatheader1_up);
		cvReleaseMat(&submatheader1_down);
	}
	if (row==0)
	{
		ColCombineSubMatrix(Vt,M1,M2);
	}
	if (row==M1->rows)
	{
		ColCombineSubMatrix(M1,Vt,M2);
	}
	return 0;
}

int EKFilter::OutputMatFile(CvMat* M,char *filename,int num,int order)
{
	ofstream outputfile;
	outputfile.open(filename,ios::app);
	if (!outputfile)
	{
		cout<<filename<<" open error!"<<endl;
		return 1;
	}

	outputfile<<"Iteration Number:"<<num<<endl;

	if (order==0)
	{
		for (int row=0;row<M->rows;row++)
		{
			for (int col=0;col<M->cols;col++)
			{
				outputfile<<cvmGet(M,row,col)<<" ";
			}
			outputfile<<endl;
		}
	}
	else
	{
		for (int col=0;col<M->cols;col++)
		{
			for (int row=0;row<M->rows;row++)
			{
				outputfile<<cvmGet(M,row,col)<<" ";
			}
			outputfile<<endl;
		}
	}
	outputfile.close();
	return 0;
}
