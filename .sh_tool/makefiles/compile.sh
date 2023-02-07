cd libft
for dir in */ ; do
	cd ${dir}
	make
	cd -
done
cd ../
cd project
make
cd ../