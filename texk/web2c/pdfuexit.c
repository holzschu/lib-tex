/* uexit.c: define uexit to do an exit with the right status.  We can't
   just call `exit' from the web files, since the webs use `exit' as a
   loop label.  Public domain. */

// uexit called from tangle, weave. uexitandclear called from (pdf)TeX

#include <w2c/config.h>
#ifdef __IPHONE__
extern void ios_exit(int errorCode) __dead2; // set error code and exits from the thread.
#define exit ios_exit
#include "pdftexdir/ptexlib.h"
#ifndef xfree
#  define xfree(p)            do { if (p != NULL) free(p); p = NULL; } while (0)
#endif

extern void* fixmem; 
extern void* eqtb; 

// Could include the header file, but not worth it
extern void PdfObjTree_free(void);
#endif

// uexit_and_clear is defined in texlive/texk/web2c/tex.ch. Must be changed too.
void
uexitandclear (int unix_code)
{
  // 	fprintf(stderr, "Entering uexitandclear\n");
  int final_code;
  
  if (unix_code == 0)
    final_code = EXIT_SUCCESS;
  else if (unix_code == 1)
    final_code = EXIT_FAILURE;
  else
    final_code = unix_code;
#ifdef __IPHONE__
  // This function is called for each exit, either regular exit 
  // or exit after error. 
  // We need to deallocate everything
  PdfObjTree_free();
  // from pdftexini.c
  xfree(yhash);
  xfree(zeqtb); 
  xfree(yzmem); 
  xfree(strstart); 
  xfree(strpool); 
  xfree(fontinfo); 
  xfree(fontcheck);
  xfree(fontsize );
  xfree(fontdsize );
  xfree(fontparams);
  xfree(fontname);
  xfree(fontarea);
  xfree(fontbc);
  xfree(fontec);
  xfree(fontglue);
  xfree(hyphenchar);
  xfree(skewchar);
  xfree(bcharlabel);
  xfree(fontbchar);
  xfree(fontfalsebchar);
  xfree(charbase);
  xfree(widthbase);
  xfree(heightbase);
  xfree(depthbase);
  xfree(italicbase);
  xfree(ligkernbase);
  xfree(kernbase);
  xfree(extenbase);
  xfree(parambase);
  xfree(pdfcharused);
  xfree(pdffontsize );
  xfree(pdffontnum);
  xfree(pdffontmap);
  xfree(pdffonttype);
  xfree(pdffontattr);
  xfree(pdffontblink);
  xfree(pdffontelink);
  xfree(pdffontstretch);
  xfree(pdffontshrink);
  xfree(pdffontstep);
  xfree(pdffontexpandratio);
  xfree(pdffontautoexpand);
  xfree(pdffontlpbase);
  xfree(pdffontrpbase);
  xfree(pdffontefbase);
  xfree(pdffontknbsbase);
  xfree(pdffontstbsbase);
  xfree(pdffontshbsbase);
  xfree(pdffontknbcbase);
  xfree(pdffontknacbase);
  xfree(vfpacketbase);
  xfree(vfdefaultfont);
  xfree(vflocalfontnum);
  // xfree(vfefnts); // This one breaks things down
  // xfree(vfifnts); // This one breaks things down
  xfree(pdffontnobuiltintounicode);
  xfree(trietrl);
  xfree(trietro);
  xfree(trietrc);
  xfree(buffer);
  xfree(nest);
  xfree(savestack);
  xfree(inputstack);
  xfree(inputfile);
  xfree(linestack);
  xfree(eofseen);
  xfree(grpstack);
  xfree(ifstack);
  xfree(sourcefilenamestack);
  xfree(fullsourcefilenamestack);
  xfree(paramstack);
  xfree(dvibuf);
  xfree(hyphword);
  xfree(hyphlist);
  xfree(hyphlink);
  xfree(objtab);
  xfree(pdfmem);
  pdfmemsize = 0; 
  pdfmemptr = 0; 
  xfree(destnames);
  xfree(pdfopbuf);
  xfree(pdfosbuf);
  xfree(pdfosobjnum);
  xfree(pdfosobjoff);
  xfree(fontused);
  xfree(nameoffile);
  dump_name = NULL; // dump_name needs to be reset, but not freed
  // it's a pointer to an area that has already been freed. 
#endif /* __IPHONE__ */
  //	fprintf(stderr, "Leaving uexitandclear\n");
  exit (final_code);
}
