cd libft
for dir in */ ; do
	cd ${dir}
	make re
	cd -
done
cd ../
cd project
make re
cd ../