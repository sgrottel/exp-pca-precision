#ifndef _testreporter_h_included_
#define _testreporter_h_included_
#pragma once

#include <string>
#include "math_Rational.h"
#include "printHelper.h"

namespace expp
{

	class TestReporter {
	private:
		std::string m_testName;
	public:
		TestReporter();

		template<typename TS>
		TS& start(TS& s, char const* name)
		{
			m_testName = name;
			return s << name;
		}

		template<typename TS>
		void result(TS& s, math::Rational const& exp, math::Rational const& act)
		{
			s << m_testName << " (" << expp::ViewR(act) << ");" << ((act < exp) ? "true" : "false") << "\n";
		}

	};

}

#endif /* _testreporter_h_included_ */
