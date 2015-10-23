#!/bin/bash

while true
do
  echo 1 > /proc/sys/vm/shrink_all_memory
  echo 1 > /proc/sys/vm/compact_memory
  sleep 1800
done
