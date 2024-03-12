cmake_minimum_required(VERSION 3.0.0)
project(cmake_intro VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCE_FILES
    cart_main.cpp
    Item.cpp
    Product.cpp
    Cart.cpp
)

add_executable(cart_project ${SOURCE_FILES})