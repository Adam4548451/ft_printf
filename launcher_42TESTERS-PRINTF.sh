ACTUAL_PATH=$(pwd)
PATH_FT_PRINTF="../"

(cd $PATH_FT_PRINTF && make re)
cd $ACTUAL_PATH
bash runtest.sh
vim diff.txt
