#!/bin/sh

echo $1 
perf stat ../bin/rotate juggling $1 $2 > j
perf stat ../bin/rotate block_swap $1 $2 > b
