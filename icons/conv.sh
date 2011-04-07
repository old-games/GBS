for pic in *.ico
do
        convert $pic $(basename $pic .xpm).xpm

done