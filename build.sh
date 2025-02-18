#!/bin/bash

cd $(dirname $0)

for lang in en fr
do
  sphinx-build ./$lang _build/$lang
done

cp ./redirect.html _build/index.html
