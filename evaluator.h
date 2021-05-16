#ifndef _evaluator_h_included_
#define _evaluator_h_included_
#pragma once

#include "testdata.h"

namespace expp
{

	template<typename T>
	class Evaluator
	{
	public:
		Evaluator(TestData& data);

		void calcCenterBasic();

		inline T const* getCenter() const { return m_center; }

	private:
		TestData& m_data;
		T m_center[4];

	};

}

#include "evaluator.inl"

#endif /* _evaluator_h_included_ */