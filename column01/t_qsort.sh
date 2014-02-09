#!/bin/sh
# qsort performance..

perf stat cat ./random_numbers | ./qsort > l_qsort

