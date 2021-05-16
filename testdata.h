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

		const unsigned int getNumPoints() const;

		const math::Rational* getPoint(unsigned int i) const;

	};

}

#endif /* _testdata_h_included_ */