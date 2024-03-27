#include <jni.h>
#include <string>
#include<android/log.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/seccomp.h>
#include <sys/prctl.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/reg.h>
//#include "proot/tracee/event.h"
#include "logging.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_testforsvctrace_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    LOGI("main thread %d", getpid());
//    char *const argv[] = {"hello"};

    return env->NewStringUTF(hello.c_str());
}
