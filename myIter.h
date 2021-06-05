//
// Linear iterators
//

#ifndef _myIter_h_included_
#define _myIter_h_included_
#pragma once

#include <array>
#include <stddef.h>

namespace expp
{

	template<typename T>
	class MyIter;

	template<typename T, size_t D1>
	class MyIter<std::array<T, D1>> {
	public:
		typedef std::array<T, D1> DT;
		typedef typename std::array<T, D1>::const_iterator const_iterator;

		MyIter(DT const& d) : m_d(d) {}
		MyIter(MyIter const& s) : m_d(s.m_d) {}

		typename DT::const_iterator begin() const { return m_d.begin(); }
		typename DT::const_iterator end() const { return m_d.end(); }

	private:
		MyIter& operator=(const MyIter&);

		DT const& m_d;
	};

	template<typename T, size_t D1>
	class MyIter<std::array<std::array<T, D1>, D1>> {
	public:
		typedef std::array<std::array<T, D1>, D1> DT;

		class const_iterator {
		public:
			friend class MyIter<std::array<std::array<T, D1>, D1>>;

			const_iterator(const_iterator const& s) : m_d(s.m_d), m_x(s.m_x), m_y(s.m_y) {}

			inline const_iterator& operator++() {
				++m_y;
				if (m_y >= D1)
				{
					m_y = 0;

					++m_x;
					if (m_x >= D1)
					{
						m_x = D1;
						m_y = D1;
					}
				}
				return *this;
			}
			inline bool operator==(const const_iterator& b) const
			{
				return m_x == b.m_x
					&& m_y == b.m_y;
			}
			inline bool operator!=(const const_iterator& b) const
			{
				return m_x != b.m_x
					|| m_y != b.m_y;
			}
			inline T const& operator*() const {
				return m_d[m_x][m_y];
			}

		private:
			const_iterator(DT const& d, size_t x, size_t y) : m_d(d), m_x(x), m_y(y) {}

			const_iterator& operator=(const_iterator const& s);

			DT const& m_d;
			size_t m_x;
			size_t m_y;
		};

		MyIter(DT const& d) : m_d(d) {}
		MyIter(MyIter const& s) : m_d(s.m_d) {}

		const_iterator begin() const { return const_iterator(m_d, 0, 0); }
		const_iterator end() const { return const_iterator(m_d, D1, D1); }

	private:

		MyIter& operator=(const MyIter&);

		DT const& m_d;
	};

	template<typename T, typename RT>
	RT makeMyIter(T const& d);
	template<typename T1, size_t D1>
	MyIter<std::array<T1, D1>> makeMyIter(std::array<T1, D1> const& d)
	{
		return MyIter<std::array<T1, D1>>(d);
	}
	template<typename T1, size_t D1>
	MyIter<std::array<std::array<T1, D1>, D1>> makeMyIter(std::array<std::array<T1, D1>, D1> const& d)
	{
		return MyIter<std::array<std::array<T1, D1>, D1>>(d);
	}

}

#endif /* _myIter_h_included_ */
