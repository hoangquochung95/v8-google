#include "openGlApi.h"
#include <node.h>
#include <iostream>
#include "openGlAddon.h"

using v8::FunctionCallbackInfo;
using v8::Value;
using v8::Isolate;
using v8::String;
using v8::Function;
using v8::Context;
using v8::Local;
Persistent<Function> openGlAddon::globalGlut ;
void openGlAddon::CreateGlutObject(const FunctionCallbackInfo<Value>& args){
    // Glut::InitTest();
    Isolate* isolate = Isolate::GetCurrent();
    Local<Function> tpl = Local<Function>::New(isolate,globalGlut);
    Local<Function> fn = Glut::GetContext(tpl);
    args.GetReturnValue().Set(globalGlut);
}

void openGlAddon::Init(Local<Function> global){
    Isolate* isolate = Isolate::GetCurrent();
    globalGlut.Reset(isolate,global);
}
