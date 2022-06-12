#!/bin/bash
apt list --installed | grep libsfml-dev && g++ --version
if [ $? -eq 1  ] 
     then
          sudo apt update
          sudo apt install g++
          sudo apt install libsfml-dev 
else
     echo OK 
fi
cd ..
make

