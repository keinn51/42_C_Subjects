#!/bin/bash

find . -name ".DS_Store" -delete
git add .
git commit --author="keinn51"
git push origin master
