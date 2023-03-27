cmake_minimum_required(VERSION 3.17)
project(shixi)

set(CMAKE_CXX_STANDARD 14)

add_executable(shixi main.cpp)
add_executable(1 alibaba/1.cpp)
add_executable(3_dfc alibaba/3_dfc.cpp)
add_executable(2 alibaba/2.cpp)
add_executable(2_dfc alibaba/2_dfc.cpp)

add_executable(two tengxun/two.cpp)
add_executable(lianbiao tengxun/lianbiao.cpp)
add_executable(yihuo tengxun/yihuo.cpp)
add_executable(gongyueshu tengxun/gongyueshu.cpp)
add_executable(offer_62 alibaba/offer_62.cpp)