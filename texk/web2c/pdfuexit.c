/* uexit.c: define uexit to do an exit with the right status.  We can't
   just call `exit' from the web files, since the webs use `exit' as a
   loop label.  Public domain. */

// uexit called from tangle, weave. uexitandclear called from (pdf)TeX

#include <w2c/config.h>
#ifdef __IPHONE__
#include <pthread.h>
#ifndef xfree
#  define xfree(p)            do { if (p != NULL) free(p); p = NULL; } while (0)
#endif
//
// from pdftexini.c
extern void* yhash; 
extern void* zeqtb; 
extern void* yzmem; 
extern void* strstart; 
extern void* strpool; 
extern void* fontinfo; 
extern void* fontcheck;
extern void* fontsize ;
extern void* fontdsize ;
extern void* fontparams;
extern void* fontname;
extern void* fontarea;
extern void* fontbc;
extern void* fontec;
extern void* fontglue;
extern void* hyphenchar;
extern void* skewchar;
extern void* bcharlabel;
extern void* fontbchar;
extern void* fontfalsebchar;
extern void* charbase;
extern void* widthbase;
extern void* heightbase;
extern void* depthbase;
extern void* italicbase;
extern void* ligkernbase;
extern void* kernbase;
extern void* extenbase;
extern void* parambase;
extern void* pdfcharused;
extern void* pdffontsize ;
extern void* pdffontnum;
extern void* pdffontmap;
extern void* pdffonttype;
extern void* pdffontattr;
extern void* pdffontblink;
extern void* pdffontelink;
extern void* pdffontstretch;
extern void* pdffontshrink;
extern void* pdffontstep;
extern void* pdffontexpandratio;
extern void* pdffontautoexpand;
extern void* pdffontlpbase;
extern void* pdffontrpbase;
extern void* pdffontefbase;
extern void* pdffontknbsbase;
extern void* pdffontstbsbase;
extern void* pdffontshbsbase;
extern void* pdffontknbcbase;
extern void* pdffontknacbase;
extern void* vfpacketbase;
extern void* vfdefaultfont;
extern void* vflocalfontnum;
extern void* vfefnts;
extern void* vfifnts;
extern void* pdffontnobuiltintounicode;
extern void* trietrl;
extern void* trietro;
extern void* trietrc;
extern void* buffer;
extern void* nest;
extern void* savestack;
extern void* inputstack;
extern void* inputfile;
extern void* linestack;
extern void* eofseen;
extern void* grpstack;
extern void* ifstack;
extern void* sourcefilenamestack;
extern void* fullsourcefilenamestack;
extern void* paramstack;
extern void* dvibuf;
extern void* hyphword;
extern void* hyphlist;
extern void* hyphlink;
extern void* objtab;
extern void* pdfmem;
extern int pdfmemsize; 
extern int pdfmemptr; 
extern void* destnames;
extern void* pdfopbuf;
extern void* pdfosbuf;
extern void* pdfosobjnum;
extern void* pdfosobjoff;
extern void* fontused; 
extern void* nameoffile; 
// Could include the header file, but not worth it
extern void PdfObjTree_free(void);
#endif

void
uexitandclear (int unix_code)
{
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
  pthread_exit(NULL); 
#else 
  exit (final_code);
#endif 
}
