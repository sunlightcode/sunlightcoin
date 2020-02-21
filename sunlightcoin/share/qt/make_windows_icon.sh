#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/sunlightcoin.png
ICON_DST=../../src/qt/res/icons/sunlightcoin.ico
convert ${ICON_SRC} -resize 16x16 sunlightcoin-16.png
convert ${ICON_SRC} -resize 32x32 sunlightcoin-32.png
convert ${ICON_SRC} -resize 48x48 sunlightcoin-48.png
convert sunlightcoin-16.png sunlightcoin-32.png sunlightcoin-48.png ${ICON_DST}

