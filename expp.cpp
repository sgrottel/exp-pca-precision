// expp.cpp : Defines the entry point for the application.
//

#include "testdata.h"
#include "evaluator.h"
#include "printHelper.h"

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

static std::string testName = "unknown";

template<typename TS>
static TS& startTest(TS& s, char const* name)
{
	testName = name;
	return s << name;
}

template<typename TS>
static void reportTest(TS& s, math::Rational const& exp, math::Rational const& act)
{
	s << testName << " (" << expp::ViewR(act) << ");" << ((act < exp) ? "true" : "false") << "\n";
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
	startTest(std::cout, "Ground truth center") << ":\n";
	expp::printMyIter(std::cout, expp::makeMyIter(centerBase));
	std::cout << "\n";

	evalDouble.calcCenter();
	startTest(std::cout, "Double center naive") << ":\n";
	error = reportMyIterDiff<double>(
		expp::makeMyIter(evalDouble.getCenter()),
		expp::makeMyIter(centerBase));
	reportTest(testResults, math::Rational(0.1), error);
	std::cout << "\n";

	evalFloat.calcCenter();
	startTest(std::cout, "Float center naive") << ":\n";
	error = reportMyIterDiff<float>(
		expp::makeMyIter(evalFloat.getCenter()),
		expp::makeMyIter(centerBase));
	reportTest(testResults, math::Rational(0.1), error);
	std::cout << "\n";


	evalBase.calcCovarMatrix();
	std::array<std::array<math::Rational, 4>, 4> const& covarBase = evalBase.getCovar();
	startTest(std::cout, "Ground truth covar") << ":\n";
	expp::printMyIter(std::cout, expp::makeMyIter(covarBase));
	std::cout << "\n";

	evalDouble.calcCovarMatrix();
	startTest(std::cout, "Double covar naive") << ":\n";
	error = reportMyIterDiff<double>(
		expp::makeMyIter(evalDouble.getCovar()),
		expp::makeMyIter(covarBase));
	reportTest(testResults, math::Rational(0.1), error);
	std::cout << "\n";

	evalFloat.calcCovarMatrix();
	startTest(std::cout, "Float covar naive") << ":\n";
	error = reportMyIterDiff<float>(
		expp::makeMyIter(evalFloat.getCovar()),
		expp::makeMyIter(covarBase));
	reportTest(testResults, math::Rational(0.1), error);
	std::cout << "\n";


	// eigenvalue search?
	// https://www.wolframalpha.com/input/?i=eigenvalue+%7B%7B-1%2C2%2C5%7D%2C%7B3%2F4%2C4%2C-12%2F2%7D%2C%7B7%2C-8%2C9%7D%7D


	testResults.close();

	return 0;
}
