#ifndef _printHelper_h_included_
#define _printHelper_h_included_
#pragma once

#include "myIter.h"

#include "math_Rational.h"

#include <iostream>
#include <iomanip>
#include <array>

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
		math::Rational const& m_r;
	};

	template<typename ts>
	static ts& operator<<(ts& s, ViewR const& v) {
		return s << std::fixed << std::setprecision(20) << v.r().to_double() << " (" << v.r() << ")";
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

}

#endif /* _printHelper_h_included_ */
