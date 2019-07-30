# myname=`date -d "0 week" +%Y%m%d`
# if [ -f $myname ];then
# 	echo "dir has exist!"
# 	exit 1
# else
# 	mkdir $myname
# fi
# cd $myname
mkdir include
mkdir src
mkdir config
mkdir log
mkdir bin
cp ../Makefile .