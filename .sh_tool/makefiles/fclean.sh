cd libft
for dir in */ ; do
	cd ${dir}
	make fclean
	cd -
done
cd ../
cd project
make fclean
cd ../