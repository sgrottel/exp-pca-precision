// expp.cpp : Defines the entry point for the application.
//

#include "testdata.h"
#include "evaluator.h"
#include "printHelper.h"

#include <iostream>
#include <fstream>
#include <cassert>

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
		math::Rational diff = tDiff;
		if (diff < 0) diff = -diff;

		std::cout << "\t" << *valsIt << "  err: " << expp::ViewR(diff) << "\n";

		if (maxDiff < diff) maxDiff = diff;

	}
	assert(baseIt == baseEnd);

	std::cout << "\t\tmax err: " << expp::ViewR(maxDiff) << "\n";

	return maxDiff;
}

int main()
{
	expp::TestData testData;

	expp::Evaluator<math::Rational> evalBase(testData);
	expp::Evaluator<double> evalDouble(testData);
	expp::Evaluator<float> evalFloat(testData);

	std::ofstream testResults("expp.testresult");
	if (!testResults.is_open())
	{
		std::cerr << "Failed to open testresults file for writing\n" << std::endl;
		return -1;
	}

	math::Rational error;

	evalBase.calcCenter();
	std::array<math::Rational, 4> const& centerBase = evalBase.getCenter();
	std::cout << "Ground truth center:\n";
	expp::printMyIter(std::cout, expp::makeMyIter(centerBase));
	std::cout << "\n";

	evalDouble.calcCenter();
	std::cout << "Double center naive:\n";
	error = reportMyIterDiff<double>(
		expp::makeMyIter(evalDouble.getCenter()),
		expp::makeMyIter(centerBase));
	testResults << "DCenterNaive;" << ((error < math::Rational(0.1)) ? "true" : "false") << "\n";
	std::cout << "\n";

	evalFloat.calcCenter();
	std::cout << "Float center naive:\n";
	error = reportMyIterDiff<float>(
		expp::makeMyIter(evalFloat.getCenter()),
		expp::makeMyIter(centerBase));
	testResults << "FCenterNaive;" << ((error < math::Rational(0.1)) ? "true" : "false") << "\n";
	std::cout << "\n";


	evalBase.calcCovarMatrix();
	std::array<std::array<math::Rational, 4>, 4> const& covarBase = evalBase.getCovar();
	std::cout << "Ground truth covar:\n";
	expp::printMyIter(std::cout, expp::makeMyIter(covarBase));
	std::cout << "\n";

	evalDouble.calcCovarMatrix();
	std::cout << "Double covar naive:\n";
	error = reportMyIterDiff<double>(
		expp::makeMyIter(evalDouble.getCovar()),
		expp::makeMyIter(covarBase));
	testResults << "DCovarNaive;" << ((error < math::Rational(0.1)) ? "true" : "false") << "\n";
	std::cout << "\n";

	evalFloat.calcCovarMatrix();
	std::cout << "Float covar naive:\n";
	error = reportMyIterDiff<float>(
		expp::makeMyIter(evalFloat.getCovar()),
		expp::makeMyIter(covarBase));
	testResults << "FCovarNaive;" << ((error < math::Rational(0.1)) ? "true" : "false") << "\n";
	std::cout << "\n";


	// eigenvalue search?
	// https://www.wolframalpha.com/input/?i=eigenvalue+%7B%7B-1%2C2%2C5%7D%2C%7B3%2F4%2C4%2C-12%2F2%7D%2C%7B7%2C-8%2C9%7D%7D


	testResults.close();

	return 0;
}
