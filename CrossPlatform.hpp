#ifndef CrossPlatform_h
#define CrossPlatform_h

#ifdef MAC_OS
void cp_setlocale(void) {
    setlocale(LC_CTYPE, "");
}
#else
void cp_setlocale(void) {
    setlocale(LC_ALL, "Russian");
}
#endif

#endif
