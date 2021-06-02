// expp.cpp : Defines the entry point for the application.
//

#include "testdata.h"
#include "evaluator.h"
#include "printHelper.h"
#include "TestReporter.h"

#include <iostream>
#include <fstream>
#include <string>


int main()
{
	expp::TestData testData;
	expp::TestReporter reportTest;

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
	reportTest.start(std::cout, "Ground truth center") << ":\n";
	expp::printMyIter(std::cout, expp::makeMyIter(centerBase));
	std::cout << "\n";

	evalDouble.calcCenter();
	reportTest.start(std::cout, "Double center naive") << ":\n";
	error = expp::reportMyIterDiff<double>(
		expp::makeMyIter(evalDouble.getCenter()),
		expp::makeMyIter(centerBase));
	reportTest.result(testResults, math::Rational(0.1), error);
	std::cout << "\n";

	evalFloat.calcCenter();
	reportTest.start(std::cout, "Float center naive") << ":\n";
	error = expp::reportMyIterDiff<float>(
		expp::makeMyIter(evalFloat.getCenter()),
		expp::makeMyIter(centerBase));
	reportTest.result(testResults, math::Rational(0.1), error);
	std::cout << "\n";


	evalBase.calcCovarMatrix();
	std::array<std::array<math::Rational, 4>, 4> const& covarBase = evalBase.getCovar();
	reportTest.start(std::cout, "Ground truth covar") << ":\n";
	expp::printMyIter(std::cout, expp::makeMyIter(covarBase));
	std::cout << "\n";

	evalDouble.calcCovarMatrix();
	reportTest.start(std::cout, "Double covar naive") << ":\n";
	error = expp::reportMyIterDiff<double>(
		expp::makeMyIter(evalDouble.getCovar()),
		expp::makeMyIter(covarBase));
	reportTest.result(testResults, math::Rational(0.1), error);
	std::cout << "\n";

	evalFloat.calcCovarMatrix();
	reportTest.start(std::cout, "Float covar naive") << ":\n";
	error = expp::reportMyIterDiff<float>(
		expp::makeMyIter(evalFloat.getCovar()),
		expp::makeMyIter(covarBase));
	reportTest.result(testResults, math::Rational(0.1), error);
	std::cout << "\n";


	// eigenvalue search?
	// https://www.wolframalpha.com/input/?i=eigenvalue+%7B%7B-1%2C2%2C5%7D%2C%7B3%2F4%2C4%2C-12%2F2%7D%2C%7B7%2C-8%2C9%7D%7D


	testResults.close();

	return 0;
}
