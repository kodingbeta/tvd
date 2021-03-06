SET( ST_STAPP_LIB_DIR "${ST_API_SDK}/stapp/stapp.dir/hmp_7109_ST40_LINUX_29BITS/" )
SET( ST_APILIB_LIB_DIR "${ST_API_SDK}/apilib/lib/hmp_7109_ST40_LINUX_29BITS/" )

# Flags
SET( ST_CFLAGS "-DST_7109 -DDVD_FRONTEND_TUNER='\"NIM_TC90517\"' -DST_LINUX -Dcocoref_gold -Dstpti4 -DDVB -DPROCESSOR_SH4 -DARCHITECTURE_ST40" )
SET( ST_CFLAGS_EX "-DDVD_TRANSPORT_STPTI4 -DDVD_TRANSPORT_STPTI   -DUSE_STFRONTEND  -DTUNER_TER_INCLUDED -DSTPTI_DVB_SUPPORT -DSTMERGE_INTERRUPT_SUPPORT -DSTVTG_CLK_HDMI -DSTVTG_HDMI -DSTPTI_INDEX_SUPPORT -DSERVICE_DVB -DSTVID_DEBUG_GET_STATISTICS -DSTAPI_INTERRUPT_BY_NUMBER -DATAPI_USING_INTERRUPTS -DRDE_DISPLAY_SERVICE -DDISABLE_OSD_DISPLAY_SERVICE -DRDE_ENABLE_NOTIFY_COMMAND_IS_POSTED -DSTTTX_SUBT_SYNC_ENABLE -DSTTTX_SYNC_OFFSET=0 -DSTFDMA_TTS_SUPPORT -DSERVICE_DVB -DTCPIP -DSTDVM_AD_SUPPORT -DSTPRM_AD_SUPPORT -DDVR -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -DDISPLAY_SD=D_PAL -DDISPLAY_HD=D_1080I50HZ -DSTCLKRV_EXT_CLKA_MHZ=30 -DSTCLKRV_EXT_CLKB_MHZ=0 -DSTCLKRV_EXT_CLK_MHZ=0 -DSTSDK -DRUN_FROM_FLASH -DLINUX_UNIFIED_STAPI -DDVD_ADDRESSMODE=29 -DHARDWARE_REVISION=1 -DST_OSLINUX -DDVD_PLATFORM='\"cocoref_gold\"' -DDVD_BACKEND='\"7109\"'" )
SET( ST_BUILD_DEFINITIONS ${ST_CFLAGS} ${ST_CFLAGS_EX} )

# Libs
SET( ST_BUILD_INCLUDE_DIRS 
  "${ST_API_SDK}/stapp/"
  "${ST_API_SDK}/stapp/include"
  "${ST_API_SDK}/stapp/platform/cocoref_gold/7109"
  "${ST_API_SDK}/apilib/include"
  "${ST_API_SDK}/apilib/config/chip"
  "${ST_API_SDK}/apilib/config/platform/cocoref_gold_7109"
  )

SET( ST_BUILD_LIBRARIES
  "${ST_STAPP_LIB_DIR}/libstapp_hmp.a"
  "${ST_STAPP_LIB_DIR}/libplayrecdvr.a"
  "${ST_APILIB_LIB_DIR}/libmulticom.a"
  "${ST_APILIB_LIB_DIR}/libstapi_stpti4.a"
  "${ST_APILIB_LIB_DIR}/libstaudlx.a"
  "${ST_APILIB_LIB_DIR}/libstavmem.a"
  "${ST_APILIB_LIB_DIR}/libstblast.a"
  "${ST_APILIB_LIB_DIR}/libstblit.a"
  "${ST_APILIB_LIB_DIR}/libstbuffer.a"
  "${ST_APILIB_LIB_DIR}/libstcc.a"
  "${ST_APILIB_LIB_DIR}/libstclkrv.a"
  "${ST_APILIB_LIB_DIR}/libstcommon.a"
  "${ST_APILIB_LIB_DIR}/libstdenc.a"
  "${ST_APILIB_LIB_DIR}/libstevt.a"
  "${ST_APILIB_LIB_DIR}/libstfdma.a"
  "${ST_APILIB_LIB_DIR}/libstfrontend.a"
  "${ST_APILIB_LIB_DIR}/libstgfb.a"
  "${ST_APILIB_LIB_DIR}/libstgxobj.a"
  "${ST_APILIB_LIB_DIR}/libsthdmi.a"
  "${ST_APILIB_LIB_DIR}/libsti2c.a"
  "${ST_APILIB_LIB_DIR}/libstinject.a"
  "${ST_APILIB_LIB_DIR}/libstlayer.a"
  "${ST_APILIB_LIB_DIR}/libstmerge.a"
  "${ST_APILIB_LIB_DIR}/libstnet.a"
  "${ST_APILIB_LIB_DIR}/libstos.a"
  "${ST_APILIB_LIB_DIR}/libstpio.a"
  "${ST_APILIB_LIB_DIR}/libstpti4.a"
  "${ST_APILIB_LIB_DIR}/libstpwm.a"
  "${ST_APILIB_LIB_DIR}/libstsmart.a"
  "${ST_APILIB_LIB_DIR}/libstspi.a"
  "${ST_APILIB_LIB_DIR}/libstsubt.a"
  "${ST_APILIB_LIB_DIR}/libstsys.a"
  "${ST_APILIB_LIB_DIR}/libstttx.a"
  "${ST_APILIB_LIB_DIR}/libstuart.a"
  "${ST_APILIB_LIB_DIR}/libstvbi.a"
  "${ST_APILIB_LIB_DIR}/libstvid.a"
  "${ST_APILIB_LIB_DIR}/libstvin.a"
  "${ST_APILIB_LIB_DIR}/libstvmix.a"
  "${ST_APILIB_LIB_DIR}/libstvout.a"
  "${ST_APILIB_LIB_DIR}/libstvtg.a"
  "dl"
  "rt"
  )
set(ST_BUILD_FOUND 1)
