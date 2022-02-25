#!/bin/bash
for i in {1..30}
do
	./push_swap `./randgen 100` | ./checker_Mac `./randgen 100`
	./push_swap `./randgen 100` | wc -l
	sleep 1
done
