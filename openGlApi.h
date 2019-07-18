#include <node.h>

using v8::Persistent;
using v8::ObjectTemplate;
using v8::Local;
using v8::FunctionCallbackInfo;
using v8::Value;
using v8::FunctionTemplate;
using v8::Context;
using v8::Object;
using v8::Function;

class Glut {
    public: 
        static Persistent<Function> constructor;
        Glut();
        ~Glut();
        Local<Function> Init(int* argc,char** argv);
        static void Display();
        static Local<FunctionTemplate> InitGlut(int* argc,char** argv);
        static Local<FunctionTemplate> CreateWindowGlut(int* argc,char** argv);
        static Local<Function> GetContext(Local<Function> globalGlut);
        static void InitTest();
};