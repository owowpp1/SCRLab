#!/bin/bash
while true; do
	read -p 'Chcesz utworzyć plik '$2' w folderze '$1'?' yesno
	case $yesno in
		[Tt]* ) mkdir $1;
			 touch $1/$2.sh;
			 echo '#!/bin/bash\nrm -R '$1'\nrm plik.sh'>>$1/$2.sh;
			 echo "Dodałem skrypt do pliku";
			 cp $1/$2.sh ./plik.sh;
			 chmod 744 plik.sh;
			 echo 'By wycofać zmiany, uruchom plik.sh';
			 break;;
		[Nn]* ) exit;;
		* ) echo "Podaj odpowiedź [T/N]";;
	esac
done
 			
