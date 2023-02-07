cd libft
for dir in */ ; do
	cd ${dir}
	rm -rf Includes
	ln -s ../../Include Includes
	make clean
	cd -
done
cd ../
cd project
make clean
cd ../