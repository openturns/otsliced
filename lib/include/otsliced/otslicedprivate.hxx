
#ifndef OTSLICED_PRIVATE_HXX
#define OTSLICED_PRIVATE_HXX

/* From http://gcc.gnu.org/wiki/Visibility */
/* Generic helper definitions for shared library support */
#if defined _WIN32 || defined __CYGWIN__
#define OTSLICED_HELPER_DLL_IMPORT __declspec(dllimport)
#define OTSLICED_HELPER_DLL_EXPORT __declspec(dllexport)
#define OTSLICED_HELPER_DLL_LOCAL
#else
#if __GNUC__ >= 4
#define OTSLICED_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
#define OTSLICED_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
#define OTSLICED_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#else
#define OTSLICED_HELPER_DLL_IMPORT
#define OTSLICED_HELPER_DLL_EXPORT
#define OTSLICED_HELPER_DLL_LOCAL
#endif
#endif

/* Now we use the generic helper definitions above to define OTSLICED_API and OTSLICED_LOCAL.
 * OTSLICED_API is used for the public API symbols. It either DLL imports or DLL exports (or does nothing for static build)
 * OTSLICED_LOCAL is used for non-api symbols. */

#ifndef OTSLICED_STATIC /* defined if OT is compiled as a DLL */
#ifdef OTSLICED_DLL_EXPORTS /* defined if we are building the OT DLL (instead of using it) */
#define OTSLICED_API OTSLICED_HELPER_DLL_EXPORT
#else
#define OTSLICED_API OTSLICED_HELPER_DLL_IMPORT
#endif /* OTSLICED_DLL_EXPORTS */
#define OTSLICED_LOCAL OTSLICED_HELPER_DLL_LOCAL
#else /* OTSLICED_STATIC is defined: this means OT is a static lib. */
#define OTSLICED_API
#define OTSLICED_LOCAL
#endif /* !OTSLICED_STATIC */


#endif // OTSLICED_PRIVATE_HXX

