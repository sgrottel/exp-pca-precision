#ifndef _printHelper_h_included_
#define _printHelper_h_included_
#pragma once

#include "myIter.h"

#include "math_Rational.h"

#include <iostream>
#include <iomanip>
#include <array>
#include <cassert>

namespace expp
{

	/// <summary>
	/// Pretty print math::Rational
	/// </summary>
	class ViewR {
	public:
		inline ViewR(math::Rational const& r) : m_r(r) {}
		inline math::Rational const& r() const { return m_r; }
	private:
		ViewR& operator=(ViewR const& s);

		math::Rational const& m_r;

		template<typename ts>
		friend ts& operator<<(ts& s, ViewR const& v);
	};

	template<typename ts>
	ts& operator<<(ts& s, ViewR const& v) {
		return s << std::fixed << std::setprecision(20) << v.r().to_double() << " (" << v.m_r << ")";
	}

	/// <summary>
	/// Print a linear myIter
	/// </summary>
	template<typename ts, typename t>
	void printMyIter(ts& s, MyIter<t> const& it)
	{
		typename MyIter<t>::const_iterator end = it.end();
		for (typename MyIter<t>::const_iterator i = it.begin(); i != end; ++i)
		{
			s << "\t" << ViewR(*i) << "\n";
		}
	}

	template <typename T, typename T1, typename T2>
	math::Rational reportMyIterDiff(
		expp::MyIter<T1> const& vals,
		expp::MyIter<T2> const& base
	)
	{
		math::Rational maxDiff(0);

		typename expp::MyIter<T1>::const_iterator valsEnd = vals.end();
		typename expp::MyIter<T2>::const_iterator baseEnd = base.end();
		typename expp::MyIter<T1>::const_iterator valsIt = vals.begin();
		typename expp::MyIter<T2>::const_iterator baseIt = base.begin();

		for (; valsIt != valsEnd; ++valsIt, ++baseIt)
		{
			T tDiff = *valsIt - static_cast<T>((*baseIt).to_double());
			math::Rational diff = static_cast<double>(tDiff);
			if (diff < 0) diff = -diff;

			std::cout << "\t" << *valsIt << "  err: " << expp::ViewR(diff) << "\n";

			if (maxDiff < diff) maxDiff = diff;

		}
		assert(baseIt == baseEnd);

		std::cout << "\t\tmax err: " << expp::ViewR(maxDiff) << "\n";

		return maxDiff;
	}

}

#endif /* _printHelper_h_included_ */
