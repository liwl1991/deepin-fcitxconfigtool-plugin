#include <QApplication>
#include <gtest/gtest.h>

#if defined(CMAKE_SAFETYTEST_ARG_ON)
#include <sanitizer/asan_interface.h>
#endif

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    testing::InitGoogleTest(&argc, argv);

    #if defined(CMAKE_SAFETYTEST_ARG_ON)
        __sanitizer_set_report_path("asan.log");
    #endif

    return  RUN_ALL_TESTS();
}
