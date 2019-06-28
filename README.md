# lib-tex

A variant of the texlive 2019 distribution, but adapted for cross-compiling and with function calls in a library. I made it so I could use pdftex and luatex on iOS, but there are other uses. 

To compile: 
```
./build_command.sh
```
This is just the "Build" command of texlive, but with most of the packages (e.g. tex, dvipdfmx...) disabled. If you are not cross-compiling for iOS, remove the "--host" and "--build" part of the command, as well as the "CFLAGS", "CXXFLAGS", "OBJCXXFLAGS". 

Once compilation is done, you may have to edit the digital libraries to change their location and the location of other dynamic libraries relative to them. Copy "fix_texlive_dynamiclibs.sh" to the directory where you will be installing the libraries, edit the two environment variables at the top, then run it:
```
./fix_texlive_dynamiclibs.sh
```

You should be all set. "texlive_ios.h" is the header file that contains the function calls you can use: 
```
extern int bibtex_main(int argc, char *argv[]);
extern int dllluatexmain(int argc, char *argv[]);
extern int dllpdftexmain(int argc, char *argv[]);
```

Each of them is equivalent to calling "main()" in the respective command. To call "lualatex myFile.tex", you call:
```
dllluatexmain(2, "lualatex", "myFile.tex");
```

If you do not have access to the standard input, you will need to disable interactive mode: 
```
dllluatexmain(3, "lualatex", "--interaction=nonstopmode", "myFile.tex");
```

Or if you use [ios_system](https://github.com/holzschu/ios_system) just call:
```
ios_system("lualatex --interaction=nonstopmode myFile.tex");
```

# TeX files

This repository contains only the binaries. You will also need the texlive files distribution. The easiest way to get them is:

- get the torrent for the distribution as an ISO file: http://tug.org/texlive/acquire-iso.html
- mount the ISO file on your Mac
- `cd` to the directory corresponding to the mounted disk
- start `./install-tl -gui` to install the files
- install all the files you need to a temporary directory. Make sure the installer also compiles the formats.
- copy that directory to `~/Library/texlive/` on your iPad application (so you should have a directory `~/Library/texlive/2019/` containing `texmf-dist`). 



# Backward compatibility

This directory contains the texlive-2019 binaries. An earlier version contained the texlive-2017 binaries. The formats generated are mutually incompatible. To prevent compatibility issues, for the time being, the `ios_system` releases keeps the texlive-2017 binaries, and this directory has the texlive-2019 binaries as a release. 

