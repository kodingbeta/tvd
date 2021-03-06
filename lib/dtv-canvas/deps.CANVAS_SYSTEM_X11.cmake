Find_Package( X11 REQUIRED )
IF("${X11_Xrender_FOUND}" STREQUAL "TRUE")
  LIST( APPEND X11_LIBRARIES ${X11_Xrender_LIB} )
ENDIF()

IF("${X11_Xcomposite_FOUND}" STREQUAL "TRUE")
  LIST( APPEND X11_LIBRARIES ${X11_Xcomposite_LIB} )
ENDIF()

IF("${X11_Xdamage_FOUND}" STREQUAL "TRUE")
  LIST( APPEND X11_LIBRARIES ${X11_Xdamage_LIB} )
ENDIF()

ADD_DEPENDENTS( X11 )
