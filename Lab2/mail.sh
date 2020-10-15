#!/bin/bash

for email in $(cat adresy.dat)
do
	cat tresc.txt | mutt -s "Okna PCV" $email -a 'spec*.pdf'
done
