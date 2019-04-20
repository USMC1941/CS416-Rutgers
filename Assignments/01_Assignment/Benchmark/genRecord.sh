#!/bin/bash
ITER=0
COUNTER=0

if [ ! -d "./record" ]; then
	mkdir record
fi

while [ $ITER -lt 10 ]; do
	let "COUNTER=0"
	while [ $COUNTER -lt 1048576 ]; do
		echo $(( $RANDOM % 65535)) >> ./record/$ITER
		let "COUNTER+=1"
	done
	let "ITER+=1"
done
