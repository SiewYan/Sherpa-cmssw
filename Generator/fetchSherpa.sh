#!/bin/bash

wget https://sherpa.hepforge.org/downloads/?f=SHERPA-MC-2.2.5.tar.gz

mv index.html?f=SHERPA-MC-2.2.5.tar.gz SHERPA-MC-2.2.5.tar.gz

tar zxvf SHERPA-MC-2.2.5.tar.gz

rm SHERPA-MC-2.2.5.tar.gz

echo "Remember to remove manual folder and manual in Makefile"