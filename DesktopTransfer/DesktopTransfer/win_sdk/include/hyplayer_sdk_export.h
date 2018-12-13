#ifndef _HYPLAYER_SDK_EXPORT_H_
#define _HYPLAYER_SDK_EXPORT_H_

#ifdef WIN32
#ifdef BUILD_HYPLAYER_SDK_DLL
#define HYPLAYER_SDK_DLL __declspec(dllexport)
#else
#define HYPLAYER_SDK_DLL __declspec(dllimport)
#endif
#else
#ifdef __GNUC__
#define HYPLAYER_SDK_DLL __attribute__ ((visibility("default")))
#else
#define HYPLAYER_SDK_DLL
#endif
#endif

#endif
