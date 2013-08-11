
#if !defined( __P2L_COMMON_gcc_diagnostics_HPP__ )
#define __P2L_COMMON_gcc_diagnostics_HPP__



//
// Enable/Disable warniongs locally for GCC
//
// Usage:
// GCC_DIAG_OFF(sign-compare); 
// if(a < b){
//      GCC_DIAG_ON(sign-compare);
// ....
//
// Where the "sign-compare" comes as the name of the command line warning option
// and can be found by running gcc with -fdiagnostics-show-option, wher warnings
// will be printed with a trailing [-W<option>] specifying which option caused
// the warning to be fired.

#if ((__GNUC__ * 100) + __GNUC_MINOR__) >= 402 
#define GCC_DIAG_STR(s) #s 
#define GCC_DIAG_JOINSTR(x,y) GCC_DIAG_STR(x ## y) 
# define GCC_DIAG_DO_PRAGMA(x) _Pragma (#x) 
# define GCC_DIAG_PRAGMA(x) GCC_DIAG_DO_PRAGMA(GCC diagnostic x) 
# if ((__GNUC__ * 100) + __GNUC_MINOR__) >= 406 
# define GCC_DIAG_OFF(x) GCC_DIAG_PRAGMA(push) \
      GCC_DIAG_PRAGMA(ignored GCC_DIAG_JOINSTR(-W,x)) 
# define GCC_DIAG_ON(x) GCC_DIAG_PRAGMA(pop) 
# else 
# define GCC_DIAG_OFF(x) GCC_DIAG_PRAGMA(ignored GCC_DIAG_JOINSTR(-W,x)) 
# define GCC_DIAG_ON(x) GCC_DIAG_PRAGMA(warning GCC_DIAG_JOINSTR(-W,x)) 
# endif 
#else 
# define GCC_DIAG_OFF(x) 
# define GCC_DIAG_ON(x) 
#endif

#endif

