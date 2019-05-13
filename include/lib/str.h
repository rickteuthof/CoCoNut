#pragma once

#include <stdbool.h>

extern char *ccn_str_cpy(const char *source);
extern char *ccn_str_cat(const char *first, const char *second);
extern bool ccn_str_equal(const char *first, const char *second);