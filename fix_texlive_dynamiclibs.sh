# Where the libraries are:
TEXWORKDIR=$HOME/src/lib-tex/Work
# Where the compiler thought the libraries would be:
TEXINSTDIR=$HOME/src/lib-tex/Work/inst/lib

cp $TEXWORKDIR/libs/lua52/.libs/libtexlua52.5.dylib .
install_name_tool -id @executable_path/Frameworks/libtexlua52.5.dylib libtexlua52.5.dylib
cp $TEXWORKDIR/texk/kpathsea/.libs/libkpathsea.6.dylib .
install_name_tool -id @executable_path/Frameworks/libkpathsea.6.dylib libkpathsea.6.dylib

cp $TEXWORKDIR/texk/web2c/.libs/luatex.dylib .
install_name_tool -id luatex.dylib luatex.dylib

install_name_tool -id @executable_path/Frameworks/luatex.dylib luatex.dylib
install_name_tool -change $TEXINSTDIR/libtexlua52.5.dylib @executable_path/Frameworks/libtexlua52.5.dylib luatex.dylib
install_name_tool -change $TEXINSTDIR/libkpathsea.6.dylib @executable_path/Frameworks/libkpathsea.6.dylib luatex.dylib

cp $TEXWORKDIR/texk/web2c/.libs/pdftex.dylib .
install_name_tool -id @executable_path/Frameworks/pdftex.dylib  pdftex.dylib
install_name_tool -change $TEXINSTDIR/libkpathsea.6.dylib @executable_path/Frameworks/libkpathsea.6.dylib pdftex.dylib

# cp $TEXWORKDIR/texk/web2c/.libs/xetex.dylib .
# install_name_tool -id @executable_path/Frameworks/xetex.dylib xetex.dylib 
# install_name_tool -change $TEXINSTDIR/libkpathsea.6.dylib @executable_path/Frameworks/libkpathsea.6.dylib xetex.dylib

cp $TEXWORKDIR/texk/bibtex-x/.libs/bibtexu.dylib .
install_name_tool -id @executable_path/Frameworks/bibtexu.dylib bibtexu.dylib 
install_name_tool -change $TEXINSTDIR/libkpathsea.6.dylib @executable_path/Frameworks/libkpathsea.6.dylib bibtexu.dylib

cp $TEXWORKDIR/texk/bibtex-x/.libs/bibtex8.dylib .
install_name_tool -id @executable_path/Frameworks/bibtex8.dylib bibtex8.dylib 
install_name_tool -change $TEXINSTDIR/libkpathsea.6.dylib @executable_path/Frameworks/libkpathsea.6.dylib bibtex8.dylib

