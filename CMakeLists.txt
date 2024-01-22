cmake_minimum_required(VERSION 3.25)
project(bouncing_square)

set(CMAKE_C_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

set(SDL2_PATH "$ENV{SDL2}") # In this part I use $ENV{} which is used to access enviorment variables so I do not need to write whole path. However, you can use for example something like this : set(SDL2_PATH "C:/SDL2_mingw/x86_64-w64-mingw32")
set(SDL2_IMAGE_PATH "$ENV{SDL2_image}") # In this part I use $ENV{} which is used to access enviorment variables so I do not need to write whole path. However, you can use for example something like this : set(SDL2_IMAGE_PATH "C:/SDL2_image_mingw/x86_64-w64-mingw32")
set(SDL2_TTF_PATH "$ENV{SDL2_ttf}") # In this part I use $ENV{} which is used to access enviorment variables so I do not need to write whole path. However, you can use for example something like this : set(SDL2_TTF_PATH "C:/SDL2_ttf_mingw/x86_64-w64-mingw32")
set(SDL2_MIXER_PATH "$ENV{SDL2_mixer}") # In this part I use $ENV{} which is used to access enviorment variables so I do not need to write whole path. However, you can use for example something like this : set(SDL2_MIXER_PATH "C:/SDL2_mixer_mingw/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR})

add_executable(bouncing_square main.cpp Game.cpp Game.h square.cpp square.h)

# Delete 3 lines bellow if you want no console
# if(WIN32)
#    target_link_options(${PROJECT_NAME} PUBLIC "-mconsole")
# endif()
# Delete 3 lines above if you want no console

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_MIXER_LIBRARY})