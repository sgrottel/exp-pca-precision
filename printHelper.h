#ifndef _printHelper_h_included_
#define _printHelper_h_included_
#pragma once

#include "math_Rational.h"
#include <iostream>
#include <iomanip>

namespace expp
{

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

}

#endif /* _printHelper_h_included_ */