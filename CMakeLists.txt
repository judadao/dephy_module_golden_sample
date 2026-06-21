cmake_minimum_required(VERSION 3.20.0)

project(dephy_module_golden_sample C)

add_library(dephy_module_golden_sample STATIC
  src/sample.c
)

target_include_directories(dephy_module_golden_sample PUBLIC include)

