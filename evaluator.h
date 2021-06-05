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
		Evaluator& operator=(Evaluator const& s);

		TestData& m_data;
		std::array<T, 4> m_center;
		std::array<std::array<T, 4>, 4> m_covar;
	};

	template<typename T>
	void sortEigenvalues(std::array<T, 2>& eigenvalues, std::array<std::array<T, 2>, 2>& eigenvectors)
	{
		if (eigenvalues[0] < eigenvalues[1])
		{
			std::swap(eigenvalues[0], eigenvalues[1]);
			std::swap(eigenvectors[0], eigenvectors[1]);
		}
	}

	template<typename T>
	void sortEigenvalues(std::array<T, 3>& eigenvalues, std::array<std::array<T, 3>, 3>& eigenvectors)
	{
		if (eigenvalues[0] < eigenvalues[1])
		{
			std::swap(eigenvalues[0], eigenvalues[1]);
			std::swap(eigenvectors[0], eigenvectors[1]);
		}
		if (eigenvalues[0] < eigenvalues[2])
		{
			std::swap(eigenvalues[0], eigenvalues[2]);
			std::swap(eigenvectors[0], eigenvectors[2]);
		}
		if (eigenvalues[1] < eigenvalues[2])
		{
			std::swap(eigenvalues[1], eigenvalues[2]);
			std::swap(eigenvectors[1], eigenvectors[2]);
		}
	}

	template<typename T>
	void sortEigenvalues(std::array<T, 4>& eigenvalues, std::array<std::array<T, 4>, 4>& eigenvectors)
	{
		if (eigenvalues[0] < eigenvalues[2])
		{
			std::swap(eigenvalues[0], eigenvalues[2]);
			std::swap(eigenvectors[0], eigenvectors[2]);
		}
		if (eigenvalues[1] < eigenvalues[3])
		{
			std::swap(eigenvalues[1], eigenvalues[3]);
			std::swap(eigenvectors[1], eigenvectors[3]);
		}
		if (eigenvalues[0] < eigenvalues[1])
		{
			std::swap(eigenvalues[0], eigenvalues[1]);
			std::swap(eigenvectors[0], eigenvectors[1]);
		}
		if (eigenvalues[2] < eigenvalues[3])
		{
			std::swap(eigenvalues[2], eigenvalues[3]);
			std::swap(eigenvectors[2], eigenvectors[3]);
		}
		if (eigenvalues[1] < eigenvalues[2])
		{
			std::swap(eigenvalues[1], eigenvalues[2]);
			std::swap(eigenvectors[1], eigenvectors[2]);
		}
	}

}

#include "evaluator.inl"

#endif /* _evaluator_h_included_ */
