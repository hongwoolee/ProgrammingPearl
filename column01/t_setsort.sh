#!/bin/sh
# qsort performance..

perf stat cat ./random_numbers | ./set_sort > l_qsort

