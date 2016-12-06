DEF_OPTIONS(UTIL_BASE linux android ios windows mingw ppapi)
DEF_OPTIONS(IO ev event uv DEFAULT ev ON)
DEF_OPTIONS(LOG none log android ios ppapi DEFAULT log ON)
DEF_OPTIONS(SETTINGS bdb xml memory DEFAULT bdb ON xml ON memory ON)
DEF_OPTIONS(BACKTRACE gnu dummy win32 breakpad DEFAULT gnu ON)
DEF_OPTIONS(UTF8_CONVERTER EMBED ICONV DEFAULT ICONV ON)
DEF_OPTIONS(DOM xerces tinyxml DEFAULT xerces ON)
DEF_OPTIONS(NETLIB curl DEFAULT curl ON)

ADD_BOOST_COMPONENTS( system filesystem thread )
