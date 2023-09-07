#include "pch.h"

#include <vector>
#include "../HojaDeTrabajo01/Ejercicio03.h"

using ::testing::TestWithParam;
using ::testing::ValuesIn;
using std::vector;

namespace HojaDeTrabajo01Tests {

	class Ejercicio03Test : public TestWithParam<int> {
	protected:
		Ejercicio03* e03;
		int n;

		void SetUp() override {
			e03 = new Ejercicio03();
			n = GetParam();
		}

		void TearDown() override {
			delete e03;
			e03 = nullptr;
		}
	};

	class Ejercicio03ValidPowers : public Ejercicio03Test {
	public:
		static vector<int> GetPowersOfTwo() {
			vector<int> powers;

			powers.push_back(1);

			int n = 2;

			while (n > 0) {
				powers.push_back(n);
				powers.push_back(-n);
				n = n * 2;
			}

			return powers;
		}
	};

	class Ejercicio03NotValidPowers : public Ejercicio03Test {
	public:
		static vector<int> GetNonPowersOfTwo() {
			vector<int> nonPowers;

			int n = 2;

			nonPowers.push_back(0);

			while (n > 0) {
				nonPowers.push_back(n + 1);
				nonPowers.push_back(-n - 1);
				n = n * 2;
			}

			return nonPowers;
		}
	};

	TEST_P(Ejercicio03ValidPowers, PotenciasDeDos) {
		EXPECT_TRUE(e03->isPowerOfTwo(n)) << n << " es una potencia de dos";
	}

	TEST_P(Ejercicio03NotValidPowers, PotenciasNoValidas) {
		EXPECT_FALSE(e03->isPowerOfTwo(n)) << n << " NO es una potencia de dos";
	}

	INSTANTIATE_TEST_CASE_P(PotenciasDeDos,
		Ejercicio03ValidPowers,
		ValuesIn(Ejercicio03ValidPowers::GetPowersOfTwo()));

	INSTANTIATE_TEST_CASE_P(NoPotenciasDeDos,
		Ejercicio03NotValidPowers,
		ValuesIn(Ejercicio03NotValidPowers::GetNonPowersOfTwo()));

}