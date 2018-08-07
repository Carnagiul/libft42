sh display.sh
echo "Voulez vous effectuer un push?"
echo "Y pour OUI et N pour NON"
read result
if [ "$result" == Y ] || [ "$result" == O ]; then
	echo "Quel est le commentaire pour le push?"
	read comment
	git add -A
	git commit -m "$result"
	git push
	echo "Le push est bien envoyer"
fi
