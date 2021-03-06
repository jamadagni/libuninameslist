/* Generic helper definitions for shared library support */
/* as explained in - https://gcc.gnu.org/wiki/Visibility */
#if defined _WIN32 || defined __CYGWIN__
  #define UN_DLL_IMPORT __declspec(dllimport)
  #define UN_DLL_EXPORT __declspec(dllexport)
  #define UN_DLL_LOCAL
#else
  #if __GNUC__ >= 4
    #define UN_DLL_IMPORT __attribute__ ((visibility ("default")))
    #define UN_DLL_EXPORT __attribute__ ((visibility ("default")))
    /* 'internal' to avoid library conflicts. 'hidden' for debugging */
    /* #define UN_DLL_LOCAL  __attribute__ ((visibility ("hidden"))) */
    #define UN_DLL_LOCAL  __attribute__ ((visibility ("internal")))
  #else
    #define UN_DLL_IMPORT
    #define UN_DLL_EXPORT
    #define UN_DLL_LOCAL
  #endif
#endif
