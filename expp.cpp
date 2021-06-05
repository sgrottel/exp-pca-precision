// expp.cpp : Defines the entry point for the application.
//

#include "findEigenvalues.h"
#include "testdata.h"
#include "evaluator.h"
#include "printHelper.h"
#include "TestReporter.h"

#include <iostream>
#include <fstream>
#include <string>


namespace
{

	template<class T, unsigned int D>
	math::Rational testEigenvalues(
		std::array<std::array<math::Rational, 4>, 4> const& covar,
		expp::TestData const& refData
		)
	{
		math::Rational error(1);

		std::array<T, D> eigenvalues;
		std::array<std::array<T, D>, D> eigenvectors;
		unsigned int num = expp::findEigenvaluesSymReal<D, T>(covar, eigenvalues, eigenvectors);
		if (num == D)
		{
			error = 0;

			expp::sortEigenvalues(eigenvalues, eigenvectors);

			std::cout << "Eigenvalues:\n";
			for (unsigned int i = 0; i < D; ++i)
			{
				std::cout << "\tval" << i << ":\t" << std::fixed << std::setprecision(80) << eigenvalues[i] << "\n";
				math::Rational ref = refData.getReferenceEigenvalue(D, i);
				std::cout << "\tref:\t" << expp::ViewR(ref) << "\n";

				math::Rational diff = ref - math::Rational(static_cast<double>(eigenvalues[i]));
				if (diff < 0) diff = -diff;
				std::cout << "\tdiff:\t" << expp::ViewR(diff) << "\n";
				if (diff > error) error = diff;
			}

			std::cout << "Eigenvectors:\n";
			for (unsigned int i = 0; i < D; ++i) {
				std::array<T, D> const& actEVec = eigenvectors[i];
				std::cout << "\tv" << i << ":\n";
				for (unsigned int c = 0; c < D; ++c)
				{
					std::cout << "\t\t" << std::fixed << std::setprecision(80) << actEVec[c] << "\n";
				}

				double actLen = 0;
				for (unsigned int c = 0; c < D; ++c)
				{
					actLen += static_cast<double>(actEVec[c]) * static_cast<double>(actEVec[c]);
				}
				actLen = std::sqrt(actLen);
				//std::cout << "\tlen:\n\t\t" << std::fixed << std::setprecision(80) << actLen << "\n";

				std::array<math::Rational, D> expEVec;
				double refLen = 0;
				for (unsigned int c = 0; c < D; ++c)
				{
					expEVec[c] = refData.getReferenceEigenvector(D, i, c);
					refLen += expEVec[c].to_double() * expEVec[c].to_double();
				}
				refLen = std::sqrt(refLen);
				for (unsigned int c = 0; c < D; ++c)
				{
					expEVec[c] *= actLen / refLen;
				}
				if (std::signbit(actEVec[0]) != std::signbit(expEVec[0].to_double()))
				{
					for (unsigned int c = 0; c < D; ++c)
					{
						expEVec[c] = -expEVec[c];
					}
				}

				std::cout << "\tref:\n";
				for (unsigned int c = 0; c < D; ++c)
				{
					std::cout << "\t\t" << expp::ViewR(expEVec[c]) << "\n";
				}
				std::cout << "\tdiff\n";
				for (unsigned int c = 0; c < D; ++c)
				{
					math::Rational diff = expEVec[c] - math::Rational(static_cast<double>(actEVec[c]));
					if (diff < 0) diff = -diff;
					std::cout << "\t\t" << expp::ViewR(diff) << "\n";
					if (diff > error) error = diff;
				}
			}

			std::cout << "Overall error:\n\t" << expp::ViewR(error) << "\n";
		}
		else
		{
			std::cerr << "Found only " << num << " Eigenvalues.\n";
		}

		return error;
	}


}


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
	//std::array<math::Rational, 4> const& centerBase = evalBase.getCenter();
	//reportTest.start(std::cout, "Ground truth center") << ":\n";
	//expp::printMyIter(std::cout, expp::makeMyIter(centerBase));
	//std::cout << "\n";

	//evalDouble.calcCenter();
	//reportTest.start(std::cout, "Double center naive") << ":\n";
	//error = expp::reportMyIterDiff<double>(
	//	expp::makeMyIter(evalDouble.getCenter()),
	//	expp::makeMyIter(centerBase));
	//reportTest.result(testResults, math::Rational(0.1), error);
	//std::cout << "\n";

	//evalFloat.calcCenter();
	//reportTest.start(std::cout, "Float center naive") << ":\n";
	//error = expp::reportMyIterDiff<float>(
	//	expp::makeMyIter(evalFloat.getCenter()),
	//	expp::makeMyIter(centerBase));
	//reportTest.result(testResults, math::Rational(0.1), error);
	//std::cout << "\n";


	evalBase.calcCovarMatrix();
	std::array<std::array<math::Rational, 4>, 4> const& covarBase = evalBase.getCovar();
	//reportTest.start(std::cout, "Ground truth covar") << ":\n";
	//expp::printMyIter(std::cout, expp::makeMyIter(covarBase));
	//std::cout << "\n";

	//evalDouble.calcCovarMatrix();
	//reportTest.start(std::cout, "Double covar naive") << ":\n";
	//error = expp::reportMyIterDiff<double>(
	//	expp::makeMyIter(evalDouble.getCovar()),
	//	expp::makeMyIter(covarBase));
	//reportTest.result(testResults, math::Rational(0.1), error);
	//std::cout << "\n";

	//evalFloat.calcCovarMatrix();
	//reportTest.start(std::cout, "Float covar naive") << ":\n";
	//error = expp::reportMyIterDiff<float>(
	//	expp::makeMyIter(evalFloat.getCovar()),
	//	expp::makeMyIter(covarBase));
	//reportTest.result(testResults, math::Rational(0.1), error);
	//std::cout << "\n";


	// eigenvalue search
	reportTest.start(std::cout, "Double eigenvalues 2x2") << ":\n";
	std::cout << sizeof(double) << "\n";
	error = testEigenvalues<double, 2>(covarBase, testData);
	reportTest.result(testResults, math::Rational(0.1), error);
	std::cout << "\n";

	reportTest.start(std::cout, "Float eigenvalues 2x2") << ":\n";
	std::cout << sizeof(float) << "\n";
	error = testEigenvalues<float, 2>(covarBase, testData);
	reportTest.result(testResults, math::Rational(0.1), error);
	std::cout << "\n";

	reportTest.start(std::cout, "Double eigenvalues 3x3") << ":\n";
	std::cout << sizeof(double) << "\n";
	error = testEigenvalues<double, 3>(covarBase, testData);
	reportTest.result(testResults, math::Rational(0.1), error);
	std::cout << "\n";

	reportTest.start(std::cout, "Float eigenvalues 3x3") << ":\n";
	std::cout << sizeof(float) << "\n";
	error = testEigenvalues<float, 3>(covarBase, testData);
	reportTest.result(testResults, math::Rational(0.1), error);
	std::cout << "\n";

	reportTest.start(std::cout, "Double eigenvalues 4x4") << ":\n";
	std::cout << sizeof(double) << "\n";
	error = testEigenvalues<double, 4>(covarBase, testData);
	reportTest.result(testResults, math::Rational(0.1), error);
	std::cout << "\n";

	reportTest.start(std::cout, "Float eigenvalues 4x4") << ":\n";
	std::cout << sizeof(float) << "\n";
	error = testEigenvalues<float, 4>(covarBase, testData);
	reportTest.result(testResults, math::Rational(0.1), error);
	std::cout << "\n";

	testResults.close();

	return 0;
}
