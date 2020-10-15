#!/bin/bash
ls -l
echo "Wypisałem zawartość folderu"
mkdir Ze_Skryptu
echo "Utworzyłem folder"
touch Ze_Skryptu/plik.sh
echo "Utworzyłem plik w folderze"
echo "#!/bin/bash\nrm -R Ze_Skryptu\nrm plik.sh">>Ze_Skryptu/plik.sh
echo "Dodałem skrypt do pliku"
cp Ze_Skryptu/plik.sh .
chmod 744 plik.sh
echo "By usunąć folder, uruchom plik.sh"
