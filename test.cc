#include <GL/glut.h>
#include "openGlApi.h"
#include "openGlAddon.h"
#include <node.h>
#include <iostream>

using v8::Persistent;
using v8::ObjectTemplate;
using v8::Local;
using v8::Isolate;
using v8::String;
using v8::NewStringType;
using v8::Context;
using v8::FunctionTemplate;
using v8::FunctionCallbackInfo;
using v8::Value;
using v8::Data; 
using v8::Number;
using v8::FunctionCallback;
using v8::HandleScope;
using v8::Context;
using v8::Object;
using v8::Function;

void init(Local<Object> exports){
    NODE_SET_METHOD(exports,"createGlutObject",openGlAddon::CreateGlutObject);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    Isolate* isolate = Isolate::GetCurrent();
    isolate->Enter();
    Glut globalGlut;
    Local<Function> global = globalGlut.Init(&argc,argv);
    openGlAddon::Init(global);

    return 0;
}

NODE_MODULE(NODE_GYP_MODULE_NAME,init);