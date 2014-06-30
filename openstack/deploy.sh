#!/bin/sh

#compute:
#./deploy.sh 128.224.163.199 192.168.1.10

#Controller:
#./deploy.sh 128.224.167.18 192.168.1.11

oldip=$1
newip=$2
echo "===== 1. filter old ip :======="
grep "$oldip" etc/* -r 

echo "===== 2. change ip :======="
for i in `grep "$oldip" etc/* -r | awk -F: '{print $1}'`; do 
    ls $i 
    sed -i "s/$oldip/$newip/g" $i
done

echo "===== 3. check new ip write in======="
grep "$newip" etc/* -r 
