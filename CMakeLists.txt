cmake_minimum_required(VERSION 3.17)
project(BT1)

set(CMAKE_CXX_STANDARD 14)
#Demo
#add_executable(BT1 Start/1.cpp )
#add_executable(BT1 Start/4.cpp )


#2D folder
#bai 1 ve duong thang bang thuat toan bresenham
#add_executable(BT1 2D/run.cpp)

#add_executable(BT1 2D/Bresenham.cpp )

#ve bre...
add_executable(BT1 run.cpp)
#//ve duong thang theo thuat toan
#add_executable(BT1 main3.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

#Thu muc 2D
#1.1.Thuật toán vẽ đoạn thẳng (xét 4 trường hợp của hệ số góc)
#1.2.Thuật toán vẽ đường tròn
#1.3.Thuật toán vẽ ellipse
#1.4.Vẽ các đường cong khác: parabol, hyperbol, sin(x), cos(x)
#Yêu cầu: Sử dụng sự kiện click chuột để xác định đoạn thẳng, đường tròn,
#ellipse,... cần vẽ

#– Cài đặt các thuật toán xén hình và tô màu sau:
#2.1.Thuật toán xén hình:
#- Cohen sutherland
#- Chia nhị phân
#2.2.Thuật toán tô màu:
#- Tô màu theo đường biên (dùng đệ quy, không đệ quy)
#- Tô màu theo dòng quét
#Yêu cầu: Sử dụng sự kiện click chuột để xác định đoạn thẳng xén, vùng tô
#(đa giác) đọc từ file dữ liệu....