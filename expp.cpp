// expp.cpp : Defines the entry point for the application.
//

#include "testdata.h"
#include "evaluator.h"
#include "printHelper.h"

#include <iostream>
#include <fstream>

template <typename T>
math::Rational reportCenter(T const* c, math::Rational const* cBase)
{
	math::Rational maxDiff(0, 1);
	math::Rational diff[4];
	for (unsigned int d = 0; d < 4; ++d)
	{
		diff[d] = math::Rational(c[d]) - cBase[d];
		if (diff[d] < 0) diff[d] = -diff[d];
		if (diff[d] > maxDiff) maxDiff = diff[d];
		std::cout << "\t" << c[d] << "  err: " << expp::ViewR(diff[d]) << "\n";
	}
	std::cout << "\t\tmax err: " << expp::ViewR(maxDiff) << "\n\n";

	return maxDiff;
}

int main()
{
	expp::TestData testData;

	expp::Evaluator<math::Rational> evalBase(testData);
	expp::Evaluator<double> evalDouble(testData);
	expp::Evaluator<float> evalFloat(testData);

	evalBase.calcCenterBasic();
	math::Rational const* centerBase = evalBase.getCenter();
	std::cout << "Ground truth center:\n"
		<< "\t" << expp::ViewR(centerBase[0]) << "\n"
		<< "\t" << expp::ViewR(centerBase[1]) << "\n"
		<< "\t" << expp::ViewR(centerBase[2]) << "\n"
		<< "\t" << expp::ViewR(centerBase[3]) << "\n\n";

	evalDouble.calcCenterBasic();
	std::cout << "Double center naive:\n";
	reportCenter(evalDouble.getCenter(), centerBase);

	evalFloat.calcCenterBasic();
	std::cout << "Float center naive:\n";
	reportCenter(evalFloat.getCenter(), centerBase);


	std::ofstream testResults("expp.testresult");
	if (testResults.is_open())
	{
		testResults << "Dummy;Passed\n";
		testResults.close();
	}

	return 0;
}
