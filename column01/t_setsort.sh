#!/bin/sh
# set sort performance..

perf stat cat ./random_numbers | ./set_sort > l_set_sort

