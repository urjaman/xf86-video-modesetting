#ifndef COMPAT_API_H
#define COMPAT_API_H

#ifndef GLYPH_HAS_GLYPH_PICTURE_ACCESSOR
#define GetGlyphPicture(g, s) GlyphPicture((g))[(s)->myNum]
#define SetGlyphPicture(g, s, p) GlyphPicture((g))[(s)->myNum] = p
#endif

#ifndef XF86_HAS_SCRN_CONV
#define xf86ScreenToScrn(s) xf86Screens[(s)->myNum]
#define xf86ScrnToScreen(s) screenInfo.screens[(s)->scrnIndex]
#endif

#ifndef XF86_SCRN_INTERFACE

#define SCRN_ARG_TYPE int
#define SCRN_INFO_PTR(arg1) ScrnInfoPtr pScrn = xf86Screens[(arg1)]

#define SCREEN_ARG_TYPE int
#define SCREEN_PTR(arg1) ScreenPtr pScreen = screenInfo.screens[(arg1)]

#define SCREEN_INIT_ARGS int i, ScreenPtr pScreen, int argc, char **argv

#define CLOSE_SCREEN_ARGS_DECL int scrnIndex, ScreenPtr pScreen
#define CLOSE_SCREEN_ARGS scrnIndex, pScreen

#define VTFUNC_ARGS(flags) pScrn->scrnIndex, (flags)
#else
#define SCRN_ARG_TYPE ScrnInfoPtr
#define SCRN_INFO_PTR(arg1) ScrnInfoPtr pScrn = (arg1)

#define SCREEN_ARG_TYPE ScreenPtr
#define SCREEN_PTR(arg1) ScreenPtr pScreen = (arg1)

#define SCREEN_INIT_ARGS ScreenPtr pScreen, int argc, char **argv

#define CLOSE_SCREEN_ARGS_DECL ScreenPtr pScreen
#define CLOSE_SCREEN_ARGS pScreen

#define VTFUNC_ARGS(flags) pScrn, (flags)
#endif
#endif
