setifempty(CANVAS_ALSA_MUTE_USE_VOLUME 0)

find_package( ALSA REQUIRED )
ADD_DEPENDENTS( ALSA )