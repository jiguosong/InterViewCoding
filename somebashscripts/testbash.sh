#!/usr/bin/env bash

#http://tldp.org/LDP/abs/html/
#http://arachnoid.com/linux/shell_programming.html
#http://tldp.org/HOWTO/Bash-Prog-Intro-HOWTO.html

#echo "this is just a test on bash in Clion"
#
#MY=323
#echo $MY
#
#for D in *
#    do [ -d "${D}" ] && echo "${D}"
#done

# only grep capital letter word
grep -roP --include \*.txt '\b\p{Lu}+\b' words.txt