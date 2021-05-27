#ifndef _testdata_h_included_
#define _testdata_h_included_
#pragma once

#include "math_Rational.h"
#include <cstdint>

namespace expp
{

	class TestData
	{
	public:

		unsigned int getNumPoints() const;

		math::Rational const * getPoint(unsigned int i) const;

	};

}

#endif /* _testdata_h_included_ */
