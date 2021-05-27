#ifndef _evaluator_h_included_
#define _evaluator_h_included_
#pragma once

#include "testdata.h"
#include <array>

namespace expp
{

	template<typename T>
	class Evaluator
	{
	public:
		Evaluator(TestData& data);

		void calcCenter();
		inline std::array<T, 4> const& getCenter() const { return m_center; }

		// center must be available!
		void calcCovarMatrix();
		inline std::array<std::array<T, 4>, 4> const& getCovar() const { return m_covar; }

	private:
		TestData& m_data;
		std::array<T, 4> m_center;
		std::array<std::array<T, 4>, 4> m_covar;
	};

}

#include "evaluator.inl"

#endif /* _evaluator_h_included_ */
