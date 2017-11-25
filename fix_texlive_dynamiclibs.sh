TEXWORKDIR=../../texlive/Work
TEXINSTDIR=/Users/holzschu/src/Xcode_iPad/texlive/inst/lib

cp $TEXWORKDIR/libs/lua52/.libs/libtexlua52.5.dylib .
install_name_tool -id @executable_path/Frameworks/libtexlua52.5.dylib libtexlua52.5.dylib
cp $TEXWORKDIR/texk/kpathsea/.libs/libkpathsea.6.dylib .
install_name_tool -id @executable_path/Frameworks/libkpathsea.6.dylib libkpathsea.6.dylib

cp $TEXWORKDIR/texk/web2c/.libs/luatex.dylib ./libluatex.dylib
install_name_tool -id libluatex.dylib libluatex.dylib

install_name_tool -id @executable_path/Frameworks/libluatex.dylib libluatex.dylib
install_name_tool -change $TEXINSTDIR/libtexlua52.5.dylib @executable_path/Frameworks/libtexlua52.5.dylib libluatex.dylib
install_name_tool -change $TEXINSTDIR/libkpathsea.6.dylib @executable_path/Frameworks/libkpathsea.6.dylib libluatex.dylib
 
cp $TEXWORKDIR/texk/web2c/.libs/pdftex.dylib ./libpdftex.dylib
install_name_tool -id @executable_path/Frameworks/libpdftex.dylib  libpdftex.dylib
install_name_tool -change $TEXINSTDIR/libkpathsea.6.dylib @executable_path/Frameworks/libkpathsea.6.dylib libpdftex.dylib
 
# Can't make XeTeX work in iOS. 
# cp $TEXWORKDIR/texk/web2c/.libs/xetex.dylib .
# install_name_tool -id @executable_path/Frameworks/xetex.dylib xetex.dylib 
# install_name_tool -change $TEXINSTDIR/libkpathsea.6.dylib @executable_path/Frameworks/libkpathsea.6.dylib xetex.dylib
 
# There's a choice to be made between bibtexu and bibtex8. You can't have both. 
# bibtexu doesn't seem to work, bibtex8 does.
# cp $TEXWORKDIR/texk/bibtex-x/.libs/bibtexu.dylib ./libbibtex.dylib
# install_name_tool -id @executable_path/Frameworks/libbibtex.dylib libbibtex.dylib 
# install_name_tool -change $TEXINSTDIR/libkpathsea.6.dylib @executable_path/Frameworks/libkpathsea.6.dylib libbibtex.dylib
 
cp $TEXWORKDIR/texk/bibtex-x/.libs/bibtex8.dylib ./libbibtex.dylib
install_name_tool -id @executable_path/Frameworks/libbibtex.dylib libbibtex.dylib 
install_name_tool -change $TEXINSTDIR/libkpathsea.6.dylib @executable_path/Frameworks/libkpathsea.6.dylib libbibtex.dylib

