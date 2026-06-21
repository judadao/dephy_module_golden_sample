if(CONFIG_DEPHY_MODULE_GOLDEN_SAMPLE)
  zephyr_library_named(dephy_module_golden_sample)
  zephyr_library_sources(../src/sample.c)
  zephyr_library_sources_ifdef(CONFIG_DEPHY_MODULE_GOLDEN_SAMPLE_STANDALONE
    ../src/main.c
  )
  zephyr_library_include_directories(../include)
  zephyr_include_directories(../include)
endif()

