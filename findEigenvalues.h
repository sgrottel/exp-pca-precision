#ifndef _findEigenvalues_h_included_
#define _findEigenvalues_h_included_
#pragma once

#include "extern/precision/math_Rational.h"
#include <array>

namespace expp
{

	template<unsigned int D, typename T>
	unsigned int findEigenvaluesSymReal
	(
		std::array<std::array<math::Rational, 4>, 4> const& covarMat,
		std::array<T, D>& outEigenvalues,
		std::array<std::array<T, D>, D>& outEigenvectors
	);

}

#include "findEigenvalues.inl"

#endif /* _findEigenvalues_h_included_ */
