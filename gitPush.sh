#!/bin/bash

find . -name ".DS_Store" -delete
git add .
git commit
git push origin master
