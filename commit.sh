#! /bin/bash

echo "committing...."

git status
git add .
if test "$?" -ne "0" ; then
    echo "failed added."
fi

git commit -m "update"

if test "$?" -ne "0" ; then
    echo "failed comitted."
fi

git push origin master

if test "$?" -ne "0" ; then
    echo "failed push."
fi

echo "committed."
