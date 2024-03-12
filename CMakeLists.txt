cmake_minimum_required(VERSION 3.0.0)
project(cmake_intro VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCE_FILES
    src/cart_main.cpp
    src/Item.cpp
    src/Product.cpp
    src/Cart.cpp
)


add_executable(cart_project ${SOURCE_FILES})
target_include_directories(cart_project PUBLIC include)

