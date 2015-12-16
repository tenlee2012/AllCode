git add ./
echo "------>add successful"
echo -n "please input you commit info: "
read cominfo
git commit -m "$cominfo"
echo "---->commit successful"
git push -u origin master
