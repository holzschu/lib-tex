#!/bin/sh
# -D __IPHONE__ for specific changes in the code
# -D NDEBUG to deactivate assert

 ./Build  --host=arm-apple-darwin --build=x86_64-apple-darwin \
 --disable-native-texlive-build \
 --enable-shared \
 --disable-static \
 --disable-cxx-runtime-hack \
 --without-x \
 --disable-cjkutils \
 --disable-texdoctk \
 --disable-tpic2pdftex \
 --disable-tex         \
 --disable-ptex        \
 --disable-eptex       \
 --disable-uptex       \
 --disable-euptex      \
 --disable-luajittex   \
 --disable-xetex       \
 --disable-web-progs   \
 --disable-synctex     \
 --disable-tex4htk     \
 --disable-mktexmf-default \
 --disable-mktexpk-default \
 --disable-mktextfm-default \
 --disable-mktexfmt-default \
 --disable-aleph \
 --disable-mp \
 --disable-pmp \
 --disable-upmp \
 --disable-xdvipdfmx \
 --disable-xindy \
 --disable-xpdfopen \
 --disable-dvi2tty \
 --disable-dvidvi \
 --disable-dviljk \
 --disable-dvipdfm-x \
 --disable-dvipng \
 --disable-dvipos \
 --disable-dvipsk \
 --disable-dvisvgm \
 --disable-xdvik \
 --with-system-zlib \
 --disable-mfluajit \
 --disable-multiplatform \
 CC=clang \
 CXX=clang++ \
 OBJCXX=clang++ \
 CFLAGS="-arch\ arm64\ -isysroot\ /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS11.0.sdk\ -D\ __IPHONE__\ -D\ POPPLER_VERSION\ " \
 CXXFLAGS="-arch\ arm64\ -isysroot\ /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS11.0.sdk\ -D\ __IPHONE__\ -D\ POPPLER_VERSION\ " \
 OBJCXXFLAGS="-arch\ arm64\ -isysroot\ /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS11.0.sdk\ -D\ __IPHONE__\ -D\ POPPLER_VERSION\ " \
 > & build_cross.log

