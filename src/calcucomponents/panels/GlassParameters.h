/*
 *Copyright 2020 X-prject authors
 *
 * BasicParameters.h (BasicParameters class)
 * 
 * */

#pragma once

#include "BasicParameters.h"
#include "grpc_basicParameters.pb.h"
#include "grpc_glass.grpc.pb.h"
#include <vector>

using Xproject::grpc_Glass;                                      
using Xproject::GlassRequest;
struct GlassParameters:public BasicParameters
{
	enum GlassType
	{
		ONE=0,
		HOLLOW=1,//ZHONG KONG
		LAMINATE=2,//JIA CENG
		HOLLOW_AND_LAMINATE=3,// ZHONG KONG + JIA CENG
		DOUBLEHOLLOW=4,// SHUANG ZHONG KONG
		DOUBLELAMINATE_AND_HOLLOW=5
	};

	enum GlassMaterial
	{
		FLAT=0,//PING BIAN
		TEMPERED=1,//GANG HUA
	};

	GlassParameters()=default;
	GlassParameters(const GlassRequest *pGlassRequest);

	virtual ~GlassParameters()=default;


	double m_height;
	double m_width;
	GlassMaterial m_eMat;

	std::vector<double>m_thickness;//bo li hou du (mm) (out->in)

	static const std::string GlassTypeStrs[6];

	virtual void print()override;
};
