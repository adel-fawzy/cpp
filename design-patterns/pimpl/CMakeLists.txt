add_library(pimpl STATIC
    src/SecureComm.cpp
    src/Encryptor.cpp
)

# The following function includes only the public header files that are required in order for the client to use the library
# If we did not use the pimpl design pattern, we would have included also the private header files
target_include_directories(pimpl PUBLIC
    include
)

target_include_directories(pimpl PRIVATE
    src/include
)

add_executable(pimpl-test src/main.cpp)

target_link_libraries(pimpl-test PRIVATE
    pimpl    
)