# Makefile.am for Open Cascade toolkit TKNIS
srcdir = @srcdir@

VPATH = @srcdir@ : \
@top_srcdir@/drv/NIS : @top_srcdir@/src/NIS


AM_CXXFLAGS = 


AM_CFLAGS = 


INCLUDES = $(CSF_OPT_INCLUDES) $(STLPort_INCLUDES) $(CSF_OpenGlLibs_INCLUDES) $(CSF_user32_INCLUDES) $(CSF_gdi32_INCLUDES)  \
-I@top_srcdir@/inc \
-I@top_srcdir@/drv/NIS -I@top_srcdir@/src/NIS


lib_LTLIBRARIES=libTKNIS.la

libTKNIS_la_LIBADD = $(CSF_OPT_LIBS) \
 \
../TKBRep/libTKBRep.la \
../TKV3d/libTKV3d.la \
../TKMath/libTKMath.la \
../TKernel/libTKernel.la \
../TKService/libTKService.la \
../TKG2d/libTKG2d.la \
../TKG3d/libTKG3d.la \
../TKMesh/libTKMesh.la \
$(STLPort_LIB) $(CSF_OpenGlLibs_LIB) $(CSF_user32_LIB) $(CSF_gdi32_LIB) 

libTKNIS_la_SOURCES = \
@top_srcdir@/src/NIS/NIS_Allocator.cxx \
@top_srcdir@/src/NIS/NIS_DrawList.cxx \
@top_srcdir@/src/NIS/NIS_Drawer.cxx \
@top_srcdir@/src/NIS/NIS_InteractiveContext.cxx \
@top_srcdir@/src/NIS/NIS_InteractiveObject.cxx \
@top_srcdir@/src/NIS/NIS_ObjectsIterator.cxx \
@top_srcdir@/src/NIS/NIS_SelectFilter.cxx \
@top_srcdir@/src/NIS/NIS_Surface.cxx \
@top_srcdir@/src/NIS/NIS_SurfaceDrawer.cxx \
@top_srcdir@/src/NIS/NIS_Triangulated.cxx \
@top_srcdir@/src/NIS/NIS_TriangulatedDrawer.cxx \
@top_srcdir@/src/NIS/NIS_View.cxx

