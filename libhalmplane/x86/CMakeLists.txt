string(CONCAT SRC
  "src/MplaneAlarms.cpp;"
  "src/MplaneEcpri.cpp;"
  "src/MplaneInterfaces.cpp;"
  "src/MplaneProcessingElements.cpp;"
  "src/MplaneUplaneConf.cpp;"
  "src/HalMplane.cpp;"
)

list(TRANSFORM SRC PREPEND "x86/")
target_sources(halmplane PRIVATE ${SRC})

