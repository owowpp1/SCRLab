#!/bin/bash

for email in $(cat adresy.dat)
do
	cat mail.dat | mutt -s "Okna PCV" $email -a 'spec*.pdf'
done
