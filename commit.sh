#!/bin/bash

description="version_"$(date +%Y)"_"$(date +%m)"_"$(date +%d)

echo "## "${description} >> README.md

git add .
git commit -m ${description}
git push origin master:master