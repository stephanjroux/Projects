#!/bin/bash

cd /home/pi/.GitFiles
rm -rf Arduino123
git clone https://github.com/stephanjroux/Arduino123
rm -rf Projects
git clone https://github.com/stephanjroux/Projects
clear
read -r -p "Do you want to create a Workspace? (y/n): " REPLY
REPLY=${REPLY,,}
if [[ $REPLY =~ ^(Y|y)$ ]]
then
  read -r -p "Is this the beginners course? (y/n): " BASIC
  if [[ $BASIC =~ ^(Y|y)$ ]]
  then
    rm -rf /home/pi/Desktop/Arduino123/* 
    cp -r /home/pi/.GitFiles/Arduino123/* /home/pi/Desktop/Arduino123
  else
    echo -n "Please enter your name: "
    read USERNAME
    echo -n "Enter project number: "
    read PROJ
    mydt=$(date +%F)
    dirname="${PROJ}_${USERNAME}_$mydt" 
    mkdir /home/pi/Desktop/$dirname
    cd /home/pi/Desktop/$dirname
    cp -r /home/pi/.GitFiles/Projects/$PROJ.*/* ./
  fi
fi