

#.tag
ctags -R

#cscope
cscope -Rbkq

find /home/gongtao/Xproject/ -name "*.h" -o -name "*.cc" > cscope.files
cscope -bkq -i cscope.files
