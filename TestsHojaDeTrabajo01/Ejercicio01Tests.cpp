#include "pch.h"

#include <tuple>
#include "../HojaDeTrabajo01/Ejercicio01.h"

using ::testing::TestWithParam;
using ::testing::Values;

namespace HojaDeTrabajo01Tests {

	class Ejercicio01Test : public TestWithParam< ::std::tuple<int, int, int>> {
	protected:
		Ejercicio01* e01;
		int a, b, expectedResult;

		void SetUp() override {
			e01 = new Ejercicio01();
			std::tie(a, b, expectedResult) = GetParam();
		}

		void TearDown() override {
			delete e01;
			e01 = nullptr;
		}
	};

	TEST_P(Ejercicio01Test, Sumando) {
		int result = e01->sum(a, b);
		EXPECT_EQ(expectedResult, result) << "[a + b = " << expectedResult << "] No es el resultado esperado. Se esperaba: [" << result << "]";
	}

	INSTANTIATE_TEST_CASE_P(Parametros,
		Ejercicio01Test,
		Values(std::tuple<int, int, int>(1, 1, 2),
			std::tuple<int, int, int>(2, 2, 4),
			std::tuple<int, int, int>(99, 99, 198),
			std::tuple<int, int, int>(0, 0, 0),
			std::tuple<int, int, int>(1, -1, 0),
			std::tuple<int, int, int>(-7, -7, -14)));
}
