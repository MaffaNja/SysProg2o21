#!/bin/bash
echo Input the pattern:
read pattern
echo Input the dir:
read dir
find $dir -maxdepth 1 -type f -name "*$pattern*">task.txt
