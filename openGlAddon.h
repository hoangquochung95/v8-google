#include <node.h>

using v8::FunctionCallbackInfo;
using v8::Value;

class openGlAddon {
  public:
    static void CreateGlutObject(const FunctionCallbackInfo<Value>& args);
    static void Init(Local<Function> context);
    static Persistent<Function> globalGlut;
};

