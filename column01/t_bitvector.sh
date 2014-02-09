#!/bin/sh
# bit vector sort performance..

perf stat cat ./random_numbers | ./bitvector_sort > l_bitvector

