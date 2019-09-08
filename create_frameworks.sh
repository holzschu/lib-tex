#!/bin/sh
# -D __IPHONE__ for specific changes in the code
# -D NDEBUG to deactivate assert

rm -rf Frameworks/texlua53.framework
mkdir Frameworks/texlua53.framework 
cp Work/libs/lua53/.libs/libtexlua53.5.dylib Frameworks/texlua53.framework/texlua53
cp basic_Info.plist Frameworks/texlua53.framework/Info.plist
plutil -replace CFBundleExecutable -string texlua53 Frameworks/texlua53.framework/Info.plist
plutil -replace CFBundleName -string texlua53 Frameworks/texlua53.framework/Info.plist
plutil -replace CFBundleIdentifier -string Nicolas-Holzschuch.texlua53 Frameworks/texlua53.framework/Info.plist
install_name_tool -id @rpath/texlua53.framework/texlua53   Frameworks/texlua53.framework/texlua53

rm -rf Frameworks/kpathsea.framework
mkdir Frameworks/kpathsea.framework 
cp Work/texk/kpathsea/.libs/libkpathsea.dylib Frameworks/kpathsea.framework/kpathsea
cp basic_Info.plist Frameworks/kpathsea.framework/Info.plist
plutil -replace CFBundleExecutable -string kpathsea Frameworks/kpathsea.framework/Info.plist
plutil -replace CFBundleName -string kpathsea Frameworks/kpathsea.framework/Info.plist
plutil -replace CFBundleIdentifier -string Nicolas-Holzschuch.kpathsea Frameworks/kpathsea.framework/Info.plist
install_name_tool -id  @rpath/kpathsea.framework/kpathsea   Frameworks/kpathsea.framework/kpathsea

rm -rf Frameworks/luatex.framework
mkdir Frameworks/luatex.framework 
cp Work/texk/web2c/.libs/luatex.dylib Frameworks/luatex.framework/luatex
cp basic_Info.plist Frameworks/luatex.framework/Info.plist
plutil -replace CFBundleExecutable -string luatex Frameworks/luatex.framework/Info.plist
plutil -replace CFBundleName -string luatex Frameworks/luatex.framework/Info.plist
plutil -replace CFBundleIdentifier -string Nicolas-Holzschuch.luatex Frameworks/luatex.framework/Info.plist
install_name_tool -id @rpath/luatex.framework/luatex   Frameworks/luatex.framework/luatex
install_name_tool -change $PWD/inst/lib/libtexlua53.5.dylib @rpath/texlua53.framework/texlua53  Frameworks/luatex.framework/luatex
install_name_tool -change @rpath/libkpathsea.6.dylib  @rpath/kpathsea.framework/kpathsea Frameworks/luatex.framework/luatex


rm -rf Frameworks/pdftex.framework
mkdir Frameworks/pdftex.framework
cp Work/texk/web2c/.libs/pdftex.dylib Frameworks/pdftex.framework/pdftex
cp basic_Info.plist Frameworks/pdftex.framework/Info.plist
plutil -replace CFBundleExecutable -string pdftex Frameworks/pdftex.framework/Info.plist
plutil -replace CFBundleName -string pdftex Frameworks/pdftex.framework/Info.plist
plutil -replace CFBundleIdentifier -string Nicolas-Holzschuch.pdftex Frameworks/pdftex.framework/Info.plist
install_name_tool -id @rpath/pdftex.framework/pdftex   Frameworks/pdftex.framework/pdftex
install_name_tool -change @rpath/libkpathsea.6.dylib @rpath/kpathsea.framework/kpathsea Frameworks/pdftex.framework/pdftex


rm -rf Frameworks/bibtex.framework
mkdir Frameworks/bibtex.framework
cp Work/texk/bibtex-x/.libs/bibtex8.dylib Frameworks/bibtex.framework/bibtex
cp basic_Info.plist Frameworks/bibtex.framework/Info.plist
plutil -replace CFBundleExecutable -string bibtex Frameworks/bibtex.framework/Info.plist
plutil -replace CFBundleName -string bibtex Frameworks/bibtex.framework/Info.plist
plutil -replace CFBundleIdentifier -string Nicolas-Holzschuch.bibtex Frameworks/bibtex.framework/Info.plist
install_name_tool -id @rpath/bibtex.framework/bibtex   Frameworks/bibtex.framework/bibtex
install_name_tool -change @rpath/libkpathsea.6.dylib @rpath/kpathsea.framework/kpathsea Frameworks/bibtex.framework/bibtex


