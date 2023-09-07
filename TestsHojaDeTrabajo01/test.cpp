#include "pch.h"
#include "../HojaDeTrabajo01/Ejercicio01.h"

TEST(TestCaseName, TestName) {
	Ejercicio01 e01;
  EXPECT_EQ(e01.sum(4, 5), 9);
  EXPECT_TRUE(true);
}