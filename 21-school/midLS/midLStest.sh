#!/bin/bash

dirName='midLStest'
mkdir ${dirName}
cd ${dirName}
fileName=(1 b 3 4 e f 7 8)
i=0
for i in $(seq 0 7); do
	date > ${fileName[$i]}
	sleep 60
done
mkdir 9
date >> 3
sleep 60
date >> f
