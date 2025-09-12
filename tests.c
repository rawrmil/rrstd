#include <stdio.h>
#include <string.h>

#define RRSTD_IMPLEMENTATION
#include "rrstd.h"

#define UT_ASSERT(COND_) \
	do { \
		if (!(COND_)) { return 1; } \
	} while(0)

R_DA_DEFINE(int, da_int)

char ut_da1() {
	da_int da = {0};
	R_DA_APPEND(&da, 1);
	R_DA_APPEND(&da, 2);
	R_DA_APPEND(&da, 3);

	UT_ASSERT(da.buf[0] == 1);
	UT_ASSERT(da.buf[1] == 2);
	UT_ASSERT(da.buf[2] == 3);

	R_DA_APPEND_MANY(&da, ((int[]){4, 5, 6, 7}), 4);

	UT_ASSERT(da.buf[3] == 4);
	UT_ASSERT(da.buf[4] == 5);
	UT_ASSERT(da.buf[5] == 6);
	UT_ASSERT(da.buf[6] == 7);

	R_DA_RESIZE(&da, 4);
	R_DA_RESIZE(&da, 4);

	UT_ASSERT(R_DA_LAST(&da) == 4);

	R_DA_REMOVE_INDEX(&da, 1);
	R_DA_REMOVE_INDEX(&da, 2);

	UT_ASSERT(da.buf[0] == 1);
	UT_ASSERT(da.buf[1] == 4);

	R_DA_FREE(&da);

	return 0;
}

char ut_sb1() {
	R_StringBuilder sb = (R_StringBuilder){0};
	R_SB_APPEND_BUFFER(&sb, "liza_b_crush66", strlen("liza_b_crush66"));
	UT_ASSERT(strncmp(sb.buf, "liza_b_crush66", strlen("liza_b_crush66")) == 0);
	R_SB_FREE(&sb);

	sb = (R_StringBuilder){0};
	R_SB_APPEND_CSTR(&sb, "bigballs3106");
	UT_ASSERT(strncmp(sb.buf, "bigballs3106", strlen("bigballs3106")) == 0);
	R_SB_FREE(&sb);

	sb = (R_StringBuilder){0};
	R_SB_AppendFormat(&sb, "hex: %x", 31);
	UT_ASSERT(strncmp(sb.buf, "hex: 1f", strlen("hex: 1f")) == 0);
	R_SB_FREE(&sb);

	return 0;
}

#define UT_ENTRY(UT_FUNC_) \
	printf("%s %s\n", UT_FUNC_() ? "[ ERR ]" : "[ OK  ]", #UT_FUNC_);

int main() {
	
	UT_ENTRY(ut_da1);
	UT_ENTRY(ut_sb1);

	return 0;
}
