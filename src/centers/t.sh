#!/bin/bash 
 
# script file for BASH 
# which bash
# save this file as t.sh
# chmod +x t.sh
# ./t.sh
# checked in https://www.shellcheck.net/




printf "compile the program \n"
gcc t.c -lm -Wall

if [ $? -ne 0 ]
then
    echo ERROR: compilation failed !!!!!!
    exit 1
fi

printf "read all data files and use them for test \n"
for file in ./lists/*.txt ; do
  echo "$file"
  # b is name of file without extension
  b=$(basename -- "$file" .txt)
  #
  # https://www.gnu.org/software/bash/manual/html_node/Shell-Parameter-Expansion.html
  ./a.out "$file" > ./lists/results/"$b"_out.txt
done

printf "\n" 
printf "info about software \n"
echo "$SHELL"
printf "\n" 
bash --version
printf "\n" 
make -v
printf "\n" 
gcc --version
# end

