#include <jni.h>       
#include <iostream>    

#include <filesystem>
#include "FileMovement.h"  // Generated
using namespace std;

std::string toString(JNIEnv *env, jstring jStr);
std::string toString(JNIEnv *env, jstring jStr){
 if (!jStr)
        return "";

    const jclass stringClass = env->GetObjectClass(jStr);
    const jmethodID getBytes = env->GetMethodID(stringClass, "getBytes", "(Ljava/lang/String;)[B");
    const jbyteArray stringJbytes = (jbyteArray) env->CallObjectMethod(jStr, getBytes, env->NewStringUTF("UTF-8"));

    size_t length = (size_t) env->GetArrayLength(stringJbytes);
    jbyte* pBytes = env->GetByteArrayElements(stringJbytes, NULL);

    std::string ret = std::string((char *)pBytes, length);
    env->ReleaseByteArrayElements(stringJbytes, pBytes, JNI_ABORT);

    env->DeleteLocalRef(stringJbytes);
    env->DeleteLocalRef(stringClass);
    return ret;
}

JNIEXPORT jboolean JNICALL Java_FileMovement_fileMove(JNIEnv *env, jobject thisObj, jstring jStr1, jstring jStr2) {

string ret1=toString(env,jStr1);

string ret2=toString(env,jStr2);
try {
    std::filesystem::rename(ret1, ret2);
	cout << "Inside c++: file moved successfully"<< endl;
	return true;
  } catch (std::filesystem::filesystem_error& e) {
    std::cout << e.what() << '\n';
  }

	cout << "Inside c++: error occured"<< endl;
   return false;
}