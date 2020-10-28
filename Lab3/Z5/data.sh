#!/bin/bash

sygnal ()
{
    case "$1" in
        "1")
            echo "\n\nSIGHUP\n" ;;
        "2") 
            echo "\n\nCTRL+C\n" 
            exit ;;
        "3")
            echo "\n\nSIGQUIT\n" ;;
        "4")
            echo "\n\nSIGILL\n" ;;
        "5")
            echo "\n\nSIGTRAP\n" ;;
        "6")
            echo "\n\nSIGABRT\n" ;;
        "7") 
            echo "\n\nSIGBUS\n" ;;
        "8")
            echo "\n\nSIGFPE\n" ;;
        "9")
            echo "\n\nSIGKILL\n" ;;
        "10")
            echo "\n\nSIGUSR1\n" ;;
        "11")
            echo "\n\nSIGSEGV\n" ;;
        "12") 
            echo "\n\nSIGUSR2\n" ;;
        "13")
            echo "\n\nSIGPIPE\n" ;;
        "14")
            echo "\n\nSIGALRM\n" ;;
        "15")
            echo "\n\nSIGTERM\n" ;;
        *) echo error ;;
    esac
}

trap 'sygnal 1' HUP
trap 'sygnal 2' INT
trap 'sygnal 3' QUIT
trap 'sygnal 4' ILL
trap 'sygnal 5' TRAP
trap 'sygnal 6' ABRT
trap 'sygnal 7' BUS
trap 'sygnal 8' FPE
trap 'sygnal 9' KILL
trap 'sygnal 10' USR1
trap 'sygnal 11' SEGV
trap 'sygnal 12' USR2
trap 'sygnal 13' PIPE
trap 'sygnal 14' ALRM
trap 'sygnal 15' TERM



while :
do
    date +%T
    sleep 1
done
