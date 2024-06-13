#include "minunit.h"

void test_setup(void) {
    // Nothing
}

void test_teardown(void) {
    // Nothing
}

MU_TEST(test_check) {
    int foo = 7;
    int bar = 5;
    double dbar = 0.2;
    char foostring[] = "Thisstring";
	mu_check(foo == 7);
	mu_assert(foo == 7, "foo should be 7");
	mu_assert_int_eq(5, bar);
	mu_assert_double_eq(0.2, dbar);
	mu_assert_string_eq("Thisstring", foostring);
}

MU_TEST_SUITE(test_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
	MU_RUN_TEST(test_check);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
