#include "rrstd.h"


R_DA_DEFINE(int, da_int)

char ut_da1() {
	da_int da = {0};
	R_DA_APPEND(&da, 1);
	R_DA_APPEND(&da, 2);
	R_DA_APPEND(&da, 3);

	R_DA_FOREACH(int, item, &da)
		printf("%d ", *item);
	printf("\n");

	R_DA_APPEND_MANY(&da, ((int[]){4, 5, 6, 7}), 4);

	R_DA_FOREACH(int, item, &da)
		printf("%d ", *item);
	printf("\n");

	R_DA_RESIZE(&da, 5);

	R_DA_FOREACH(int, item, &da)
		printf("%d ", *item);
	printf("\n");

	printf("%d\n", R_DA_LAST(&da));

	R_DA_FREE(&da);
	return 0;
}

char ut_sb1() {
	//R_StringBuilder sb = {0};
	//R_SB_APPEND_CSTR(&sb, "number:");
	//int n = R_SB_AppendFormat(&sb, "%d", 123);
	//printf("string: '%s', appended: %d\n", sb.buf, n);
	//R_SB_AppendFormat(&sb, ", hex: %x", 123);
	//printf("string: '%s'\n", sb.buf, n);
	//R_SB_FREE(&sb);
	return 0;
}

#define UT_ENTRY(UT_FUNC_) \
	printf("%s %s\n", UT_FUNC_() ? "[ ERR ]" : "[ OK  ]", #UT_FUNC_);

int main() {
	
	UT_ENTRY(ut_da1);
	UT_ENTRY(ut_sb1);

	return 0;
}
