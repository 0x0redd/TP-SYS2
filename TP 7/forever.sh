#!/bin/bash
while [ 1 ]; do
for ((x=1; x <= 100000; x++))
do
echo 'hello' > /dev/null
done
echo "bonjour, il est "`date`;
done
