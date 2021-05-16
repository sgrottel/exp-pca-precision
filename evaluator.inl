#ifndef _evaluator_inl_included_
#define _evaluator_inl_included_
#pragma once

namespace
{

	template<typename t>
	struct helper;

	template<>
	struct helper<math::Rational>
	{
		static inline math::Rational fromUInt(unsigned int u) { return math::Rational(u, 1); }
		static inline math::Rational const& fromRational(math::Rational const& r) { return r; }
	};

	template<>
	struct helper<double>
	{
		static inline double fromUInt(unsigned int u) { return static_cast<double>(u); }
		static inline double fromRational(math::Rational const& r) { return r.to_double(); }
	};

	template<>
	struct helper<float>
	{
		static inline float fromUInt(unsigned int u) { return static_cast<float>(u); }
		static inline float fromRational(math::Rational const& r) { return static_cast<float>(r.to_double()); }
	};

}

template<typename T>
expp::Evaluator<T>::Evaluator(TestData& data)
	: m_data(data)
{
	// intentionally empty
}

template<typename T>
void expp::Evaluator<T>::calcCenterBasic()
{
	for (size_t d = 0; d < 4; ++d)
		m_center[d] = 0;

	unsigned int numPts = m_data.getNumPoints();
	for (unsigned int p = 0; p < numPts; ++p)
	{
		for (size_t d = 0; d < 4; ++d)
		{
			math::Rational const* pt = m_data.getPoint(p);
			m_center[d] += helper<T>::fromRational(pt[d]);
		}
	}

	T scale = helper<T>::fromUInt(numPts);
	for (size_t d = 0; d < 4; ++d)
		m_center[d] /= scale;
}

#endif /* _evaluator_inl_included_ */