cmake_minimum_required(VERSION 3.12)
project(ed1_queue_list09_cpp LANGUAGES CXX)

add_executable(queue_list09
    main.cpp
    src/Exer01_ImmediateShiftQueue.cpp
    src/Exer02_StackBasedQueue.cpp
    src/Exer03_OutputRestrictedDeque.cpp
    src/Exer04_PreservedCountQueue.cpp
    src/Exer05_MergeSortedQueues.cpp
    src/Exer06_SplitEvenOddQueue.cpp
)
target_include_directories(queue_list09 PRIVATE include)
target_compile_features(queue_list09 PRIVATE cxx_std_14)
