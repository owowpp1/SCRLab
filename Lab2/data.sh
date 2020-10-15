#!/bin/bash
dzien=$(date +%u)

if [$dzien -gt 5] ; then
	echo "Pozdrowionka i miłej zabawy wikendowej"
else
	echo "Pozdrowionka i miłej pracy"
fi
