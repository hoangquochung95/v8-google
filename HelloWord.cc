#include <node.h>
#include <iostream>
#include <GL/glut.h>
#include <stdlib.h> 

namespace HelloWord
{
    using v8::FunctionCallbackInfo;
    using v8::Local;
    using v8::Isolate;
    using v8::Value;
    using v8::String;
    using v8::Object;
    using v8::Number;
    using v8::Exception;
    using v8::Context;
    using v8::Function;
    using v8::NewStringType;
    using v8::ObjectTemplate;
    
    void concatString (const FunctionCallbackInfo<Value>& args){
        Isolate* isolate = args.GetIsolate();
        std::cout << args[0]->IsString() ;
        if(args.Length() == 0 || !args[0]->IsString() || !args[1]->IsString() ){
            isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate,"Not a string")));
        }
        // args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Hello World"));
        Local<String> fullName = String::Concat(args[0]->ToString(),args[1]->ToString());
        args.GetReturnValue().Set(fullName);
    }

    void total (const FunctionCallbackInfo<Value>& args){
        Isolate* isolate = args.GetIsolate();
        if(args.Length() == 0 || !args[0]->IsNumber() || !args[1]->IsNumber() ){
            isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate,"Not a number")));
        }
        double total = args[0]->NumberValue() + args[1]->NumberValue();
        args.GetReturnValue().Set(Number::New(isolate,total));
    }

    void runCallback(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();
        Local<Context> context = isolate->GetCurrentContext();
        Local<Function> cb = Local<Function>::Cast(args[0]);
        const unsigned argc = 2;
        Local<Value> argv[argc] = {
            String::NewFromUtf8(isolate,
                                "Hoang",
                                NewStringType::kNormal).ToLocalChecked(),
                                
            String::NewFromUtf8(isolate,
                                "Hung",
                                NewStringType::kNormal).ToLocalChecked(),
                                 };
                                                             
        cb->Call(context, Null(isolate), argc, argv).ToLocalChecked();
    }

    void createObject(const FunctionCallbackInfo<Value>& args){
        Isolate* isolate = args.GetIsolate();
        Local<Context> context = isolate->GetCurrentContext();
        Local<Object> obj = Object::New(isolate);

        obj->Set(context,
                String::NewFromUtf8(isolate,
                                "info",
                                NewStringType::kNormal).ToLocalChecked(),
                args[0]->ToString(context).ToLocalChecked()) 
               .FromJust();
        args.GetReturnValue().Set(obj);
    }

    void init (Local<Object> exports){
        NODE_SET_METHOD(exports,"concatString",concatString);
        NODE_SET_METHOD(exports,"total",total);
        NODE_SET_METHOD(exports,"runCallback",runCallback);

    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, init)
} // namespace HelloWord
