#include "pch.h"

#include <tuple>
#include <string>
#include "../HojaDeTrabajo01/Ejercicio02.h"

using ::testing::TestWithParam;
using ::testing::Values;
using std::string;

namespace HojaDeTrabajo01Tests {
	
	class Ejercicio02Test : public TestWithParam<string> {
	protected:
		Ejercicio02* e02;
		string s;

		void SetUp() override {
			e02 = new Ejercicio02();
			s = GetParam();
		}

		void TearDown() override {
			delete e02;
			e02 = nullptr;
		}
	};

	class Ejercicio02PalindromosTest : public Ejercicio02Test {};

	class Ejercicio02NoPalindromosTest : public Ejercicio02Test {};

	TEST_P(Ejercicio02PalindromosTest, PalindromosValidos) {
		EXPECT_TRUE(e02->isPalindrome(s)) << s << " es un palindromo valido!";
	}

	TEST_P(Ejercicio02NoPalindromosTest, PalindromosNoValidos) {
		EXPECT_FALSE(e02->isPalindrome(s)) << s << " NO es un palindromo valido";
	}

	INSTANTIATE_TEST_CASE_P(PalindromosValidos,
		Ejercicio02PalindromosTest,
		Values("", "b", "a", "aba", "bab", "aaaaaabbbbaaaaaa", "somos", "reconocer", "anilina", "tenet", "holaloh", "holaaloh",
			"ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccacccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc",
			"abcdefghijklmnopqrstuvwxyzzyxwvutsrqponmlkjihgfedcba"));

	INSTANTIATE_TEST_CASE_P(PalindromosNoValidos,
		Ejercicio02NoPalindromosTest,
		Values("ba", "ab", "abc", "aaaabbbaa", "holahola", "apap", "ppppppppppz", "pppzppppp"
			"zyxwvutsrqponmlkjihgfedcba", "abcdefghijklmnopqrstuvwxyz",
			"ccccccccccccccccccaccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccacccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc"));

}