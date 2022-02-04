cd libft
for dir in */ ; do
	cd ${dir}
	rm -rf Includes
	ln -s ../../Include Includes
	rm -rf .sh_tools
	ln -s ../../.sh_tools sh_tools
	cd -
done
cd ../
cd project
rm -rf Includes
ln -s ../Include Includes
rm -rf .sh_tools
ln -s ../.sh_tools sh_tools
cd ../