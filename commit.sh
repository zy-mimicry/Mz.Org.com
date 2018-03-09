#! /bin/bash

echo "committing...."

git status
git add .
git commmit -m "update"
git push origin master

echo "committed."
