add_library(WhatchaDoinPass MODULE WhatchaDoin.cpp)

target_compile_features(WhatchaDoinPass PRIVATE cxx_range_for cxx_auto_type)

set_target_properties(WhatchaDoinPass PROPERTIES COMPILE_FLAGS "-fno-rtti")
if(APPLE)
    set_target_properties(WhatchaDoinPass PROPERTIES
        LINK_FLAGS "-undefined dynamic_lookup"
    )
endif(APPLE)
