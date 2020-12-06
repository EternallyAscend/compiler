#/bin/bash
echo $1 $2 $3
git add $1
git commit -m $2
git push origin $3
