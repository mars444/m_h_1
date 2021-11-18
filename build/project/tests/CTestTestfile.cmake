# CMake generated Testfile for 
# Source directory: /home/mars444/TP/mail-homework/project/tests
# Build directory: /home/mars444/TP/mail-homework/build/project/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(BaseTest "/home/mars444/TP/mail-homework/memtest.sh" "/home/mars444/TP/mail-homework/build/project/tests/tests" "/home/mars444/TP/mail-homework/project/tests/data" "--gtest_filter=-*Extra*")
set_tests_properties(BaseTest PROPERTIES  _BACKTRACE_TRIPLES "/home/mars444/TP/mail-homework/project/tests/CMakeLists.txt;26;ADD_TEST;/home/mars444/TP/mail-homework/project/tests/CMakeLists.txt;0;")
add_test(ExtraTest "/home/mars444/TP/mail-homework/memtest.sh" "/home/mars444/TP/mail-homework/build/project/tests/tests" "/home/mars444/TP/mail-homework/project/tests/data" "--gtest_filter=*Extra*")
set_tests_properties(ExtraTest PROPERTIES  _BACKTRACE_TRIPLES "/home/mars444/TP/mail-homework/project/tests/CMakeLists.txt;30;ADD_TEST;/home/mars444/TP/mail-homework/project/tests/CMakeLists.txt;0;")
